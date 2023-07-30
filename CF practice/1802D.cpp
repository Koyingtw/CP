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
#define MAXN 500005
#define MAXM 1000005 
int n, m;
pii x[MAXN];

void sol() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i].F >> x[i].S;
    }

    sort(x, x + n);
    multiset<int> st1, st2;
    for (int i = 0; i < n; i++) {
        st2.insert(x[i].S);
    }
        
    int ans = INF;

    for (int i = 0; i < n; i++) {
        st2.erase(st2.find(x[i].S));
        int nxtmx;
        if (st2.size() == 0) nxtmx = INF;
        else nxtmx = *st2.rbegin();

        auto it = st1.lower_bound(x[i].F);

        if (st2.size() == 0) {
            if (it != st1.end()) {
                cmin(ans, abs(*it - x[i].F));
            }
            if (it != st1.begin()) {
                it--;
                cmin(ans, abs(*it - x[i].F));
            }
            st1.insert(x[i].S);
            continue;
        }

        if (st1.size() == 0) {
            cmin(ans, abs(nxtmx - x[i].F));
            st1.insert(x[i].S);
            continue;
        }

        // nxtmx > x[i].F

        if (nxtmx >= x[i].F) {
            cmin(ans, abs(nxtmx - x[i].F));
        }

        // nxtmx <= x[i].F
        if (nxtmx <= x[i].F) {
            cmin(ans, abs(x[i].F - nxtmx));
            if (*st1.rbegin() >= nxtmx) {
                if (it != st1.end() && *it >= nxtmx)
                    cmin(ans, abs(*it - x[i].F));
                if (it != st1.begin()) {
                    --it;
                    if (*it >= nxtmx)
                        cmin(ans, abs(*it - x[i].F));
                }
            }
        }

        st1.insert(x[i].S);
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