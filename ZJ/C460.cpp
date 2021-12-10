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
map<int, int> mp[3];
void sol()
{
	cin >> n;
	for(int i = 0, a, b, c, d, tmp; i < n; i++)
	{
		cin >> a >> b >> c >> d;
		a--;
		tmp = 0;
		tmp = b * (1 << 0) + c * (1 << 1) + d * (1 << 2);
		mp[a][tmp]++;
	}
	int ans = 0;
	for(auto i: mp[0])
	{
		for(auto j: mp[1])
		{
			for(auto k: mp[2])
			{
				if((i.F | j.F | k.F) == 7)
					ans += (i.S * j.S * k.S);
			}
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