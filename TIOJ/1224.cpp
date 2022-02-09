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
#define MAXN 100005
#define MAXM 1000005 
int n, m;
struct Node
{
	int l, r, sum, tag;
	void update(int val)
	{
		sum = val * (r - l + 1);
		tag += val;
	}
}seg[MAXM << 2];

void pull(int id)
{
	if(seg[id].tag)
		seg[id].update(1);
	else if(seg[id].l != seg[id].r)
		seg[id].sum = seg[id * 2].sum + seg[id * 2 + 1].sum;
	else seg[id].sum = 0;
}

void build(int id, int l, int r)
{
	seg[id] = {l, r, 0, 0};
	if(l == r) return;
	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
}
void update(int id, int ql, int qr, int val)
{
	int l = seg[id].l, r = seg[id].r;
	if(ql <= l && r <= qr)
	{
		seg[id].tag += val;
		pull(id);
		return;
	}
	if(ql > r || qr < l)
		return;
	update(id * 2, ql, qr, val);
	update(id * 2 + 1, ql, qr, val);
	pull(id);
}

struct in
{
	int l, d, u, val;
};

vector<in> x;
bool cmp(in a, in b)
{
	return a.l < b.l;
}

void sol()
{
	cin >> n;	
	for(int i = 1, l, r, d, u; i <= n; i++)
	{
		cin >> l >> r >> d >> u;
		x.pb({l, d + 1, u, 1});
		x.pb({r, d + 1, u, -1});
	}
	build(1, 1, MAXM);
	sort(x.begin(), x.end(), cmp);
	int now = 0, ans = 0;
	for(int i = 0; i < x.size(); i++)
	{
		if(x[i].l != now)
		{
			ans += 1ll * (x[i].l - now) * seg[1].sum;
			now = x[i].l;
		}
		update(1, x[i].d, x[i].u, x[i].val);
	}
	put(ans)
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