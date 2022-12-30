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
int n, k;
pii x[MAXN];

void sol() {
    cin >> n >> k;
    multiset<int> st;
    for (int i = 0; i < n; i++)
        cin >> x[i].F;
    for (int i = 0; i < n; i++) {
        cin >> x[i].S;
        st.insert(x[i].S);
    }
    sort(x, x + n);

    int sum = k;
    for (int i = 0; i < n; i++) {
        if (x[i].F <= sum) {
            st.erase(st.find(x[i].S));
            continue;
        }

        // k + k - mn + k - 2 * mn;
        int mn = *st.begin();
        int l = 1, r = k / mn + 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (sum + k * (mid) - mn * (mid * (mid + 1)) / 2 >= x[i].F) {
                r = mid;
            }
            else
                l = mid + 1;
        }


        sum += k * r - mn * (r * (r + 1)) / 2;
        k -= mn * r;
        // cout << i << ' ' << sum << endl;
        if (r == INF || k <= 0 || sum < x[i].F) {
            cout << "NO" << endl;
            return;
        }

        st.erase(st.find(x[i].S));

    }
    // cout << endl;

    cout << "YES" << endl;
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