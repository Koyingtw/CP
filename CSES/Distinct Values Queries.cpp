#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <bits/extc++.h>
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
#define MAXN 20005
#define MAXM 1000005 
int n, m;
int x[MAXN];

struct Node {
	int l, r;
	bitset<MAXN> s;
} seg[MAXN << 2];

void pull(int id) {
	seg[id].s |= seg[id * 2].s;
	seg[id].s |= seg[id * 2 + 1].s;
	return;
}

void build(int id, int l, int r) {
	seg[id].l = l, seg[id].r = r;
	if (l == r) {
		seg[id].s[x[l]] = true;
		return;
	}
	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	pull(id);
}

bitset<MAXN> query(int id, int ql, int qr) {
	int l = seg[id].l, r = seg[id].r;
	bitset<MAXN> tmp;
	if (l > qr || r < ql) return tmp;
	if (ql <= l && r <= qr)
		return seg[id].s;
	bitset<MAXN> ls = query(id * 2, ql, qr), rs = query(id * 2 + 1, ql, qr);
	tmp |= ls;
	tmp |= rs;
	return tmp;
}

void sol()
{
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		v[i - 1] = x[i];
	}
	sort(all(v));
	v.erase(unique(all(v)), v.end());
	for (int i = 1; i <= n; i++) {
		x[i] = lower_bound(all(v), x[i]) - v.begin();
	}
	build(1, 1, n);
	int a, b;
	while (m--) {
		cin >> a >> b;
		// set<int> ans = query(1, a, b);
		cout << query(1, a, b).count() << endl;
	}
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