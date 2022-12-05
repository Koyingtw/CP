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
#pragma GCC optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int dp[20][10], sum[20];

void pre() {
    for (int i = 0; i < 10; i++)
        dp[1][i] = 1;
    sum[1] = 10;
    for (int i = 2; i < 20; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) if (j != k)
                dp[i][j] += dp[i - 1][k];
            if (j)
                sum[i] += dp[i][j];
        }
    }
}

int cal(string s) {
    int res = 0;

    if (stoll(s) < 0)
        return 0;
    if (stoll(s) <= 1)
        return 1;

    for (int i = 1; i < s.size(); i++)
        res += sum[s.size() - i];
    for (int j = 1; j < s[0] - '0'; j++)
        res += dp[s.size()][j];

    for (int i = 1; i < s.size(); i++) {
            
        for (int j = 0; j < s[i] - '0'; j++) if (j != s[i - 1] - '0')
            res += dp[s.size() - i][j];
        if (s[i] == s[i - 1])
            break;
    }
    bool legal = true;
    for (int j = 1; j < s.size(); j++) {
        if (s[j] == s[j - 1])
            legal = false;
    }
    res += legal;
    return res;
}


void sol() {
    pre();
    cin >> n >> m;
    cout << cal(to_string(m)) - cal(to_string(n - 1)) << endl;
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