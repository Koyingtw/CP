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
#pragma optimize("Ofase", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
vector<pii> x(MAXN);
map<int, int> mp;
int cnt[MAXN], sum = 0, ans = INF;

int dfs(int i, int dep, vector<pii> &v) {
    // cout << i << endl;
    sum += dep * mp[i];
    vector<pii> v1, v2;
    for (int j = 0; j < (int)v.size(); j++) {
        if (v[j].S < i)
            v1.pb(v[j]);
        if (v[j].S > i)
            v2.pb(v[j]);
    }

    int res1 = INF * (v1.size() != 0), res2 = INF * (v2.size() != 0);

    for (int j = 0; j < (int)v1.size() && v1[j].F * 2 >= v1[0].F; j++) {
        cmin(res1, dfs(v1[j].S, dep + 1, v1));
    }
    for (int j = 0; j < (int)v2.size() && v2[j].F * 2 >= v2[0].F; j++) {
        cmin(res2, dfs(v2[j].S, dep + 1, v2));
    }
    return res1 + res2 + dep * mp[i];
}

void sol() {
	cin >> n;
    x.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i].F;
        x[i].S = i;
        mp[x[i].S] = x[i].F;
    }
    sort(all(x), greater<pii>());
    for (int i = 0; i < n && x[i].F * 2 >= x[0].F; i++) {
        sum = 0;
        cmin(ans, dfs(x[i].S, 1, x));
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