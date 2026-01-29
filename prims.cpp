// ## Prim's Algorithm Implementation (With Time Measurement)

#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

void primSimple(int V, vector<vector<pair<int,int>>> &adj) {
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> visited(V, false);

    key[0] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = -1;
        int minKey = INT_MAX;

        for (int i = 0; i < V; i++) {
            if (!visited[i] && key[i] < minKey) {
                minKey = key[i];
                u = i;
            }
        }

        visited[u] = true;

        for (auto it : adj[u]) {
            int v = it.first;
            int wt = it.second;

            if (!visited[v] && wt < key[v]) {
                key[v] = wt;
                parent[v] = u;
            }
        }
    }

    int totalCost = 0;
    cout << "\n--- Simple Prim's (Without Priority Queue) ---\n";
    cout << "Edges in MST:\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i
             << " (weight = " << key[i] << ")\n";
        totalCost += key[i];
    }
    cout << "Total cost = " << totalCost << endl;
}

int main() {
    cout << "Enter number of vertices and edges:\n";
    int V, E;
    cin >> V >> E;

    vector<vector<pair<int,int>>> adj(V);
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    auto start = high_resolution_clock::now();
    primSimple(V, adj);

    auto end = high_resolution_clock::now();
    auto timeTaken = duration_cast<nanoseconds>(end - start);

    cout << "\nTime Taken by Simple Prim's Algorithm = "
         << timeTaken.count() << " nanoseconds\n";

    return 0;
}


/*

Sample Input:
Enter number of vertices and edges:
5 7
Enter edges (u v weight):
0 1 2
0 3 6
1 2 3
1 3 8
1 4 5
2 4 7
3 4 9

*/
