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
int x[MAXN], pre[MAXN];


void sol()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> x[i];
	for(int i = 1; i <= n; i++)
	{
		pre[i] = pre[i - 1] + x[i];
		// cout << pre[i - 1] << " ";
	}
	// cout << endl;
	int t, k;
	int goin = 0;
	int l = 1;
	vector<int> v;
	while(m--)
	{
		cin >> t >> k;
		if(t == 1)
		{
			int id = lower_bound(pre + l, pre + n + 1, pre[l - 1] + k) - pre;
			k -= (pre[id - 1] - pre[l - 1]);
			int cnt = 0;
			k--;
			for(int it: v)
				if(it < x[id])
					cnt += it;
			cnt %= x[id];
			cout << (k + x[id] - cnt) % x[id] + pre[id - 1] + 1 << endl;
			goin = 0;
		}
		else
		{
			goin += pre[l + k - 1] - pre[l - 1];
			v.pb(pre[l + k - 1] - pre[l - 1]);
			l += k;
		}
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