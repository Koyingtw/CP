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
int n, x, y;
int a[MAXN];

int check(int mid, int tar) {
    int now = x;
    for (int i = 0; i < n; i++) {
        if (a[i] <= now)
            now += mid;
        else
            now -= mid;
        // cout << now << ' ';
    }
    
    if (now >= tar)
        return true;
    return false;
}

void sol() {
    cin >> n >> x >> y;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);

    int rnd = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] <= x)
            x++;
        else {
            int add = i - (n - i);
            if (add <= 0) {
                cout << -1 << endl;
                return;
            }

            int tmp = (min(y, a[i]) - x + add - 1) / add;
            rnd += tmp;
            x += add * tmp;
            if (x >= y) {
                cout << rnd * n + i - (x - y) << endl;
                return;
            }

            x++;
        }
        if (x == y) {
            cout << rnd * n + i + 1 << endl;
            return;
        }
    }
    rnd++;
    cout << (rnd * n + y - x) << endl;
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