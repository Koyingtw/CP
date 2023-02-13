#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int> 
#define all(v) v.begin(), v.end()
#define lowbit(x) (x & (-x))
#define MEM(x, n) memset(x, n, sizeof(x))
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#if !LOCAL
#define endl '\n'
#pragma GCC optimize("Ofast, unroll-all-loops")
#endif 
using namespace std;

#define MAXN 1000005

int n, m;

bitset<MAXN> not_prime;
vector<int> prime;

void pre() {
    for (int i = 2; i < MAXN; i++) {
        if (!not_prime[i]) {
            prime.push_back(i);
            for (int j = i * i; j < MAXN; j += i) {
                not_prime[j] = true;
            }
        }
    }
}

void sol() {
    cin >> m;
    for (int i = 0; i < prime.size(); i++) {
        if (binary_search(prime.begin(), prime.end(), m - prime[i])) {
            cout << prime[i] << ' ' << *lower_bound(prime.begin(), prime.end(), m - prime[i]) << endl;
            return;            
        }
    }

}

signed main() {
    Koying;
    int t = 1;
    cin >> t;
    pre();
    while (t--) {
        sol();
    }
}