#include <bits/stdc++.h>

using namespace std;

signed main() {
    string s;
    map<string, int> mp;
    for (int i = 0; i < 14; i++) {
        cin >> s;
        mp[s]++;
    }
    for (auto [a, b]: mp) {
        if (b != 2) {
            cout << "Bad Luck." << endl;
            return 0;
        }
    }
    cout << "Seven Pairs!" << endl;
}