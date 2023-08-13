#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define ll long long
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
#define SZ(v) ((int)v.size())
#if !LOCAL
#define endl "\n"
#pragma GCC optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int x[MAXN];
int y[MAXN];
int pre[MAXN];

void sol() {
    cin >> n >> m;
    int ans = 0;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        y[i] = x[i];
        cmax(ans, x[i]);
        cmax(mx, x[i] + i);
    }


    for (int i = 1; i < n; i++) {

        int l = x[i] + 1, r = 1e9;
        while (l <= r) {
            for (int j = 1; j <= n; j++)
                y[j] = x[j];
            int mid = (l + r + 1) / 2;
            int tmpm = m;

            if (y[i] < mid) {
                if (i == n - 1 && mid > y[n] + 1)
                    tmpm = -INF;
                tmpm -= mid - y[i];
                y[i] = mid;
            }
            // y[i] += tmp;
            for (int j = i + 1; j < n; j++) {
                if (y[j] < y[j - 1] - 1) {
                    tmpm -= y[j - 1] - y[j] - 1;
                    y[j] = y[j - 1] - 1;
                    if (j == n - 1 && y[n] < y[j] - 1)
                        tmpm = -INF;
                }
                else
                    break;
            }
            if (tmpm >= 0) {
                cmax(ans, y[i]);
                if (l == r)
                    break;
                l = mid;
            }
            else
                r = mid - 1;
                
        }
    }



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