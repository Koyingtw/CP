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
int yes[MAXN], pre[MAXN];

void sol() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++)
        cin >> y[i];
    pre[1] = x[1];
    for (int i = 2; i <= n; i++) {
        yes[i] = yes[i - 1] + (y[i - 1] % y[i] == 0);
        pre[i] = pre[i - 1] + x[i];
        // cout << yes[i] << ' ';
    }
    // cout << endl;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (x[i] <= m)
            cmax(ans, 1);
        if (i == n)
            continue;
        int l = i + 1, r = n;
        bool legal = false;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (yes[mid] - yes[i] == mid - i && pre[mid] - pre[i - 1] <= m)
                l = mid, legal = true;
            else   
                r = mid - 1;
        } 
        // cout << i << ' ' << l << ' ' << legal << endl;
        if (yes[l] - yes[i] == l - i && pre[l] - pre[i - 1] <= m)
            cmax(ans, l - (i - 1));
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