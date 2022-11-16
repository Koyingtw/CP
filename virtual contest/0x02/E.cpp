#include <bits/stdc++.h>
// #define int long long
#define pii pair<int, int>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) a = (a > b ? a : b)
#define cmin(a, b) a = (a < b ? a : b)
#define lowbit(x) (x & (-x))
#define F first
#define S second
#define Koying ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) v.begin(), v.end()
#if !LOCAL
#define endl '\n'
#endif
#pragma optimize("Ofast, unroll-all-loops");

const int INF = 0x3f3f3f3f;

using namespace std;

#define MAXN 7005

int n, m;
int x[MAXN], pre[MAXN], suf[MAXN];
vector<int> v;

struct Fenwick_Tree {
    int arr[MAXN];

    void init(int t) {
        for (int i = 0; i <= t; i++)
            arr[i] = 0;
    }

    int query(int i) {
        int res = 0;
        for (; i; i -= lowbit(i))
            res += arr[i];
        return res;
    }

    void update(int i, int val) {
        for (; i <= v.size(); i += lowbit(i))
            arr[i] += val;
    }
} bit1, bit3;

int rev(int i) {
    return n - i + 1;
}

map<int, int> mp;

void sol() {
    cin >> n;
    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        v.emplace_back(x[i]);
    }

    sort(all(v));
    v.erase(unique(all(v)), v.end());

    int ans = -INF, owo = 0;

    for (int i = 1; i <= n; i++) {
        x[i] = upper_bound(all(v), x[i]) - v.begin();
        pre[i] = bit1.query(x[i]);
        cnt += bit1.query(v.size()) - pre[i];

        bit3.init(v.size());

        for (int j = 1; j < i; j++) {
            if (x[j] >= x[i]) {
                int tmp = -pre[i] + bit3.query(x[i]) - pre[j] + bit1.query(x[j])
                        + (bit1.query(x[j] - 1) - bit3.query(x[j] - 1)) - (bit1.query(x[i] - 1) - bit3.query(x[i] - 1));
                if (ans == tmp)
                    owo++;
                else if (tmp > ans) {
                    owo = 1;
                    ans = tmp;
                }
            }
            bit3.update(x[j], 1);
        }

        bit1.update(x[i], 1);
    }

    if (ans == -INF) {
        cout << 1 << ' ' << n - 1 << endl;
        return;
    }

    cout << cnt - ans << ' ' << owo << endl;
}

signed main() {
    int _ = 1;
    Koying
    while (_--) {
        sol();
    }
    return 0;
} 