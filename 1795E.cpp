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
#define MAXN 300005
#define MAXM 1000005 
int n, m;
int h[MAXN], pre[MAXN], suf[MAXN];

void sol() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        pre[i] = suf[i] = 0;
    }
    
    stack<pii> st;

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && st.top().F + (i - st.top().S) > h[i]) {
            sum += min(st.top().F, st.top().F - (h[i] - (i - st.top().S)));
            st.pop();
        }

        st.push({h[i], i});
        pre[i] = sum;
    }

    while (!st.empty()) {
        st.pop();
    }
    sum = 0;

    for (int i = n; i > 0; i--) {
        while (!st.empty() && st.top().F + (st.top().S - i) > h[i]) {
            sum += min(st.top().F, st.top().F - (h[i] - (st.top().S - i)));
            st.pop();
        }

        st.push({h[i], i});
        suf[i] = sum;
    }

    int ans = INF;
    for (int i = 1; i <= n; i++) {
        cmin(ans, pre[i] + suf[i] + h[i]);
        cout << pre[i] << ' ' << suf[i] << endl;
    }
    put(ans);
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