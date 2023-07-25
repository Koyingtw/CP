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
#define MAXN 200005
#define MAXM 1000005 
int n, m;
vector<pii> v(MAXN);

template<typename T>
struct RMQ_ST {
    T arr[25][MAXN];

    T pick(T &a, T &b) {
        return min(a, b);
    }

    void build(vector<T> &v, int n) {
        for (int i = 1; i <= n; i++)
            arr[0][i] = v[i];
        for (int i = 1; i <= __lg(n); i++) {
            for (int j = 1; j <= n; j++) {
                arr[i][j] = pick(arr[i - 1][j], arr[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    T query(int l, int r) {
        int k = __lg(r - l + 1);
        int rng = (1 << k);
        return pick(arr[k][l], arr[k][r - rng + 1]);
    }
};


RMQ_ST<pii> ST;

void sol() {
	cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i].F;
        v[i].S = i;
    }
    ST.build(v, n);
    sort(v.begin() + 1, v.begin() + n + 1);

    set<int> st;
    st.insert(0);
    st.insert(n + 1);

    int now = n * v[1].F;
    int ans = now;

    for (int i = 1; i < n; i++) {
        int prv = *(--st.lower_bound(v[i].S));
        int nxt = *(st.upper_bound(v[i].S));

        now -= (nxt - prv - 1) * ST.query(prv + 1, nxt - 1).F;
        st.insert(v[i].S);
        if (v[i].S != prv + 1)
            now += (v[i].S - prv - 1) * ST.query(prv + 1, v[i].S - 1).F;
        if (v[i].S != nxt - 1)
            now += (nxt - v[i].S - 1) * ST.query(v[i].S + 1, nxt - 1).F;
        cmax(ans, now);
        // cout << now << endl;
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