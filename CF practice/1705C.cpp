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
#define MAXM 1000005 
#define MAXC 45
int n, c, q;
pii x[MAXC];
string s;

void sol() {
    cin >> n >> c >> q;
    cin >> s;
    int sz = n;
    for (int i = 0; i < c; i++) {
        cin >> x[i].F >> x[i].S;
        sz += (x[i].S - x[i].F + 1);
    }
    for (int i = 0, a; i < q; i++) {
        cin >> a;
        int tmp = sz;
        for (int i = c - 1; i >= 0; i--) {
            if (tmp - (x[i].S - x[i].F + 1) < a) {
                a = a - (tmp - (x[i].S - x[i].F + 1) + 1) + x[i].F;
            }
            tmp -= (x[i].S - x[i].F + 1);
            // cout << tmp << ' ' << a << endl;
        }
        cout << s[a - 1] << endl;
    }
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