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
int n, m;
vector<double> v;
double ans[105];

double f(double x) {
    double res = 0;
    for (int i = 0; i < n; i++) {
        res += (double)(pow(x, i) * v[i]);
    }
    return res;
}

double g(double x) {
    double res = 0;
    for (int i = 1; i < n; i++) {
        res += (double)((double)i * v[i] * pow(x, i - 1));
    }
    return res;
}

void sol() {
	int a;
    while (cin >> a)
        v.pb(a);
    
    reverse(all(v));
    n = v.size();
    ans[0] = 0;
    for (int i = 1; i <= 100; i++)
        ans[i] = ans[i - 1] - f(ans[i - 1]) / g(ans[i - 1]);
    for (int i = 2; i < 100; i++) {
        if (abs(f(ans[i])) < 0.0001) {
            cout << fixed << setprecision(2) << ans[i] << endl;
            return;
        }
    }

    // cout << fixed << setprecision(10) << f(0.596974) << endl;
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