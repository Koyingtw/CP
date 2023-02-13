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
const int P = 998244353;

using namespace std;
/******************************************************************************/
#define MAXN 80005
#define MAXM 1000005 
int n, m;
int a[MAXN], d[MAXN];
int sum = 0;

struct Disjoint_Set {
    int arr[MAXN], cnt[MAXN], ans[MAXN];
    map<int, int> mp[MAXN];

    void init() {
        for (int i = 1; i <= n; i++) {
            arr[i] = i;
            mp[i][a[i]]++;
            cnt[i] = 0;
            ans[i] = 0;
        }
    }

    int find(int i) {
        return (arr[i] == i ? i : arr[i] = find(arr[i]));
    }

    bool unite(int i, int j) {
        i = find(i);
        j = find(j);
        if (i == j)
            return false;
        sum -= ans[i];
        sum -= ans[j];
        sum %= P;
        sum += P;
        sum %= P;
        if (mp[i].size() < mp[j].size())
            swap(i, j);
        arr[j] = i;
        for (auto &[a, b]: mp[j]) {
            mp[i][a] += b;
        }

        int tmp = 1;
        for (auto &[a, b]: mp[i]) {
            // cout << a << endl;
            int ouo = (b - 1);
            for (int k = 0; k < 20; k++) {
                if (mp[i].count(a ^ (1 << k)))
                    ouo += mp[i][a ^ (1 << k)];
                for (int l = k + 1; l < 20; l++) {
                    if (mp[i].count(a ^ (1 << k) ^ (1 << l)))
                        ouo += mp[i][a ^ (1 << k) ^ (1 << l)];
                }
            }
            tmp *= ouo * (b);
            tmp %= P;
        }
        // cout << endl;

        ans[i] = tmp;
        ans[j] = 0;
        sum += ans[i];
        sum = (sum % P + P) % P;
        return true;
    }
} dsu;

vector<int> G[1 << 20];

void sol() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> d[i];
    dsu.init();

    vector<int> ans;
    for (int i = n - 1; i >= 0; i--) {
        // cout << a[d[i]] << ' ';
        for (auto it: G[a[d[i]]])
            dsu.unite(d[i], it);
        for (int k = 0; k < 20; k++) {
            for (auto it: G[a[d[i]] ^ (1 << k)])
                dsu.unite(d[i], it);
            for (int l = k + 1; l < 20; l++) {
                for (auto it: G[a[d[i]] ^ (1 << k) ^ (1 << l)])
                    dsu.unite(d[i], it);
            }
        }
        G[a[d[i]]].pb(d[i]);
        ans.pb(sum);
    }
    reverse(all(ans));
    for (auto it: ans)
        cout << it << endl;
    cout << endl;
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