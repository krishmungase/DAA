#include<bits/stdc++.h>
using namespace std;

int knapsack(int W, const vector<int>& val, const vector<int>& wt,
             int n, vector<vector<int>>& dp) {

    if (n == 0 || W == 0)
        return 0;

    if (dp[n][W] != -1)
        return dp[n][W];

    int pick = 0;
    if (wt[n - 1] <= W)
        pick = val[n - 1] + knapsack(W - wt[n - 1], val, wt, n - 1, dp);

    int notPick = knapsack(W, val, wt, n - 1, dp);

    return dp[n][W] = max(pick, notPick);
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> val(n), wt(n);

    cout << "Enter values of items: ";
    for (int i = 0; i < n; i++) cin >> val[i];

    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++) cin >> wt[i];

    cout << "Enter capacity of knapsack: ";
    cin >> W;

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));

    int result = knapsack(W, val, wt, n, dp);
    cout << "\nMaximum value in Knapsack = " << result << endl;

    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= W; j++)
        dp[0][j] = 0;

    cout << "\nDP Table (rows = items, cols = capacity)\n\n";

    cout << setw(5) << " ";
    for (int j = 0; j <= W; j++)
        cout << setw(5) << j;
    cout << "\n--------------------------------------------------\n";

    for (int i = 0; i <= n; i++) {
        cout << setw(3) << i << " |";
        for (int j = 0; j <= W; j++) {
            if (dp[i][j] == -1)
                cout << setw(5) << ".";
            else
                cout << setw(5) << dp[i][j];
        }
        cout << endl;
    }

    return 0;
}
