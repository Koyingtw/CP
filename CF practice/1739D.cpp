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
int dep[MAXN], p[MAXN];
vector<int> G[MAXN];

int cnt, mx;

void dfs(int i, int mid) {
    for (int j: G[i]) {
        dfs(j, mid);
        cmax(dep[i], dep[j]);
    }

    dep[i] += (i != 1);

    if (dep[i] == mid && p[i] != 1) {
        // cout << i << endl;
        cnt++;
        dep[i] = 0;
    }
}

bool check(int mid) {
    mx = cnt = 0;
    for (int i = 1; i <= n; i++) {
        dep[i] = 0;
    }
    dfs(1, mid);
    // cout << endl;

    return !(cnt > m || mx > mid);
}

void sol() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        G[i].clear();
        dep[i] = 0;
    }
    p[1] = 1;
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
        G[p[i]].pb(i);
    }

    check(1);

    int l = 1, r = n - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) 
            r = mid;
        else
            l = mid + 1;
    }
    cout << r << endl;
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