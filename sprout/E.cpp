#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500005;

int n, m;
#define F first
#define S second
pair<int, int> x[MAXN];
vector<int> v[2];


void sol() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x[i].F >> x[i].S;
        v[x[i].S].push_back(x[i].F);
    }
    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());

    int ans = 0;
    int mx = 0;
    for (int r = 0, l = 0; r < v[0].size(); r++) {
        while (v[0][r] - v[0][l] > m)
            l++;
        mx = max(mx, r - l + 1);
    }
    ans += mx;

    mx = 0;

    for (int r = 0, l = 0; r < v[1].size(); r++) {
        while (v[1][r] - v[1][l] > m)
            l++;
        mx = max(mx, r - l + 1);
    }
    ans += mx;

    cout << ans << endl;
}

signed main() {
    sol();
}