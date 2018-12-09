#include "jni_common.h"

char* jstring2cstr(JNIEnv* env, jobject jstr) {
    char* rtn = NULL;
    if ( jstr != NULL )
    {
        jclass clsstring = env->FindClass("java/lang/String");
        jstring strencode = env->NewStringUTF("GB18030");
        jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
        jbyteArray barr = (jbyteArray) env->CallObjectMethod((jstring)jstr, mid, strencode);
        jsize alen = env->GetArrayLength(barr);
        jbyte* ba = env->GetByteArrayElements(barr, JNI_FALSE);
        if (alen >= 0) {
            rtn = (char*) malloc(alen + 1);
            memcpy(rtn, ba, alen);
            rtn[alen] = 0;
        }
        env->ReleaseByteArrayElements(barr, ba, 0);
        env->DeleteLocalRef(barr);
        env->DeleteLocalRef(strencode);
        env->DeleteLocalRef(clsstring);
    }
    else
    {
        rtn = (char*) malloc(1);
        rtn[0] = 0;
    }
    return rtn;
}

char* jstring2utf8cstr1(JNIEnv* env, jobject jstr) {
    char* rtn = NULL;
    if ( jstr != NULL )
    {
        jclass clsstring = env->FindClass("java/lang/String");
        jstring strencode = env->NewStringUTF("utf-8");
        jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
        jbyteArray barr = (jbyteArray) env->CallObjectMethod((jstring)jstr, mid, strencode);
        jsize alen = env->GetArrayLength(barr);
        jbyte* ba = env->GetByteArrayElements(barr, JNI_FALSE);
        if (alen >= 0) {
            rtn = (char*) malloc(alen + 1);
            memcpy(rtn, ba, alen);
            rtn[alen] = 0;
        }
        env->ReleaseByteArrayElements(barr, ba, 0);
        env->DeleteLocalRef(barr);
        env->DeleteLocalRef(strencode);
        env->DeleteLocalRef(clsstring);
    }
    else
    {
        rtn = (char*) malloc(1);
        rtn[0] = 0;
    }
    return rtn;
}

char* jstring2utf8cstr(JNIEnv* env, jobject jstr)
{
	char* rtn = NULL;
	if (jstr != NULL)
	{
		jstring str = (jstring) jstr;
		const char *cstr = env->GetStringUTFChars(str, 0);
		jsize alen = strlen(cstr);
		if (alen >= 0)
		{
			rtn = (char*) malloc(alen + 1);
			memcpy(rtn, cstr, alen);
			rtn[alen] = 0;
		}

		env->ReleaseStringUTFChars(str, cstr);
	}
	else
	{
		rtn = (char*) malloc(1);
		rtn[0] = 0;
	}
	return rtn;
}


jstring cstr2jstring(JNIEnv* env, const char* pat)
{
	jclass strClass = env->FindClass("java/lang/String");
	jmethodID ctorID = env->GetMethodID(strClass, "<init>", "([BLjava/lang/String;)V");
	jbyteArray bytes = env->NewByteArray(strlen(pat));
	env->SetByteArrayRegion(bytes, 0, strlen(pat), (jbyte*) pat);
	jstring encoding = env->NewStringUTF("utf-8");
	jstring ret = (jstring) env->NewObject(strClass, ctorID, bytes, encoding);

	env->DeleteLocalRef(encoding);
	env->DeleteLocalRef(bytes);
	env->DeleteLocalRef(strClass);
	//env->DeleteLocalRef(ret);

	return ret;
}

jstring utf8cstr2jstring(JNIEnv* env, const char* pat)
{

	jclass strClass = env->FindClass("java/lang/String");
	jmethodID ctorID = env->GetMethodID(strClass, "<init>", "([BLjava/lang/String;)V");
	jbyteArray bytes = env->NewByteArray(strlen(pat));
	env->SetByteArrayRegion(bytes, 0, strlen(pat), (jbyte*) pat);
	jstring encoding = env->NewStringUTF("utf-8");
	jstring ret = (jstring) env->NewObject(strClass, ctorID, bytes, encoding);

	env->DeleteLocalRef(encoding);
	env->DeleteLocalRef(bytes);
	env->DeleteLocalRef(strClass);
	//env->DeleteLocalRef(ret);


	//jstring ret = env->NewStringUTF(pat);
	return ret;
}

void callback(JNIEnv* env, jobject listener, const char* method_name, const char* param_def, /*jobject jinfo*/...)
{
    va_list args;
    va_start(args, param_def);

    jclass listener_cls = env->GetObjectClass(listener);
    jmethodID callbackID = env->GetMethodID(listener_cls , method_name , param_def) ;//或得该回调方法句柄
    if (callbackID) env->CallVoidMethodV(listener , callbackID , args);

    va_end(args);

    env->DeleteLocalRef(listener_cls);
}
