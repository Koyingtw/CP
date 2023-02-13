#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

int n, k, d;
int a[MAXN];

void sol() {
    cin >> n >> k >> d;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int cnt = 1, ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i - 1] <= d || cnt == 0) 
            cnt++;
        else
            cnt = 1;
        
        if (cnt == k) {
            cnt = 0;
            ans++;
        }
    }
    cout << ans << endl;
}

signed main() {
    sol();
}