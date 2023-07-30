#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define ll long long
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
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
string s[3];

void sol() {
    for (int i = 0; i < 3; i++) cin >> s[i];
    for (int i = 0; i < 3; i++) {
        if (s[i][0] == s[i][1] && s[i][1] == s[i][2] && s[i][0] != '.') {
            cout << s[i][0] << endl;
            return;
        }
        if (s[0][i] == s[1][i] && s[1][i] == s[2][i] && s[0][i] != '.') {
            cout << s[0][i] << endl;
            return;
        }
    }
    if (s[0][0] == s[1][1] && s[1][1] == s[2][2] && s[0][0] != '.') {
        cout << s[0][0] << endl;
        return;
    }
    if (s[0][2] == s[1][1] && s[1][1] == s[2][0] && s[0][2] != '.') {
        cout << s[0][2] << endl;
        return;
    }
    cout << "DRAW" << endl;
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