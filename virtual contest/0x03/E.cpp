#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0);
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define SZ(v) ((int)v.size())
#define lowbit(x) (x & (-x))
#define pb push_back
#define pf push_front
#define MEM(x, n) memset(x, n, sizeof(x))
const int INF = 0x3f3f3f3f3f3f3f3f;

using namespace std;

int n, m;

void sol() {
    string s;
    while (getline(cin, s) && s != "0") {
        vector<int> v;
        map<int, int> mp;
        stringstream ss;
        ss << s;
        int a;
        while (ss >> a) {
            mp[a]++;
        }
        for (auto it: mp)
            if (it.S % 2 == 0)
                v.pb(it.F);
        sort(all(v));
        if (v.size() == 0)
            cout << -1;
        for (auto it: v)
            cout << it << ' ';
        cout << endl;
    }

}

signed main() {
    Koying
    sol();
    return 0;
}