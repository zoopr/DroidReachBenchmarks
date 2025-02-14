#include <jni.h>
#include <string>

class C1 {
public: virtual int M1(){ return 1; }
};

class C2 : C1{
public: virtual int M2(){ return 2; }
};

class C3 : public C1 {

public:
    C2* member_c2;

    C3(){
        member_c2 = new C2();
    }

    virtual ~C3() {
        free(member_c2);
    }

    virtual int M3(){ return 3; }
};



extern "C"
JNIEXPORT jlong JNICALL
Java_com_example_cp_1membervtable_MainActivity_build_1obj(JNIEnv *env, jobject thiz) {
    C3* c3ptr = new C3();
    return reinterpret_cast<jlong>(c3ptr);
}

// Consumer-Producer Member VTable lookup.
// This is the most complex example.
// The method is called from a separate vtable, dereferenced from the member offset.
// This usage will not be visible by any build except the latest one.
// It is also a pattern that happens quite often in "Container-style" main classes
// Common in multi-platform adaptations of larger codebases.
// We've seen this in chromium-based apps and game engines.

extern "C"
JNIEXPORT jint JNICALL
Java_com_example_cp_1membervtable_MainActivity_member_1class_1method(JNIEnv *env, jobject thiz,
                                                                     jlong native_obj) {
    C3* c3ptr = reinterpret_cast<C3 *>(native_obj);
    return c3ptr->member_c2->M2();
}