#pragma region
#pragma optimize("O3")
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
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f;
const int P = 1e9+7;

using namespace std;
#pragma endregion
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
struct Node
{
	int id, l, r, sum, mx;
}seg[MAXN * 4];
int x[MAXN], pre[MAXN];

void pull(int id)
{
	seg[id].sum = seg[id * 2].sum + seg[id * 2 + 1].sum;
	seg[id].mx = max(seg[id].sum, max(seg[id * 2].sum, seg[id * 2 + 1].sum));
}

void build(int id, int l, int r)
{
	seg[id].id = id, seg[id].l = l, seg[id].r = r;
	int mid = (l + r) / 2;
	if(l == r)
	{
		seg[id].sum = x[l];
		seg[id].mx = x[l];
		return;
	}
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	pull(id);
}

void update(int id, int tar, int val)
{
	int l = seg[id].l, r = seg[id].r;
	if(tar > r || tar < l)
		return;
	if(l == r)
	{
		x[l] = val;
		seg[id].sum = val;
		seg[id].mx = val;
		return;
	}
	update(id * 2, tar, val);
	update(id * 2 + 1, tar, val);
	pull(id);
}

int query(int id, int ql, int qr)
{
	int l = seg[id].l, r = seg[id].r;
	if(ql <= l && r <= qr)
		return seg[id].sum;
	if(ql > r || qr < l)
		return -INF;
	return max(query(id * 2, ql, qr), query(id * 2 + 1, ql, qr));
}
struct BIT{
	#define MAXN 200005
	int arr[MAXN];
	int query(int x)
	{
		int sum = 0;
		while(x)
		{
			sum += arr[x];
			x -= lowbit(x);
		}
		return sum;
	}
	void update(int x, int val)
	{
		while(x < MAXN)
		{
			arr[x] += val;
			x += lowbit(x);
		}
	}
}BIT;

void sol()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> x[i];
		pre[i] = x[i] + pre[i - 1];
		BIT.update(i, x[i]);
		// cout << pre[i] << " ";
	}
	build(1, 1, n);
	int k, a, b;
	while(m--)
	{
		cin >> k >> a >> b;
		if(k == 1)		
		{
			update(1, a, b);
		}
		else
		{
			// for(int i = 1; i < 16; i++)
				// cout << seg[i].mx << endl;
			cout << query(1, a - 1, b) + BIT.query(a - 1) << endl;
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