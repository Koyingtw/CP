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
int n, m, x, y, d;

void sol() {
    cin >> n >> m >> x >> y >> d;
    int ans = n + m - 2;
    int good[2] = {1, 1};
    int legal = 2;
    for (int i = 1; i <= m; i++) {
        if (abs(1 - x) + abs(i - y) <= d) {
            good[0]--;
            // cout << 1 << ' ' << i << endl;
            break;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (abs(i - x) + abs(m - y) <= d) {
            good[1]--;
            // cout << i << ' ' << 1 << endl;
            break;
        }
    }

    if (good[0] == 0 || good[1] == 0)
        legal--;
    good[0] = good[1] = 1;
    for (int i = 1; i <= m; i++) {
        if (abs(n - x) + abs(i - y) <= d) {
            good[0]--;
            // cout << n << ' ' << i << endl;
            break;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (abs(i - x) + abs(1 - y) <= d) {
            good[1]--;
            // cout << i << ' ' << m << endl;
            break;
        }
    }

    if (good[0] == 0 || good[1] == 0)
        legal--;
    if (!legal)
        ans = -1;
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