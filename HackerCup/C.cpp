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
// #if !LOCAL
#define endl "\n"
#pragma GCC optimize("Ofast", "unroll-all-loops")
// #endif
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 4000005
#define MAXM 1000005 
int n, m;
string s;
int x[MAXN];
// int cnt[MAXN][2];
map<pii, int> mp1[MAXN], mp2[MAXN]; // 第幾輪、從哪開始，有幾次
vector<pii> Q[MAXN]; // 第 i 輪 從 F 開始有 S 次
int cnt1[MAXN], cnt2[MAXN];
int q[MAXN];

void sol(int id) {
    cout << "Case #" << id + 1 << ": ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        // cnt[i][0] = 1;
        mp1[i].clear();
        mp2[i].clear();
    }
    cin >> s;
    for (int i = 1; i <= n; i++)
        x[i] = s[i - 1] - '0';
    cin >> m;
    s = " " + s;
    for (int i = 1; i <= m; i++) {
        cin >> q[i];
        cnt1[i] = cnt2[i] = 0;
        mp1[q[i]][pii(i, q[i])]++;
    }

    // 0 1 0 1
    // 0 1 1 1
    // 0 0 1 1
    // 0 0 1 0

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        // cout << i << endl;
        for (auto [a, b]: mp1[i]) {
            cnt1[a.F] += b;
            if (i + a.S <= n)
                mp1[i + a.S][a] += b;
        }
        for (auto [a, b]: mp2[i]) {
            cnt2[a.F] += b;
            if (i + a.S <= n)
                mp2[i + a.S][a] += b;
        }

        for (int j = 1; j <= m; j++) {
            cnt1[j] = cnt1[j - 1] + cnt1[j];
            // cout << cnt[j] << ' ';
            if ((cnt1[j] + cnt2[j] + x[i]) % 2) {
                ans++;
                mp2[i + i][pii(j, i)]++;
            }
        }
        // cout << ans << ' ';
        for (int j = 1; j <= m; j++)
            cnt1[j] = cnt2[j] = 0;
        mp1[i].clear();
        mp2[i].clear();
    }
    cout << ans << endl;
}

signed main() {
    Weakoying;
    int t = 1;
    while (cin >> t)
	{
    	for (int i = 0; i < t; i++) {
            sol(i);
        }
    }
        
    return 0;
}