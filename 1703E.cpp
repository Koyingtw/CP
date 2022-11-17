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
#define MAXN 105
#define MAXM 1000005 
int n, m;
string s[MAXN];

void sol() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int tmp = 0;

            set<pii> foo;
            foo.insert({i, j});
            foo.insert({n - j - 1, i});
            foo.insert({n - i - 1, n - j - 1});
            foo.insert({j, n - i - 1});

            for (auto it: foo)
                tmp += s[it.F][it.S] - '0';

            int tar = (tmp < foo.size() - tmp ? 0 : 1);

            for (auto it: foo) {
                if (s[it.F][it.S] - '0' != tar) {
                    ans++;
                    s[it.F][it.S] = tar + '0';
                }
            }
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