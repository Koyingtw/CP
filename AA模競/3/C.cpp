#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// #define int long long
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
#define putarr(x) for(int i = 0; i < sizeof(x); i++) cout << x[i] << (" \n")[i == sizeof(x) - 1]; 
#define all(v) v.begin(), v.end()
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 200005
int n, m;
vector<pii> G[MAXN];
map<int, int> mp[MAXM];
ll x[MAXN];
ll sum[MAXN];

void sol()
{
	cin >> n >> m;
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		mp[x[i]]++;
	}
	for (auto it: mp)
		sum[0] += (ll)(it.F) * (ll)(it.S) * (ll)(it.S);
	long long ans = 0;
	queue<pair<int, map<int, int>>> q;
	int a, b;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		G[a].pb({i, b});
	}
	q.push({0, mp});
	while (q.size()) {
		int now = q.front().F;
		map<int, int> nmp = q.front().S;
		q.pop();
		// cout << now << endl;
		for (pii e: G[now]) {
			sum[e.F] = sum[now] - (ll)(abs(e.S)) * (ll)(nmp[abs(e.S)]) * (ll)(nmp[abs(e.S)]);
			if (e.S > 0) {
				nmp[e.S]++;
				// cout << nmp[e.S] << endl;
				// cout << sum[e.F] << endl;
				sum[e.F] += (ll)(e.S) * (ll)(nmp[e.S]) * (ll)(nmp[e.S]);
				if (G[e.F].size())
					q.push({e.F, nmp});
				nmp[e.S]--;
			}
			else {
				e.S = abs(e.S);
				nmp[e.S]--;
				sum[e.F] += (ll)(e.S) * (ll)(nmp[e.S]) * (ll)(nmp[e.S]);
				if (G[e.F].size())
					q.push({e.F, nmp});
				nmp[e.S]++;
			}
		}
	}
	for (int i = 0; i <= m; i++) {
		// cout << sum[i] << " ";
		ans ^= sum[i];
	}
	cout << ans << endl;
}

signed main()
{
    Weakoying;
    int t = 1;
    //while (cin >> t)
    {
    	while (t--)
        {
            sol();
        }
    }
        
    return 0;
}