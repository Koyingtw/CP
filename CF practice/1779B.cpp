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
int ans[MAXN];

void dfs(int i) {
    if (i == n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += ans[i];
        }
        // cout << sum << endl;
        bool legal = 1;
        for (int i = 2; i <= n; i++) {
            legal &= (ans[i] + ans[i - 1] == sum);

        }
        if (legal) {
            for (int i = 1; i <= n; i++)
                cout << ans[i] << ' ';
            cout << endl;
        }
        return;
    }
    for (int j = -5; j <= 5; j++) if (j != 0) {
        ans[i + 1] = j;
        dfs(i + 1);
    }
}

void sol() {
    cin >> n;

    if (n == 3) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    if (n % 2 && n > 2) {
        for (int i = 1; i <= n; i++) {
            if (i % 2)
                cout << n / 2 - 1 << ' ';
            else
                cout << -(n / 2) << ' ';
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            if (i % 2)
                cout << -1 << ' ';
            else
                cout << 1 << ' ';
        }
    }
    cout << endl;
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