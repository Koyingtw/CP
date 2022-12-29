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
#define pb push_back

const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int INFLL = 0x3f3f3f3f3f3f3f3f;

using namespace std;

#define MAXN 2005

int n;
bitset<100005> notPrime;
vector<int> prime;
vector<int> G[MAXN];
int num[MAXN];

void make_prime() {
    for (int i = 2; i * i <= 1e9; i++) {
        if (!notPrime[i]) {
            prime.pb(i);
            for (int j = 2 * 2; j * j <= 1e9; j += i) {
                notPrime[j] = true;
            }
        }
    }
}

int dfs(int i) {
    int res = 0;
    bool need = false;
    for (int e: G[i]) {
        res += dfs(e);

        if (__gcd(num[i], num[e]) == 1)
            need = true;

    }

    if (need)
        num[i] = 1;
    for (int e: G[i]) {
        for (int j = 0; j < prime.size() && __gcd(num[i], num[e]) == 1; j++) {
            if (__gcd(num[i] * prime[j], num[e]) != 1) {
                num[i] *= prime[j];
            }
        }
    }

    // cout << i << ' ' << num[i] << endl;
    // for (int e: G[i])
    //     cout << __gcd(num[i], num[e]) << ' ';
    // cout << endl;
    res += num[i] * need;
    return res;
}


void sol() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    for (int i = 2, p; i <= n; i++) {
        cin >> p;
        G[p].pb(i);
    }

    if (n == 2) {
        if (__gcd(num[1], num[2]) > 1)
            cout << 0 << endl;
        else if (num[1] % 2 == 0 || num[2] % 2 == 0)
            cout << 2 << endl;
        else if (num[1] % 3 == 0 || num[2] % 3 == 0)
            cout << 3 << endl;
        else
            cout << 4 << endl;
        return;

    }

    cout << dfs(1) << endl;
}

/*
6
5 6 3 4 9 12
1 1 1 3 1

3
1 2 3
1 2
*/

signed main() {
    make_prime();
    Koying;
    sol();
    return 0;
}