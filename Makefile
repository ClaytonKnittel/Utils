include common.mk

SDIR=src
ODIR=.obj
PSDIR=src
PODIR=.pobj

SLIB=$(LIB_DIR)/libutil.a


SRC=$(shell find $(SDIR) -type f -name '*.c')
OBJ=$(patsubst $(SDIR)/%.c,$(ODIR)/%.o,$(SRC))
DEP=$(wildcard $(SDIR)/*.h)

DIRS=$(shell find $(SDIR) -type d)
OBJDIRS=$(patsubst $(SDIR)/%,$(ODIR)/%,$(DIRS))

$(shell mkdir -p $(LIB_DIR))
$(shell mkdir -p $(ODIR))
$(shell mkdir -p $(OBJDIRS))
$(shell mkdir -p $(BIN_DIR))

DEPFILES=$(SRC:$(SDIR)/%.c=$(ODIR)/%.d)


PSRC=$(shell find $(PSDIR) -type f -name '*.cpp')
POBJ=$(patsubst $(PSDIR)/%.cpp,$(PODIR)/%.o,$(PSRC))
PDEP=$(wildcard $(PSDIR)/*.h)

PDIRS=$(shell find $(PSDIR) -type d)
POBJDIRS=$(patsubst $(PSDIR)/%,$(PODIR)/%,$(PDIRS))

$(shell mkdir -p $(PODIR))
$(shell mkdir -p $(POBJDIRS))

PDEPFILES=$(PSRC:$(PSDIR)/%.cpp=$(PODIR)/%.d)


.PHONY: all
all: $(SLIB) tests

.PHONY: tests
tests:
	(make -C $(TEST_DIR) BASE_DIR=$(BASE_DIR) SLIB=$(SLIB) LIBUTIL=$(SLIB))


$(SLIB): $(OBJ) $(POBJ)
	$(AR) -rcs $@ $^


$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) $(CFLAGS) $< -c -o $@ $(IFLAGS)

$(PODIR)/%.o: $(SDIR)/%.cpp
	$(PCC) $(CPPFLAGS) $< -c -o $@ $(IFLAGS)


-include $(wildcard $(DEPFILES))
-include $(wildcard $(PDEPFILES))

.PHONY: clean
clean:
	rm -rf $(ODIR) $(PODIR)
	rm -rf $(LIB_DIR)
	rm -rf $(BIN_DIR)
	(make -C $(TEST_DIR) clean)


