#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of rides: ";
    cin >> n;

    vector<int> start(n), end(n);

    cout << "Enter start and end time for each ride:\n";
    for (int i = 0; i < n; i++) {
        cout << "Ride " << i + 1 << ": ";
        cin >> start[i] >> end[i];
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int i = 0, j = 0;
    int active = 0, maxCabs = 0;

    while (i < n) {
        if (start[i] < end[j]) {
            active++;
            maxCabs = max(maxCabs, active);
            i++;
        } else {
            active--;
            j++;
        }
    }

    cout << "\n✅ Minimum number of cabs required: "
         << maxCabs << endl;

    return 0;
}
