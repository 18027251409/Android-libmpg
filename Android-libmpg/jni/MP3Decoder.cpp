#include "generatedJniHeaders/nobleworks_libmpg_MP3Decoder.h"
#include "generatedJniHeaders/nobleworks_libmpg_MP3Decoder_Error.h"
#include "generatedJniHeaders/nobleworks_libmpg_MP3Decoder_Feature.h"
#include "generatedJniHeaders/nobleworks_libmpg_Encoding_Ordinals.h"
#include <stddef.h>
#include <fcntl.h>
#include "mpg123/src/libmpg123/compat.h"
#include "mpg123.h"
#include <jni.h>

// This should really throw an exception, but I'm a bit lazy
// to do that for a case that won't ever occur.
#define CHECK_ERROR_CODE(code) \
	if(MPG123_##code != nobleworks_libmpg_MP3Decoder_Error_##code)\
	{\
		return MPG123_BAD_VALUE;\
	}

JNIEXPORT jint JNICALL Java_nobleworks_libmpg_MP3Decoder_initialize
  (JNIEnv *env, jclass)
{
    CHECK_ERROR_CODE(DONE)
    CHECK_ERROR_CODE(NEW_FORMAT)
    CHECK_ERROR_CODE(NEED_MORE)
    CHECK_ERROR_CODE(ERR)
    CHECK_ERROR_CODE(OK)
    CHECK_ERROR_CODE(BAD_OUTFORMAT)
    CHECK_ERROR_CODE(BAD_CHANNEL)
    CHECK_ERROR_CODE(BAD_RATE)
    CHECK_ERROR_CODE(ERR_16TO8TABLE)
    CHECK_ERROR_CODE(BAD_PARAM)
    CHECK_ERROR_CODE(BAD_BUFFER)
    CHECK_ERROR_CODE(OUT_OF_MEM)
    CHECK_ERROR_CODE(NOT_INITIALIZED)
    CHECK_ERROR_CODE(BAD_DECODER)
    CHECK_ERROR_CODE(BAD_HANDLE)
    CHECK_ERROR_CODE(NO_BUFFERS)
    CHECK_ERROR_CODE(BAD_RVA)
    CHECK_ERROR_CODE(NO_GAPLESS)
    CHECK_ERROR_CODE(NO_SPACE)
    CHECK_ERROR_CODE(BAD_TYPES)
    CHECK_ERROR_CODE(BAD_BAND)
    CHECK_ERROR_CODE(ERR_NULL)
    CHECK_ERROR_CODE(ERR_READER)
    CHECK_ERROR_CODE(NO_SEEK_FROM_END)
    CHECK_ERROR_CODE(BAD_WHENCE)
    CHECK_ERROR_CODE(NO_TIMEOUT)
    CHECK_ERROR_CODE(BAD_FILE)
    CHECK_ERROR_CODE(NO_SEEK)
    CHECK_ERROR_CODE(NO_READER)
    CHECK_ERROR_CODE(BAD_PARS)
    CHECK_ERROR_CODE(BAD_INDEX_PAR)
    CHECK_ERROR_CODE(OUT_OF_SYNC)
    CHECK_ERROR_CODE(RESYNC_FAIL)
    CHECK_ERROR_CODE(NO_8BIT)
    CHECK_ERROR_CODE(BAD_ALIGN)
    CHECK_ERROR_CODE(NULL_BUFFER)
    CHECK_ERROR_CODE(NO_RELSEEK)
    CHECK_ERROR_CODE(NULL_POINTER)
    CHECK_ERROR_CODE(BAD_KEY)
    CHECK_ERROR_CODE(NO_INDEX)
    CHECK_ERROR_CODE(INDEX_FAIL)
    CHECK_ERROR_CODE(BAD_DECODER_SETUP)
    CHECK_ERROR_CODE(MISSING_FEATURE)
    CHECK_ERROR_CODE(BAD_VALUE)
    CHECK_ERROR_CODE(LSEEK_FAILED)
    CHECK_ERROR_CODE(BAD_CUSTOM_IO)
    CHECK_ERROR_CODE(LFS_OVERFLOW)

    return mpg123_init();
}

JNIEXPORT jintArray JNICALL Java_nobleworks_libmpg_MP3Decoder_getSupportedRates
  (JNIEnv *env, jclass)
{
	const long *list;
	size_t number;

	mpg123_rates(&list, &number);

	jintArray result = env->NewIntArray(number);

	jint *resultData = (jint *)env->GetPrimitiveArrayCritical(result, 0);

	for(size_t i = 0; i < number; i++)
	{
		resultData[i] = list[i];
	}

	env->ReleasePrimitiveArrayCritical(result, resultData, 0);

	return result;
}

int convertToEncodingOrdinal(int encoding)
{
	switch(encoding)
	{
		default : return -1;
		case MPG123_ENC_ALAW_8:		 return nobleworks_libmpg_Encoding_Ordinals_ALAW_8;
		case MPG123_ENC_ULAW_8:		 return nobleworks_libmpg_Encoding_Ordinals_ULAW_8;
		case MPG123_ENC_SIGNED_8:	 return nobleworks_libmpg_Encoding_Ordinals_PCM_SIGNED_8;
		case MPG123_ENC_UNSIGNED_8:	 return nobleworks_libmpg_Encoding_Ordinals_PCM_UNSIGNED_8;
		case MPG123_ENC_SIGNED_16:	 return nobleworks_libmpg_Encoding_Ordinals_PCM_SIGNED_16;
		case MPG123_ENC_UNSIGNED_16: return nobleworks_libmpg_Encoding_Ordinals_PCM_UNSIGNED_16;
		case MPG123_ENC_SIGNED_24:	 return nobleworks_libmpg_Encoding_Ordinals_PCM_SIGNED_24;
		case MPG123_ENC_UNSIGNED_24: return nobleworks_libmpg_Encoding_Ordinals_PCM_UNSIGNED_24;
		case MPG123_ENC_SIGNED_32:	 return nobleworks_libmpg_Encoding_Ordinals_PCM_SIGNED_32;
		case MPG123_ENC_UNSIGNED_32: return nobleworks_libmpg_Encoding_Ordinals_PCM_UNSIGNED_32;
		case MPG123_ENC_FLOAT_32:	 return nobleworks_libmpg_Encoding_Ordinals_PCM_FLOAT_32;
		case MPG123_ENC_FLOAT_64:	 return nobleworks_libmpg_Encoding_Ordinals_PCM_FLOAT_64;
	}
}

JNIEXPORT jintArray JNICALL Java_nobleworks_libmpg_MP3Decoder_getEncodings
  (JNIEnv *env, jclass)
{
	const int *list;
	size_t number;

	mpg123_encodings(&list, &number);

	jintArray result = env->NewIntArray(number);

	jint *resultData = (jint *)env->GetPrimitiveArrayCritical(result, 0);

	for(size_t i = 0; i < number; i++)
	{
		resultData[i] = convertToEncodingOrdinal(list[i]);
	}

	env->ReleasePrimitiveArrayCritical(result, resultData, 0);

	return result;
}

JNIEXPORT jstring JNICALL Java_nobleworks_libmpg_MP3Decoder_getErrorMessage
  (JNIEnv *env, jclass clz, jint error)
{
	return env->NewStringUTF(mpg123_plain_strerror(error));
}

JNIEXPORT jlong JNICALL Java_nobleworks_libmpg_MP3Decoder_create
  (JNIEnv *, jclass)
{
	return (jlong)mpg123_new(NULL,NULL);
}

mpg123_handle *getHandle(JNIEnv *env, jobject obj)
{
    jclass cls = env->GetObjectClass(obj);
    jfieldID fid = env->GetFieldID(cls, "handle", "I");

    return (mpg123_handle *)env->GetIntField(obj, fid);
}

JNIEXPORT void JNICALL Java_nobleworks_libmpg_MP3Decoder_delete
  (JNIEnv *env, jobject instance)
{
	mpg123_handle *handle = getHandle(env, instance);

	mpg123_delete(handle);
}

JNIEXPORT jint JNICALL Java_nobleworks_libmpg_MP3Decoder_close
  (JNIEnv *env, jobject instance)
{
	mpg123_handle *handle = getHandle(env, instance);

	return mpg123_close(handle);
}

JNIEXPORT jboolean JNICALL Java_nobleworks_libmpg_MP3Decoder_00024Feature_isFeatureSupported
  (JNIEnv *env, jclass, jint feature)
{
	return mpg123_feature( (enum mpg123_feature_set)feature);
}


