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
const int P = 998244353;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m, k, q;
pii op[MAXN];

void sol() {
	set<int> x, y;
    int ans = 1;
    cin >> n >> m >> k >> q;
    for (int i = 0; i < q; i++)
        cin >> op[i].F >> op[i].S;
    
    for (int i = q - 1; i >= 0; i--) {
        if (x.count(op[i].F) && y.count(op[i].S))
            continue;
        if (x.size() == n || y.size() == m)
            break;
        else {
            ans *= k;
            ans %= P;
            x.insert(op[i].F);
            y.insert(op[i].S);
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