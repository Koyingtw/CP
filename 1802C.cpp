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

void sol() {
    cin >> n >> m;

    // cout << (24 ^ 17) << endl;

    vector<vector<int>> ans(n, vector<int>(m, 0));

    int now = 0;
    cout << n * m << endl;
    set<int> st;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int tmpi = i, tmpj = j;
            for (int k = 0; k < 64; k++) {
                ans[i][j] |= ((tmpi % 2) * 2 + tmpj % 2) * (1 << (k * 2));
                tmpi /= 2;
                tmpj /= 2;
            }
            st.insert(ans[i][j]);
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    assert(st.size() == n * m);
}

/*
now = 1
4 5 8 9
6 7 10 11
*/

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