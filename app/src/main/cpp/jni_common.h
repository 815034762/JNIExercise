#include <stdlib.h>
#include <jni.h>

#define MSG_BUF_SIZE 256 * 1024
extern char msg_bufs[MSG_BUF_SIZE];
extern unsigned int msg_buf_postion;

extern JNIEnv* mainEnv;
extern JavaVM *gJavaVM;

char* jstring2cstr(JNIEnv* env, jobject jstr);

char* jstring2utf8cstr(JNIEnv* env, jobject jstr);
char* jstring2utf8cstr1(JNIEnv* env, jobject jstr);

jstring cstr2jstring(JNIEnv* env, const char* pat);

jstring utf8cstr2jstring(JNIEnv* env, const char* pat);

void callback(JNIEnv* env, jobject listener, const char* method_name, const char* param_def, ...);


#define GET_ENV() \
	JNIEnv* gEnv; \
	bool isAttacked = false; \
	int status = gJavaVM->GetEnv((void **) &gEnv, JNI_VERSION_1_4); \
	if (status < 0) \
	{ \
		status = gJavaVM->AttachCurrentThread(&gEnv, NULL); \
		if (status < 0) \
		{ \
			return; \
		} \
		isAttacked = true; \
	} \


#define DE_ENV() \
	if (isAttacked) \
	{ \
		gJavaVM->DetachCurrentThread(); \
	}


#define callback_list(env, listener, class_name, on_method) \
		jclass list_cls = env->FindClass("java/util/ArrayList"); \
		jmethodID list_costruct = env->GetMethodID(list_cls, "<init>", "()V"); \
		jobject list_obj = env->NewObject(list_cls, list_costruct); \
		jmethodID list_add = env->GetMethodID(list_cls, "add", "(Ljava/lang/Object;)Z"); \
		for (int i = 0; i < infos.size(); i++) \
		{ \
			jni_get_##class_name(env, infos[i]); \
			env->CallBooleanMethod(list_obj, list_add, jinfo); \
			env->DeleteLocalRef(jinfo);   \
		} \
		callback(env, listener, #on_method, "(Ljava/util/List;)V", list_obj); \
		env->DeleteLocalRef(list_obj);   \
		env->DeleteLocalRef(list_cls);

#define get_jlist(env, list_obj, class_name, infos) \
		jclass list_cls = env->FindClass("java/util/ArrayList"); \
		jmethodID list_costruct = env->GetMethodID(list_cls, "<init>", "()V"); \
		list_obj = env->NewObject(list_cls, list_costruct); \
		jmethodID list_add = env->GetMethodID(list_cls, "add", "(Ljava/lang/Object;)Z"); \
		for (int i = 0; i < infos.size(); i++) \
		{ \
			jni_get_##class_name(env, infos[i]); \
			env->CallBooleanMethod(list_obj, list_add, jinfo); \
			env->DeleteLocalRef(jinfo);   \
		} \
		env->DeleteLocalRef(list_cls);



#define get_jstring_list(env, list_obj, infos) \
		jclass list_cls##list_obj = env->FindClass("java/util/ArrayList"); \
		jmethodID list_costruct##list_obj = env->GetMethodID(list_cls##list_obj, "<init>", "()V"); \
		jobject list_obj = env->NewObject(list_cls##list_obj, list_costruct##list_obj); \
		jmethodID list_add##list_obj = env->GetMethodID(list_cls##list_obj, "add", "(Ljava/lang/Object;)Z"); \
		for (int i = 0; i < infos.size(); i++) \
		{ \
			jstring jinfostring = utf8cstr2jstring(env, infos[i].c_str()); \
			env->CallBooleanMethod(list_obj, list_add##list_obj, jinfostring); \
			env->DeleteLocalRef(jinfostring);   \
		} \
		env->DeleteLocalRef(list_cls##list_obj);


#define get_jlist0(env, list_obj, class_name, infos) \
		jclass list_cls##list_obj = env->FindClass("java/util/ArrayList"); \
		jmethodID list_costruct##list_obj = env->GetMethodID(list_cls##list_obj, "<init>", "()V"); \
		jobject list_obj = env->NewObject(list_cls##list_obj, list_costruct##list_obj); \
		jmethodID list_add##list_obj = env->GetMethodID(list_cls##list_obj, "add", "(Ljava/lang/Object;)Z"); \
		for (int j = 0; j < infos.size(); j++) \
		{ \
			jni_get_##class_name(env, jinfo0, infos[j]); \
			env->CallBooleanMethod(list_obj, list_add##list_obj, jinfo0); \
			env->DeleteLocalRef(jinfo0);   \
		} \
		env->DeleteLocalRef(list_cls##list_obj);


#define get_jlist1(env, list_obj1, class_name1, infos1) \
		jclass list_cls##list_obj1 = env->FindClass("java/util/ArrayList"); \
		jmethodID list_costruct##list_obj1 = env->GetMethodID(list_cls##list_obj1, "<init>", "()V"); \
		jobject list_obj1 = env->NewObject(list_cls##list_obj1, list_costruct##list_obj1); \
		jmethodID list_add##list_obj1 = env->GetMethodID(list_cls##list_obj1, "add", "(Ljava/lang/Object;)Z"); \
		for (int i1 = 0; i1 < infos1.size(); i1++) \
		{ \
			jni_get_##class_name1(env, jinfo1, infos1[i1]); \
			env->CallBooleanMethod(list_obj1, list_add##list_obj1, jinfo1); \
			env->DeleteLocalRef(jinfo1);   \
		} \
		env->DeleteLocalRef(list_cls##list_obj1);


#define get_jlist2(env, list_obj2, class_name2, infos2) \
		jclass list_cls##list_obj2 = env->FindClass("java/util/ArrayList"); \
		jmethodID list_costruct##list_obj2 = env->GetMethodID(list_cls##list_obj2, "<init>", "()V"); \
		jobject list_obj2 = env->NewObject(list_cls##list_obj2, list_costruct##list_obj2); \
		jmethodID list_add##list_obj2 = env->GetMethodID(list_cls##list_obj2, "add", "(Ljava/lang/Object;)Z"); \
		for (int i2 = 0; i2 < infos2.size(); i2++) \
		{ \
			jni_get_##class_name2(env, jinfo2, infos2[i2]); \
			env->CallBooleanMethod(list_obj2, list_add##list_obj2, jinfo2); \
			env->DeleteLocalRef(jinfo2);   \
		} \
		env->DeleteLocalRef(list_cls##list_obj2);


#define get_jlist3(env, list_obj3, class_name3, infos3) \
		jclass list_cls##list_obj3 = env->FindClass("java/util/ArrayList"); \
		jmethodID list_costruct##list_obj3 = env->GetMethodID(list_cls##list_obj3, "<init>", "()V"); \
		jobject list_obj3 = env->NewObject(list_cls##list_obj3, list_costruct##list_obj3); \
		jmethodID list_add##list_obj3 = env->GetMethodID(list_cls##list_obj3, "add", "(Ljava/lang/Object;)Z"); \
		for (int i3 = 0; i3 < infos3.size(); i3++) \
		{ \
			jni_get_##class_name3(env, jinfo3, infos3[i3]); \
			env->CallBooleanMethod(list_obj3, list_add##list_obj3, jinfo3); \
			env->DeleteLocalRef(jinfo3);   \
		} \
		env->DeleteLocalRef(list_cls##list_obj3);
