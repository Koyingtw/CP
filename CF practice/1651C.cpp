#pragma GCC optimize("Ofast")
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
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int choise[2][2][3];
pii x[MAXN], y[MAXN];


void sol() {
	cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i].F;
    for (int i = 0; i < n; i++)
        cin >> y[i].F;
    for (int i = 0; i < n; i++)
        x[i].S = y[i].S = i + 1;

    MEM(choise, 0x3f);

    choise[0][0][0] = abs(x[0].F - y[0].F);
    choise[0][0][2] = abs(x[0].F - y[n - 1].F);
    choise[0][1][0] = abs(x[n - 1].F - y[0].F);
    choise[0][1][2] = abs(x[n - 1].F - y[n - 1].F);
    choise[1][0][0] = abs(y[0].F - x[0].F);
    choise[1][0][2] = abs(y[0].F - x[n - 1].F);
    choise[1][1][0] = abs(y[n - 1].F - x[0].F);
    choise[1][1][2] = abs(y[n - 1].F - x[n - 1].F);

    for (int i = 1; i < n - 1; i++) {
        cmin(choise[0][0][1], abs(x[0].F - y[i].F));
        cmin(choise[0][1][1], abs(x[n - 1].F - y[i].F));
        cmin(choise[1][0][1], abs(y[0].F - x[i].F));
        cmin(choise[1][1][1], abs(y[n - 1].F - x[i].F));
    }

    int ans = INF;

    for (int x1 = 0; x1 < 3; x1++) {
        for (int x2 = 0; x2 < 3; x2++) {
            for (int y1 = 0; y1 < 3; y1++) {
                for (int y2 = 0; y2 < 3; y2++) {
                    cmin(ans, choise[0][0][x1] + choise[0][1][x2] + (x1 != 0 && x2 != 0) * choise[1][0][y1] + (x1 != 2 && x2 != 2) * choise[1][1][y2]);
                }
            }
        }
    }
    
    cout << ans << endl;
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