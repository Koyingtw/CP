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
#define MAXN 200005
#define MAXM 1000005 
int n, m;
string s[2];
bitset<MAXN> vis[2];

void sol() {
    cin >> n;
    cin >> s[0] >> s[1];

    for (int k = 0; k < 2; k++) {
        if (s[k][0] == 'B') {
            vis[0].reset(), vis[1].reset();

            int x = k, y = 0;
            bool legal = true;
            while (1) {
                // cout << x << ' ' << y << endl;
                vis[x][y] = 1;


                int x1 = x + (x == 1 ? -1 : 1);
                int y1 = y;
                int x2 = x;
                int y2 = y + 1;


                if (y1 < n && s[x1][y1] == 'B' && !vis[x1][y1]) {
                    x = x1, y = y1;
                } 
                else if (y2 < n && s[x2][y2] == 'B' && !vis[x2][y2]) {
                    x = x2, y = y2;
                }
                else
                    break;
            }

            for (int i = 0; i < 2; i++)
                for (int j = 0; j < n; j++)
                    legal &= (s[i][j] == 'W' || vis[i][j]);
                
            if (legal) {
                put("YES");
                return;
            }
        }
    }
    put("NO");
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