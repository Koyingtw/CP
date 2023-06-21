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
int mxe[MAXN];
vector<pair<vector<int>, int>> x;
vector<vector<int>> lis;

int LIS(vector<int> &v) {
    int n = SZ(v);
    vector<int> dp(n, INF);
    for (int i = 0; i < n; i++) {
        *lower_bound(all(dp), v[i]) = v[i];
    }
    return lower_bound(all(dp), INF) - dp.begin();
}

vector<int> make_LIS(vector<int> &v) {
    vector<int> ans;
    int mx = 0;
    for (auto it: v) {
        if (it > mx) {
            ans.push_back(it);
            mx = it;
        }
    }
    return ans;
}

struct BIT
{   
    int arr[MAXN];

    void init() {
        MEM(arr, 0);
    }

    void add(int x, int v) {
        for (int i = x; i < MAXN; i += lowbit(i)) {
            arr[i] += v;
        }
    }

    int query(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += arr[i];
        }
        return ans;
    }
} BIT;


void sol() {
    cin >> n;
    x.clear();

    for (int i = 0; i < n; i++) {
        cin >> m;
        mxe[i] = 0;
        x.push_back({vector<int>(m), i});
        for (int j = 0; j < m; j++) {
            cin >> x[i].F[j];
            cmax(mxe[i], x[i].F[j]);
        }
        lis.push_back(make_LIS(x[i].F));
        // for (auto it: lis[i]) {
        //     cout << it << " ";
        // }
        // cout << endl;
    }

    sort(all(x), [&](pair<vector<int>, int> a, pair<vector<int>, int> b) {
        int ab = lis[a.S].size() + lis[b.S].size() - (upper_bound(all(lis[b.S]), mxe[a.S]) - lis[b.S].begin());
        int ba = lis[a.S].size() + lis[b.S].size() - (upper_bound(all(lis[a.S]), mxe[b.S]) - lis[a.S].begin());
        if (ab == ba) {
            return mxe[b.S] - lis[a.S][0] < mxe[a.S] - lis[b.S][0];
            return lis[a.S][0] > lis[b.S][0];
            if (lis[a.S].size() == 0)
                return mxe[a.S] < mxe[b.S];
        }
        else
            return ab > ba;
    });

    vector<int> v;
    for (auto &it: x) {
        for (auto &i: it.F) {
            v.push_back(i);
            // cout << i << ' ';
        }
        // cout << endl;
    }

    cout << make_LIS(v).size() << endl;
    // auto ans = make_LIS(v);
    // for (auto &it: ans) {
    //     cout << it << ' ';
    // }
    // cout << endl;
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