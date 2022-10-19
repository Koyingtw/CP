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
string s;

void sol() {
    cin >> n;
    cin >> s;

    int cnt = 0;
    int need = 0;
    vector<int> ans;
    
    for (int i = 0; i < 2 * n; i += 2) {
        if (s[i] != s[i + 1]) {
            cnt++;
            ans.pb(i + 1 + (s[i] - '0' != need));
            need ^= 1;
        }
    }

    if (cnt & 1) {
        cout << -1 << endl;
        return;
    }

    cout << ans.size() << ' ';
    for (int it: ans)
        cout << it << ' ';
    cout << endl;

    for (int i = 1; i <= 2 * n; i += 2)
        cout << i << ' ';
    cout << endl;
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