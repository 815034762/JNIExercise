package com.example.administrator.jniresrevedemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

import com.bean.Movie;
import com.bean.MyInterface;
import com.bean.MyInterfaceImpl;
import com.bean.Person;
import com.bean.Quick;
import com.google.gson.Gson;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Date;
import java.util.List;
import java.util.Random;

/**
 * JNI演示样例集成
 */
public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    ArrayList<Person> personArrayList = new ArrayList<>();
    int[] temp = new int[10000000];

    static {
        System.loadLibrary("JniDemo");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        findViewById(R.id.tvCtoJava).setOnClickListener(this);
        findViewById(R.id.tvJavaToC).setOnClickListener(this);
        findViewById(R.id.tvGetNetData).setOnClickListener(this);
        findViewById(R.id.tvCallSort).setOnClickListener(this);

//      tv.setText(stringFromJNI() + "  " + person.getName() + "  " + person.getAge() + getStringFromOtherFile());
//      person = setObjProperty("TTT", 20);
//      Log.e("tag", " " + person.getName() + " age is " + person.getAge());
//      printJavaProperty(person);
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {

            case R.id.tvJavaToC:
                javaCallC();
                break;
            case R.id.tvCtoJava:
                cCallJava();
                break;
            case R.id.tvGetNetData:
                getNetWorkData();
                break;
            case R.id.tvCallSort:
                callSortArithmetic();
                break;
        }
    }

    /**
     * Java调用C语言
     */
    private void javaCallC() {
        String result = JavaCallC();
        Toast.makeText(MainActivity.this, result, Toast.LENGTH_SHORT).show();
    }

    /**
     * C语言调用Java
     */
    private void cCallJava() {
        Person person = getObjFromc();
        Toast.makeText(MainActivity.this, new Gson().toJson(person), Toast.LENGTH_SHORT).show();
    }

    /**
     * 利用C++获取网络数据
     */
    private void getNetWorkData() {

        Movie movie = getListFromUrl();
        if (movie != null) {
            Toast.makeText(MainActivity.this, new Gson().toJson(new Gson().toJson(movie)), Toast.LENGTH_SHORT).show();
        }
    }

    /**
     * 调用排序算法
     */
    private void callSortArithmetic() {

        Person person1 = new Person();
        person1.setAge(10);
        person1.setName("name10");
        personArrayList.add(person1);

        person1 = new Person();
        person1.setAge(5);
        person1.setName("name5");
        personArrayList.add(person1);

        person1 = new Person();
        person1.setAge(14);
        person1.setName("name14");
        personArrayList.add(person1);

        person1 = new Person();
        person1.setAge(2);
        person1.setName("name2");
        personArrayList.add(person1);

        person1 = new Person();
        person1.setAge(20);
        person1.setName("name20");
        personArrayList.add(person1);

        Person[] people = new Person[personArrayList.size()];
        for (int i = 0; i < personArrayList.size(); i++) {
            people[i] = personArrayList.get(i);
        }
        for (int i = 0; i < people.length; i++) {
            Log.e("tag", "Array排序前: people's info is " + people[i].getAge() + " name is " + people[i].getName());
        }
        sortPersonByAge(people);

        for (int i = 0; i < people.length; i++) {
            Log.e("tag", "Array排序后 people's info is " + people[i].getAge() + " name is " + people[i].getName());
        }
    }

    /**
     * 初始化数据
     */
//    private void initData() {
//        personArrayList.clear();
//        for (int i = 0; i < 10000; i++) {
//            Person person = new Person();
//            person.setName("张三" + Math.rint(1000000));
//            person.setAge((int) Math.rint(1000000));
//            personArrayList.add(person);
//        }
//    }

    /**
     * Java 排序
     */
//    private void javaSortData(ArrayList<Person> dataList) {
//
//        for (int i = 0; i < dataList.size(); ++i) {
//            for (int j = 0; j < (dataList.size() - 1) - i; j++) {
//                //内层循环控制每一趟排序多少次
//                Person person1 = dataList.get(j);
//                int age = person1.getAge();
//                Person person2 = dataList.get(j + 1);
//                int age2 = person2.getAge();
//                if (age > age2) {
//                    dataList.add(j, person2);
//                    dataList.add(j + 1, person1);
//                }
//            }
//        }// end for
//    }


    /**************native方法声明*************/
    public native String JavaCallC();
    public native Person getObjFromc();
    //jni支持地址传递
    public native Person[] sortPersonByAge(Person[] personArray);
    // String
    public native Movie getListFromUrl();
    //jni支持地址传递
    public native void sortData();
    public native String getStringFromOtherFile();
    public native Person setObjProperty(String name, int age);
    public native void printJavaProperty(Person person);
    public native void initArray();
    /**************end native方法声明*************/
}
