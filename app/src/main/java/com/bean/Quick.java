package com.bean;

public class Quick {

    /**
     * @param arr
     * @param low
     * @param high
     */
    public void sort(int arr[], int low, int high) {

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
                arr[l] = temp;// l++;//省去也可以
            }

            while (l < h && arr[l] <= povit)
                l++;
            if (l < h) {
                int temp = arr[h];
                arr[h] = arr[l];
                arr[l] = temp;// h--;//省去也可以
            }
        }

        if (l > low)
            sort(arr, low, l - 1);//sort(arr, low, l - 1);改成sort(arr, low, h - 1);
        if (h < high)
            sort(arr, l + 1, high);//sort(arr, l + 1, high);改成sort(arr, h + 1, high);也行，因为l和h的值是一样

    }

}
