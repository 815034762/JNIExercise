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

#define JNI_PERSON "com/bean/Person"

extern "C"
JNIEXPORT jstring

JNICALL
Java_com_example_administrator_jniresrevedemo_MainActivity_stringFromJNI(JNIEnv *env,
                                                                         jobject obj /* this */) {

    std::string hello = "Hello from C++";

    jclass helloClazz = env->GetObjectClass(obj);
    jfieldID jfieldId = env->GetFieldID(helloClazz, "property", "I");
    jmethodID jmethodId = env->GetMethodID(helloClazz, "function", "(ILjava/util/Date;[I)V");
//   "(ILjava/util/Date;[I)I" 解释，()里面的是参数类型，)右边的I是返回值
    env->CallIntMethod(obj, jmethodId, 0, NULL, NULL);

    return env->NewStringUTF(hello.c_str());
}
extern "C"

JNIEXPORT jobject JNICALL
Java_com_example_administrator_jniresrevedemo_MainActivity_getObjFrom(JNIEnv *env,
                                                                      jobject instance) {

    jclass clazzPerson = env->FindClass("com/bean/Person");
    jmethodID methodId = env->GetMethodID(clazzPerson, "<init>", "(Ljava/lang/String;I)V");
    jstring str = env->NewStringUTF(" come from Native ");
    jobject personObj = env->NewObject(clazzPerson, methodId, str, 20);

    return personObj;
}extern "C"

JNIEXPORT jobject JNICALL
Java_com_example_administrator_jniresrevedemo_MainActivity_setObjProperty(JNIEnv *env,
                                                                          jobject instance,
                                                                          jstring name_, jint age) {
//  const char *name = env->GetStringUTFChars(name_, 0);
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

JNIEXPORT jobject JNICALL
Java_com_example_administrator_jniresrevedemo_MainActivity_sortPeron(JNIEnv *env, jobject instance,
                                                                     jobject list) {

    int i;
    jclass cls_arraylist = env->GetObjectClass(list);
    jmethodID arraylist_get = env->GetMethodID(cls_arraylist, "get", "(I)Ljava/lang/Object;");
    jmethodID arraylist_size = env->GetMethodID(cls_arraylist, "size", "()I");
    jmethodID arraylist_remove = env->GetMethodID(cls_arraylist, "remove", "(I)Ljava/lang/Object;");
    jmethodID arraylist_add = env->GetMethodID(cls_arraylist, "add", "(ILjava/lang/Object;)V");

    jint lenth = env->CallIntMethod(list, arraylist_size);

    for (int i = 0; i < lenth; ++i) {
        for (int j = 0; j < (lenth - 1) - i; j++) {//内层循环控制每一趟排序多少次

            jobject obj_user = env->CallObjectMethod(list, arraylist_get, j);
            jclass cls_user = env->GetObjectClass(obj_user);
            jfieldID ageFieldID = env->GetFieldID(cls_user, "age", "I"); // 获得属性ID
            jint age = env->GetIntField(obj_user, ageFieldID);//获得属性值

            jobject obj_user2 = env->CallObjectMethod(list, arraylist_get, j + 1);
            cls_user = env->GetObjectClass(obj_user2);
            ageFieldID = env->GetFieldID(cls_user, "age", "I"); // 获得属性ID
            jint age2 = env->GetIntField(obj_user2, ageFieldID);//获得属性值

            LOGI(" age1 %d  age2  %d ", age, age2);

            if (age > age2) {

                env->CallObjectMethod(list, arraylist_remove, j);
                env->CallObjectMethod(list, arraylist_add, j, obj_user2);

                env->CallObjectMethod(list, arraylist_remove, j + 1);
                env->CallObjectMethod(list, arraylist_add, j + 1, obj_user);
            }
        }
    }

//    for (i = 0; i < len; i++) {
//        jobject obj_user = env->CallObjectMethod(list, arraylist_get, i);
//        jclass cls_user = env->GetObjectClass(obj_user);
//        jfieldID nameID = env->GetFieldID(cls_user, "name", "Ljava/lang/String;"); // 获得属性ID
//        jfieldID ageFieldID = env->GetFieldID(cls_user, "age", "I"); // 获得属性ID
//        jint age = env->GetIntField(obj_user, ageFieldID);//获得属性值
//    }

    return list;
}extern "C"

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