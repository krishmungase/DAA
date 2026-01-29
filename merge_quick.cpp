// ## Simple Merge Sort and Quick Sort with Time Measurement

#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

/* ---------------- MERGE SORT ---------------- */

void merge(vector<int>& arr, int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;

    int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

/* ---------------- QUICK SORT ---------------- */

int partition(vector<int>& arr, int l, int r) {
    int pivot = arr[r];
    int i = l - 1;

    for (int j = l; j < r; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

void quickSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int pi = partition(arr, l, r);
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, r);
    }
}

/* ---------------- MAIN ---------------- */

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    vector<int> arr(n), arrCopy(n);
    srand(time(0));

    cout << "Original Array:\n";
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
        arrCopy[i] = arr[i];
        cout << arr[i] << " ";
    }
    cout << "\n";

    // ---- Merge Sort Time ----
    auto start1 = high_resolution_clock::now();
    mergeSort(arr, 0, n - 1);
    auto end1 = high_resolution_clock::now();
    auto mergeTime = duration_cast<nanoseconds>(end1 - start1);

    // ---- Quick Sort Time ----
    auto start2 = high_resolution_clock::now();
    quickSort(arrCopy, 0, n - 1);
    auto end2 = high_resolution_clock::now();
    auto quickTime = duration_cast<nanoseconds>(end2 - start2);

    cout << "\nAfter Merge Sort:\n";
    for (int x : arr)
        cout << x << " ";
    cout << "\nTime Taken by Merge Sort = "
         << mergeTime.count() << " nanoseconds\n";

    cout << "\nAfter Quick Sort:\n";
    for (int x : arrCopy)
        cout << x << " ";
    cout << "\nTime Taken by Quick Sort = "
         << quickTime.count() << " nanoseconds\n";

    return 0;
}
