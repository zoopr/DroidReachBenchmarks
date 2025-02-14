#include <android/log.h>
#include <jni.h>
#include <string>

#define LOG_TAG    "trigger"
#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

void target_fun() {
    LOGI("call: target_fun()");
}

class C1 {
public: virtual int M1(){
    target_fun();
    return 1;
    }
};

class C3 : public C1 {
public: virtual int M3(){ return 3; }
};



extern "C"
JNIEXPORT jlong JNICALL
Java_com_example_cp_1ancestorvtable_MainActivity_build_1obj(JNIEnv *env, jobject thiz) {
    C3* c3ptr = new C3();
    return reinterpret_cast<jlong>(c3ptr);
}

// Consumer-Producer filled-in method from ancestor class.
// In theory, this ends up in the same vtable as the instantiated class
// and should have been visible by the previous DroidReach build.
// (at least, to my understanding of clang internals)
// However, detecting inherited methods is very inconsistent with direct vtable hooks.
// I suspect an Angr bug. Anyway, the new approach is much more consistent.

extern "C"
JNIEXPORT jint JNICALL
Java_com_example_cp_1ancestorvtable_MainActivity_parent_1class_1method(JNIEnv *env, jobject thiz,
                                                                       jlong native_obj) {
    C3* c3ptr = reinterpret_cast<C3 *>(native_obj);
    return c3ptr->M1();
}