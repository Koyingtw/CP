#include <bits/stdc++.h>

using namespace std;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int ans = 0;
        ans += (s[0] - '0' + s[2] - '0');
        cout << ans << endl;
    }
    return 0;
}