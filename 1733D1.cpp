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
#define MAXN 3005
#define MAXM 1000005 
int n, x, y;
string a, b;
int dp[MAXN], predif[MAXN];
bool dif[MAXN];

int cal(int l, int r) {
    int mn = INF;
    if (l == r)
        return dif[l] * INF;
    if ((predif[r] - predif[l - 1]) % 2)
        return INF;
    if ((predif[r] - predif[l - 1]) == (r - l + 1)) {
        cmin(mn, min(x * (r - l + 1) / 2, INF + x + y * (r - l + 1 - 2)));
    }

    for (int i = l; i <= r; i++) {
        int foo = 0;
        foo += (dif[i - 1] && i - 1 >= r);
        foo += (dif[i + 1] && i + 1 <= r);
        
    }

    return mn;
}

void sol() {
    cin >> n >> x >> y;
    cin >> a >> b;
    a = " " + a;
    b = " " + b;
    for (int i = 1; i <= n; i++) {
        dif[i] = a[i] != b[i];
        predif[i] = predif[i - 1] + dif[i];
        dp[i] = INF;
    }
    dif[n + 1] = 0;
    dp[0] = 0;

    if (predif[n] % 2) {
        cout << -1 << endl;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!dif[i])
            dp[i] = dp[i - 1];
        for (int j = 0; j < i; j++) {
            cmin(dp[i], dp[j] + cal(j + 1, i));
        }
    }

    if (pos.S - pos.F > 4)
        cmin(dp[n], y * predif[n]);

    cout << (dp[n] >= INF ? -1 : dp[n]) << endl;
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