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
int n, m;
int a[MAXN], b[MAXN];

int check(int mid) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > mid || b[i] > mid) {
            cnt = -1;
            break;
        }
        cnt += mid - min(a[i], b[i]);
    }
    return cnt;
}

void sol() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    int ans = INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int tmp = 0;
            for (int k = 0; k < n; k++) {
                if (a[k] < a[i] || b[k] < b[j]) {
                    tmp = INF;
                    break;
                }
                tmp += a[k] - a[i] + b[k] - b[j];
                tmp -= min(a[k] - a[i], b[k] - b[j]);
            }
            // cout << a[i] << ' ' << b[j] << ' ' << tmp << endl;
            cmin(ans, tmp);
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