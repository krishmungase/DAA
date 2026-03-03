#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of keys: ";
    cin >> n;

    vector<double> p(n + 1), q(n + 1);

    cout << "Enter successful search probabilities (p1 to pn):\n";
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    cout << "Enter unsuccessful search probabilities (q0 to qn):\n";
    for (int i = 0; i <= n; i++) {
        cin >> q[i];
    }

    // DP tables
    vector<vector<double>> e(n + 2, vector<double>(n + 1, 0));
    vector<vector<double>> w(n + 2, vector<double>(n + 1, 0));
    vector<vector<int>> root(n + 2, vector<int>(n + 1, 0));

    // Initialization
    for (int i = 1; i <= n + 1; i++) {
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }

    // Length of subtree
    for (int l = 1; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            e[i][j] = INT_MAX;

            w[i][j] = w[i][j - 1] + p[j] + q[j];

            for (int r = i; r <= j; r++) {
                double cost = e[i][r - 1] + e[r + 1][j] + w[i][j];

                if (cost < e[i][j]) {
                    e[i][j] = cost;
                    root[i][j] = r;
                }
            }
        }
    }

    cout << "\nMinimum Expected Search Cost: " << e[1][n] << endl;

    cout << "\nRoot Table:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i <= j)
                cout << root[i][j] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }

    return 0;
}