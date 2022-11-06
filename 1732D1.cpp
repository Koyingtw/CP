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
#if !LOCAL
#define endl "\n"
#pragma optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000000005
int n, m;

bitset<MAXM> not_prime;
vector<pair<int, vector<int>>> prime;

void make_prime() {
    for (int i = 2; i * i <= MAXM; i++) {
        if (not_prime[i]) continue;
        prime.pb({i, vector<int>()});

        for (int j = i * i; j < MAXM; j += i) {
            not_prime[j] = 1;
        }
    }
}

void sol() {
    cin >> n;
    make_prime();
    cout << prime.size() << endl;
    for (int i = 0; i < n; i++) {
        char c;
        int x;
        cin >> c >> x;
        if (c == '+') {
            for (auto &p : prime) {
                if (x % p.F == 0) {
                    p.S.pb(x);
                    break;
                }
            }
        }
    }
}

signed main() {
    Weakoying;
    int t = 1;
    //while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}