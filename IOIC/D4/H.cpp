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
const int P = 998244353;

using namespace std;
/******************************************************************************/
#define MAXN 500005
#define MAXM 1000005 
int n, m;
int x[MAXN], y[MAXN];

int fpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = (res * a) % P;
        a = (a * a) % P;
        b >>= 1;
    }
    return res;
}

void sol() {
    cin >> n;
    int p = 0, q = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        sum += x[i];
    }
    p = x[0];
    q += 1;
    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> y[i];
        p += p * fpow(sum, P - 2) % P * y[i];
        p %= P;
        sum += y[i];
    }

    cout << p << endl;
    // cout << p * fpow(sum, P - 2) % P << endl;
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