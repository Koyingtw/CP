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

void sol() {
    cin >> n >> m;
    vector<vector<int>> x(n);
    for (int i = 0; i < n; i++) {
        x[i].resize(m);
        for (int j = 0; j < m; j++)
            cin >> x[i][j];
    }
    int l = 0, r = min(n, m);
    while (l < r) {
        int mid = (l + r + 1) / 2;
        vector<int> legal(m, 0);
        bool success = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                legal[j] += (x[i][j] >= mid);
            if (i >= mid) {
                for (int j = 0; j < m; j++)
                    legal[j] -= (x[i - mid][j] >= mid);
            }
            int last = -1;
            if (i >= mid - 1) {
                for (int j = 0; j < m; j++) {
                    if (legal[j] != mid) {
                        last = j;
                    }
                    else if (j - last >= mid) {
                        success = true;
                        goto done;
                    }
                }
            }
        }
        done:
        if (success) {
            l = mid;
        }
        else
            r = mid - 1;
    }
    cout << l << endl;
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