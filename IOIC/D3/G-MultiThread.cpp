#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
// #define ll long long
#define pii pair<int, int>
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define MEM(x, n) memset(x, n, sizeof(x))
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) (a = (a > b ? a : b))
#define cmin(a, b) (a = (a < b ? a : b))
#define pb push_back
using namespace std;
#define lowbit(x) (x & (-x))

#define MAXN 200005
#define MAXM 1000005

// #if !LOCAL
// #define endl '\n'
#pragma GCC optimize ("Ofast, unroll-all-looops")
// #endif


#include <omp.h>

map<int, int> mp;

void sol(int i) {
    int n = i;

    if (n % 2 == 0 || n % 5 == 0 || n == 1 || n == 0) {
        mp[n] = -1;
        return;
    }

    int tmp = 10;
    int ans = 0;
    while (tmp < n) {
        tmp *= 10;
        // ans++;
    }

    set<int> st;
    // st.insert(0);
    int m = n;

    while (n && !st.count(tmp % n)) {
        st.insert(tmp % n);
        ans++;
        tmp %= n;
        tmp *= 10;
    }

    mp[m] = ans;
    // cout << m << ' ' << ans << endl;
    // cout << m << endl;

    return;
}

signed main() {
    Koying;
    // pre();

    // int t;
    // cin >> t;
    // while (t--)
    //     sol();

    omp_set_num_threads(100);
// #pragma omp parallel
//     {
//         int ID = omp_get_thread_num();
//         printf("Hello, I am thread number %d.\n", ID);
//     }

#pragma omp parallel for
    for (int i = 1; i < MAXM; i++) {

        // #pragma omp parallel
        // {
            sol(i);
            // sol(i);
        // }
    }

    cout << "{ ";
    for (int i = 0; i < MAXM; i++) {
        cout << mp[i] << ",\n"[i == MAXM - 1];
    }
    // cout << "OWO" << endl;
}