#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
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
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;

struct disjont_set {
    int arr[MAXN], cnt[MAXN];
    void init() {
        for (int i = 0; i <= n; i++)
            cnt[i] = 1, arr[i] = i;
    }

    int find(int i) {
        return arr[i] == i ? i : arr[i] = find(arr[i]);
    }

    bool same(int i, int j) {
        return find(i) == find(j);
    }

    int unite(int i, int j) {
        i = find(i);
        j = find(j);
        if (i == j) return 0;
        if (cnt[i] < cnt[j])
            swap(i, j);
        arr[j] = i;
        cnt[i] += cnt[j];
        return 1;
    }
} dsu;

void sol() {
	cin >> n >> m;
    dsu.init();

    int t, u, v;
    while (m--) {
        cin >> t >> u >> v;
        if (t == 0) {
            dsu.unite(u, v);
        }
        else {
            cout << dsu.same(u, v) << endl;
        }
    }
}

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