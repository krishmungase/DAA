#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

struct Node {
    vector<vector<int>> mat;
    int cost, vertex, level;
    vector<int> path;
    bool operator>(const Node& o) const { return cost > o.cost; }
};

int reduce(vector<vector<int>>& mat, int n) {
    int cost = 0;
    for (int i = 0; i < n; i++) {
        int mn = INF;
        for (int j = 0; j < n; j++) if (mat[i][j] != INF) mn = min(mn, mat[i][j]);
        if (mn != INF && mn > 0) {
            cost += mn;
            for (int j = 0; j < n; j++) if (mat[i][j] != INF) mat[i][j] -= mn;
        }
    }
    for (int j = 0; j < n; j++) {
        int mn = INF;
        for (int i = 0; i < n; i++) if (mat[i][j] != INF) mn = min(mn, mat[i][j]);
        if (mn != INF && mn > 0) {
            cost += mn;
            for (int i = 0; i < n; i++) if (mat[i][j] != INF) mat[i][j] -= mn;
        }
    }
    return cost;
}

pair<int, vector<int>> solveTSP(vector<vector<int>> input, int n) {
    Node root;
    root.mat = input;
    root.level = 0;
    root.vertex = 0;
    root.path = {0};
    root.cost = reduce(root.mat, n);

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push(root);

    int best = INF;
    vector<int> finalPath;

    while (!pq.empty()) {
        Node curr = pq.top(); pq.pop();
        if (curr.cost >= best) continue;

        int i = curr.vertex;

        if (curr.level == n - 1) {
            if (curr.mat[i][0] != INF) {
                int total = curr.cost + curr.mat[i][0];
                if (total < best) {
                    best = total;
                    finalPath = curr.path;
                    finalPath.push_back(0);
                }
            }
            continue;
        }

        for (int j = 0; j < n; j++) {
            if (curr.mat[i][j] == INF) continue;
            bool seen = false;
            for (int c : curr.path) if (c == j) { seen = true; break; }
            if (seen) continue;

            Node child;
            child.mat = curr.mat;
            child.level = curr.level + 1;
            child.vertex = j;
            child.path = curr.path;
            child.path.push_back(j);

            for (int k = 0; k < n; k++) child.mat[i][k] = INF;
            for (int k = 0; k < n; k++) child.mat[k][j] = INF;
            if (child.level < n - 1) child.mat[j][0] = INF;

            child.cost = curr.cost + curr.mat[i][j] + reduce(child.mat, n);
            if (child.cost < best) pq.push(child);
        }
    }

    return {best, finalPath};
}

int main() {
    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter cost matrix (" << n << "x" << n << "), enter -1 for no edge:\n";
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == -1 || i == j) mat[i][j] = INF;
        }

    auto [cost, path] = solveTSP(mat, n);

    cout << "\nMinimum Cost: " << cost << "\n";
    cout << "Path: ";
    for (int k = 0; k < (int)path.size(); k++) {
        cout << path[k];
        if (k + 1 < (int)path.size()) cout << " -> ";
    }
    cout << "\n";

    return 0;
}