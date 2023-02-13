#include <bits/stdc++.h>
#define int long long
#define Koying ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pii pair<int, int>
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) (a = (a > b ? a : b))
#define cmin(a, b) (a = (a < b ? a : b))
#define all(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define SZ(v) ((int)v.size())
#define MEM(x, n) memset(x, n, sizeof(x))
#define lowbit(x) (x & (-x))
#if !LOCAL
#define endl '\n'
#pragma GCC optimize("Ofast, unroll-all-loops")
#endif

const int INF = 0x3f3f3f3f;
const int INFLL = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9 + 7;

using namespace std;

#define MAXN 2000005
#define MAXM 2000005
int n, m, q;
int x[MAXN], b[MAXN];

// struct Fenwick {
//     int arr[MAXM];

//     void update(int i, int val) {
//         for (; i < MAXM; i += lowbit(i))
//             arr[i] += val;
//     }

//     int query(int i) {
//         int res = 0;
//         for (; i > 0; i +=)
//     }
// }

int cal(int a, int b) {
    int res = 0;
    while (a) {
        res += a % b;
        a /= b;
    }
    return res;
}

void sol() {
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 0; i < q; i++) {
        cin >> b[i];
        int ans = 0;
        for (int j = 0; j < n; j++) {
            ans += (cal(x[j], b[i]) == m);
        }
        cout << ans << endl;
    }
}

/*
10 3 10
1 2 3 4 5 6 7 8 9 10
2
3
4
5
6
7
8
9
10
11
*/

signed main() {
    Koying;
    sol();
    return 0;
}