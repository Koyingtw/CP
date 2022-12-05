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
vector<vector<pii>> x;

void sol() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        x.pb(vector<pii>(m + 1));
        int sum = 0;
        for (int j = 0, a; j < m; j++) {
            cin >> x[i][j].F;
            x[i][j].S = j;
            sum += x[i][j].F;
        }
        x[i][m] = {sum, m};
    }

    map<int, pii> mp;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < x[i].size() - 1; j++) {
            if (mp.count(x[i].back().F - x[i][j].F)) {
                auto ans = mp[x[i].back().F - x[i][j].F];
                cout << "YES" << endl;
                cout << ans.F << ' ' << ans.S << endl;
                cout << i + 1 << ' ' << j + 1 << endl;
                return;
            }
        }

        for (int j = 0; j < x[i].size() - 1; j++) {
            mp[x[i].back().F - x[i][j].F] = {i + 1, j + 1};
        }
    }
    cout << "NO" << endl;
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