#include <bits/stdc++.h>
#define int long long
#define Koying ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
#define pii pair<int, int> 
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define pb push_back
#define MEM(x, n) memset(x, n, sizeof(x))
#define lowbit(x) (x & (-x))
#define SZ(x) ((int)x.size())
#if !LOCAL
#define endl '\n'
#pragma GCC optimize("Ofast, unroll-all-loops")
#endif
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) (a = max(a, b))
#define cmin(a, b) (a = min(a, b))

const int INF = 0x3f3f3f3f;
const int INFLL = 0x3f3f3f3f3f3f3f3f;
using namespace std;

#define MAXN 200005

int n, m;
int cnt[10005];

void sol() {
    int zero = 0;
    vector<int> ans;
    for (int i = 1; i <= 10000; i++) {
        string s = to_string(i);
        for (auto it: s)
            cnt[i] += (it == '0');
        if (cnt[i] == 1 && SZ(ans) < 100)
            ans.pb(i);
    }

    for (int i = 1; i <= 10000; i++) {
        if (cnt[i] == 0 && SZ(ans) < 1000)
            ans.pb(i);
    }

    sort(all(ans));
    for (int it: ans)
        cout << it << endl;
}

signed main() {
    Koying
    sol();
}