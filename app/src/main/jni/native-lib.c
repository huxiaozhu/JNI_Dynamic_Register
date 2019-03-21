#include "com_example_jni_dynamic_register_TestNdk.h"
//添加log
#include <android/log.h>

#define TAG "JNI"
#define log_e(...) __android_log_print(ANDROID_LOG_ERROR,TAG,__VA_ARGS__)

# define NELEM(x) ((int) (sizeof(x) / sizeof((x)[0])))

#include <assert.h>

/**
 * 静态注册
 */
JNIEXPORT jstring JNICALL Java_com_example_jni_1dynamic_1register_TestNdk_getString
        (JNIEnv *env, jclass cls) {
    log_e("JNI begin");
    return (*env)->NewStringUTF(env, "Hello ,Wellcome to Jni World");
}

/**
 * *********************************
 * 动态注册流程
 */
JNIEXPORT void JNICALL native_diff
        (JNIEnv *env, jclass clazz, jstring path, jstring pattern_Path, jint file_num) {
    //3.
    log_e("JNI begin 动态注册的方法 ");
}

static int registerNatives(JNIEnv *engv) {
    //2
    log_e("registerNatives begin");
    jclass clazz;
    clazz = (*engv)->FindClass(engv, "com/example/jni_dynamic_register/TestNdk");

    if (clazz == NULL) {
        log_e("clazz is null");
        return JNI_FALSE;
    }

    JNINativeMethod gMethods[] = {
            {"diff", "(Ljava/lang/String;Ljava/lang/String;I)V", (void *) native_diff}
    };

    if ((*engv)->RegisterNatives(engv, clazz, gMethods, NELEM(gMethods)) < 0) {
        log_e("RegisterNatives error");
        return JNI_FALSE;
    }

    return JNI_TRUE;
}

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    //1.
    log_e("jni_OnLoad begin");

    JNIEnv *env = NULL;
//    jint result = -1;

    if ((*vm)->GetEnv(vm, (void **) &env, JNI_VERSION_1_4) != JNI_OK) {
        log_e("ERROR: GetEnv failed\n");
        return -1;
    }
    assert(env != NULL);

    registerNatives(env);

    return JNI_VERSION_1_4;
}

