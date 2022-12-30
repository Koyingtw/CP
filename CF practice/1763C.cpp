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
#define SZ(v) ((int)v.size())
#if !LOCAL
#define endl "\n"
#pragma GCC optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int x[MAXN];


void sol() {
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }

    if (n == 1) {
        cout << x[1] << endl;
    }
    else if (n == 2) {
        cout << max(x[1] + x[2], abs(x[1] - x[2]) * 2) << endl;
    }
    else if (n == 3) {
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans += x[i];
        vector<pii> op = {{1, 2}, {1, 2}, {2, 3}, {2, 3}, {1, 3}, {1, 3}};
        sort(all(op));
        do {
            int y[4];
            for (int i = 1; i <= n; i++)
                y[i] = x[i];
            for (auto it : op) { 
                int tmp = abs(y[it.F] - y[it.S]);
                for (int j = it.F; j <= it.S; j++)
                    y[j] = tmp;
                int sum = 0;
                for (int i = 1; i <= n; i++)
                    sum += y[i];
                cmax(ans, sum);
            }
        } while (next_permutation(all(op)));

        cout << ans << endl;
    }
    else {
        cout << *max_element(x + 1, x + n + 1) * n << endl;
    }
    
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