package com.bean;

import android.util.Log;

public class MyInterfaceImpl implements MyInterface {
    @Override
    public void callBack(String result) {
        Log.e("tag","=====================执行回调============================" + result);
    }
}
