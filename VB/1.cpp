// Linear, Binary and Recursive Binary search with time
#include <bits/stdc++.h>
using namespace std;

int linearSearch(const vector<int> &arr, int target, long long n)
{
    for (long long i = 0; i < n; i++)
    {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int binarySearch(const vector<int> &arr, int target, long long n)
{
    long long l = 0, r = n - 1;

    while (l <= r)
    {
        long long mid = (r + l) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int recursiveBinarySearch(const vector<int> &arr, int target,
                          long long l, long long r)
{
    if (l > r)
        return -1;

    long long mid = (r + l) / 2;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] > target)
        return recursiveBinarySearch(arr, target, l, mid - 1);
    else
        return recursiveBinarySearch(arr, target, mid + 1, r);
}

int main()
{
    long long n;
    cout << "Enter the array size: ";
    cin >> n;
    vector<int> arr(n);

    srand(time(0));

    for (long long i = 0; i < n; i++)
    {
        arr[i] = rand();
        cout << arr[i] << " ";
    }

    cout << endl;

    int target;
    cout << "Enter the target: ";
    cin >> target;

    cout << endl;

    auto start1 = chrono::high_resolution_clock::now();
    int idx1 = linearSearch(arr, target, n);
    auto end1 = chrono::high_resolution_clock::now();

    cout << "Linear Search Index: " << idx1 << "\n";
    cout << "Linear Search Time: "
         << chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count()
         << " nanoseconds\n\n";

    sort(arr.begin(), arr.end());

    auto start2 = chrono::high_resolution_clock::now();
    int idx2 = binarySearch(arr, target, n);
    auto end2 = chrono::high_resolution_clock::now();

    cout << "Binary Search Index: " << idx2 << "\n";
    cout << "Binary Search Time: "
         << chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count()
         << " nanoseconds\n\n";

    auto start3 = chrono::high_resolution_clock::now();
    int idx3 = recursiveBinarySearch(arr, target, 0, n - 1);
    auto end3 = chrono::high_resolution_clock::now();

    cout << "Recursive Binary Search Index: " << idx3 << "\n";
    cout << "Recursive Binary Search Time: "
         << chrono::duration_cast<chrono::nanoseconds>(end3 - start3).count()
         << " nanoseconds\n";

    return 0;
}