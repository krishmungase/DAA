// ## Medians of Medians QuickSort Implementation (With Time Measurement)

#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

int partition(vector<int> &a, int l, int r, int pivot)
{
    int pivotIndex;
    for (pivotIndex = l; pivotIndex <= r; pivotIndex++)
        if (a[pivotIndex] == pivot)
            break;

    swap(a[pivotIndex], a[r]);

    int i = l;
    for (int j = l; j < r; j++)
    {
        if (a[j] <= pivot)
        {
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[r]);
    return i;
}

int findMedian(vector<int> &a, int l, int n)
{
    sort(a.begin() + l, a.begin() + l + n);
    return a[l + n / 2];
}

int medianOfMedians(vector<int> &a, int l, int r)
{
    int n = r - l + 1;
    if (n <= 5)
        return findMedian(a, l, n);

    vector<int> medians;
    for (int i = 0; i < n / 5; i++)
        medians.push_back(findMedian(a, l + i * 5, 5));

    if (n % 5)
        medians.push_back(findMedian(a, l + (n / 5) * 5, n % 5));

    return medianOfMedians(medians, 0, medians.size() - 1);
}

void quickSort(vector<int> &a, int l, int r)
{
    if (l >= r)
        return;

    int pivot = medianOfMedians(a, l, r);
    int pos = partition(a, l, r, pivot);

    quickSort(a, l, pos - 1);
    quickSort(a, pos + 1, r);
}

int main()
{
    int n;
    cout << "Enter the array size: ";
    cin >> n;

    vector<int> v(n);
    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        v[i] = rand();
    }
    cout << endl;

    auto start = high_resolution_clock::now();
    quickSort(v, 0, n - 1);

    auto end = high_resolution_clock::now();
    auto timeTaken = duration_cast<nanoseconds>(end - start);

    cout << "\nSorted array:\n";
    for (int x : v)
        cout << x << " ";
    cout << endl;

    cout << "\nTime Taken by Median of Medians QuickSort = "
         << timeTaken.count() << " nanoseconds\n";

    return 0;
}