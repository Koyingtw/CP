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
int x[MAXN];

void sol() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        
    }

    if (m == 1) {
        for (int i = 1; i <= n; i++)
            cout << x[i] << ' ';
        cout << endl;
    }

    multiset<pii> st;
    int cnt = n - m + 1;
    for (int i = 1; i < m; i++)
        st.insert({x[i], i});
    for (int i = m; i <= n; i++) {
        st.insert({x[i], i});
        auto X = *st.begin();
        st.erase(st.begin());
        if (i - m + 1 != X.S) {
            st.erase(st.find({x[i - m + 1], i - m + 1}));
            swap(x[i - m + 1], x[X.S]);
            st.insert({x[X.S], X.S});
            cnt--;
        }
    }
    

    int tmp = n - m + 2;
    while (cnt && st.size()) {
        auto X = *st.begin();
        st.erase(st.begin());
        if (tmp != X.S) {
            st.erase(st.find({x[tmp], tmp}));
            swap(x[tmp], x[X.S]);
            st.insert({x[X.S], X.S});
            cnt--;
        }
        tmp++;
    }

    for (int i = 1; i <= n; i++)
        cout << x[i] << " \n"[i == n];
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