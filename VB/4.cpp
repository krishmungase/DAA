#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Merge two subarrays L and M into arr
void merge(vector<int> &arr, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    vector<int> L(n1), M(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    int i = 0, j = 0, k = p;

    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main()
{
    int n;
    cout << "Enter size for Merge Sort: ";
    cin >> n;
    vector<int> arr(n);
    srand(time(0));

    for (int i = 0; i < n; i++)
        arr[i] = rand() % 1000;

    auto start = high_resolution_clock::now();
    mergeSort(arr, 0, n - 1);
    auto end = high_resolution_clock::now();

    cout << "Merge Sort Time: "
         << duration_cast<nanoseconds>(end - start).count()
         << " nanoseconds" << endl;
    return 0;
}