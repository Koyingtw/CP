#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500005;

int n, k, d;
pair<int, int> a[MAXN], dp[10];
#define F first
#define S second


void reset() {
    dp[1] = {2e9, 2e9};
    dp[2] = {0, 0};
    dp[3] = {2e9, 2e9};
    dp[4] = {0, 0};
    dp[5] = {2e9, 2e9};
}

void sol() {
    cin >> n;
    reset();
    for (int i = 0; i < n; i++) {
        cin >> a[i].F;
        a[i].S = i + 1;
    }
        
    int pos = -1;
    vector<pair<int, int>> ans = {{2e9, 0}};

    for (int i = 0; i < n; i++) {
        if (pos == 1) {
            if (a[i].F > ans.back().F) {
                ans.push_back(a[i]);
                pos = -pos;
            }
            else
                ans.back() = a[i];
        }
        else {
            if (a[i].F < ans.back().F) {
                ans.push_back(a[i]);
                pos = -pos;
            }
            else
                ans.back() = a[i];
        }

        if (ans.size() == 6) {
            for (int j = 1; j <= 5; j++)
                cout << ans[j].S << ' ';
            cout << endl;
            return;
        }
    }

    
    cout << "KFC!" << endl;
}

signed main() {
    sol();
}