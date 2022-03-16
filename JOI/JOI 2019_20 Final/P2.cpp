#include <bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) a = max(a, b)
#define cmin(a, b) a = min(a, b)
#define MEM(x, n) memset(x, n, sizeof(x))
#define pii pair<int, int>
#define pdd pair<double, double>
#define DB(x) cerr << #x << " " << x << endl;
#define endl "\n"
#define Koying ios::sync_with_stdio(0), cin.tie(0)
#define lowbit(x) x &(-x)
const int INF = 0x3f3f3f3f3f3f3f3f;
using namespace std;
 
#define MAXN 200005
 
int n, k;
string s;
 
void sol() {
    cin >> n >> k;
    cin >> s;
    int mn = INF;
    //DB(s);
    int a, b, c, d;
    a = b = c = d = -1;
    int cntJ, cntO, cntI;
    cntJ = cntO = cntI = 0;
    for (int i = 0; i < n; i++) {
        while (d + 1 <= i) {
            d++;
            cntI += s[d] == 'I';
        }
        while (c + 1 < d && cntI - (s[c + 1] == 'I') >= k) {
            c++;
            cntO += s[c] == 'O';
            cntI -= s[c] == 'I';
        }
        while (b + 1 < c && cntO - (s[b + 1] == 'O') >= k) {
            b++;
            cntJ += s[b] == 'J';
            cntO -= s[b] == 'O';
        }
        while (a + 1 < b && cntJ - (s[a + 1] == 'J') >= k) {
            a++;
            cntJ -= s[a] == 'J';
        }
        if (cntJ >= k && cntO >= k && cntI >= k)
            cmin(mn, d - a);
        //cout << a << " " << b << " " << c << " " << d << endl;
        //cout << cntJ << " " << cntO << " " << cntI << endl;
    }
    if (mn == INF) {
        cout << -1 << endl;
        return;
    }
    cout << mn - 3 * k << endl;
}
 
signed main()
{
    Koying;
    int t = 1;
    //cin >> t;
    sol();
    return 0;
}