#include <bits/stdc++.h>
using namespace std;

vector<int> naiveSearch(string text, string pattern) {
    vector<int> matches;
    int n = text.size(), m = pattern.size();

    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j])
            j++;
        if (j == m)
            matches.push_back(i);
    }
    return matches;
}

int main() {
    string text, pattern;

    cout << "Enter text: ";
    cin >> text;

    cout << "Enter pattern: ";
    cin >> pattern;

    vector<int> result = naiveSearch(text, pattern);

    if (result.empty()) {
        cout << "\nPattern not found." << endl;
    } else {
        cout << "\nPattern found at index(es): ";
        for (int idx : result)
            cout << idx << " ";
        cout << endl;
    }
    return 0;
}