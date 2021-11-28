// Problem: Two Sets
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1092
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
#define MAXN 1000005
#define MAXM 1000005 
int n, m;
int x[MAXN];
void sol()
{
	cin >> n;
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		x[i] = i + 1;
		sum += x[i];
	}
	if(sum & 1)
	{
		cout << "NO" << endl;
		return;
	}
	set<int> s1, s2;
	int a = 0, b = 0;
	sort(x, x + n, greater<int>());
	for(int i = 0; i < n; i++)
	{
		if(a + x[i] <= sum / 2)
		{
			s1.insert(x[i]);
			a += x[i];
		}
		else
		{
			s2.insert(x[i]);
			b += x[i];
		}
	}
	cout << "YES" << endl;
	cout << s1.size() << endl;
	for(int it: s1) cout << it << " ";
	cout << endl;
	
	cout << s2.size() << endl;
	for(int it: s2) cout << it << " ";
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