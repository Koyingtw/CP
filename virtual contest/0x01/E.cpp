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
pii x[MAXN];
array<int, 3> E[MAXN];
map<pii, int> mp;

struct Disjoint_Set {
    int arr[MAXN], cnt[MAXN];

    void init() {
        for (int i = 1; i <= n; i++)
            arr[i] = i, cnt[i] = 1;
    }

    int find(int i) {
        return (arr[i] == i ? i : arr[i] = find(arr[i]));
    }

    int unite(int i, int j) {
        i = find(i);
        j = find(j);
        if (i == j)
            return 0;
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
    for (int i = 1; i <= n; i++) {
        cin >> x[i].F;
        x[i].S = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> E[i][1] >> E[i][2] >> E[i][0];
        mp[{min(E[i][1], E[i][2]), max(E[i][1], E[i][2])}] = E[i][0];
    }

    sort(E, E + m);
    int ans = 0, cnt = n;
    
    for (int i = 0; i < m; i++) {
        if (dsu.find(E[i][1]) != dsu.find(E[i][2]) && E[i][0] < x[E[i][1]].F + x[E[i][2]].F) {
            dsu.unite(E[i][1], E[i][2]);
            ans += E[i][0];
            cnt--;
        }
    }
    // cout << ans << endl;

    sort(x + 1, x + 1 + n);

    for (int i = 1; i <= n && cnt > 1; i++) {
        for (int j = i + 1; j <= n && cnt > 1; j++) {
            if (dsu.find(x[i].S) != dsu.find(x[j].S) && !mp.count({min(x[i].S, x[j].S), max(x[i].S, x[j].S)})) {
                dsu.unite(x[i].S, x[j].S);
                ans += x[i].F + x[j].F;
                cnt--;
                // cout << x[i].S << ' ' << x[j].S << endl;
                // cout << mp[{min(x[i].S, x[j].S), max(x[i].S, x[j].S)}] << endl;
            }
        }

    }
    cout << ans << endl;
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