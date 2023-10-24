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
#define MAXN 25
#define MAXM 1000005 
int n, m;
int x[MAXN][MAXN];

int dis(int x1, int y1, int x2, int y2) {
    return (abs(x1 - x2) + abs(y1 - y2));
}

int cal(array<int, 5> now) {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int mn = INFLL;
            for (int k = 0; k < 5; k++) {
                cmin(mn, x[i][j] * dis(i, j, now[k] / 5, now[k] % 5));
            }
            sum += mn;
        }
    }
    return sum;
}

void sol() {
    cin >> n;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            x[i][j] = 0;
    for (int i = 0, a, b; i < n; i++) {
        cin >> a >> b;
        cin >> x[a][b];
    }

    array<int, 5> ans;
    int mn = INFLL;
    for (int i = 0; i < 25; i++) {
        for (int j = i + 1; j < 25; j++) {
            for (int k = j + 1; k < 25; k++) {
                for (int o = k + 1; o < 25; o++) {
                    for (int p = o + 1; p < 25; p++) {
                        array<int, 5> now = {i, j, k, o, p};
                        int res = cal(now);
                        if (res < mn) {
                            ans = now;
                            mn = res;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < 5; i++)
        cout << ans[i] << ' ';
    cout << endl;
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