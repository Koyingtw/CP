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
#define MAXN 300005
#define MAXM 1000005 
int n, m;
int x[MAXN];


void sol() {
    cin >> n;
    set<int> MEX, st[2];
    for (int i = 0; i < n; i++) {
        st[i & 1].clear();
        cin >> x[i];
        MEX.insert(x[i]);

        st[i & 1].insert(x[i]);
        if (i) {
            for (auto &it: st[(i - 1) & 1]) {
                if (it * x[i] / __gcd(it, x[i]) > n * n + 1) continue;
                st[i & 1].insert(it * x[i] / __gcd(it, x[i]));
                MEX.insert(it * x[i] / __gcd(it, x[i]));
            }
        }
    }

    MEX.insert(0);

    for (auto it = MEX.begin(); it != MEX.end(); it++) {
        if (it == MEX.begin()) continue;
        if (*it != *prev(it) + 1) {
            put(*prev(it) + 1);
            return;
        }
    }
    cout << *MEX.rbegin() + 1 << endl;
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