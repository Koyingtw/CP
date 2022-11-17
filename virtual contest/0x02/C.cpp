#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) a = (a > b ? a : b)
#define cmin(a, b) a = (a < b ? a : b)
#define lowbit(x) (x & (-x))
#define F first
#define S second
#define Koying ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define eb emplace_back
#if !LOCAL
#define endl '\n'
#endif

using namespace std;

#define MAXN 100005

int n, m, k;
int x[MAXN];
vector<int> G[MAXN];
bitset<MAXN> vis;

struct Disjoint_Set {
    int arr[MAXN], cnt[MAXN];

    void init() {
        for (int i = 1; i <= n; i++) {
            arr[i] = i, cnt[i] = x[i];
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
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    dsu.init();

    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        G[a].eb(b);
        G[b].eb(a);
        if (a * b) {
            dsu.unite(a, b);
        }
    }

    int ans = 0;
    for (int e: G[0]) if (!vis[dsu.find(e)]) {
        vis[dsu.find(e)] = true;
        int cnt = dsu.cnt[dsu.find(e)];
        ans += (cnt + k - 1) / k;
    }   
    cout << ans - (ans > 0) << endl;
}

signed main() {
    int _ = 1;
    Koying
    while (_--) {
        sol();
    }
    return 0;
} 