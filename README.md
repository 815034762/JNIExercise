# JNIExercise
介绍jni的基本用法，实际项目根据需求进行开发

###JNI用法

1、java调用C
在MainActivity中声明 
'JavaCallC'
然后再JniDemo.cpp中添加实现方法
```
extern "C"
JNIEXPORT jstring
JNICALL
Java_com_example_administrator_jniresrevedemo_MainActivity_JavaCallC(JNIEnv *env,
                                                                     jobject obj /* this */) {

    std::string hello = "Hello from C++";

    return env->NewStringUTF(hello.c_str());
}
```
例如，我们要在native层返回一个字符串给JAVA端，因为C和JAVA是不能直接交互的,那么我们需要JNIEnv作为中间的桥梁，
首先我们要知道，java和c或者c++之前是有一个类型转换的。他们之间的关系如下图所示:



2、java调用C
'public native Person getObjFromc();'
然后再JniDemo.cpp中添加实现方法
```
JNIEXPORT jobject JNICALL
Java_com_example_administrator_jniresrevedemo_MainActivity_getObjFromc(JNIEnv *env,
                                                                       jobject instance) {

    jclass clazzPerson = env->FindClass("com/bean/Person");
    jmethodID methodId = env->GetMethodID(clazzPerson, "<init>", "(Ljava/lang/String;I)V");
    jstring str = env->NewStringUTF("张三");
    jobject personObj = env->NewObject(clazzPerson, methodId, str, 20);

    return personObj;
}extern "C"
``` 
