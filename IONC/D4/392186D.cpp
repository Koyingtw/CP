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
#pragma optimize("Ofase", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;

int cal(int n) {
    string s = to_string(n);
    int res = 0;
    for (char c: s) {
        res += c - '0';
    }
    return res;
}

void sol() {
	cin >> n >> m;
    int ans = INF, cnt = 0;
    if (cal(n) <= m) {
        cout << 0 << endl;
        return;
    }
    for (int i = 10; i <= 2e18; i *= 10) {
        cnt += (10 - n % 10) * i / 10;
        n += (10 - n % 10);
        n /= 10;
        if (cal(n) <= m) {
            cout << cnt << endl;
            return;
        }
    }
    cout << ans << endl;
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