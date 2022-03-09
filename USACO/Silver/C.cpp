#pragma GCC optimize("O3")
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
#define MAXN 100005
#define MAXM 1000005 
int n, m, k;
int x[MAXN];
int cnt[MAXN];

void sol()
{
	cin >> n >> m >> k;
	set<pii> f, ma;
	set<int> all;
	MEM(cnt, 0);
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		all.insert(i);
		cnt[x[i]]++;
	}
	for (int i = 1; i <= k; i++) {
		f.insert({i, i});
	}
	int mnow = 0;
	for (mnow = 1; ma.size() < k && mnow <= n; mnow++) {
		if (x[mnow] <= k) {
			all.erase(mnow);
			cnt[x[mnow]]--;
			continue;
		}
		if (mnow <= k)
			ma.insert({mnow, x[mnow]});
	}
	cout << (*ma.begin()).F << endl;
	for (int i = k + 1; i <= m; i++) {
		while (cnt[i - k]) {
			if (i - k <= x[mnow] && x[mnow] < i) {
				all.erase(mnow);
				cnt[x[mnow]]--;
				continue;
			}
			ma.insert({mnow, x[mnow]});
			if (ma.size() > k) break;
		}
	}
	if (all.size())
		cout << "No" << endl;
	else cout << "Yes" << endl;
}

signed main()
{
    Weakoying;
    int t = 1;
    while (cin >> t)
    {
    	while (t--)
        {
            sol();
        }
    }
        
    return 0;
}