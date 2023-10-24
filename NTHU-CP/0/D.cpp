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
int x[MAXN], y[MAXN];
int ans[MAXN];

void sol() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        char c;
        cin >> c;
        y[i] = (c == 'R' ? 1 : -1);
    }
    ans[0] = n;
    for (int k = 1; k <= 100; k++) {
        ans[k] = ans[k - 1];
        for (int i = 0; i < n; i++) {
            x[i] += y[i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (x[i] == x[j]) {
                    y[i] *= -1;
                    y[j] *= -1;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (x[i] == 1 || x[i] == m) {
                ans[k]--;
                x[i] = INF;
            }
        }
    }

    int t;
    cin >> t;
    int q;
    while (t--) {
        cin >> q;
        cout << ans[q] << '\n';
    }
}

signed main() {
    Weakoying;
    int t = 1;
    //while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}