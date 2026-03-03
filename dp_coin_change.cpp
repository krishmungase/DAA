#include <bits/stdc++.h>
using namespace std;

int findMinimumCoins(vector<int>& coins, int index, int amount, vector<vector<int>>& dp)
{
    if (amount == 0)
        return 0;

    if (index == 0) {
        if (amount % coins[0] == 0)
            return amount / coins[0];
        else
            return 1e9;
    }

    if (dp[index][amount] != -1)
        return dp[index][amount];

    int notTake = findMinimumCoins(coins, index - 1, amount, dp);

    int take = 1e9;
    if (coins[index] <= amount)
        take = 1 + findMinimumCoins(coins, index, amount - coins[index], dp);

    dp[index][amount] = min(notTake, take);
    return dp[index][amount];
}

int coinChange(vector<int>& coins, int amount)
{
    int n = coins.size();

    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

    int result = findMinimumCoins(coins, n - 1, amount, dp);

    if (result >= 1e9)
        return -1;

    return result;
}

int main()
{
    int n;
    cout << "Enter number of coins: ";
    cin >> n;

    vector<int> coins(n);

    cout << "Enter coin values: ";
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    int amount;
    cout << "Enter target amount: ";
    cin >> amount;

    int minimumCoins = coinChange(coins, amount);

    if (minimumCoins == -1)
        cout << "Amount cannot be formed using given coins" << endl;
    else
        cout << "Minimum coins required = " << minimumCoins << endl;

    return 0;
}