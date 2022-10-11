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
int n, k, b, s;

void sol() {
    cin >> n >> k >> b >> s;
    int mnsum = k * b;
    int mxsum = (k * (b + 1) - 1) + (n - 1) * (k - 1);
    if (s < mnsum || s > mxsum) {
        cout << -1 << endl;
        return;
    }
    else {
        // int tmp = 
        vector<int> ans;
        ans.pb(min(s, (k * (b + 1) - 1)));
        s -= ans.back();
        int avg = s / (n - (n > 1));
        for (int i = 1; i < n; i++) {
            ans.pb(avg);
            s -= ans.back();
        }
        for (int i = 1; i < n; i++) {
            if (s > 0) {
                ans[i]++;
                s--;
            }
        }
        for (int it: ans)
            cout << it << ' ';
        cout << endl;
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