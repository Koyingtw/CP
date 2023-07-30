#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pqueue priority_queue
#define pb push_back
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) a = (a > b ? a : b)
#define cmin(a, b) a = (a < b ? a : b)
#define put(x) cout << x << endl;
#define DB(x) cerr << #x << " " << x << endl
#define all(v) v.begin(), v.end()
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#define SZ(v) ((int)v.size())
#if !LOCAL
#define endl "\n"
#pragma GCC optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
#define MAXK 50
int n, m, k;
int x[MAXN];
int c[MAXN];

struct Disjoint_Set {
    int arr[MAXN], cnt[MAXN];

    void init() {
        for (int i = 0; i < MAXN; i++)
            arr[i] = i, cnt[i] = 1;
    }

    int find(int i) {
        return (arr[i] == i ? i : arr[i] = find(arr[i]));
    }

    void unite(int i, int j) {
        i = find(i), j = find(j);
        if (i == j) return;

        if (cnt[i] < cnt[j])
            swap(i, j);
        
        arr[j] = i;
        cnt[i] += cnt[j];
    }
} dsu;

int cnt[MAXN];
// set<int> st[MAXK];
bitset<MAXK> st[MAXK];

int ans = 0;

void dfs(int i, int mask, int sum) {
    cmax(ans, sum);

    int tmp = 0;
    // if (i == n) {
    //     for (int j = 1; j <= k; j++) if (mask & (1 << (j - 1))) {
    //         tmp += c[j];
    //     }
    //     cmax(ans, tmp);
    //     return;
    // }

    for (int j = i + 1; j <= k; j++) {
        bool legal = true;
        for (int o = 1; o <= i; o++) if (mask & (1 << (o - 1))) {
            legal &= st[o][j] == false;
        }
        if (legal)
            dfs(j, mask | (1LL << (j - 1)), sum + c[j]);
    }
}

void sol() {
    cin >> n >> m >> k;
    dsu.init();
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        cnt[x[i]]++;
    }
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        st[x[a]][x[b]] = 1;
        st[x[b]][x[a]] = 1;
        // st[x[a]].insert(x[b]);
        // st[x[b]].insert(x[a]);
        // dsu.unite(a + n, b);
        // dsu.unite(a, b + n);
        // dsu.unite(a, b);
    }
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
        // c[i] *= cnt[i];
    }

    for (int i = 1; i <= k; i++)
        dfs(i, (1 << (i - 1)), c[i]);
    cout << ans << endl;
    return;

    int ans = 0;
    for (int i = 0; i < (1LL << k); i++) {
        int tmp = 0;
        bool legal = true;
        vector<int> v;
        for (int j = 1; j <= k; j++) if (i & (1LL << (j - 1))) {
            v.pb(j);
            tmp += c[j];
            // cout << j << ' ';
        }

        // for (int j = 1; j < v.size(); j++)
        //     legal &= st[v[i - 1]].count(v[i]) == 0;

        for (int o = 0; o < v.size(); o++) {
            for (int p = o + 1; p < v.size(); p++) {
                legal &= st[v[o]][v[p]] == 0;
            }
        }
        cmax(ans, legal * tmp);
        // cout << legal * tmp << endl;
    }
    cout << ans << endl;
}

// 30 / 10 / 10 / 10 / 10 / 10 / 15 / 20 / 20 / 20 / 20 / 20 / 25 / 25 / 25

signed main() {
    Weakoying;
    int t = 1;
    //while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}