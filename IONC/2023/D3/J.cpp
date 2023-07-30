#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// #define int long long
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
#define MAXN 5005
#define MAXM 1000005 
int n, m;
string s[MAXN];
int ss[MAXN][MAXN];
int x[MAXN][MAXN];

const int p[] = {1, 0, -1, 0, 1}; // DLUR
string S = "DLUR";

void sol() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++) {
            ss[i][j] = -1;
            for (int k = 0; k < 4; k++) {
                if (s[i][j] == S[k])
                    ss[i][j] = k;
            }
        }
    }
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--, b--, c--, d--;

    deque<array<int, 3>> dq;
    dq.push_back({a, b, 0});
    MEM(x, 0x3f);
    x[a][b] = 0;

    while (dq.size()) {
        auto now = dq.front();
        dq.pop_front();

        if (x[now[0]][now[1]] != now[2])
            continue;

        for (int i = 0; i < 4; i++) {
            int xx = now[0] + p[i];
            int yy = now[1] + p[i + 1];


            if (xx >= 0 && yy >= 0 && xx < n && yy < m && 
                ss[xx][yy] >= 0 && x[now[0]][now[1]] + (ss[now[0]][now[1]] != i) < x[xx][yy]) {
                if (ss[now[0]][now[1]] == i) {
                    x[xx][yy] = x[now[0]][now[1]];
                    dq.push_front({xx, yy, x[xx][yy]});
                }
                else {
                    x[xx][yy] = x[now[0]][now[1]] + 1;
                    dq.push_back({xx, yy, x[xx][yy]});
                }
            }
        }
    }
    cout << (x[c][d] > n * n ? -1 : x[c][d]) << endl;
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