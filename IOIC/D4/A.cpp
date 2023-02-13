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

#define pdd pair<double, double>

void sol() {
    cin >> n;
    
    double y = 0.0;
    double x = 1.0;
    double sum = 0.0;
    double tmpx = 0.0;
    const double tar = 1e-15;


    for (int i = 0; i < n - 2; i++)
        cout << 0 << ' ' << 1 << endl;
    cout << -1 << ' ' << 0 << endl;
    return;


    if (n & 1) {
        for (int i = 1; i < n / 2; i++) {
            y += tar;
            tmpx = x;
            x = sqrt(1.0 - y * y);
            cout << fixed << setprecision(9) << x << ' ' << y << endl;
            sum += (x + tmpx) * tar;
        }
        // cout << sum << endl;
        double h = (1.0 - sum) / x;
        cout << fixed << setprecision(9) << sqrt(1.0 - (y + h) * (y + h)) << ' ' << y + h << endl;

        assert(sum <= 1);
        for (int i = n / 2 - 1; i >= 0; i--) {
            y -= tar;
            tmpx = sqrt(1.0 - y * y);
            cout << fixed << setprecision(9) << -x << ' ' << y << endl;
            x = tmpx;
        }
    }

    else {
        for (int i = 1; i < n / 2 - 1; i++) {
            y += tar;
            tmpx = x;
            x = sqrt(1.0 - y * y);
            cout << fixed << setprecision(9) << x << ' ' << y << endl;
            sum += (1 - x + tmpx) * tar;
        }
        double h = (1.0 - sum) / x;
        cout << fixed << setprecision(9) << sqrt(1.0 - (y + h) * (y + h)) + tar << ' ' << y + h - tar << endl;
        cout << fixed << setprecision(9) << sqrt(1.0 - (y + h) * (y + h)) << ' ' << y + h << endl;

        assert(sum <= 1);
        for (int i = n / 2 - 2; i >= 0; i--) {
            y -= tar;
            tmpx = sqrt(1.0 - y * y);
            cout << fixed << setprecision(9) << -x << ' ' << y << endl;
            x = tmpx;
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