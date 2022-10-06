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
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int x[MAXN];

void sol() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    vector<pii> ans1, ans2;
    if (x[0] % 2 != x[n - 1] % 2) {
        ans1.pb({0, n - 1});
        x[n - 1] = x[0];
    }
    for (int i = 0; i < n - 1; i++) {
        if ((x[i] + x[n - 1]) % 2 == 0) {
            ans1.pb({i, n - 1});
            x[i] = x[n - 1];
        }
    }
    for (int i = 1; i < n; i++) {
        if ((x[i] + x[0]) % 2) {
            ans1.pb({0, i});
            x[i] = x[0];
        }
    }
    cout << ans1.size() << endl;
    for (auto i : ans1) {
        cout << i.F + 1 << ' ' << i.S + 1 << endl;
        if ((x[i.F] + x[i.S]) % 2)
            x[i.S] = x[i.F];
        else
            x[i.F] = x[i.S];
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