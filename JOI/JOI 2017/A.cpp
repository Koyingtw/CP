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
int n, q, s, t;

int x[MAXN], pre[MAXN];

int f(int i)
{
	int rtn = 0;
	if(i > 0)
		rtn -= i * s;
	else rtn -= i * t;
	return rtn;
}

void sol()
{
	cin >> n >> q >> s >> t;
	for(int i = 0; i <= n; i++)
	{
		cin >> x[i];
		if(i)
			pre[i] = x[i] - x[i - 1];
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		ans += f(pre[i]);
	}
	// cout << ans << endl;
	int l, r, v;
	while(q--)
	{
		cin >> l >> r >> v;
		
		int tmp = (v > 0 ? 1 : -1);
		if(pre[l] > 0)
		{
			int after = pre[l] + v;
			if(after < 0)
			{
				ans -= f(pre[l]);
				ans += f(after);
			}
			else
			{
				ans -= f(pre[l]);		
				ans += f(after);
			}
			
			pre[l] = after;
		}
		else // < 0
		{
			int after = pre[l] + v;
			if(after > 0)
			{
				ans -= f(pre[l]);
				ans += f(after);
			}
			else
			{
				ans -= f(pre[l]);
				ans += f(after);
			}
			pre[l] = after;
		}
		// cout << ans << " ";
		if(r != n) 
		{
			if(pre[r + 1] > 0)
			{
				int after = pre[r + 1] - v;
				if(after < 0)
				{
					ans -= f(pre[r + 1]);
					ans += f(after);
				}
				else
				{
					
					ans -= f(pre[r + 1]);
					ans += f(after);
				}
				pre[r + 1] = after;
			}
			else
			{

				int after = pre[r + 1] - v;
				if(after > 0)
				{
					
					ans -= f(pre[r + 1]);
					ans += f(after);
				}
				else
				{
					
					ans -= f(pre[r + 1]);
					ans += f(after);
				}
				pre[r + 1] = after;
			}
		}
		tmp = -tmp;
		
		cout << ans << endl;
		// for(int i = 1; i <= n; i++)
			// cout << pre[i] << " ";
		// cout << endl;
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