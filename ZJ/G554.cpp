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
int n, m, timestamp = 1, cnt = 1, tar;
int D[MAXN], L[MAXN], SCCID[MAXN], in[MAXN];
bitset<MAXN> inSt;
vector<int> G[MAXN];
set<int> SCC[MAXN], vis[MAXN];
stack<int> st;

void dfs(int i, int fa)
{
	st.push(i);
	inSt[i] = true;
	D[i] = L[i] = timestamp++;
	
	for(int e: G[i])
	{
		if(!D[e])
		{
			dfs(e, i);
			L[i] = min(L[i], L[e]);
		}
		else if(inSt[e])
			L[i] = min(L[i], D[e]);
	}
	if(D[i] == L[i])
	{
		int a;
		do
		{
			a = st.top();
			st.pop();
			inSt[a] = false;
			SCCID[a] = cnt;
			if(a == 1) tar = cnt;
		}while(a != i);
		cnt++;
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
	dfs(1, 1);
	for(int i = 1; i <= n; i++)
	{
		for(int e: G[i])
		{
			if(SCCID[i] != SCCID[e] && !SCC[SCCID[e]].count(SCCID[i]))
			{
				SCC[SCCID[e]].insert(SCCID[i]);
				in[SCCID[i]]++;
			}
		}
	}
	queue<int> q;
	vector<int> topo;
	sort(in + 1, in + cnt);
	bool ans = 1;
	for(int i = 1; i < cnt; i++) if(in[i] != i - 1) ans = 0;
	cout << (ans && in[SCCID[1]] == 0 ? "Yes": "No") << endl;
	return;
	if(!in[SCCID[1]]) q.push(SCCID[1]);
	bool yes = q.size() < 2;
	while(q.size())
	{
		int now = q.front();
		bool has = 0;
		q.pop();
		yes &= (q.size() < 2);
		topo.pb(now);
		in[now] = INF;
		for(int e: SCC[now])
		{
			in[e]--;
			if(!in[e])
			{
				q.push(e);
				if(has)
				{
					yes = 0;
					//break;
				}
				has = 1;
			}
		}
		yes &= (q.size() < 2);
	}
	if(topo.size() == cnt - 1 && yes)
		cout << "Yes" << endl;
	else cout << "No" << endl;
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