include common.mk

SDIR=src
ODIR=.obj
PSDIR=src

SLIB=$(LIB_DIR)/libutil.a


SRC=$(shell find $(SDIR) -type f -name '*.c')
OBJ=$(patsubst $(SDIR)/%.c,$(ODIR)/%_c.o,$(SRC))
DEP=$(wildcard $(SDIR)/*.h)

DIRS=$(shell find $(SDIR) -type d)
OBJDIRS=$(patsubst $(SDIR)/%,$(ODIR)/%,$(DIRS))

$(shell mkdir -p $(LIB_DIR))
$(shell mkdir -p $(ODIR))
$(shell mkdir -p $(OBJDIRS))
$(shell mkdir -p $(BIN_DIR))

DEPFILES=$(SRC:$(SDIR)/%.c=$(ODIR)/%_c.d)


PSRC=$(shell find $(PSDIR) -type f -name '*.cpp')
POBJ=$(patsubst $(PSDIR)/%.cpp,$(ODIR)/%_cc.o,$(PSRC))
PDEP=$(wildcard $(PSDIR)/*.h)

PDIRS=$(shell find $(PSDIR) -type d)
POBJDIRS=$(patsubst $(PSDIR)/%,$(ODIR)/%,$(PDIRS))

$(shell mkdir -p $(POBJDIRS))

PDEPFILES=$(PSRC:$(PSDIR)/%.cpp=$(PODIR)/%_cc.d)

ASM=$(shell find $(SDIR) -type f -name '*.s')
ASM_OBJ=$(patsubst $(SDIR)/%.s,$(ODIR)/%_s.o,$(ASM))


.PHONY: all
all: $(SLIB)

.PHONY: test
test: $(SLIB)
	(make -C $(TEST_DIR) BASE_DIR=$(BASE_DIR) SLIB=$(SLIB) LIBUTIL=$(SLIB))

.PHONY: run_tests
run_tests: test
	(make run_all -C $(TEST_DIR) BASE_DIR=$(BASE_DIR))


$(SLIB): $(OBJ) $(POBJ) $(ASM_OBJ)
	$(AR) -rcs $@ $^


$(ODIR)/%_c.o: $(SDIR)/%.c
	$(CC) $(CFLAGS) $< -c -o $@ $(IFLAGS)

$(PODIR)/%_cc.o: $(SDIR)/%.cpp
	$(PCC) $(CPPFLAGS) $< -c -o $@ $(IFLAGS)

$(ODIR)/%_s.o: $(SDIR)/%.s
	$(CC) $(CFLAGS) $< -c -o $@


-include $(wildcard $(DEPFILES))
-include $(wildcard $(PDEPFILES))

.PHONY: clean
clean:
	rm -rf $(ODIR)
	rm -rf $(LIB_DIR)
	rm -rf $(BIN_DIR)
	(make -C $(TEST_DIR) clean)


