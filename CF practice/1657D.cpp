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
#define MAXN 300005
#define MAXM 1000005 
int n, m, C;
int dp[MAXM];
int D[MAXN], H[MAXN];
int mx[MAXM];

struct hero {
    int c, d, h;

    bool operator < (const hero &a) const {
        return d * h < a.d * a.h;
    }
} heros[MAXN];


void sol() {
    cin >> n >> C;
    for (int i = 0; i < n; i++) {
        cin >> heros[i].c >> heros[i].d >> heros[i].h;
        cmax(mx[heros[i].c], heros[i].d * heros[i].h);
    }
    
    for (int i = 1; i <= C; i++) {
        for (int j = i; j <= C; j += i) {
            cmax(mx[j], mx[i] * (j / i));
        }
        cmax(mx[i], mx[i - 1]);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> D[i] >> H[i];
        
        int ans = upper_bound(mx, mx + C + 1, D[i] * H[i]) - mx;
        cout << (ans <= C ? ans : -1) << ' ';
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