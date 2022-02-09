#pragma GCC optimize("O3")
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
#define all(v) v.begin(), v.end()
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 100005
#define MAXM 1000005 
int n, m;
int x[25][25];

void sol()
{
	cin >> n >> m;
	vector<int> v;
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		int mx = 0;
		for(int j = 0; j < m; j++)
		{
			cin >> x[i][j];
			mx = max(mx, x[i][j]);
		}
		sum += mx;
		v.push_back(mx);
	}	
	cout << sum << endl;
	bool yes = 0;
	for(int it: v)
	{
		if(sum % it == 0)
		{
			if(yes) cout << " ";
			cout << it;
			yes = 1;
		}
	}
	if(!yes) cout << -1 << endl;
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