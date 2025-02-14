#include <android/log.h>
#include <jni.h>
#include <string>

#define LOG_TAG    "trigger"
#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

void target_fun() {
    LOGI("call: target_fun()");
}

class C1 {
    public: virtual int M1(){ return 1; }
};

class C3 : public C1 {
    public: virtual int M3(){
    target_fun();
    return 3; }
};

extern "C"
JNIEXPORT jlong JNICALL
Java_com_example_cp_1derivedvtable_MainActivity_build_1obj(JNIEnv *env, jobject thiz) {
    C3* c3ptr = new C3();
    return reinterpret_cast<jlong>(c3ptr);
}

// Baseline for Consumer-Producer indirect jump. Simple indirect jump + vtable method lookup.
// The other tools and previous version of DroidReach should not see it, but the experimental
// build with the basic Angr hooks should.
extern "C"
JNIEXPORT jint JNICALL
Java_com_example_cp_1derivedvtable_MainActivity_own_1class_1method(JNIEnv *env, jobject thiz,
                                                                   jlong native_obj) {
    C3* c3ptr = reinterpret_cast<C3 *>(native_obj);
    return c3ptr->M3();
}