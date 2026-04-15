#include <iostream>
using namespace std;

int N;
int cost[10][10];
bool visited[10];
int minCost = 100000;

int bestPath[20], currPath[20];


void tsp(int currCity, int count, int currCost) {

    if (count == N && cost[currCity][0]) {
        int total = currCost + cost[currCity][0];

        if (total < minCost) {
            minCost = total;

            for (int i = 0; i < N; i++)
                bestPath[i] = currPath[i];

            bestPath[N] = 0;
        }
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i] && cost[currCity][i]) {

            int temp = currCost + cost[currCity][i];

            if (temp < minCost) {

                visited[i] = true;
                currPath[count] = i;

                tsp(i, count + 1, temp);

                visited[i] = false;
               
            }
        }
    }
}

int main() {

    cout << "Enter number of cities: ";
    cin >> N;

    cout << "Enter cost matrix:\n";
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> cost[i][j];

    for (int i = 0; i < N; i++)
        visited[i] = false;

    visited[0] = true;
    currPath[0] = 0;

    tsp(0, 1, 0);

    cout << "\nOptimal Path: ";
    for (int i = 0; i <= N; i++)
        cout << bestPath[i] << " ";

    cout << "\n\nCost Calculation:\n";

    int total = 0;

    for (int i = 0; i < N; i++) {
        int from = bestPath[i];
        int to = bestPath[i + 1];

        cout << "Cost(" << from << " -> " << to << ") = "
             << cost[from][to] << endl;

        total += cost[from][to];
    }

    // Summation format
    cout << "\nTotal Cost = ";

    for (int i = 0; i < N; i++) {
        cout << cost[bestPath[i]][bestPath[i + 1]];
        if (i < N - 1) cout << " + ";
    }

    cout << " = " << total << endl;

    return 0;
}