#include "com_example_jni_dynamic_register_TestNdk.h"

JNIEXPORT jstring JNICALL Java_com_example_jni_1dynamic_1register_TestNdk_getString
        (JNIEnv *env, jclass cls) {
    return (*env)->NewStringUTF(env, "Hello ,Wellcome to Jni World");
}