#include "generatedJniHeaders/nobleworks_libmpg_MP3Decoder.h"
#include <stddef.h>
#include <fcntl.h>
#include "mpg123/src/libmpg123/compat.h"
#include "mpg123.h"
#include <jni.h>

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
