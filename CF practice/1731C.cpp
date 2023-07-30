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
#define MAXM 1000005 
int n, m;
int x[MAXN], cnt[MAXM];
bitset<MAXN> not_prime;
vector<int> prime;
vector<int> odd;

void pre() {
    for (int i = 2; i < MAXN; i++) {
        if (!not_prime[i]) {
            prime.pb(i);
            for (int j = i * i; j < MAXN; j += i)
                not_prime[j] = true;
        }
    }
    // return;

    cnt[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        cnt[i] = 1;
        int tmp = i;
        for (int it: prime) {
            if (it > tmp)
                break;
            int owo = 0;
            while (tmp % it == 0) {
                owo++;
                tmp /= it;
                // cout << tmp << endl;
            }
            cnt[i] *= (owo + 1);
        }
    }
}


void sol() {
    cin >> n;
    int now = 0;
    int mx = 0;
    for (int j = 0; j <= (1 << (__lg(n) + 1)); j++) {
        cnt[j] = 0;
        // mx = (1 << i);
        // break;
    }
    cnt[0] = 1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        now ^= x[i];
        for (int j = 0; j * j <= (1 << (__lg(n) + 1)); j++) {
            ans += cnt[now ^ (j * j)];
        }
        cnt[now]++;
    }

    cout << (n + 1) * n / 2 - ans << endl;
}

signed main() {
    Weakoying;
    // pre();
    int t = 1;
    while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}