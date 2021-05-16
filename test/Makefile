include ../common.mk

ODIR=.obj

SRC=$(shell find . -type f -name '*.c')
OBJ=$(patsubst %.c,$(ODIR)/%_c.o,$(SRC))
EXE=$(patsubst %.c,$(BIN_DIR)/%,$(SRC))

PSRC=$(shell find . -type f -name '*.cc')
POBJ=$(patsubst %.cc,$(ODIR)/%_cc.o,$(PSRC))
PEXE=$(patsubst %.cc,$(BIN_DIR)/%,$(PSRC))

$(shell mkdir -p $(ODIR))

DEPFILES=$(SRC:%.c=$(ODIR)/%.d)
PDEPFILES=$(PSRC:%.cc=$(ODIR)/%.d)


# to prevent files from being auto-deleted by make after build completes
.SECONDARY:

.PHONY: all
all: $(EXE) $(PEXE)

run_all:
	./run_tests.sh $(EXE) $(PEXE)

$(BIN_DIR)/%: $(ODIR)/%_c.o $(LIBUTIL)
	$(CC) $(CFLAGS) $< -o $@ $(IFLAGS) $(LDFLAGS) -lutil

$(BIN_DIR)/%: $(ODIR)/%_cc.o $(LIBUTIL)
	$(PCC) $(CPPFLAGS) $< -o $@ $(IFLAGS) $(LDFLAGS) -lutil

$(ODIR)/%_c.o: %.c
	$(CC) $(CFLAGS) $< -c -o $@ $(IFLAGS)

$(ODIR)/%_cc.o: %.cc
	$(PCC) $(CPPFLAGS) $< -c -o $@ $(IFLAGS)


-include $(wildcard $(DEPFILES))
-include $(wildcard $(PDEPFILES))

.PHONY: clean
clean:
	rm -rf $(ODIR)

