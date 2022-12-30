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
int x[MAXN];
vector<pii> rng[MAXN];

void sol() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        rng[i].clear();
    
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        if (i && x[i] == x[i - 1]) {
            rng[x[i]].back().S = i;
        }
        else {
            rng[x[i]].pb({i, i});
        }
    }

    int ans = INF;
    for (int i = 1; i <= n; i++) if (rng[i].size()) {
        cmin(ans, rng[i].size() - 1 + (rng[i][0].F != 0) + (rng[i].back().S != n - 1));
    }
    cout << ans << endl;
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