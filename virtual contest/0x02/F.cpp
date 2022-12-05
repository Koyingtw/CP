#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) a = (a > b ? a : b)
#define cmin(a, b) a = (a < b ? a : b)
#define lowbit(x) (x & (-x))
#define F first
#define S second
#define Koying ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#if !LOCAL
#define endl '\n'
#endif
#define all(v) v.begin(), v.end()
const int P = (int)1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
using namespace std;

#pragma optimize("Ofast, unroll-all-looops")

#define MAXN 500005

int n, k, h;
int x[MAXN], cnt[MAXN];

struct Fenwick_Tree {
    int arr[MAXN];

    int query(int i) {
        int res = 0;
        for (; i; i -= lowbit(i)) {
            res += arr[i];
        }
        res %= P;
        return res;
    }

    void update(int i, int val) {
        val = (val % P + P) % P;
        for (; i < MAXN; i += lowbit(i)) {
            arr[i] += val;
            arr[i] %= P;
        }
    }
} bit;

void sol() {
    cin >> n >> k >> h;
    vector<int> v {-INF, 0, h};
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        v.emplace_back(x[i]);
    }
    sort(all(v));
    v.erase(unique(all(v)), v.end());

    for (int i = 0; i < n; i++) {
        x[i] = lower_bound(all(v), x[i]) - v.begin();
        cnt[x[i]]++;
    }
    cnt[v.size() - 1] = 1;

    bit.update(1, 1);

    for (int i = 2; i < v.size(); i++) {
        int bot = lower_bound(all(v), v[i] - k) - v.begin();

        int tmp = (bit.query(i) - bit.query(bot - 1)) * cnt[i] % P;
        tmp = (tmp % P + P) % P;

        if (i == v.size() - 1) {
            cout << tmp << endl;
            return;
        }
        bit.update(i, tmp);
    }
}

signed main() {
    int _ = 1;
    Koying
    while (_--) {
        sol();
    }
    return 0;
} 