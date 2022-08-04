#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// #define int long long
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
#if !LOCAL
#define endl "\n"
#pragma optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1e9 + 1
int n, m;

bitset<(int)MAXM> not_prime;
vector<int> primes;
vector<int> prime_factors[305];
pii x[305];
pii ans[305];
map<int, int> mp;

void pre() {
    for (int i = 2; i * i < MAXM; i++) {
        if (!not_prime[i]) {
            // primes.pb(i);

            for (int j = i * i; j * j < MAXM; j += i) {
                not_prime[j] = 1;
            }

            for (auto [a, b]: mp) {
                if (a % i == 0 && a != i) {
                    prime_factors[b].pb(i);
                }
            }
        }
    }
}

int lcm(int a, int b) {
    return a * b / __gcd(a, b);
}


void sol() {
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> x[i].F;
        mp[x[i].F] = i;
        x[i].S = i;
        // cout << mp[x[i].F] << " ";
    }

    // cout << "OWO";
    pre();

    for (int i = 0; i < n; i++) {
        int id = mp[x[i].F];
        if (prime_factors[id].size() < 2) {
            cout << "-1 -1 -1 -1" << endl; 
        }
        else {
            int ans1 = 1, ans2 = 1;
            int tmp = x[i].F;
            while (tmp % prime_factors[id][0] == 0) {
                tmp /= prime_factors[id][0];
                ans1 *= prime_factors[id][0];
            }
            tmp = x[i].F;
            while (tmp % prime_factors[id][1] == 0) {
                tmp /= prime_factors[id][1];
                ans2 *= prime_factors[id][1];
            }
            // cout << ans1 << " " << ans2 << endl;
            cout << ans1 * (x[i].F / (ans2 * ans1)) << " " << x[i].F << " " << ans2 * (x[i].F / (ans2 * ans1)) << " " << x[i].F << endl;
        }
    }
}

signed main() {
    Weakoying;
    int t = 1;

    // cout << lcm(__gcd(104, 312), __gcd(36, 117)) << endl;
    // cout << lcm(__gcd(104, 936), __gcd(117, 936)) << endl;
    // pre();
    // while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}