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
#define MAXN 2005
#define MAXM 1000005 
int n, m;
string s[3][MAXN];

void sol() {
    cin >> n;
    map<string, int> mp;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < n; j++) {
            cin >> s[i][j];
            mp[s[i][j]]++;
        }
    int ans[3] = {0, 0, 0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            if (mp[s[i][j]] == 1) {
                ans[i] += 3;
            }
            else if (mp[s[i][j]] == 2)
                ans[i] += 1;
        }
    }
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << endl;
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