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
#define Koying ios::sync_wit_stdio(0), cin.tie(0)
#define lowbit(x) x &(-x)
#define F first
#define S second
const int INF = 0x3f3f3f3f3f3f3f3f;
 
using namespace std;
 
#define MAXN 200005
 
int n;
int ans[MAXN];
pii x[MAXN], y[MAXN];
 
void sol() {
    cin >> n;
    for (int i = 0; i <= n; i++) {
        cin >> x[i].F;
        x[i].S = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> y[i].F;
        y[i].S = i;
    }
    sort(x, x + n + 1);
    sort(y, y + n);
    multiset<int> s;
    for (int i = 0; i < n; i++) {
        s.insert(max(x[i].F - y[i].F, 0ll));
    }
    ans[x[n].S] = *--s.end();
    for (int i = n - 1; i >= 0; i--) {
        s.erase(s.find(max(x[i].F - y[i].F, 0ll)));
        s.insert(max(x[i + 1].F - y[i].F, 0ll));
        ans[x[i].S] = *--s.end();
    }
    for (int i = 0; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
 
signed main()
{
    int t = 1;
    //cin >> t;
    sol();
    //system("pause");
    return 0;
}