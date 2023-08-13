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
set<int> G[MAXN];

void sol() {
    cin >> n;
    for (int i = 0, k; i < n; i++) {
        cin >> k;
        for (int j = 0, a; j < k; j++) {
            cin >> a;
            G[i].insert(a);
        }
    }

    int res;
    cin >> res;

    set<int> ans;

    for (int i = 0; i < n; i++) {
        if (G[i].count(res)) {
            if (ans.size() == 0)
                ans.insert(i);
            else if (G[i].size() < G[*ans.begin()].size()) {
                ans.clear();
                ans.insert(i);
            }
            else if (G[i].size() ==  G[*ans.begin()].size())
                ans.insert(i);
        }
    }

    cout << ans.size() << endl;
    for (auto it: ans)
        cout << it + 1 << ' ';
    cout << endl;
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