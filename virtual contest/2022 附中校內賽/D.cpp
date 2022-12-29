#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define SZ(v) ((int)v.size())
#define MEM(x, n) memset(x, n, sizeof(x))
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) (a = (a > b ? a : b))
#define cmin(a, b) (a = (a < b ? a : b))
#if !LOCAL
#define endl '\n'
#pragma GCC optimize("Ofast, unroll-all-loops")
#endif
#define pb push_back

const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int INFLL = 0x3f3f3f3f3f3f3f3f;

using namespace std;

#define MAXN 200005
int n, m, q;

vector<int> G[MAXN];
vector<vector<int>> x;
bool cant[MAXN];

struct Disjoint_Set {
    int arr[MAXN], cnt[MAXN];

    Disjoint_Set() {
        for (int i = 1; i < MAXN; i++) {
            arr[i] = i, cnt[i] = 1;
        }
    }

    int find(int i) {
        return (arr[i] == i ? i : arr[i] = find(arr[i]));
    }

    void unite(int i, int j) {
        i = find(i);
        j = find(j);

        if (i == j)
            return;
        if (cnt[i] < cnt[j])
            swap(i, j);
        arr[j] = i;
        cnt[i] += cnt[j];
    }
} dsu;

void sol() {
    cin >> n >> m;
    for (int i = 1, a, b; i <= m; i++) {
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }

    cin >> q;
    int op, w, a, b;
    for (int i = 0; i < q; i++) {
        x.pb(vector<int>{});
        cin >> op;
        x.back().pb(op);
        if (op == 1) {
            cin >> w;
            x.back().pb(w);
            cant[w] = 1;
        }
        else {
            cin >> a >> b;
            x.back().pb(a);
            x.back().pb(b);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int e: G[i]) if (!(cant[i] && cant[e])) {
            dsu.unite(i, e);
        }
    }

    reverse(all(x));

    vector<string> ans;


    for (int i = 0; i < q; i++) {
        if (x[i][0] == 2) {
            ans.pb("");
            if (dsu.find(x[i][1]) == dsu.find(x[i][2]))
                ans.back() = "YES";
            else
                ans.back() = "NO";
            // ans.back() = (find(x[i][1]) == find(x[i][2] ? "YES" : "NO"));
        }
        else {
            cant[x[i][1]] = false;
            for (int e: G[x[i][1]]) if (cant[e] + cant[x[i][1]] < 2) {
                dsu.unite(x[i][1], e);
            }
        }
    }

    reverse(all(ans));
    for (auto it: ans)
        cout << it << endl;
}

/*
7 6
1 2
2 3
3 4
4 5
5 6
6 7
5
2 2 5
1 3
2 2 5
1 4
2 2 5
*/

signed main() {
    Koying;
    sol();
    return 0;
}