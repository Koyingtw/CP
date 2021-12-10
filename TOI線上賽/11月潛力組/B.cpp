#pragma region
#pragma optimize("O3")
#include <iostream>
#include <algorithm>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int short
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

using namespace std;
#pragma endregion
/******************************************************************************/
#define MAXN 4005
#define MAXM 1000005 
int n, m;
struct in
{
	int F, S, id;
}x[MAXN];

bool cmp(in a, in b)
{
	if(a.S - a.F != b.S - b.F)
		return a.S - a.F < b.S - b.F;
	else return a.id < b.id;
}

void sol()
{
	cin >> n >> m;
	for(int i = 0; i < n + m; i++)
	{
		cin >> x[i].F >> x[i].S;
		x[i].id = i;
	}
	signed ans = 0;	
	sort(x, x + n + m, cmp);
	for(int i = 0; i < m; i++)
	{
		ans += x[i].S;
	}
	for(int i = m; i < n + m; i++)
		ans += x[i].F;
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