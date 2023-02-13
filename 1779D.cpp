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
int y[MAXN];
int a[MAXN];
map<int, int> mp;
bool good[MAXN];
int l[MAXN];

void sol() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        l[i] = -1;
    }
    mp.clear();
    for (int i = 0; i < n; i++) {
        cin >> y[i];
        good[i] = 0;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    stack<int> st;
    
    for (int i = 0; i < n; i++) {
        if (x[i] < y[i]) {
            cout << "NO" << endl;
            return;
        }
        while (st.size() && y[st.top()] < y[i]) {
            st.pop();
        }
        if (st.size())
            l[i] = st.top();

        st.push(i);
    }

    for (int i = 0; i < n; i++) {
        if (l[i] == -1 || good[l[i]] || y[l[i]] > y[i]) {
            good[i] = (x[i] == y[i]);
            mp[y[i]] -= (!good[i]);
        }
    }

    for (auto it: mp) {
        if (it.S < 0) {
            cout << "NO" << endl;
            return;
        }
    }


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