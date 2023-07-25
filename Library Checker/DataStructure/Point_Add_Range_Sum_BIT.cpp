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
#define maxn 500005
#define MAXM 1000005 
int n, m;

template<typename T, int RANGE>
struct Fenwick_Tree {
    vector<T> arr;

    Fenwick_Tree() {
        arr.resize(RANGE + 5);
        for (int i = 0; i <= n; i++)
            arr[i] = 0;
    }

    void update(int pos, T val) {
        for (int i = pos; i <= n; i += lowbit(i))
            arr[i] += val;
    }

    T query(int pos) {
        T ret = 0;
        for (int i = pos; i > 0; i -= lowbit(i))
            ret += arr[i];
        return ret;
    }

    T query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

class BIT {
   private:
    ll a[maxn];
    ll sum(int i) {
        ll r = 0;
        while (i > 0) r += a[i], i -= i & -i;
        return r;
    }
   public:
    // size = maxn 的空 BIT ，所有元素都是零
    BIT() { memset(a, 0, sizeof(a)); }
    // 注意 1-based
    void add(int i, ll v) {
        while (i < maxn) a[i] += v, i += i & -i;
    }
    // 注意 1-based
    ll sum(int l, int r) { return sum(r) - sum(l - 1); }
} BIT;

// Fenwick_Tree<int, 500000> BIT;
vector<int> v;

void sol() {
    cin >> n >> m;
    v.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        BIT.add(i, v[i]);
    }

    int op, a, b;
    while (m--) {
        cin >> op >> a >> b;
        if (op == 0)
            BIT.add(a + 1, b);
        else 
            cout << BIT.sum(a + 1, b) << endl;
    }
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