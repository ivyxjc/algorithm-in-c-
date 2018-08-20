//
// Created by ivyxjc on 8/19/2018.
//
#include <iostream>

using namespace std;


int no_cache_count = 0;
int cache_count = 0;
int bottom_up_count = 0;

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

/**
 * 自底而上的方法
 * @param p
 * @param n
 * @return
 */
int bottom_up_cut_rod(int *p, int n) {
    int *value = new int[n + 1];
    value[0] = 0;

    for (int j = 1; j <= n; j++) {
        int q = INT32_MIN;
        for (int i = 1; i <= j; i++) {
            bottom_up_count++;
            q = max(q, p[i] + value[j - i]);
        }
        value[j] = q;
    }
    return value[n];
}

int *extended_bottom_up_cut_rod(int *p, int n) {
    int *value = new int[n + 1];
    int *detail = new int[n + 1];
    value[0] = 0;

    for (int j = 0; j <= n; j++) {
        int q = INT32_MIN;
        for (int i = 0; i <= j; i++) {
            if (q < p[i] + value[j - i]) {
                q = p[i] + value[j - i];
                detail[j] = i;
            }
        }
        value[j] = q;
    }
    detail[0] = value[n];
    return detail;
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

    int length = 10000;

    int *value = new int[length + 1];
    for (int i = 0; i < length + 1; i++) {
        value[i] = -1;
    }
//    int res=cut_rod(arr,length);
    int res2 = cut_rod(arr, length, value);
    int res3 = bottom_up_cut_rod(arr, length);
    int res4 = extended_bottom_up_cut_rod(arr, length)[0];
//    cout<<res<<endl;
    cout << "=============" << endl;
    cout << res2 << endl;
    cout << res3 << endl;
    cout << res4 << endl;
    cout << "============" << endl;
    cout << no_cache_count << endl;
    cout << cache_count << endl;
    cout << bottom_up_count << endl;
}

