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
#define MAXN 1005
#define MAXM 1000005 
int n, m;
int pre[MAXN][MAXN];

void sol() {
    cin >> n >> m;
    MEM(pre, 0);
    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y;
        pre[x][y] += x * y;
    }
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            pre[i][j] += pre[i][j - 1];
        }
    }
    for (int j = 1; j <= 1000; j++) {
        for (int i = 1; i <= 1000; i++) {
            pre[i][j] += pre[i - 1][j];
        }
    }

    while (m--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << pre[x2 - 1][y2 - 1] - pre[x1][y2 - 1] - pre[x2 - 1][y1] + pre[x1][y1] << endl;
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