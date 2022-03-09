// Problem: E - Ranges on Tree
// Contest: AtCoder - AtCoder Beginner Contest 240
// URL: https://atcoder.jp/contests/abc240/tasks/abc240_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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
int n, m;
pii x[MAXN];

struct segmentree {
	int seg[MAXN << 2];
	
	void update(int id, int l, int r, int pos) {
		if (l == r) {
			seg[id]++;
			return;
		}
		int mid = (l + r) / 2;
		if (pos <= mid) 
			update(id * 2, l, mid, pos);
		else update(id * 2 + 1, mid + 1, r, pos);
		seg[id] = seg[id * 2] + seg[id * 2 + 1];
		return;
	}
	
	int query(int id, int l, int r, int ql, int qr) {
		if (ql > r  || qr < l) 
			return 0;
		if (ql <= l && r <= qr) 
			return seg[id];
		int mid = (l + r) / 2;
		return query(id * 2, l, mid, ql, qr) 
			 + query(id * 2 + 1, mid + 1, r, ql, qr);
	}
} mnseg, mxseg;

void sol()
{
	cin >> n;
	for (int i = 1; i < n; i++)	{
		cin >> x[i].F >> x[i].S;
		if (x[i].F > x[i].S)
			swap(x[i].F, x[i].S);
		mnseg.update(1, 1, n, x[i].F);
		mxseg.update(1, 1, n, x[i].S);
	}
	int ans = {1, n};
	int l = 1, r = 1;
	
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