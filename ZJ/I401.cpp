#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// #define int long long
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
#define MAXN 250005
#define MAXM 30005
int n, m;

const int trans[2][4] = {
	{1, 0, 3, 2},
	{3, 2, 1, 0}
};

struct Mirror {
	int F, S, t;
	
	bool operator <(Mirror _a) {
		if (F != _a.F)
			return F < _a.F;
		else
			return S < _a.S;
	}
} x[MAXN], y[MAXN];

Mirror now = {0, 0, 0};
int ans = 0, dir = 0;

void update(Mirror a) {
	now = a;
	dir = trans[a.t][dir];
	return;	
}

void sol() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i].F >> x[i].S >> x[i].t;
		y[i] = {x[i].S, x[i].F, x[i].t};
	}
	sort(x, x + n);
	sort(y, y + n);
	

	
	while (1) {
		if (dir == 0) {
			Mirror tmp = {now.S, now.F + 1, 0};
			auto qq = lower_bound(y, y + n, tmp);
			if (qq == y + n || (*qq).F != now.S)
				break;
			Mirror res = {(*qq).S, (*qq).F, (*qq).t};
			update(res);
		}
		else if (dir == 1) {
			Mirror tmp = {now.F, now.S + 1, 0};
			auto qq = lower_bound(x, x + n, tmp);
			if (qq == x + n || (*qq).F != now.F)
				break;
			Mirror res = *qq;
			update(res);
		}
		else if (dir == 2) {
			Mirror tmp = {now.S, now.F, 0};
			auto qq = lower_bound(y, y + n, tmp);
			if (qq == y || (*qq).F != now.S)
				break;
			qq--;
			Mirror res = {(*qq).S, (*qq).F, (*qq).t};
			update(res);
		}
		else if (dir == 3) {
			Mirror tmp = {now.F, now.S, 0};
			auto qq = lower_bound(x, x + n, tmp);
			if (qq == x || (*qq).F != now.F)
				break;
			qq--;
			Mirror res = *qq;
			update(res);
		}
		ans++;
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