#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define pii pair<int, int>
#define MEM(x, n) memset(x, n, sizeof(x))
#define F first
#define S second
#define all(v) v.begin(), v.end()
#if !LOCAL
#define endl '\n'
#pragma optimize("Ofast, unroll-all-loops")
#endif

using namespace std;

#define MAXN 5005
#define MAXM 1000005

int n, m;

pii operator +(pii _a, pii _b) {
    _a.F += _b.F;
    _a.S += _b.S;
    return _a;
}

pii operator -(pii _a, pii _b) {
    _a.F -= _b.F;
    _a.S -= _b.S;
    return _a;
}

pii operator *(pii _a, int _b) {
    _a.F *= _b;
    _a.S *= _b;
    return _a;
}

struct Position {
    int u, v, w;

    pii operator ()() {
        pii res(0, 0);
        res = res + pii(0, 2) * u;
        res = res + pii(1, 1) * v;
        res = res + pii(1, -1) * w;
        res.F += n;
        res.S += 2 * n;
        return res;
    }
};

bool check(pii pos) {
    pos = pos - pii(n, 2 * n);
    return (abs(pos.F) <= n && abs(pos.S) <= 2 * n - abs(pos.F));
}

const pii path[] = {pii(0, 2), pii(0, -2), pii(1, 1), pii(1, -1), pii(-1, 1), pii(-1, -1)};
int dis[MAXN][MAXN];

bitset<MAXN> dirt[MAXN];


void sol() {
    cin >> n >> m;
    Position st, fin;
    cin >> st.u >> st.v >> st.w;
    cin >> fin.u >> fin.v >> fin.w;

    MEM(dis, 0x3f);


    for (int i = 0; i < m; i++) {
        Position room;
        cin >> room.u >> room.v >> room.w;
        dirt[room().F][room().S] = true;
        // cout << room().F << ' ' << room().S << endl;
    }


    deque<pair<pii, int>> dq;
    dq.push_front({st(), 0});
    dis[st().F][st().S] = 0;

    while (dq.size()) {
        auto now = dq.front().F;
        auto nowdis = dq.front().S;
        dq.pop_front();

        if (nowdis != dis[now.F][now.S])
            continue;

        // cout << now.F << ' ' << now.S << endl;

        if (now == fin())
            break;

        for (auto it: path) {
            pii tmp = now + it;
            if (!check(tmp))
                continue;

            if (dis[tmp.F][tmp.S] > dis[now.F][now.S] + dirt[tmp.F][tmp.S]) {
                dis[tmp.F][tmp.S] = dis[now.F][now.S] + dirt[tmp.F][tmp.S];
                if (!dirt[tmp.F][tmp.S])
                    dq.push_front({tmp, dis[tmp.F][tmp.S]});
                else
                    dq.push_back({tmp, dis[tmp.F][tmp.S]});

            }
        }
    }

    cout << dis[fin().F][fin().S] << endl;

    // pii tmp = fin();
    // while (from[tmp] != st()) {
    //     cout << from[tmp].F << ' ' << from[tmp].S << endl;
    //     tmp = from[tmp];
    // }
}

signed main() {
    Koying
    int _ = 1;
    // cin >> _
    while (_--) {
        sol();
    }

    return 0;
}