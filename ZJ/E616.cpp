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
int x[MAXN];
void sol()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{ 
		cin >> x[i];
	}
	sort(x, x + n);
	int l = 1, r = INF, mid = (l + r) / 2;
	while(l < r)
	{
		mid = (l + r + 1) / 2;
		int cnt = 1;
		int now = 0;
		for(int i = 1; i < n; i++)
		{
			if(x[i] - x[now] >= mid)
			{
				cnt++;
				now = i;
			}
		}
		if(cnt >= m)
			l = mid;
		else r = mid - 1;
	}
	cout << l << endl;
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