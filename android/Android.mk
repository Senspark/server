LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_CPPFLAGS += -std=c++1z
LOCAL_MODULE := server_static
LOCAL_MODULE_FILENAME := lib$(LOCAL_MODULE)
LOCAL_SRC_FILES := ${shell find $(LOCAL_PATH)/../src -name "*.cpp" -print}
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../src
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/../src
LOCAL_STATIC_LIBRARIES := smartfox_static

include $(BUILD_STATIC_LIBRARY)
