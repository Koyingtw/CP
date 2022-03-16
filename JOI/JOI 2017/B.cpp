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
const int INF = 0x3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
#pragma endregion
/******************************************************************************/
#define MAXN 100005
#define MAXM 3005
int n, m, k, t;
int A, B, C;
int x[MAXM];
pii dis[MAXM];

void sol2()
{
	int ans = 0;
	for(int i = 2; i < n; i++)
	{
		int ouo = 0;
		// if(binary_search(x, x + m, i)) continue;
		for(int j = i + 1; j <= n; j++)
		{
			// if(binary_search(x, x + m, j)) continue;	
			int cnt = 0;			
			for(int k = 2; k <= n; k++)
			{
				int tmp = dis[k].F;
				int F = upper_bound(x, x + m, k) - x;
				F--;
				if(F >= 0)
				{
					cmin(tmp, A * (k - x[F]) + dis[x[F]].F);
				}
				
				if(upper_bound(x, x + m, i) - x - 1 != -1 && i <= k)
					cmin(tmp, A * (abs(k - i)) + C * abs(i - (x[upper_bound(x, x + m, i) - x - 1])) + dis[x[upper_bound(x, x + m, i) - x - 1]].F);
				if(upper_bound(x, x + m, j) - x - 1 != -1 && j <= k)
					cmin(tmp, A * (abs(k - j)) + C * abs(j - (x[upper_bound(x, x + m, j) - x - 1])) + dis[x[upper_bound(x, x + m, j) - x - 1]].F);
				
				if(tmp <= t)
					cnt++;
				// cout << tmp << " ";
			}
			// cout << endl;
			// if(cnt > ans)
				// cout << i << " " << j << endl;
			cmax(ans, cnt);
		}
		// cout << i << " " << ouo << endl;
	}
	cout << ans << endl;
}

void find_dist()
{
	for(int i = 0; i < MAXM; i++)
		dis[i] = {INF, INF};
	dis[1] = {0, 0};
	for(int i = 1; i < m; i++)
	{
		dis[x[i]].F = B * (x[i] - 1);
		dis[x[i]].S = 0;
	}
	for(int i = 2; i <= n; i++)
	{
		cmin(dis[i].F, A * (i - 1));
		int F = upper_bound(x, x + m, i) - x;
		F--;
		if(F == -1) continue;
		cmin(dis[i].F, dis[x[F]].F + A * (abs(x[F] - i)));
		cmin(dis[i].S, abs(x[F] - i));
	}
	for(int i = 1; i <= n; i++)
		cout << dis[i].F << " ";
	cout << endl;
	// for(int i = 1; i <= n; i++)
		// cout << dis[i].S << " ";
	// cout << endl;
}



void sol()
{
	cin >> n >> m >> k;
	cin >> A >> B >> C;
	cin >> t;
	set<int> s;
	for(int i = 0; i < m; i++)
	{
		cin >> x[i];
	}
	find_dist();
	
	if(0)
	{
		sol2();
		return;
	}
	else
	{
		int ans = 0;
		int l = t, r = INF, mid = (l + r) / 2;
		while(l < r)
		{
			int cnt = 0, ouo = k - m, pre = 1, tmp = 0;
			mid = (l + r) / 2;
			cout << mid << endl;
			for(int i = 2; i <= n; i++)
			{
				if(tmp + (i - pre) * A <= t)
				{
					cnt++;
					// continue;
				} 
				// if(i < x[0]) continue;
				if(binary_search(x, x + m, i))
					continue;
				if(tmp + (i - pre) * A >= mid)
				{
					int awa = tmp + (i - pre) * A;
					if(ouo <= 0)
					{
						ouo--;
						continue;
					}
					tmp = tmp + (i - pre) * C;
					pre = i;
					if(tmp <= t && awa > t) cnt++;
					ouo--;
					cout << i << " ";
				}
			}
			cout << cnt << endl;
			cmax(ans, cnt);
			if(ouo >= 0)
			{
				r = mid;
			}
			else l = mid + 1;
		}
		cout << ans << endl;
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