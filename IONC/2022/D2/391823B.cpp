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
#define MAXN 1000005
#define MAXM 1000005 
int n, m;
int x[MAXN], l[MAXN], r[MAXN], ans[MAXN];

void sol() {
	cin >> n;   
    for (int i = 1; i <= n; i++) {
        x[i] = i, l[i] = i - 1, r[i] = i + 1;
    }
    l[1] = n, r[n] = 1;
    vector<int> v;
    int now = 1;
    for (int i = 1; i <= n; i++) {
        now = r[now];
        v.pb(x[now]);
        r[l[now]] = r[now];
        l[r[now]] = l[now];
        now = r[now];
    }
    for (int i = 0; i < (int)v.size(); i++)
        ans[v[i]] = i + 1;
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
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