################################################################################
# Android optee-hello-world makefile                                           #
################################################################################
LOCAL_PATH := $(call my-dir)

CFG_TEEC_PUBLIC_INCLUDE = $(LOCAL_PATH)/../optee_client/public

################################################################################
# Build hello world                                                            #
################################################################################
include $(CLEAR_VARS)
LOCAL_CFLAGS += -DANDROID_BUILD
LOCAL_CFLAGS += -Wall

LOCAL_SRC_FILES += host/new_taps_ca.c \
new_taps_ca_debug.c \
new_taps_ca_test.c

LOCAL_C_INCLUDES := $(LOCAL_PATH)/ta/include \
		$(CFG_TEEC_PUBLIC_INCLUDE) \

LOCAL_SHARED_LIBRARIES := libcutils libteec
LOCAL_MODULE_TAGS := eng

LOCAL_MODULE := tee_newtaps

include $(BUILD_EXECUTABLE)

include $(LOCAL_PATH)/ta/Android.mk
