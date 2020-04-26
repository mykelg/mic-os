include $(CLEAR_VARS)

LOCAL_MODULE := bootloader

LOCAL_SRC_FILES :=
LOCAL_SRC_FILES += main.c
LOCAL_SRC_FILES += test.c
LOCAL_SRC_FILES += elf.c
LOCAL_SRC_FILES += lib.c
LOCAL_SRC_FILES += vector.c
LOCAL_SRC_FILES += startup.s
LOCAL_LINKER_FILE := linker.ld
LOCAL_BINARY := micos

LOCAL_SRC_DIR := bootloader

include $(BUILD_EXECUTABLE)
