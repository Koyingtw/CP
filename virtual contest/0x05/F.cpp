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

#define MAXN 35

int n, m;
string s[MAXN];

const int p[] = {1, 0, -1, 0, 1};
const string pos = "SWNE";

map<pair<pii, pii>, int> dis;
map<pair<pii, pii>, pair<pair<pii, pii>, char>> from;

bool check(int i, int j) {
    return (i > 0 && i <= n && j > 0 && j <= m && s[i][j] != 'x');
}

void sol() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = " " + s[i];
    }
    queue<pair<pii, pii>> q;
    q.push({{1, 1}, {n, m}});
    dis[q.front()] = 1;
    auto fin = q.front();


    while (q.size()) {
        auto [now1, now2] = q.front();


        if (now1 == now2) {
            fin = q.front();
            break;
        }

        q.pop();

        for (int i = 0; i < 4; i++) {
            int j = (i + 2) % 4;
            pii tmp1 = {now1.F + p[i], now1.S + p[i + 1]};
            pii tmp2 = {now2.F + p[j], now2.S + p[j + 1]};
            if (!check(tmp1.F, tmp1.S))
                tmp1 = now1;
            if (!check(tmp2.F, tmp2.S))
                tmp2 = now2;

            if (tmp1 == now1 && tmp2 == now2)
                continue;
            if (dis.count({tmp1, tmp2}))
                continue;

            dis[{tmp1, tmp2}] = dis[{now1, now2}] + 1;
            q.push({tmp1, tmp2});
            from[{tmp1, tmp2}] = {{now1, now2}, pos[i]};
        }
    }

    string ans;
    while (from.count(fin)) {
        auto [now1, now2] = fin;
        // cout << now1.F << ' ' << now1.S << ' ' << now2.F << ' ' << now2.S << endl;

        ans += from[fin].S;
        fin = from[fin].F;
    }

    if (ans.size() == 0) {
        cout << "-1\nimpossible" << endl;
        return;
    }

    reverse(all(ans));
    cout << ans.size() << endl;
    cout << ans << endl;
}

signed main() {
    Koying
    sol();
}