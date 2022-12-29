#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// #define int long long
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
#if !LOCAL
#define endl "\n"
#pragma optimize("Ofast", "unroll-all-loops")
#endif
// const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 1000005
#define MAXM 1000005 
int n, l;

struct Disjoint_Set {
    int arr[MAXN * 3], cnt[MAXN * 3];

    void init() {
        for (int i = 0; i < MAXN * 3; i++)
            arr[i] = i, cnt[i] = 1;
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
} DSU;

vector<int> G[MAXN];

void sol() {
    cin >> n >> l;
    vector<pii> E;
    DSU.init();

    for (int i = 1; i <= l; i++)
        G[i].clear();

    for (int i = 1, a; i <= n; i++) {
        while (cin >> a && a) {
            G[a].pb(i);
        }
        while (cin >> a && a) {
            G[a].pb(-i);
        }
    }

    for (int i = 1; i <= l / 2; i++) {
        for (int j: G[i]) if (j > 0) 
            for (int k: G[i]) if (k < 0) {
                DSU.unite(j * 2, -k * 2 + 1);
                DSU.unite(j * 2 + 1, -k * 2);
            }
    }

    for (int i = 1; i <= n; i++) {
        if (DSU.find(i * 2) == DSU.find(i * 2 + 1)) {
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
}

signed main() {
    Weakoying;
    int t = 1;
    while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}