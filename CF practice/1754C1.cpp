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
int x[MAXN], from[MAXN];
int pre[2][MAXN];

void sol() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        from[i] = INF;
        if (i % 2) {
            pre[0][i] = pre[0][i - 1] - x[i];
            pre[1][i] = pre[1][i - 1] + x[i];
        }
        else {
            pre[0][i] = pre[0][i - 1] + x[i];
            pre[1][i] = pre[1][i - 1] - x[i];
        }
    }

    if (n % 2) {
        cout << -1 << endl;
        return;
    }

    vector<pii> ans;

    for (int i = 1; i <= n; i += 2) {
        if (x[i] == x[i + 1]) {
            ans.pb({i, i + 1});
        }
        else {
            ans.pb({i, i});
            ans.pb({i + 1, i + 1});
        }
    }
    cout << ans.size() << endl;
    for (auto it: ans)
        cout << it.F << ' ' << it.S << endl;
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