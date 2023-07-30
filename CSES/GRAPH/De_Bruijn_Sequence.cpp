#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pqueue priority_queue
// #define pb push_back
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
#define pb insert
int n, m;
set<int> G[(1 << 17)], RG[(1 << 17)];
string ans;

void dfs(int i) {
    cout << i << ' ' << G[i].size() << endl;
    ans += to_string(i & 1);
    if (G[i].size()) {
        int it = *G[i].begin(); 
        for (auto it2: RG[it])
            G[it2].erase(it);
        RG[it].clear();
        dfs(it);
    }
}

void sol() {
    cin >> n;
    for (int i = 0; i < (1 << n); i++) {
        bitset<20> tmp(i);
        tmp[n - 1] = 0;
        tmp <<= 1;
        tmp[0] = 1;
        if ((int)tmp.to_ulong() != i) {
            G[i].pb(tmp.to_ulong());
            RG[tmp.to_ulong()].pb(i);
            cout << i << ' ' << tmp.to_ulong() << endl;
        }
        tmp[0] = 0;
        if ((int)tmp.to_ullong() != i) {
            cout << i << ' ' << tmp.to_ulong() << endl;
            G[i].pb(tmp.to_ulong());
            RG[tmp.to_ulong()].pb(i);
        }
    }

    ans = string(n - 1, '0');

    for (auto it: RG[0])
        G[it].erase(0);
    RG[0].clear();

    dfs(0);
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