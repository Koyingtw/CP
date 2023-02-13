#include <bits/stdc++.h>

using namespace std;


signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> ans;
        int now = 0;
        for (int i = 1; i <= n; i++) {
            int nxt = now + i;
            if (m - nxt < (n - i)) {
                for (int j = i; j <= n; j++) {
                    ans.push_back(now + j - i + 1);
                }
                break;
            }
            else
                ans.push_back(nxt);
            now = nxt;
        }
        for (int it: ans)
            cout << it << ' ';
        cout << endl;
    }
    return 0;
}