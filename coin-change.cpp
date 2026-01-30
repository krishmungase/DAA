#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200, 500};
    int amount;
    cout << "Enter the amount: ";
    cin >> amount;

    sort(coins.rbegin(), coins.rend());
    cout << "Coin usage:\n";

    for (int i : coins) {
        if (amount >= i) {
            int count = amount / i; 
            amount = amount % i;
            cout << i << " -> " << count << " coins\n";
        }
    }

    return 0;
}
