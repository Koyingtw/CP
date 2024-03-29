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
    cin >> n;
    pii mx(0, 0);
    pii mn(INF, 0);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        cmax(mx, pii(x[i], i));
        cmin(mn, pii(x[i], i));
    }

    int ans = 0;
    int tmp = 1;

    tmp = 1;
    for (int i = 0; i < n; i++) {
        if (i == mx.S)
            tmp *= (x[i] + 1);
        else
            tmp *= x[i];
    }
    cmax(ans, tmp);

    tmp = 1;
    for (int i = 0; i < n; i++) {
        if (i == mn.S)
            tmp *= (x[i] + 1);
        else
            tmp *= x[i];
    }
    cmax(ans, tmp);

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