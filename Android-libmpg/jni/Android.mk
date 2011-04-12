LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

MPG123_CFLAGS 	  := -O2 -Wall -D__ANDROID__ -I. -I mpg123/src

MPG123_SRC_FILES := \
	mpg123/src/libmpg123/compat.c \
	mpg123/src/libmpg123/frame.c \
	mpg123/src/libmpg123/id3.c \
	mpg123/src/libmpg123/format.c \
	mpg123/src/libmpg123/stringbuf.c \
	mpg123/src/libmpg123/libmpg123.c\
	mpg123/src/libmpg123/readers.c\
	mpg123/src/libmpg123/icy.c\
	mpg123/src/libmpg123/icy2utf8.c\
	mpg123/src/libmpg123/index.c\
	mpg123/src/libmpg123/layer1.c\
	mpg123/src/libmpg123/layer2.c\
	mpg123/src/libmpg123/layer3.c\
	mpg123/src/libmpg123/parse.c\
	mpg123/src/libmpg123/optimize.c\
	mpg123/src/libmpg123/synth.c\
	mpg123/src/libmpg123/synth_8bit.c\
	mpg123/src/libmpg123/synth_real.c\
	mpg123/src/libmpg123/synth_s32.c\
	mpg123/src/libmpg123/synth_arm.S\
	mpg123/src/libmpg123/ntom.c\
	mpg123/src/libmpg123/dct64.c\
	mpg123/src/libmpg123/equalizer.c\
	mpg123/src/libmpg123/dither.c\
	mpg123/src/libmpg123/tabinit.c\
	mpg123/src/libmpg123/feature.c

LOCAL_MODULE    := mpg
LOCAL_ARM_MODE  := arm
LOCAL_SRC_FILES := MP3Decoder.cpp $(MPG123_SRC_FILES)
LOCAL_CFLAGS    := $(MPG123_CFLAGS)

include $(BUILD_SHARED_LIBRARY)

