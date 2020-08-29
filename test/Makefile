include ../common.mk

ODIR=.obj
PODIR=.pobj

SRC=$(shell find . -type f -name '*.c')
OBJ=$(patsubst %.c,$(ODIR)/%.o,$(SRC))
EXE=$(patsubst %.c,$(BIN_DIR)/%,$(SRC))

PSRC=$(shell find . -type f -name '*.cpp')
POBJ=$(patsubst %.cpp,$(PODIR)/%.o,$(PSRC))
PEXE=$(patsubst %.cpp,$(BIN_DIR)/%,$(PSRC))

$(shell mkdir -p $(ODIR))
$(shell mkdir -p $(PODIR))

DEPFILES=$(SRC:%.c=$(ODIR)/%.d)
PDEPFILES=$(PSRC:%.cpp=$(PODIR)/%.d)


# to prevent files from being auto-deleted by make after build completes
.SECONDARY:

.PHONY: all
all: $(EXE) $(PEXE)

$(BIN_DIR)/%: $(ODIR)/%.o $(LIBUTIL)
	$(CC) $(CFLAGS) $< -o $@ $(IFLAGS) $(LDFLAGS) -lutil

$(BIN_DIR)/%: $(PODIR)/%.o $(LIBUTIL)
	$(PCC) $(CPPFLAGS) $< -o $@ $(IFLAGS) $(LDFLAGS) -lutil

$(ODIR)/%.o: %.c
	$(CC) $(CFLAGS) $< -c -o $@ $(IFLAGS)

$(PODIR)/%.o: %.cpp
	$(PCC) $(CPPFLAGS) $< -c -o $@ $(IFLAGS)


-include $(wildcard $(DEPFILES))
-include $(wildcard $(PDEPFILES))

.PHONY: clean
clean:
	rm -rf $(ODIR)

