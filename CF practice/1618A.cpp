// Problem: A. Polycarp and Sums of Subsequences
// Contest: Codeforces - Codeforces Round #760 (Div. 3)
// URL: https://codeforces.com/contest/1618/problem/A
// Memory Limit: 256 MB
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
#define MAXN 100005
#define MAXM 1000005 
int n, m;

void sol()
{
	int x[7];
	n = 7;
	for(int i = 0; i < n; i++)
		cin >> x[i];
	do
	{
		map<int, int> mp;
		for(int i = 3; i < n; i++)
			mp[x[i]]++;
		bool yes = 1;
		if(mp[x[0] + x[1]])
			mp[x[0] + x[1]]--;
		else yes = 0;
		if(mp[x[2] + x[1]])
			mp[x[2] + x[1]]--;
		else yes = 0;
		if(mp[x[0] + x[2]])
			mp[x[0] + x[2]]--;
		else yes = 0;
		if(mp[x[0] + x[1] + x[2]])
			mp[x[0] + x[1] + x[2]]--;
		else yes = 0;
		if(yes)
		{
			cout << x[0] << " " << x[1] << " " << x[2] << endl;
			break;
		}
	}while(next_permutation(x, x + n));
}

signed main()
{
    Weakoying;
    int t = 1;
    while (cin >> t)
    {
    	while (t--)
        {
            sol();
        }
    }
        
    return 0;
}