// Problem: Collecting Numbers II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2217
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
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int x[MAXN], pos[MAXN];
void sol()
{
	cin >> n >> m;
	pos[0] = 0;
	pos[n + 1] = n + 1;
	for(int i = 0; i < n; i++) 
	{
		cin >> x[i];
		pos[x[i]] = i + 1;
	}
	int ans = 1;
	for(int i = 2; i <= n; i++) 
		ans += pos[i] < pos[i - 1];
		
	int a, b;
	while(m--)
	{
		cin >> a >> b;
		a--, b--;
		int ouo = 0;
		if(x[a] > 1)
			ouo -= pos[x[a]] < pos[x[a] - 1];
		if(x[a] != n)
			ouo -= pos[x[a] + 1] < pos[x[a]];
		if(x[b] > 1 && x[b] - x[a] != 1)
			ouo -= pos[x[b]] < pos[x[b] - 1];
		if(x[b] != n && x[b] - x[a] != -1)
			ouo -= pos[x[b] + 1] < pos[x[b]];
		swap(pos[x[a]], pos[x[b]]);
		swap(x[a], x[b]);
		if(x[a] > 1)
			ouo += pos[x[a]] < pos[x[a] - 1];
		if(x[a] != n)
			ouo += pos[x[a] + 1] < pos[x[a]];
		if(x[b] > 1 && x[b] - x[a] != 1)
			ouo += pos[x[b]] < pos[x[b] - 1];
		if(x[b] != n && x[b] - x[a] != -1)
			ouo += pos[x[b] + 1] < pos[x[b]];
		ans += ouo;
		put(ans);
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