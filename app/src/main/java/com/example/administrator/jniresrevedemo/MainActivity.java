package com.example.administrator.jniresrevedemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import com.bean.Person;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Date;
import java.util.List;

/**
 * JNI演示样例集成
 */
public class MainActivity extends AppCompatActivity {

    public int property;

    public void function(int foo, Date date, int[] arr) {

        System.out.println("execute function");
    }

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        Person person = getObjFrom();
        System.out.print(person.getName() + "  " + person.getAge());

        tv.setText(stringFromJNI() + "  " + person.getName() + "  " + person.getAge());
        person = setObjProperty("TTT", 20);

        Log.e("tag", " " + person.getName() + " age is " + person.getAge());

        printJavaProperty(person);

        ArrayList<Person> personArrayList = new ArrayList<>();

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
        for (int i=0;i< personArrayList.size();i++){
            people[i] = personArrayList.get(i);
        }

        sortPersonByAge(people);

        for (int i = 0;i < people.length;i++){
            Log.e("tag", "people's info is " + people[i].getAge() + " name is " + people[i].getName());
        }

        for (int i=0;i< personArrayList.size();i++){
            Log.e("tag", "Array排序前: people's info is " + personArrayList.get(i).getAge() + " name is " + personArrayList.get(i).getName());
        }

        sortPeron(personArrayList);

        for (int i=0;i< personArrayList.size();i++){
            Log.e("tag", "Array排序后: people's info is " + personArrayList.get(i).getAge() + " name is " + personArrayList.get(i).getName());
        }
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public native Person getObjFrom();

    public native Person setObjProperty(String name, int age);

    public native void printJavaProperty(Person person);

    //jni支持地址传递的
    public synchronized native ArrayList<Person> sortPeron(ArrayList<Person> list);

    public native Person[] sortPersonByAge(Person[] personArray);
}
