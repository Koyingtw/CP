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
#define MAXN 200005
#define MAXM 200005
int n, m, A, B;
int x[MAXN];


// struct Node {
	// int l, r, val;
	// map<int, int> mp;
// 	
// 	
	// Node operator +(Node _N) {
		// Node tmp;
		// tmp.mp = mp;
		// int sum = 0;
		// for (auto it: _N.mp)
			// tmp.mp[it.F] += it.S;
		// for (auto it: tmp.mp)
			// sum += it.F * (A <= it.S && it.S <= B);
		// tmp.val = sum;
		// return tmp;
	// }
	// void operator =(Node _N) {
		// mp = _N.mp;	
		// val = _N.val;
	// }
// }seg[MAXN << 2];

struct Node {
	int l, r, val;
	set<int> mp;
	
	Node operator +(Node _N) {
		Node tmp;
		tmp.mp = mp;
		tmp.val = val;
		for (int it: _N.mp) {
			tmp.val += it * tmp.mp.insert(it).S;
		}
		
		return tmp;
	}
	void operator =(Node _N) {
		mp = _N.mp;	
		val = _N.val;
	}
} seg[MAXN << 2];


// vector<Node> seg(MAXN << 2);

void build(int id, int l, int r) {
	seg[id].l = l, seg[id].r = r, seg[id].val = 0;
	if (l == r) {
		seg[id].mp.insert(x[l]);
		seg[id].val = x[l] * (A == 1);
		return;
	}
	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	seg[id] = seg[id * 2] + seg[id * 2 + 1];
}

Node query(int id, int ql, int qr) {
	int l = seg[id].l, r = seg[id].r;
	
	Node tmp;
	tmp.val = 0;
	if (ql > r || qr < l)
		return tmp;
	if (ql <= l && r <= qr)
		return seg[id];
	return query(id * 2, ql, qr) + query(id * 2 + 1, ql, qr);
}

void sol()
{
	cin >> n >> A >> B;
	for (int i = 1; i <= n; i++)
		cin >> x[i];
	build(1, 1, n);
	cin >> m;
	int l, r;
	while (m--) {
		cin >> l >> r;
		cout << query(1, l, r).val << endl;
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