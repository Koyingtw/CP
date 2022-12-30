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

#define MAXN 1386580
#define MAXM 200005

int n, m;
string s;
bitset<MAXN> vis;
int ans[MAXM];
map<int, vector<int>> mp;

void sol() {
    cin >> n >> m;
    cin >> s;
    s = " " + s;

    for (int i = 1, q; i <= m; i++) {
        cin >> q;
        mp[q].pb(i);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
        cnt += s[i] == 'x';
    vector<pii> pt;
    pt.pb({cnt, 1});

    int pos = (s[cnt] == 'x' ? -1 : 1);

    int now = cnt;
    int step = 0;
    int rnd = 0;
    while (1) {
        if (now == 0 || now > n || step > 1000000)
            break;
        int tmppos;
        step++;
        tmppos = (s[now] == 'x' ? -1 : 1);
        s[now] = (s[now] == 'x' ? 'o' : 'x');

        cout << step << ": " << now << endl;
        if (mp.count(step))
            for (int it: mp[step])
                ans[it] = now;

        if (tmppos != pos) {
            pos = tmppos;

            if (vis[now]) {
                rnd = (step - pt.back().S) * 2;
                // cout << now << ' ' << pt.back().F << endl;
                break;
            }
            pt.pb({now, step});
            vis[now] = true;
        }

        now += tmppos;
    }
    // cout << rnd << endl;

    for (int i = 1; i <= m; i++)
        cout << ans[i] << ' ';
    cout << endl;
}

signed main() {
    Koying
    sol();
}