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
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int x[MAXN];



void sol() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    set<int> st;
    for (int i = 1; i <= n; i++)
        st.insert(x[i]);
    int l = 1, r = n;
    while (l <= r) {
        // cout << l << ' ' << r << endl;
        bool legal = true;
        if (l <= r && x[l] == *st.begin()) {
            st.erase(x[l]);
            l++;
            legal = false;
        }
        if (l <= r && x[l] == *(--st.end())) {
            st.erase(x[l]);
            l++;
            legal = false;
        }
        if (l <= r && x[r] == *st.begin() && l <= r) {
            st.erase(x[r]);
            r--;
            legal = false;
        }
        if (l <= r && x[r] == *(--st.end()) && l <= r) {
            st.erase(x[r]);
            r--;
            legal = false;
        }

        if (legal) {
            cout << l << ' ' << r << endl;
            return;
        }
    }
    cout << -1 << endl;
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