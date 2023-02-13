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
#define MAXN 35
#define MAXM 1000005 
int n, m, k;
string s[105][MAXN];
bitset<105> vis;
vector<int> G[105];
vector<int> GG[105];

const int p[] = {1, 0, -1, 0, 1};

bool check(int x, int now) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) if (s[x][i][j] != s[now][i][j]) {
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
                return false;
            for (int l = 0; l < 4; l++) {
                if (s[now][i + p[l]][j + p[l + 1]] == s[now][i][j])
                    return false;
            }
            cnt++;
        }
    }
    return cnt > 0;
}

bool same(int x, int y) {
    bool res = true;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            res &= (s[x][i][j] == s[y][i][j]);
    return res;
}

int in[105];

void sol() {
    cin >> n >> m >> k;
    vis.reset();

    // vector<int> ans;
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < n; j++)
            cin >> s[i][j];
    }

    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= k; j++) if (i != j) {
            if (check(i, j)) {
                G[j].pb(i);
                // cout << j << ' ' << i << endl;
                in[i]++;
            }
            else if (same(i, j) && i > j) {
                GG[i].pb(j);
                // in[j]++;
            }
        }
    }

    queue<int> q;
    vector<int> ans;
    for (int i = 0; i <= k; i++) if (!in[i])
        q.push(i);
    while (q.size()) {
        int now = q.front();
        q.pop();
        ans.pb(now);

        for (int e: GG[now]) {
            if (in[e] > 0) {
                q.push(e);
                in[e] = -10;
            }
        }

        for (int e: G[now]) {
            in[e]--;
            if (!in[e])
                q.push(e);
        }
    }

    cout << ans.front() + 1 << endl;
    vector<vector<int>> output;
    for (int i = 1; i < ans.size(); i++) {
        if (same(ans[i], ans[i - 1])) {
            output.pb({2, ans[i] + 1});
            // cout << 2 << ' ' << ans[i] + 1 << endl;
        }
        else {
            // cout << 1 << ' ';
            for (int x = 0; x < n; x++)
                for (int y = 0; y < m; y++)
                    if (s[ans[i - 1]][x][y] != s[ans[i]][x][y]) {
                        output.pb({1, x + 1, y + 1});
                    }

        
            output.pb({2, ans[i] + 1});
        }
    }
    cout << output.size() << endl;
    for (auto out: output) {
        for (int it: out)
            cout << it << ' ';
        cout << endl;
    }
}

signed main() {
    Weakoying;
    int t = 1;
    // while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}