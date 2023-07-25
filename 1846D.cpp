#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define ll long long
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
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n;
double d, h;
int x[MAXN];

void sol() {
    cin >> n >> d >> h;
    vector<pii> v;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        v.pb({x[i], 1});
        v.pb({x[i] + h, -1});
    }
    double ans = d * h / 2.0 * n;

    double ouo = (d / 2.0) / h;
    double ouob = (d + d - 2 * ouo) / 2;

    // cout << ouo << endl;
    // cout << d << ' ' << h << ' ' << endl;

    queue<int> q;

    for (int i = 0; i < n; i++) {
        while (q.size() && x[q.front()] + h < x[i]) q.pop();

        while (q.size()) {
            int j = q.front();
            double a = h - (x[i] - x[j]);
            double b = (double)d - ouo * (x[i] - x[j]) * 2;
            ans -= b * a / 2;
            q.pop();
            // cout << a << ' ' << b << endl;
        }

        q.push(i);
    }
    cout << setprecision(10) << fixed << ans << endl;
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