// ## Activity Selection Algorithm with Time Measurement

#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    int n;
    cout << "Enter the number of activities: ";
    cin >> n;

    vector<pair<int, int>> activities(n);

    cout << "Enter start and finish times of each activity:\n";
    for (int i = 0; i < n; i++) {
        int start, finish;
        cout << "Activity " << i + 1 << " - Start: ";
        cin >> start;
        cout << "Activity " << i + 1 << " - Finish: ";
        cin >> finish;
        activities[i] = {finish, start}; 
    }

    cout << "\nBefore sorting:\n";
    cout << "Start Time\tFinish Time\n";
    for (int i = 0; i < n; i++) {
        cout << activities[i].second << "\t\t" << activities[i].first << endl;
    }
    cout << "\n";

    auto startTime = high_resolution_clock::now();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (activities[j].first > activities[j + 1].first) {
                swap(activities[j], activities[j + 1]);
            }
        }
    }
    int last = activities[0].first;

    auto endTime = high_resolution_clock::now();
    auto timeTaken = duration_cast<nanoseconds>(endTime - startTime);

    cout << "After sorting:\n";
    cout << "Start Time\tFinish Time\n";
    for (int i = 0; i < n; i++) {
        cout << activities[i].second << "\t\t" << activities[i].first << endl;
    }
    cout << "\n";

    cout << "Selected activities are:\n";
    cout << "Activity: (" << activities[0].second << ", " << activities[0].first << ")\n";

    for (int i = 1; i < n; i++) {
        if (activities[i].second >= last) {
            cout << "Activity: (" << activities[i].second << ", " 
                 << activities[i].first << ")\n";
            last = activities[i].first;
        }
    }

    cout << "\nTime Taken by Activity Selection Algorithm = "
         << timeTaken.count() << " nanoseconds\n";

    return 0;
}

/*


Sample Input/Output:
6
1 2
3 4
0 6
5 7
8 9
5 9


*/