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
#define MAXN 1000005
#define MAXM 1000005 
int n, m;
vector<int> G[MAXN];
pii in[MAXN];
void sol()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		in[i].S = i;
	for(int i = 0, a, b; i < m; i++)
	{
		cin >> a >> b;
		G[a].pb(b);
		in[b].F++;
	}
	queue<int> q;
	vector<int> ans;
	for(int i = 1; i <= n; i++)
		if(!in[i].F)
		{
			q.push(i);
			break;
		}
	while(q.size())
	{
		int now = q.front();
		q.pop();
		ans.pb(now);
		in[now].F = -INF;
		for(int e: G[now])
		{
			in[e].F--;
		}
		for(int e: G[now])
			if(!in[e].F)
			{
				q.push(e);
				in[e].F = -INF;
				break;
			}
	}

	
	if(ans.size() != n) cout << -1 << endl;
	else 
	{
		for(int it: ans)
			cout << it << " ";
		cout << endl;
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