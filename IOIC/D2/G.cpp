#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int> 
#define all(v) v.begin(), v.end()
#define lowbit(x) (x & (-x))
#define MEM(x, n) memset(x, n, sizeof(x))
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
#define cmin(a, b) (a = min(a, b))
#define cmax(a, b) (b = max(a, b))
#define F first
#define S second

#if !LOCAL
#define endl '\n'
#pragma GCC optimize("Ofast, unroll-all-loops")
#endif 
using namespace std;

#define MAXN 100005
#define MAXM 1000005

int n;
pii x[MAXN];
vector<int> cnt[MAXM];

struct Disjoint_Set {
    int arr[MAXN], cnt[MAXN];
    set<int> num[MAXN];

    void init() {
        for (int i = 1; i <= n; i++)
            arr[i] = i, cnt[i] = 1;
    }

    int find(int i) {
        return (arr[i] == i ? i : arr[i] = find(arr[i]));
    }

    void unite(int i, int j) {
        i = find(i);
        j = find(j);

        if (i == j)
            return;
        
        if (cnt[i] < cnt[j])
            swap(i, j);
        arr[j] = i;
        cnt[i] += cnt[j];
    }
} dsu;

const int INF = 0x3f3f3f3f;


void sol() {
    cin >> n;
    // cout << prime.size() << endl;

    // if (n > 2000)
    //     return;


    for (int i = 1; i <= n; i++) {
        cin >> x[i].F;
        x[i].S = i;
        cnt[x[i].F].push_back(x[i].S);
    }

    dsu.init();
    int ans = 0;
    int ouo = 0;

    
    // sort(x + 1, x + n + 1, greater<pii>());

    for (int i = (int)1e6; i > 0; i--) {
        vector<int> v;
        for (int j = i; j < MAXM; j += i) {
            for (int it: cnt[j]) {
                v.push_back(it);
            }
        }
        for (int k = 1; k < v.size(); k++) {
            if (dsu.find(v[0]) != dsu.find(v[k])) {
                ans += i;
                dsu.unite(v[0], v[k]);
                ouo++;
            }

            if (ouo == n - 1) {
                cout << ans << endl;
                return;
            }
        }
    }

    cout << ans << endl;
}

signed main() {
    Koying;
    sol();
}