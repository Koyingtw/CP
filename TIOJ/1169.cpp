#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#pragma pack(1)
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
#define MAXM 1000005 
int n, m, c;
int x[MAXN];

struct Node {
	int lc, rc;
	int l, r;
	int sum, pre, suf, mx;
	
	Node(int l, int r): lc(-1), rc(-1), l(l), r(r), sum(0), pre(r - l + 1), suf(r - l + 1), mx(r - l + 1){}

	
	Node operator +(Node a) {
		Node tmp(l, a.r);
		tmp.sum = sum + a.sum;
		
		if (!sum)
			tmp.pre = r - l + 1 + a.pre;
		else
			tmp.pre = pre;
		
		if (!a.sum)
			tmp.suf = a.r - a.l + 1 + suf;
		else 
			tmp.suf = a.suf;
		
		if (!tmp.sum) {
			tmp.mx = tmp.r - tmp.l + 1;
		}
		else {
			tmp.mx = max(suf + a.pre, max(mx, a.mx));
		}
		return tmp;
	}
	void operator =(Node a) {
		l = a.l, r = a.r;
		sum = a.sum;
		pre = a.pre;
		suf = a.suf;
		mx = a.mx;
	}
};


vector<Node> seg(25751250, Node(0, MAXN - 1));
int Size = 0;

int nothing[10000];

int newNode(int col, int l, int r) {
	seg[Size] = Node(l, r);
	return Size++;
}

void init() {
	Node zero = Node(0, n - 1);
	for (int i = 0; i < (1 << 24); i++) {
		Size = i;
	}
	return;
}

void update(int col, int id, int pos, int val) {
	Node now = seg[id];
	int l = now.l, r = now.r;
	int lc = now.lc, rc = now.rc;
	
	if (l == r) {
		seg[id].sum += val;
		seg[id].pre 
		= seg[id].suf
		= seg[id].mx
		= !(seg[id].sum);
		return;
	}
	
	int mid = (l + r) / 2;
	
	if (pos <= mid) {
		if (lc == - 1)
			lc = seg[id].lc = newNode(col, l, mid);
		update(col, lc, pos, val);
	}
	else {
		if (rc == -1)
			rc = seg[id].rc = newNode(col, mid + 1, r);
		update(col, rc, pos, val);
	}

	Node lnode(l, mid), rnode(mid + 1, r);
	if (lc != -1)
		lnode = seg[lc];
	if (rc != -1)
		rnode = seg[rc];
		
	seg[id] = lnode + rnode;
}

Node query(int col, int id, int ql, int qr) {
	Node now = seg[id];
	int l = now.l, r = now.r;
	int lc = now.lc, rc = now.rc;
	
	if (ql <= l && r <= qr) {
		return seg[id];
	}
	
	if (ql > r || qr < l)
		return Node(l, l - 1);
	
	int mid = (l + r) / 2;
	Node qrl(l, mid), qrr(mid + 1, r);

	if (ql <= mid && qr >= l) {
		if (lc == -1)
			qrl = Node(max(l, ql), min(qr, mid));
		else
			qrl = query(col, lc, ql, qr);
	}
	else {
		qrl = Node(ql, ql - 1);
	}
	
	if (qr > mid && ql <= r) {
		if (rc == -1)
			qrr = Node(max(mid + 1, ql), min(qr, r));
		else 
			qrr = query(col, rc, ql, qr);
	}
	else {
		qrr = Node(qr + 1, qr);
	}
	
	return qrl + qrr;
}

void sol()
{
	cin >> n >> m >> c;
	init();
	
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		update(x[i], x[i], i, 1);
	}

	int q, a, b, k;
	while (m--) {
		cin >> q;
		if (q == 0) {
			cin >> a >> k;
			
			update(x[a], x[a], a, -1);
			x[a] = k;
			update(x[a], x[a], a, 1);
			
		}
		else {
			cin >> a >> b >> k;
			b--;
			cout << query(k, k, a, b).mx << endl;
		}
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