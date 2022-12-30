#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define SZ(v) ((int)v.size())
#define MEM(x, n) memset(x, n, sizeof(x))
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) (a = (a > b ? a : b))
#define cmin(a, b) (a = (a < b ? a : b))
#if !LOCAL
#define endl '\n'
#pragma GCC optimize("Ofast, unroll-all-loops")
#endif

const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int INFLL = 0x3f3f3f3f3f3f3f3f;

using namespace std;

#define MAXN 200005

int n, k;

bool check(int mid) {
    int cnt = mid;
    while (mid >= k) {
        cnt += mid / k;
        assert(mid != (mid % k + mid / k));
        mid = mid % k + mid / k;
        if (cnt >= n)
            return true;    
    }
    return (cnt >= n);
}

void sol() {
    cin >> n >> k;
    int l = 0, r = n;
    // cout << "check " << check(7) << endl;
    // return;

    int tmpn = n;
    int a = 1;
    for (int i = 0; i < 64; i++) {
        tmpn -= a;
        a *= k;
        if (tmpn <= a) {
            l = tmpn, r = a;
            while (l < r) {
                int mid = (l + r) / 2;
                if (check(mid))
                    r = mid;
                else
                    l = mid + 1;
            }
            break;
        }
    }

    cout << r << endl;
}

/*
5
5 2
10 3
123 2
7356 10
3141592653589793 123
*/

signed main() {
    Koying;
    int t;
    cin >> t;
    while (t--)
        sol();
    return 0;
}