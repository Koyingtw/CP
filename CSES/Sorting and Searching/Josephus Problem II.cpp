// Problem: Josephus Problem I
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2162
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
}B;
void sol()
{
	cin >> n >> m;
	m++;
	MEM(B.arr, 0);
	for(int i = 1; i <= n; i++) B.update(i, 1);
	int now = 0, tar = m;
	for(int i = 0; i < n; i++)
	{
		tar = m;
		if(B.query(n) - B.query(now) < tar)
		{
			tar -= (B.query(n) - B.query(now));
			now = 0;
		}
		tar %= B.query(n);
		if(tar == 0) tar = B.query(n);
		int l = now, r = n, mid = (l + r) / 2;
		while(l < r)
		{
			mid = (l + r) / 2;
			if(B.query(mid) - B.query(now) >= tar)
				r = mid;
			else l = mid + 1;
		}
		cout << l << " ";
		now = l ;
		B.update(now, -1);
	}
	cout << endl;
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