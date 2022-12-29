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
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 1000005
#define MAXM 1000005 
int n, m;
int x[MAXN];

void sol() {
    cin >> n;
    stack<int> st;
    int ans = 0;

    for (int i = 0; i < n; i++)
        cin >> x[i];

    for (int i = 0; i < n; i++) {
        while (st.size() && st.top() <= x[i]) {
            st.pop();
            if (st.size())
                ans += min(x[i], st.top());
            else
                ans += x[i];
        }
        st.push(x[i]);
    }
    if (st.size())
        st.pop();
    while (st.size()) {
        ans += st.top();
        st.pop();
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
