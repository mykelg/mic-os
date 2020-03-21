include $(CLEAR_VARS)

LOCAL_MODULE := micos

LOCAL_SRC_FILES :=
LOCAL_SRC_FILES += test.c
LOCAL_SRC_FILES += vector.c
LOCAL_SRC_FILES += startup.s

LOCAL_SRC_DIR := os
LOCAL_LFLAGS := -T $(LOCAL_SRC_DIR)/test.ld

include $(BUILD_EXECUTABLE)
