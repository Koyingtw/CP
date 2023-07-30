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
#define DB(x) cerr << #x << " " << x << endl
#define all(v) v.begin(), v.end()
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#pragma optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int x[MAXN];
int ans = INF;

void dfs(int i, int now, int dep) {
    if (now == 1) {
        cmin(ans, dep);
        return;
    }
    if (dep > ans)
        return;
    if (i >= n)
        return;

    dfs(i + 1, __gcd(now, i + 1), dep + n - i);
    dfs(i + 1, now, dep);
}

void sol() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }



    int gcd;
    int cost = 0;
    for (int j = 0; j < n; j++) {
        if (j == 0) {
            gcd = x[j];
        }
        else {
            gcd = __gcd(gcd, x[j]);
        }
    }


    ans = n;

    dfs(0, gcd, 0);
    
    cout << ans << endl;
}

signed main() {
    Weakoying;
    int t = 1;
    while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}