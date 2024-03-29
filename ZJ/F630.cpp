#pragma region
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
#define MAXN 2505
#define MAXM 1000005 
int n, m;
bitset<MAXN> G[MAXN];
bitset<MAXN> zero;
void sol()
{
	cin >> n;
	int ans = 0;
	for(int i = 1, a; i <= n; i++)	
	{
		cin >> a;
		for(int j = 0, b; j < a; j++)
		{
			cin >> b;
			G[i][b] = 1;
		}
	}
	for(int i = 1; i < n; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			bitset<MAXN> tmp = G[i] & G[j];
			ans += (tmp != zero);
		}
	}
	cout << ans << endl;
	
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