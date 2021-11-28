// Problem: Road Reparation
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1675/
// Memory Limit: 128 MB
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
#define put(x) cout << x << endl
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
#define MAXM 200005 
int n, m;
int dsu[MAXN], cnt[MAXN];
void init()
{
	for(int i = 0; i < MAXN; i++)
		dsu[i] = i, cnt[i] = 1;
}
int find(int x)
{
	if(dsu[x] == x) return x;
	return dsu[x] = find(dsu[x]);
}
void modify(int x, int y)
{
	int a = find(x), b = find(y);
	if(cnt[a] < cnt[b])
	{
		swap(x, y);
		swap(a, b);
	}
	dsu[b] = a;
	cnt[a] += cnt[b];
}

struct Node
{
	int a, b, c;
}G[MAXN];

bool cmp(Node a, Node b)
{
	if(a.c != b.c) return a.c < b.c;
	else return a.a < a.b;
}

void sol()
{
	cin >> n >> m;
	int sum = 0;
	init();
	for(int i = 0; i < m; i++)
	{
		cin >> G[i].a >> G[i].b >> G[i].c;
	}
	sort(G, G + m, cmp);
	int cons = n;
	for(int i = 0; i < m; i++)
	{
		if(cons == 1) break;
		if(find(G[i].a) != find(G[i].b))
		{
			sum += G[i].c;
			modify(G[i].a, G[i].b);
			cons--;
		}
	}
	if(cons > 1) put("IMPOSSIBLE");
	else cout << sum << endl;
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