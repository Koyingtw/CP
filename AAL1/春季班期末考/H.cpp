// Problem: H. 特制乘法表
// Contest: Codeforces - 2021 AA 競程 Level 1 春季期末考
// URL: https://codeforces.com/gym/331434/problem/H
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma region
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
int n, t;

int f(int m, int i)
{
	int l = 0, r = n, mid = (l + r) / 2;
	return m / (i * (i + 1));
}

void sol()
{
	cin >> n >> t;
    // cout << f(4, 1) << endl;
	while(t--)
	{
		int q;
		cin >> q;
		q = n * n - q;
	    int l = 0, r = n * n * (n + 1), m = (l + r) >> 1;
	    while (l < r)
	    {
	        int cnt = 0;
	        m = (l + r) >> 1;
	        for (int i = 1; i <= n; i++)
	        {
	            cnt += min(f(m, i), n);
	            //cout << f(m, i) << endl;
	        }
	        if (cnt > q)
	        {
	            r = m;
	        }
	        else
	            l = m + 1;
	        // cout << m << " " << cnt << endl;
	    }
	    cout << r << endl;
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