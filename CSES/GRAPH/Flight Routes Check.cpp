// Problem: Flight Routes Check
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1682
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
vector<int> G[MAXN];
bitset<MAXN> inSt;
stack<int> st;
int timestamp = 0, D[MAXN], L[MAXN], con[MAXN], SCCID = 0;

void dfs(int v, int fa)
{
	D[v] = L[v] = ++timestamp;
	st.push(v);
	inSt[v] = true;
	
	for(int w: G[v])
	{
		if(!D[w])
		{
			dfs(w, v);
			cmin(L[v], L[w]);
		}
		else if(inSt[w])
			cmin(L[v], D[w]);
	}
	if(D[v] == L[v])
	{
		SCCID++;
		int x = -1;
		do
		{
			x = st.top();
			st.pop();
			inSt[x] = false;
			con[x] = SCCID;
		}while(x != v);
	}
}

void sol()
{
	cin >> n >> m;
	for(int i = 0, a, b; i < m; i++)
	{
		cin >> a >> b;
		G[a].pb(b);
	}
	for(int i = 1; i <= n; i++)
	{
		if(!D[i])
			dfs(i, i);
	}
	if(SCCID == 1) 
	{
		cout << "YES" << endl; 
		return;
	}
	for(int i = 1; i <= n; i++)
	{
		for(int w: G[i])
		{
			if(con[i] != con[w])
			{
				cout << "NO" << endl;
				cout << w << " " << i << endl;
				return;
			}
		}
	}
	for(int i = 2; i <= n; i++)
	{
		if(con[i] != con[1])
			cout << "NO\n" << i << " 1" << endl;
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