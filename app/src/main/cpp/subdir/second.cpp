#include <jni.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
// 引入log头文件
#include <android/log.h>

typedef struct {
    char name[255];
    int age;
} Person;
// log标签
#define  TAG    "zty_tag"
// 定义info信息
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG,__VA_ARGS__)
// 定义debug信息
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)
// 定义error信息
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG,__VA_ARGS__)

//同一个
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_administrator_jniresrevedemo_MainActivity_getStringFromOtherFile(JNIEnv *env,
                                                                                  jobject instance) {
    std::string hello = "This String is from second C++ file";
    return env->NewStringUTF(hello.c_str());
}