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
#define MAXN 505
#define MAXM 1000005 
int n, m;
int pos[26];
string s[MAXN];
const int p[] = {1, 0, -1, 0, 1};
bitset<MAXN> vis[MAXN];

void sol() {
    string owo = "snuke";
    for (int i = 0; i < owo.size(); i++)
        pos[owo[i] - 'a'] = i;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    
    queue<pii> q;
    q.push({0, 0});
    while (q.size()) {
        auto now = q.front();
        q.pop();
        int x = now.F, y = now.S;
        for (int i = 0; i < 4; i++) {
            int xx = x + p[i], yy = y + p[i + 1];
            if (xx < 0 || xx >= n || yy < 0 || yy >= m)
                continue;
            if (pos[s[xx][yy] - 'a'] == (pos[s[x][y] - 'a'] + 1) % 5 && !vis[xx][yy]) {
                vis[xx][yy] = 1;
                q.push({xx, yy});

                if (xx == n - 1 && yy == m - 1) {
                    put("Yes");
                    return;
                }
            }
        }
    }
    put("No");
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