// Problem: Exponentiation II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1712
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
#define MAXN 100005
#define MAXM 1000005 
int n, m;

int p(int a, int b, int c)
{
	if(b == 0) return 1;
	stack<int> st;
	while(b)
	{
		st.push(b & 1);
		b /= 2;
	}
	st.pop();
	int ans = a;
	while(st.size())
	{
		int now = st.top();
		ans *= ans;
		ans %= c;
		if(now) ans *= a;
		ans %= c;
		st.pop(); 
	}
	return ans % c;
}

void sol()
{
	int a, b, c;
	cin >> a >> b >> c;
	b = p(b, c, P - 1);
	cout << p(a, b, P) % P << endl;
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