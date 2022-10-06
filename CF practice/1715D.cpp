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
vector<array<int, 3>> E[31];
int ans[MAXN][31];

void sol() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 31; j++)
            ans[i][j] = -1;

    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        if (a > b)
            swap(a, b);

        for (int j = 0; j < 31; j++) {
            if (!(c >> j & 1)) 
                ans[a][j] = ans[b][j] = 0;
            else {
                E[j].pb({a, b, 1});
            }
        }
    }
    for (int i = 0; i < 31; i++)
        sort(all(E[i]));

    for (int i = 0; i < 31; i++) {
        for (auto it: E[i]) {
            if (it[0] == it[1]) {
                ans[it[0]][i] = it[2];
                continue;
            }
            else if ((ans[it[0]][i] != 0) + (ans[it[1]][i] != 0) == 1) {
                ans[it[0]][i] = (ans[it[0]][i] != 0);
                ans[it[1]][i] = (ans[it[1]][i] != 0);
            }
        }
    }
    
    for (int i = 0; i < 31; i++) {
        for (auto it: E[i]) {
            if (ans[it[0]][i] == -1 && ans[it[1]][i] == -1) {
                ans[it[1]][i] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 0; j < 31; j++) {
            sum += (1 << j) * (ans[i][j] > 0);
        }
        cout << sum << ' ';
    }
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