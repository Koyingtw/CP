// Problem: B. Drazil and His Happy Friends
// Contest: Codeforces - Codeforces Round #292 (Div. 2)
// URL: https://codeforces.com/contest/515/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
#define MAXN 105
#define MAXM 1000005 
int n, m;
bitset<MAXN> x, y;
void sol()
{
	cin >> n >> m;
	int a, b;
	cin >> a;
	while(a--)
	{
		cin >> b;
		x[b] = 1;
	}
	cin >> a;
	while(a--)
	{
		cin >> b;
		y[b] = 1;
	}
	for(int i = 0; i < n * m * n * m; i++)
	{
		if(x[i % n] || y[i % m])
		{
			x[i % n] = y[i % m] = true;
		}
	}
	bool yes = 1;
	for(int i = 0; i < n; i++)
		yes &= x[i];
	for(int i = 0; i < m; i++)
		yes &= y[i];
	if(yes) cout << "Yes" << endl;
	else cout << "No" << endl;
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