#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// #define int long long
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
int x[MAXN];
int ans[MAXM];

struct Data {
    int l, r, id;
} q[MAXM];

struct MO {
    set<int> ele;
    multiset<int> ans;
    multiset<int> eft[MAXN];

    void add(int i) {
        // cout << "add: " << i << endl;
        if (ele.empty()) {
            ele.insert(i);
            return;
        }

        auto it = ele.upper_bound(i);
        
        if (it != ele.end() && eft[*it].find(i) == eft[*it].end()) {
            ans.insert(abs(*it - i));
            // cout << "insert: " << *it << ' ' << i << endl;
            eft[*it].insert(i);
            eft[i].insert(*it);
        }
        it = ele.lower_bound(i);
        if (it != ele.begin() && eft[*it].find(i) == eft[*it].end()) {
            --it;
            ans.insert(abs(*it - i));
            // cout << "insert: " << *it << ' ' << i << endl;
            eft[*it].insert(i);
            eft[i].insert(*it);
        }
        ele.insert(i);
    }

    void del(int i) {
        // cout << "del: " << i << endl;

        for (auto it: eft[i]) {
            ans.erase(ans.find(abs(it - i)));
            eft[it].erase(i);
            // cout << "takeout: " << it << ' ' << i << endl;
        }
        ele.erase(i);
        for (auto it: eft[i])
            add(it);
        eft[i].clear();
    }
} Mo;

void sol() {
    cin >> n >> m;
    int sq = sqrt(m);
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    for (int i = 0; i < m; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }

    sort(q, q + m, [&](auto &a, auto &b) {
        if (a.l / sq != b.l / sq) return a.l < b.l;
        return a.r < b.r;
    }); 
    x[0] = INF;

    Mo.ans.insert(INF);

    int l = 1, r = 1; // [l, r]
    Mo.add(x[l]);
    for (int i = 0; i < m; i++) {
        // cout << q[i].l << ' ' << q[i].r << endl;
        while (l > q[i].l) {
            --l;
            Mo.add(x[l]);
        }
        while (r < q[i].r) {
            ++r;
            Mo.add(x[r]);
        }
        while (l < q[i].l) {
            Mo.del(x[l]);
            ++l;
        }
        while (r > q[i].r) {
            Mo.del(x[r]);
            --r;
        }
        ans[q[i].id] = *Mo.ans.begin();
    }
    for (int i = 0; i < m; i++)
        cout<< ans[i] << endl;
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