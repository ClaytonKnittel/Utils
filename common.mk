CC=gcc
PCC=g++
AR=ar

BASE_DIR=$(shell pwd)
LIB_DIR=$(BASE_DIR)/lib
TEST_DIR=$(BASE_DIR)/test
BIN_DIR=$(BASE_DIR)/bin

IFLAGS=-I$(BASE_DIR)/include

FTEST_MACROS=-D_GNU_SOURCE

DEBUG=0

ifeq ($(DEBUG), 0)
CFLAGS=-O3 -Wall -Wno-unused-function -MMD -MP $(FTEST_MACROS)
CPPFLAGS=-O3 -std=c++17 -Wall -Wno-unused-function -MMD -MP $(FTEST_MACROS)
else
CFLAGS=-O0 -Wall -Wno-unused-function -MMD -MP -g3 -DDEBUG $(FTEST_MACROS)
CPPFLAGS=-O0 -std=c++17 -Wall -Wno-unused-function -MMD -MP -g3 -DDEBUG $(FTEST_MACROS)
endif

LDFLAGS=-flto -L$(LIB_DIR)

