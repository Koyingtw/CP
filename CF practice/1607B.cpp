// Problem: B. Odd Grasshopper
// Contest: Codeforces - Codeforces Round #753 (Div. 3)
// URL: https://codeforces.com/contest/1607/problem/B
// Memory Limit: 256 MB
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

int f(int x)
{
	return (x + 1) * x / 2;
}
void sol()
{
	int x0, n;
	cin >> x0 >> n;
	if(x0 % 2)
	{
		if(n % 4ll == 1)
		{
			x0 += n;
		}
		else if(n % 4ll == 2)
		{
			x0--;
		}
		else if(n % 4ll == 3)
		{
			x0 -= n + n - 1 - (n - 2);
		}
	}
	else
	{
		if(n % 4ll == 1)
		{
			x0 -= n;
		}
		else if(n % 4ll == 2)
		{
			x0++;
		}
		else if(n % 4ll == 3)
		{
			x0 += n + n - 1 - (n - 2);
		}
	}
	put(x0);
}

signed main()
{
    Weakoying;
    int t = 1;
    while (cin >> t)
    {
    	while (t--)
        {
            sol();
        }
    }
        
    return 0;
}