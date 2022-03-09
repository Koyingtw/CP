#pragma GCC optimize("O3")
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
#define MAXM 1000000
int n, m;
// vector<int> v(MAXN);

int getval(int val) {
	// return lower_bound(all(v), val)	- v.begin();
}

struct Node {
	int l, r;
	long long sum;
	int tag;
	void add(int val) {
		sum = val * (r - l + 1);
	}
	void set(int _l, int _r) {
		l = _l, r = _r;
		sum = 0, tag = 0;
		return;
	}
} seg[MAXM << 2];

void pull(int id) {
	if (seg[id].tag)
		seg[id].add(1);
	else if (seg[id].l != seg[id].r)
		seg[id].sum = seg[id * 2].sum + seg[id * 2 + 1].sum;
	else seg[id].sum = 0;
}

void build(int id, int l, int r) {
	seg[id].set(l, r);
	if (l == r)
		return;
	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
}

void update(int id, int ql, int qr, int val) {
	auto [l, r] = make_pair(seg[id].l, seg[id].r);
	if (ql > r || qr < l)
		return;
	if (ql <= l && r <= qr) {
		seg[id].tag += val;
		pull(id);
		return;
	}
	update(id * 2, ql, qr, val);
	update(id * 2 + 1, ql, qr, val);
	pull(id);
}

void query(int id, int ql, int qr) {
	
}



vector<tuple<int, int, int, int>> x(MAXN << 1);
void sol()
{
	cin >> n;
	for (int i = 0, l, r, d, u; i < n; i++) {
		cin >> l >> r >> d >> u;
		x[i * 2] = {l, d + 1, u, 1};
		x[i * 2 + 1] = {r, d + 1, u, -1};
		// v.pb(l);
		// v.pb(r);
		// v.pb(d);
		// v.pb(u);
	}
	sort(x.begin(), x.begin() + 2 * n);
	// sort(all(v));
	// v.erase(unique(all(v)), v.end());
	build(1, 0, MAXM);
	long long ans = 0, now = 0;
	for (auto it: x) {
		auto [l, d, u, val] = it;
		// l = getval(l);
		// d = getval(d);
		// u = getval(u);
		if (l != now) {
			ans += 1ll * (l - now) * seg[1].sum;
			now = l;
			
		}
		update(1, d, u, val);
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