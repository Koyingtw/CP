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
#define MAXN 200005
#define MAXM 1000005 
int n, m;
pii x[MAXN];

vector<int> win[MAXN];


void sol() {
    cin >> n >> m;
    deque<pii> dq;

    for (int i = 0; i < n; i++) {
        cin >> x[i].F;
        x[i].S = i;
        dq.push_back(x[i]);
        win[i].clear();
    }

    int rndcnt = 0;
    while (dq[0].F != n) {
        rndcnt++;
        auto a = dq[0];
        dq.pop_front();
        auto b = dq[0];
        dq.pop_front();

        if (a.F > b.F) {
            win[a.S].pb(rndcnt);
        }
        else {
            swap(a, b);
            win[a.S].pb(rndcnt);
        }
        dq.push_front(a);
        dq.push_back(b);
    }

    int i, k;
    while (m--) {
        cin >> i >> k;
        i--;
        int ans = 0;
        if (x[i].F != n || k <= rndcnt) {
            ans = upper_bound(all(win[i]), k) - win[i].begin();
        }
        else {
            ans = win[i].size() + (k - rndcnt);
        }
        cout << ans << endl;
    }
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