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
#define MAXN 300005
#define MAXM 1000005 
int n, m;
vector<int> G[MAXN];
pii x[MAXN];
int from[MAXN];

int dfs(int i) {
    int ret = 0;
    for (auto it: G[i]) {
        int tmp = dfs(it);
        cmax(ret, tmp);
    }   
    return ret + 1;
}

void sol() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i].F;
        x[i].S = i;
        from[i] = 0;
        G[i].clear();
    }
    sort(x + 1, x + 1 + n, greater<>());
    int now = 1;
    for (int i = 2; i <= n; i++) {
        while (x[now].F == 0) {
            now++;
        }
        G[x[now].S].pb(x[i].S);
        from[x[i].S] = x[now].S;
        x[now].F--;
    }

    cout << dfs(x[1].S) - 1 << endl;

    for (int i = 1; i <= n; i++)
        cout << from[i] << " \n"[i == n];
}

// 30 / 10 / 10 / 10 / 10 / 10 / 15 / 20 / 20 / 20 / 20 / 20 / 25 / 25 / 25

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