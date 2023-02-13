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

struct Disjoint_Set {
    int arr[MAXN], cnt[MAXN];

    void init(int n) {
        for (int i = 0; i <= n; i++) {
            arr[i] = i;
            cnt[i] = 1;
        }
    }

    int find(int i) {
        if (arr[i] == i) return i;
        return arr[i] = find(arr[i]);
    }

    void unite(int i, int j) {
        int x = find(i), y = find(j);
        if (x == y) return;
        if (cnt[x] < cnt[y]) swap(x, y);
        arr[y] = x;
        cnt[x] += cnt[y];
    }
};

map<pii, Disjoint_Set> dsu;


void sol() {
    cin >> n;
    
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            dsu[pii(i, j)].init(n);
        }
    }

    set<pii> st;
    vector<pii> x(1);
    for (int i = 1, a, b; i <= n; i++) {
        cin >> a >> b;
        st.insert({a, b});
    }
    for (auto i : st) {
        x.pb(i);
    }

    for (int i = 1; i < x.size(); i++) {
        for (int j = 1; j < i; j++) {
            if ((x[i].F - x[j].F) * (x[i].F - x[j].F) + (x[i].S - x[j].S) * (x[i].S - x[j].S) <= 2) {
                dsu[pii(x[i].F - x[j].F, x[i].S - x[j].S)].unite(i, j);
                dsu[pii(-(x[i].F - x[j].F), -(x[i].S - x[j].S))].unite(i, j);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i < x.size(); i++) {
        for (auto &it: dsu)
            cmax(ans, it.S.cnt[it.S.find(i)]);
    }
    cout << (ans - (ans == 1)) << endl;
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