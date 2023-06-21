#include <bits/stdc++.h>

using namespace std;

pair<int, int> x[10005];
int cnt[10000005];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i].first >> x[i].second;
        cnt[x[i].first]++;
        cnt[x[i].second]--;
    }
    int ans = 0;
    for (int i = 0; i < 10000005; i++) {
        cnt[i] += cnt[i - 1];
        ans += (cnt[i] > 0);
    }
    cout << ans << '\n';
}