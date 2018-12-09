#include <jni.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <json.h>
#include <reader.h>
#include <iostream>
#include "JniUtils.h"
#include "time.h"
#include "web_task.h"
#include <sys/time.h>

using namespace std;

typedef struct {
    char name[255];
    int age;
} Person;

void quick_sort(int pInt[], int i, int i1);
int arrayList[10000000];
#define TAG "zty_tag"
#define JNI_PERSON "com/bean/Person"
#define MOVIE_BEAN "com/bean/Movie"

static jobject myInterface;

extern "C"
JNIEXPORT jstring

JNICALL
Java_com_example_administrator_jniresrevedemo_MainActivity_JavaCallC(JNIEnv *env,
                                                                     jobject obj /* this */) {

    std::string hello = "Hello from C++";

    return env->NewStringUTF(hello.c_str());
}
extern "C"

JNIEXPORT jobject JNICALL
Java_com_example_administrator_jniresrevedemo_MainActivity_getObjFromc(JNIEnv *env,
                                                                       jobject instance) {

    jclass clazzPerson = env->FindClass("com/bean/Person");
    jmethodID methodId = env->GetMethodID(clazzPerson, "<init>", "(Ljava/lang/String;I)V");
    jstring str = env->NewStringUTF("张三");
    jobject personObj = env->NewObject(clazzPerson, methodId, str, 20);

    return personObj;
}extern "C"

JNIEXPORT jobject JNICALL
Java_com_example_administrator_jniresrevedemo_MainActivity_setObjProperty(JNIEnv *env,
                                                                          jobject instance,
                                                                          jstring name_, jint age) {
    jclass clazzPerson = env->FindClass("com/bean/Person");
    jmethodID methodId = env->GetMethodID(clazzPerson, "<init>", "()V");
    //调用java类里面的方法
    jobject personObj = env->NewObject(clazzPerson, methodId);
    jmethodID setNameId = env->GetMethodID(clazzPerson, "setName", "(Ljava/lang/String;)V");
    env->CallCharMethod(personObj, setNameId, name_);
    jmethodID setAgeId = env->GetMethodID(clazzPerson, "setAge", "(I)V");
    env->CallIntMethod(personObj, setAgeId, age);

    return personObj;
}extern "C"

JNIEXPORT void JNICALL
Java_com_example_administrator_jniresrevedemo_MainActivity_printJavaProperty(JNIEnv *env,
                                                                             jobject instance,
                                                                             jobject person) {
    Person mPerson;
    //获取JAVA中的实例
    jclass clazzPerson = env->FindClass(JNI_PERSON);
    //获取类中每一个变量的ID
    jfieldID jfd = env->GetFieldID(clazzPerson, "name", "Ljava/lang/String;");
    jfieldID jfi = env->GetFieldID(clazzPerson, "age", "I");
    jstring jstr = (jstring) env->GetObjectField(person, jfd);
    const char *pszStr = (char *) env->GetStringUTFChars(jstr, 0);
    strcpy(mPerson.name, pszStr);
    mPerson.age = env->GetIntField(clazzPerson, jfi);

    LOGE("name is %s  age is %d ", mPerson.name, mPerson.age);
}extern "C"

// 比较
int compare(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

extern "C"

JNIEXPORT jobjectArray JNICALL
Java_com_example_administrator_jniresrevedemo_MainActivity_sortPersonByAge(JNIEnv *env,
                                                                           jobject instance,
                                                                           jobjectArray personArray) {

    jint lenth = env->GetArrayLength(personArray);
    for (int i = 0; i < lenth; ++i) {
        for (int j = 0; j < (lenth - 1) - i; j++) {
            //内层循环控制每一趟排序多少次
            jobject jobj = env->GetObjectArrayElement(personArray, j);
            jclass cls_person = env->GetObjectClass(jobj);
            jfieldID ageFieldID = env->GetFieldID(cls_person, "age", "I"); // 获得属性ID
            jint age = env->GetIntField(jobj, ageFieldID);//获得属性值

            jobject jobj2 = env->GetObjectArrayElement(personArray, j + 1);
            cls_person = env->GetObjectClass(jobj2);
            ageFieldID = env->GetFieldID(cls_person, "age", "I"); // 获得属性ID
            jint age2 = env->GetIntField(jobj2, ageFieldID);//获得属性值

            if (age > age2) {
                env->SetObjectArrayElement(personArray, j, jobj2);
                env->SetObjectArrayElement(personArray, j + 1, jobj);
            }
        }
    }

    return personArray;
}
extern "C"
JNIEXPORT jobject JNICALL  // jstring
Java_com_example_administrator_jniresrevedemo_MainActivity_getListFromUrl(JNIEnv *env,
                                                                          jobject instance) {

    //GET请求
    string url = "http://api.douban.com/v2/movie/in_theaters?count=2";
    WebTask task;
    task.SetUrl(url.c_str());
    task.SetConnectTimeout(5);
    task.DoGetString();
    if (task.WaitTaskDone() == 0) {
        //请求服务器成功
        string jsonResult = task.GetResultString();
        LOGI("返回的json数据是：%s\n", jsonResult.c_str());
        jmethodID method;
        jclass cls;
        cls = env->FindClass(MOVIE_BEAN);
        method = env->GetStaticMethodID(cls, "parseModel", "(Ljava/lang/String;)Lcom/bean/Movie;"); // 如果是返回实体类，那么就L+对应类名
        jobject objResult = env->CallStaticObjectMethod(cls, method, Str2Jstring(env, jsonResult.c_str()));
        return objResult;
    } else {
        return NULL;//env->NewStringUTF("网络连接失败！");
    }
}

//extern "C"
//JNIEXPORT jobject JNICALL
//Java_com_example_administrator_jniresrevedemo_MainActivity_sortData(JNIEnv *env, jobject instance,
//                                                                    jobject list) {
//    int i;
//    jclass cls_arraylist = env->GetObjectClass(list);
//    jmethodID arraylist_get = env->GetMethodID(cls_arraylist, "get", "(I)Ljava/lang/Object;");
//    jmethodID arraylist_size = env->GetMethodID(cls_arraylist, "size", "()I");
//    jmethodID arraylist_remove = env->GetMethodID(cls_arraylist, "remove", "(I)Ljava/lang/Object;");
//    jmethodID arraylist_add = env->GetMethodID(cls_arraylist, "add", "(ILjava/lang/Object;)V");
//    jint lenth = env->CallIntMethod(list, arraylist_size);
//    jobject obj = env->CallObjectMethod(list, arraylist_get, 0);
//    qsort(list,lenth, sizeof(int),compare);
//}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_administrator_jniresrevedemo_MainActivity_sortData(JNIEnv *env, jobject instance) {
    // 通过Java的数组，拿到C的数组的指针
//    jint *list = env->GetIntArrayElements(list_, NULL);
//    jsize lenth = env->GetArrayLength(list_);
//    qsort(list,lenth, sizeof(jint),compare);
//    env->ReleaseIntArrayElements(list_, list, 0);

    quick_sort(arrayList, 0, 10000000 - 1);
}

/**
 * 快速排序
 * @param s
 * @param l
 * @param r
 */
void quick_sort(int arr[], int low, int high) {

    int l = low;
    int h = high;
    int povit = arr[low];

    while (l < h) {
        while (l < h && arr[h] >= povit) {//如果后面的大于povit的，下标一直往前移
            h--;
        }
        if (l < h) {//记住前面的坐标是加的后面的是减得就可以了
            int temp = arr[h];
            arr[h] = arr[l];
            arr[l] = temp;
        }
        while (l < h && arr[l] <= povit)
            l++;
        if (l < h) {
            int temp = arr[h];
            arr[h] = arr[l];
            arr[l] = temp;
        }
    }
    if (l > low)
        quick_sort(arr, low, l - 1);
    if (h < high)
        quick_sort(arr, l + 1, high);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_administrator_jniresrevedemo_MainActivity_initArray(JNIEnv *env,
                                                                     jobject instance) {
    for (int i = 0; i < 10000000; i++) {
        arrayList[i] = rand() % 90000000;
    }
}

jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    LOGE("============JNI_Onload");
    return JNI_VERSION_1_4;
}

JNIEXPORT void JNICALL JNI_OnUnload(JavaVM *vm, void *reserved) {
    LOGE("============JNI_OnUnload");
}

