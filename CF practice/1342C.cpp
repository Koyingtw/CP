#pragma GCC optimize("Ofast")
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
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int a, b, n;

void sol() {
	cin >> a >> b >> n;

    vector<int> v;

    int lcm = a * b / __gcd(a, b);
    for (int j = 0; j < lcm; j++)
        if ((j % a) % b != (j % b) % a)
            v.pb(j);

    for (int i = 0, l, r; i < n; i++) {
        cin >> l >> r;
        int ans = 0;
        ans += v.size() * (r / lcm - (l - 1) / lcm);
        
        int findl = upper_bound(all(v), (l - 1) % lcm) - v.begin() - 1;
        int findr = upper_bound(all(v), r % lcm) - v.begin() - 1;
        ans += findr - findl;
        
        cout << ans << " ";
    }
    cout << endl;
}

signed main() {
    Weakoying;
    int t = 1;
    while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}