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
const int P = 998244353;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int x[MAXN];
vector<int> G[MAXN];
int d[MAXN];
bool legal = true;
int in[MAXN];

void dfs(int i, int dep) {
    d[i] = dep;
    for (int e: G[i]) if (e != i) {
        if (!d[e])
            dfs(e, dep + 1);
        else if (d[e] % 2 == d[i] % 2)
            legal = false;
    }
}

void sol() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        if (x[i] != i) {
            G[i].pb(x[i]);
            in[x[i]]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!d[i] && G[i].size() && in[i] == 0)
            dfs(i, 1);   
    }
    for (int i = 1; i <= n; i++) if (!d[i]) {
        cout << -1 << endl;
        return;
    }



    if (!legal) {
        cout << -1 << endl;
        return;
    }
    vector<int> v[2];
    for (int i = 1; i <= n; i++) {
        v[d[i] % 2].pb(i);
    }
    cout << v[1].size() << endl;
    for (auto it: v[1])
        cout << x[it] << ' ';
    cout << endl;
    return;


    // take v[0]
    set<int> st, st2;
    for (int i = 1; i <= n; i++)
        st.insert(i);
    
    // 將 v[0] 中的拿走
    for (auto it: v[0]) {
        if (st.count(it))
            st.erase(it);
    }

    vector<int> r;
    for (auto it: st) // 剩下的就是 r
        r.pb(x[it]);

    for (int i = 1; i <= n; i++)
        st2.insert(i);

    vector<int> take;
    for (auto it: r) { // 按照 r 的順序拿走
        if (st2.count(it)) {
            st2.erase(it);
            take.pb(it);
        }
    }
    sort(all(take));
    if (st == st2 && take == v[0]) {
        cout << r.size() << endl;
        for (auto it: r)
            cout << it << ' ';
        cout << endl;
        return;
    }
        
    


    // take v[1]
    st.clear();
    st2.clear();
    for (int i = 1; i <= n; i++)
        st.insert(i);
    for (auto it: v[1]) {
        if (st.count(it))
            st.erase(it);
    }
    r.clear();
    for (auto it: st)
        r.pb(x[it]);
    for (int i = 1; i <= n; i++)
        st2.insert(i);

    take.clear();
    for (auto it: r) {
        if (st2.count(it)) {
            st2.erase(it);
            take.pb(it);
        }
    }
    sort(all(take));
    if (st == st2 && take == v[1]) {
        cout << r.size() << endl;
        for (auto it: r)
            cout << it << ' ';
        cout << endl;
        return;
    }
    cout << -1 << endl;
}

signed main() {
    Weakoying;
    int t = 1;
    // while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}