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
int pre[2][MAXN];

void sol() {
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        cnt += abs(x[i]);
        if (i % 2) {
            pre[0][i] = pre[0][i - 1] - x[i];
            pre[1][i] = pre[1][i - 1] + x[i];
        }
        else {
            pre[0][i] = pre[0][i - 1] + x[i];
            pre[1][i] = pre[1][i - 1] - x[i];
        }
    }
    if (cnt % 2) {
        cout << -1 << endl;
        return;
    }
    if (pre[1][n] == 0) {
        cout << 1 << endl;
        cout << 1 << " " << n << endl;
        return;

    }

    vector<pii> ans;

    for (int i = 1; i <= n; i++) {
        cnt = 0;
        int sum = 0;
        vector<int> tmp, tmp1;
        for (int j = i; j <= n; j++) {
            cnt += abs(x[j]);
            tmp.pb(x[j]);

            if (tmp.size() % 2)
                sum += x[j];
            else
                sum -= x[j];

            if (cnt % 2 == 0 || j == n) {
                if (sum == 0) {
                    ans.pb({i, j});
                }
                else {
                    for (int k = i; k < j; k++) {
                        int sum = pre[i % 2][k] - pre[i % 2][i - 1];
                        if (pre[(k + 1) % 2][j] - pre[(k + 1) % 2][k] == -sum) {
                            // cout << sum << ' ' << pre[(k + 1) % 2][j] - pre[(k + 1) % 2][k] << endl;
                            ans.pb({i, k});
                            ans.pb({k + 1, j});
                            break;
                        }
                    }
                }
                i = j;
                break;
            }
        }
    }

    cout << ans.size() << endl;
    for (auto i : ans) {
        cout << i.F << ' ' << i.S << endl;
    }

    // assert(ans.back().S == n);
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