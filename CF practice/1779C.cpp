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
int x[MAXN];

void sol() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int sum = 0;
    int ans = 0;
    bool change_m = false;
    for (int i = m; i > 1; i--) {
        pq.push(pii(-x[i], i));
        sum -= x[i];
        while (sum < 0) {
            if (pq.top().S == m)
                change_m = true;
            x[pq.top().S] = -x[pq.top().S];
            sum -= 2 * pq.top().F;
            pq.pop();
            ans++;
        }
    }

    pq = priority_queue<pii, vector<pii>, greater<pii>>();
    sum = 0;

    for (int i = m + 1; i <= n; i++) {
        pq.push(pii{x[i], i});
        sum += x[i];
        while (sum < 0) {
            sum -= 2 * pq.top().F;
            x[pq.top().S] = -x[pq.top().S];
            pq.pop();
            ans++;
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