LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

MPG123_CFLAGS := -O2 -Wall -D__ANDROID__ -I.

MPG123_SRC_FILES := \
	libmpg123/compat.c \
	libmpg123/frame.c \
	libmpg123/id3.c \
	libmpg123/format.c \
	libmpg123/stringbuf.c \
	libmpg123/libmpg123.c\
	libmpg123/readers.c\
	libmpg123/icy.c\
	libmpg123/icy2utf8.c\
	libmpg123/index.c\
	libmpg123/layer1.c\
	libmpg123/layer2.c\
	libmpg123/layer3.c\
	libmpg123/parse.c\
	libmpg123/optimize.c\
	libmpg123/synth.c\
	libmpg123/synth_8bit.c\
	libmpg123/synth_real.c\
	libmpg123/synth_s32.c\
	libmpg123/synth_arm.S\
	libmpg123/ntom.c\
	libmpg123/dct64.c\
	libmpg123/equalizer.c\
	libmpg123/dither.c\
	libmpg123/tabinit.c\
	libmpg123/synth_arm_accurate.S\
	libmpg123/feature.c

LOCAL_MODULE    := mpg
LOCAL_ARM_MODE  := arm
LOCAL_SRC_FILES := MP3Decoder.cpp $(MPG123_SRC_FILES)
LOCAL_CFLAGS    := $(MPG123_CFLAGS)

include $(BUILD_SHARED_LIBRARY)

