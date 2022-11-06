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
#define MAXN 1005
#define MAXM 1000005 
int n, m, k;
string s, t;
vector<int> G1[30], G2[30];

int dp[MAXN][MAXN];

void LCS() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i] != t[j])
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            else
                dp[i][j] = dp[i - 1][j - 1] + 1;
            // cout << dp[i][j] << ' ';
        }
        // cout << endl;
    }

    int x = n, y = m;
    string ans;
    while (x > 0 && y > 0 && ans.size() < k) {
        // cout << x << ' ' << y << endl;
        if (s[x] == t[y]) {
            ans += s[x];
            x--;
            y--;
        }
        else if (x - 1 >= 0 && dp[x - 1][y] == dp[x][y]) {
            x--;
        }
        else
            y--;
    }

    reverse(all(ans));
    cout << ans.size() << '\n' << ans << endl;
}

string ans, mx;
bool found = false;
set<string> st;

void dfs(int i, int j, int dep) {
    // cout << i << ' ' << j << ' ' << ans << endl;
    if (found || st.count(ans))
        return;
    st.insert(ans);
    if (ans.size() == k) {
        mx = ans;
        found = true;
        return;
    }

    if (ans.size() > mx.size())
        mx = ans;

    for (int c = 0; c < 26; c++) {
        auto tmpi = upper_bound(all(G1[c]), i);
        auto tmpj = upper_bound(all(G2[c]), j);
        // cout << tmpi << ' ' << tmpj << endl;

        if (tmpi == G1[c].end() || tmpj == G2[c].end())
            continue;

        ans.pb((char)('a' + c));
        dfs(*tmpi, *tmpj, dep + 1);
        ans.pop_back();
    }
}

set<pii> vis;
map<pii, pii> from;

void sol() {
    cin >> n >> m >> k;
    cin >> s >> t;
    s = " " + s;
    t = " " + t;
    if (n <= 1000 && m <= 1000) {
        LCS();
        return;
    }

    for (int i = 1; i <= n; i++)
        G1[s[i] - 'a'].pb(i);
    for (int i = 1; i <= m; i++)
        G2[t[i] - 'a'].pb(i);

        

    ans = "";
    dfs(0, 0, 0);

    queue<array<int, 3>> q;
    q.push({0, 0, 0});
    vis.insert(pii(0, 0));

    pii last;

    while (q.size()) {
        auto now = q.front();
        q.pop();
        pii pos = {now[0], now[1]};
        last = pos;

        if (now[2] == k) {
            string ans;
            while (pos.F != 0 && pos.S != 0) {
                ans.pb(s[pos.F]);
                pos = from[pos];
            }

            reverse(all(ans));
            cout << ans.size() << endl;
            cout << ans << endl;
            found = true;
            return;
        }

        for (int c = 0; c < 26; c++) {
            auto tmpi = upper_bound(all(G1[c]), now[0]);
            auto tmpj = upper_bound(all(G2[c]), now[1]);

            if (tmpi == G1[c].end() || tmpj == G2[c].end() || vis.count(pii(*tmpi, *tmpj)))
                continue;

            vis.insert(pii(*tmpi, *tmpj));

            q.push({*tmpi, *tmpj, now[2] + 1});
            from[pii(*tmpi, *tmpj)] = {now[0], now[1]};
        }
    }

    if (found)
        return;


    pii pos = last;
    while (pos.F != 0 && pos.S != 0) {
        ans.pb(s[pos.F]);
        pos = from[pos];
    }

    reverse(all(ans));
    cout << ans.size() << endl;
    cout << ans << endl;
    return;
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