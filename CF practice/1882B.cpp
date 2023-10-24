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
#define MAXN 55
#define MAXM 1000005 
int n, m;
vector<int> G[MAXN];
int cnt[MAXN];

void sol() {
    cin >> n;
    MEM(cnt, 0);
    bitset<MAXN> all;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int k;
        G[i].clear();
        cin >> k;
        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            G[i].pb(a);
            cnt[a]++;
            all[a] = true;
        }
    }
    for (int i = 0; i < MAXN; i++) if (all[i]) {
        bitset<MAXN> tmp;
        for (int j = 0; j < n; j++) if (!binary_search(all(G[j]), i)) {
            for (auto it: G[j])
                tmp[it] = true;
        }
        cmax(ans, tmp.count());
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