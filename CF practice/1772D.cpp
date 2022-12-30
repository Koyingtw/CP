#include <bits/stdc++.h>

using namespace std;

int x[200005];
int n;

#define endl '\n'

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> x[i];
        bool legal = true;
        int l = -1e9, r = 1e9;
        for (int i = 1; i < n; i++) {
            if (x[i - 1] > x[i]) {
                int tmpl = (x[i] + x[i - 1] + 1) / 2;
                int tmpr = 1e9;
                if (tmpl > r || tmpr < l)
                    legal = false;
                l = max(l, tmpl);
                r = min(r, tmpr);
            }
            else if (x[i - 1] < x[i]) {
                int tmpl = -1e9;
                int tmpr = (x[i] + x[i - 1]) / 2;
                if (tmpl > r || tmpr < l)
                    legal = false;
                l = max(l, tmpl);
                r = min(r, tmpr);
            }
        }
        cout << (legal == true ? r : -1) << endl;
    }
    return 0;
}