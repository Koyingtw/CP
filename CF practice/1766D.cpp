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
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 10000005 
int n, m;

bitset<MAXM> notPrime;
vector<int> prime;
int mn[MAXM];

void make_prime() {
    for (int i = 2; i * i < MAXM; i++) {
        if (!notPrime[i]) {
            prime.emplace_back(i);
            for (int j = i * i; j < MAXM; j += i) {
                notPrime[j] = 1;
                if (!mn[j])
                    mn[j] = i;
            }
        }
    }
}



void sol() {
    cin >> n >> m;

    if (n > m)
        swap(n, m);

    int k = abs(n - m);
    int kk = k;
    int ans = INF;

    if (n == m) {
        cout << (__gcd(n, m) == 1) << endl;
        return;
    }

    if (__gcd(n, m) != 1) {
        cout << 0 << endl;
        return;
    }

    if (abs(n - m) == 1) {
        cout << -1 << endl;
        return;
    }

    if (!notPrime[k]) 
        cmin(ans, k * ((n + k - 1) / k));
    else {
        while (k > 1 && mn[k]) {
            int it = mn[k];
            cmin(ans, it * ((n + it - 1) / it));
            while (k % it == 0)
                k /= it;
        }
        if (k > 1 && !notPrime[k]) 
            cmin(ans, k * ((n + k - 1) / k));
    }

    // assert(ans - n >= 0);
    cout << ans - n << endl;
}

signed main() {
    Weakoying;
    int t = 1;
    make_prime();
    while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}