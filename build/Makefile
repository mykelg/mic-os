PREFIX  := /usr/local/gcc-arm-none-eabi-9-2019-q4-major
ARCH    := arm-none-eabi
BINDIR  := $(PREFIX)/bin
ADDNAME := $(ARCH)-

AR      := $(BINDIR)/$(ADDNAME)ar
AS      := $(BINDIR)/$(ADDNAME)as
CC      := $(BINDIR)/$(ADDNAME)gcc
LD      := $(BINDIR)/$(ADDNAME)ld
NM      := $(BINDIR)/$(ADDNAME)nm
OBJCOPY := $(BINDIR)/$(ADDNAME)objcopy
OBJDUMP := $(BINDIR)/$(ADDNAME)objdump
RANLIB  := $(BINDIR)/$(ADDNAME)ranlib
STRIP   := $(BINDIR)/$(ADDNAME)strip

#Q := @
OUT_TARGET_ARM_DIR := out/target/arm
BIN_DIR := $(OUT_TARGET_ARM_DIR)/bin
OBJ_DIR := $(OUT_TARGET_ARM_DIR)/obj

CFLAGS :=
CFLAGS += -Wall -mthumb -mlittle-endian -march=armv7-m -mcpu=cortex-m3
CFLAGS += -ffreestanding
CFLAGS += -nostdinc -nostdlib -fno-builtin
#CFLAGS += -g
CFLAGS += -Os

LFLAGS :=
LFLAGS += -static

CLEAR_VARS := build/clear_vars.mk
BUILD_EXECUTABLE := build/build_executable.mk

$(foreach mkfile,$(MAKEFILES),$(eval include $(mkfile)))

all: $(BIN_DIR)/micos

clean:
	rm -rf out

start: $(BIN_DIR)/micos
	qemu-system-arm -cpu cortex-m3 -machine lm3s6965evb -nographic -kernel $^
