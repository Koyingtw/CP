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
#pragma GCC optimize("Ofast, unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 105
#define MAXM 1000005 
int n, m;
int x[MAXN];
bitset<1000000000> not_prime;
vector<signed> prime;

void sol() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    
    map<int, set<int> > mp;
    int mxgcd = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            cmax(mxgcd, __gcd(x[i], x[j]));
            if (abs(x[i] - x[j]) == 0) {
                cout << "NO" << endl;
                return;
                continue;
            }

            mp[abs(x[i] - x[j])].insert((abs(x[i] - x[j]) - min(x[i], x[j]) % abs(x[i] - x[j])) % abs(x[i] - x[j]));
        }
    }
    int ans = 0;

    vector<int> v;
    for (auto &it: mp)
        v.pb(it.F);

    for (auto &it: mp) {
        if (it.S.size() == it.F && it.F != 1) {
            cout << "NO" << endl;
            return;
        }
        int tmp = it.F;
        for (int p: prime) if (tmp % p == 0) {
            if (p > tmp)
                break;
            for (int it2: it.S) {
                mp[p].insert(it2 % p);
                if (mp[p].size() == p && p != 1) {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }

    cout << "YES" << endl;
}

signed main() {
    Weakoying;
    int t = 1;

    prime.pb(2);
    for (int i = 3; i < 1e4; i += 2) {
        if (!not_prime[i]) {
            prime.emplace_back(i);
            for (int j = i * i; j < 1e4; j += i) {
                not_prime[j] = 1;
            }
        }
    }

    while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}