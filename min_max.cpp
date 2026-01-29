// ## Min-Max Problem: Simple Method vs Divide & Conquer Method
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

/* ---------- SIMPLE METHOD ---------- */
void simpleMinMax(vector<long long>& arr, long long &mini, long long &maxi, long long &cnt,int n) {

    mini = maxi = arr[0];

    for (int i = 1; i < n; i++) {
        cnt++;
        if (arr[i] > maxi) {
            maxi = arr[i];
        }

        cnt++;
        if (arr[i] < mini) {
            mini = arr[i];
        }
    }
}

/* ---------- DIVIDE & CONQUER METHOD ---------- */
void divideConquerMinMax(vector<long long>& arr, int low, int high,
                         long long &mini, long long &maxi, long long &cnt) {

    if (low == high) {
        mini = maxi = arr[low];
        return;
    }

    if (high == low + 1) {
        cnt++;
        if (arr[low] < arr[high]) {
            mini = arr[low];
            maxi = arr[high];
        } else {
            mini = arr[high];
            maxi = arr[low];
        }
        return;
    }

    int mid = (low + high) / 2;
    long long min1, max1, min2, max2;

    divideConquerMinMax(arr, low, mid, min1, max1, cnt);
    divideConquerMinMax(arr, mid + 1, high, min2, max2, cnt);

    cnt++;
    mini = min(min1, min2);

    cnt++;
    maxi = max(max1, max2);
}

int main() {
    long long n;
    cout << "Enter the array size: ";
    cin >> n;

    vector<long long> arr(n);
    srand(time(0));

    for (long long i = 0; i < n; i++) {
        arr[i] = rand();
        cout << arr[i] << " ";
    }
    cout << endl;

    long long sMin = -1e9, sMax = 1e9, dMin = -1e9, dMax = 1e9;
    long long cnt1 = 0, cnt2 = 0;

   
    auto start1 = high_resolution_clock::now();
    simpleMinMax(arr, sMin, sMax, cnt1,n);
    auto end1 = high_resolution_clock::now();
    auto time1 = duration_cast<nanoseconds>(end1 - start1);

 
    auto start2 = high_resolution_clock::now();
    divideConquerMinMax(arr, 0, n - 1, dMin, dMax, cnt2);
    auto end2 = high_resolution_clock::now();
    auto time2 = duration_cast<nanoseconds>(end2 - start2);

    cout << "\nSimple Method:\n";
    cout << "Min = " << sMin << ", Max = " << sMax << endl;
    cout << "Comparisons = " << cnt1 << endl;
    cout << "Time Taken = " << time1.count() << " nanoseconds\n";

    cout << "\nDivide & Conquer Method:\n";
    cout << "Min = " << dMin << ", Max = " << dMax << endl;
    cout << "Comparisons = " << cnt2 << endl;
    cout << "Time Taken = " << time2.count() << " nanoseconds\n";

    return 0;
}