#pragma GCC optimize("O3")
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
#define all(v) v.begin(), v.end()
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 2005
#define MAXM 1000005 
int n, m, cnt = 0, sum = 0;
int D[MAXN], L[MAXN];
bool isAP[MAXN];
vector<int> G[MAXN];

void init() {
	MEM(isAP, 0);
	MEM(L, 0);
	MEM(D, 0);
	for(int i = 1; i <= n; i++)
		G[i].clear();
	cnt = 0;
	sum = 0;
}

void dfs(int i, int fa) {
	D[i] = L[i] = ++cnt;
	int chd = 0;
	for (int e: G[i]) {
		if (e == fa) continue;
		if (!D[e]) {
			chd++;
			dfs(e, i);
			cmin(L[i], L[e]);
			if (L[e] >= D[i] && fa != -1) {
				isAP[i] = true;
			}
		}
		else if(D[e] < D[i])
			cmin(L[i], D[e]);
	}
	if (fa == -1 && chd > 1)
		isAP[i] = true;
}

void sol()
{
	cin >> n >> m;
	init();
	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}
	dfs(1, -1);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (isAP[i]) {
			sum++;
		}
	}
	ans = sum * (n - sum);
	ans += sum * (sum - 1) / 2;
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