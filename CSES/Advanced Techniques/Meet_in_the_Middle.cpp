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
#define MAXN 45
#define MAXM 1000005 
int n, m;
int x[MAXN];

void sol() {
    cin >> n >> m;
    int nn = n - n / 2;
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++) 
        cin >> x[i];
    for (int mask = 0; mask < (1 << n / 2); mask++) {
        int sum = 0;
        for (int i = 0; i < n / 2; i++) if (mask & (1 << i)) {
            sum += x[i];
            if (sum > m) {
                sum = INF;
                break;
            }
        }
        ++mp[sum];
    }

    int ans = 0;
    for (int mask = 0; mask < (1 << nn); mask++) {
        int sum = 0;
        for (int i = 0; i < nn; i++) if (mask & (1 << i)) {
            sum += x[i + n / 2];
            if (sum > m) {
                sum = INF;
                break;
            }
        }
        ans += mp[m - sum];
    }
    cout << ans << endl;
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