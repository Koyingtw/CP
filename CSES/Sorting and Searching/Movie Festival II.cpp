// Problem: Movie Festival II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1632
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
pii a[MAXN];

bool cmp(pii a, pii b)
{
	if(a.S != b.S)
		return a.S < b.S;
	else return a.F < b.F;
}
void sol()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> a[i].F >> a[i].S;
	sort(a, a + n, cmp);
	multiset<int> s;
	int ans = 0;
	for(int i = 0; i < m; i++) s.insert(0);
	
	for(int i = 0; i < n; i++)
	{
		auto it = s.upper_bound(a[i].F);
		if(it == s.begin()) continue;
		s.erase(--it);
		s.insert(a[i].S);
		ans++;
	}
	put(ans);
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