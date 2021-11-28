// Problem: Sliding Cost
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1077
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
int a[MAXN];
void sol()
{
	cin >> n >> m;
	multiset<int> sm, big;
	int sum1 = 0, sum2 = 0;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++)
	{
		if(big.size() && a[i] >= *big.begin())
		{
			big.insert(a[i]);
			sum2 += a[i];
		}
		else 
		{
			sm.insert(a[i]);
			sum1 += a[i];	
		}
		while(sm.size() > big.size())
		{
			int tmp = *prev(sm.end());
			big.insert(tmp);
			sum2 += tmp;
			sm.erase(sm.find(tmp));
			sum1 -= tmp;
		}
		while(big.size() > sm.size())
		{
			int tmp = *big.begin();
			sm.insert(tmp);
			sum1 += tmp;
			big.erase(big.find(tmp));
			sum2 -= tmp;
		}
		if(sm.size() + big.size() == m)
		{
			int mid = *prev(sm.end());
			int ans = sum2 - mid * big.size();
			ans += mid * sm.size() - sum1;
			cout << ans << " ";
			if(big.size() && a[i - m + 1] >= *big.begin())
			{
				big.erase(big.find(a[i - m + 1]));
				sum2 -= a[i - m + 1];
			}
			else
			{
				sm.erase(sm.find(a[i - m + 1]));
				sum1 -= a[i - m + 1];
			}
			
		}
	}
	cout << endl;
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