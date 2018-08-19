//
// Created by ivyxjc on 8/19/2018.
//
#include <iostream>
#include "string.h"

using namespace std;


int no_cache_count = 0;
int cache_count = 0;


/**
 * 不带备忘的自顶向下的方法
 * @param p
 * @param n
 * @return
 */
int cut_rod(int *p, int n) {
    if (n == 0) {
        return 0;
    }
    int q = INT32_MIN;

    for (int i = 1; i <= n; i++) {
        q = max(q, p[i] + cut_rod(p, n - i));
        no_cache_count++;
    }
    return q;
}

/**
 * 带备忘的自顶向下的方法
 * @param p
 * @param n
 * @param value
 * @return
 */
int cut_rod(int *p, int n, int *value) {
    if (n == 0) {
        return 0;
    }
    int q = INT32_MIN;

    for (int i = 1; i <= n; i++) {
        if (value[n - i] == -1) {
            q = max(q, p[i] + cut_rod(p, n - i, value));
        } else {
            q = max(q, p[i] + value[n - i]);
        }
        cache_count++;
    }
    value[n] = q;
    return q;
}

int bottom_up_cut_rod(int *p, int n) {
    if(n==0){
        return 0;
    }
}


int main() {
    int *arr = new int[11];
    arr[1] = 1;
    arr[2] = 5;
    arr[3] = 8;
    arr[4] = 9;
    arr[5] = 10;
    arr[6] = 17;
    arr[7] = 17;
    arr[8] = 20;
    arr[9] = 24;
    arr[10] = 30;

    int length = 100;

    int *value = new int[length + 1];
    for (int i = 0; i < length + 1; i++) {
        value[i] = -1;
    }
//    int res=cut_rod(arr,length);
    int res2 = cut_rod(arr, length, value);
//    cout<<res<<endl;
    cout << res2 << endl;
    cout << no_cache_count << endl;
    cout << cache_count << endl;
}

