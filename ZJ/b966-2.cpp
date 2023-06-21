#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

pair<int, int> e[20005];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        e[i * 2] = {x, 1};
        e[i * 2 + 1] = {y, -1};
    }

    sort(e, e + n * 2);

    int ans = 0, now = 0, cnt = 0;
    for (int i = 0; i < n * 2; i++) {
        if (cnt == 0) {
            cnt += e[i].second;
            now = e[i].first;
        }
        else {
            cnt += e[i].second;
            ans += e[i].first - now;
            now = e[i].first;
        }
        
    }
    cout << ans << '\n';
}