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

void sol() {
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> x[i];
    sort(x, x + m);

    // int ans = 0;

    int ans = max((x[0] - 1) / 15, 0);
    int now = x[0];
    for (int i = 1; i < m; i++) {
        if (x[i] - x[i - 1] > 15) {
            
            ans += (x[i] - x[i - 1] - 1) / 15;
        }
        now = x[i];
    }
    if (n - now >= 15)
        ans += (n - now) / 15;
    cout << ans << endl;
}

// 30 / 10 / 10 / 10 / 10 / 10 / 15 / 20 / 20 / 20 / 20 / 20 / 25 / 25 / 25

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