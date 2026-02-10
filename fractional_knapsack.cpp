#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b) {
    double r1 = (double)a.first / a.second;
    double r2 = (double)b.first / b.second;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<pair<int,int>> &items) {
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;

    for (auto &item : items) {
        int value = item.first;
        int weight = item.second;

        if (W >= weight) {
            W -= weight;
            totalValue += value;
        } else {
            totalValue += (double)value * W / weight;
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter knapsack capacity: ";
    cin >> W;

    vector<pair<int,int>> items;

    cout << "Enter value and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        int value, weight;
        cin >> value >> weight;
        items.push_back({value, weight});
    }

    double ans = fractionalKnapsack(W, items);

    cout << "Maximum value in knapsack = " << ans << endl;

    return 0;
}
