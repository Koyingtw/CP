// Problem: B. 有怪獸，有怪獸，纏著我～
// Contest: Codeforces - 2021 AA 競程 秋季 Level 1 期末測驗
// URL: https://codeforces.com/gym/356593/problem/B
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
#define MAXN 10005
#define MAXM 1000005 
int n, m;
double x[MAXN];
void sol()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
		cin >> x[i];
	sort(x, x + m);
	int sum = 0;
	int ans = 0;
	double tmp = n;
	double now = n;
	do
	{
		for(int i = 0; i < m; i++)
		{
			now = (int)(long double)(now * (100.0 - x[i]) * 0.01);
			sum += tmp - now;
			tmp = now;
		}
		cmax(ans, sum);
		//put(sum)
		sum = 0;
		tmp = n;
		now = n;		
	}
	while(next_permutation(x, x + m));
	put(ans);
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