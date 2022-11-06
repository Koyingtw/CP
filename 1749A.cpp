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
#define MAXN 10
#define MAXM 1000005 
int n, m;
pii x[MAXN];
bitset<MAXN> has1, has2;

void sol() {
    cin >> n >> m;

    for (int i = 0; i < m; i++)
        cin >> x[i].F >> x[i].S;

    bool legal = false;
    for (int i = 0; i < m; i++) {
        has1.reset(), has2.reset();
        for (int j = 0; j < m; j++) {
            if (i == j)
                continue;
            has1[x[j].F] = has2[x[j].S] = true;
        }

        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (!has1[j] && !has2[k] && j != x[i].F && k != x[i].S) {
                    legal = true;
                    break;
                }
            }
        }
    }
    cout << (legal ? "YES" : "NO") << endl;
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