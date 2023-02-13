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
    int a, b;
    cin >> a >> b;

    if (a < b) {
        cout << 0 << endl;
        return;
    }

    int l = 1, r = 1e18, ans = 0;
    while (l < r) {
        int mid = l + (r - l + 1) / 2;
        if (a / mid >= b)
            l = mid;
        else
            r = mid - 1;
    }
    // cout << l << endl;
    ans += l;

    l = 1, r = 1e18;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (a / mid <= b)
            r = mid;
        else
            l = mid + 1;
    }
    // cout << r << endl;
    ans -= r - 1;
    cout << ans << endl;
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