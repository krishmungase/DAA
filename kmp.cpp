#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> buildLPS(const string& pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);

    int len = 0; 
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            lps[i] = ++len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> KMPSearch(const string& text, const string& pattern) {
    vector<int> result;
    int n = text.size();
    int m = pattern.size();

    if (m == 0 || m > n) return result;

    vector<int> lps = buildLPS(pattern);

    int i = 0; 
    int j = 0;

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            result.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return result;
}

int main() {
    string text;
    string pattern;

    cout << "Enter text: ";
    cin >> text;
    cout << "Enter pattern: ";
    cin >> pattern;

    cout << "Text    : " << text    << "\n";
    cout << "Pattern : " << pattern << "\n\n";

    vector<int> lps = buildLPS(pattern);
    cout << "LPS array: [ ";
    for (int v : lps) cout << v << " ";
    cout << "]\n\n";

    vector<int> matches = KMPSearch(text, pattern);

    if (matches.empty()) {
        cout << "Pattern not found in text.\n";
    } else {
        cout << "Pattern found at index(es): ";
        for (int idx : matches) cout << idx << " ";
        cout << "\n\n";

        for (int idx : matches) {
            cout << "Match at index " << idx << ":\n";
            cout << "  " << text << "\n";
            cout << "  " << string(idx, ' ') << pattern << "\n\n";
        }
    }

    return 0;
}