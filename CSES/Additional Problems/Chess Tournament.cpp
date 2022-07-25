// Problem: Chess Tournament
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1697
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
#define DB(x) cerr << #x << " " << x << endl
#define all(v) v.begin(), v.end()
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 100005
#define MAXM 1000005 
int n, m;
int BIT[MAXN];
vector<pii> ans;
pii x[MAXN];

void update(int i, int val) {
	while (i < MAXN) {
		BIT[i] += val;
		i += lowbit(i);
	}
}

int query(int i) {
	int sum = 0;
	while (i) {
		sum += BIT[i];
		i -= lowbit(i);
	}
	return sum;
}

void sol() {
	cin >> n;
	set<pii, greater<pii>> st;
	for (int i = 0; i < n; i++)	{
		cin >> x[i].F;
		x[i].S = i;
		st.insert(x[i]);
	}
	
	bool yes = true;
	
	for (int i = 0; i < n && st.size(); i++) {
		pii now = *st.begin();
		st.erase(st.begin());
		int cnt = 0;
		vector<pii> tmp;
		if (now.F <= 0)
			break;
		for (auto it: st) {
			cnt++;
			if (it.F <= 0)
				yes = 0;
			ans.pb({now.S, it.S});
			tmp.pb(it);
			if (cnt >= now.F) {
				break;
			}
		}
		if (cnt < now.F)
			yes = false;
		for (pii it: tmp) {
			st.erase(it);
			it.F--;
			if (it.F > 0)
				st.insert(it);
		}
	}
	if (yes) {
		cout << ans.size() << endl;
		for (pii it: ans)
			cout << ++it.F << " " << ++it.S << endl;
	}
	else {
		cout << "IMPOSSIBLE" << endl;
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