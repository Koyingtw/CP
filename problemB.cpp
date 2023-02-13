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
int n, m;

void sol() {
    string s, out, op;
    cin >> s >> out >> op;
    for (int i = 0; i < s.size(); i++) {
        if (op[i] == '&') {
            if ((0 & (s[i] - '0')) == (out[i] - '0'))
                cout << 0;s
            else if ((1 & (s[i] - '0')) == (out[i] - '0'))
                cout << 1;
            else
                cout << 'X';
        }
        else {
            if ((0 ^ (s[i] - '0')) == (out[i] - '0'))
                cout << 0;
            else if ((1 ^ (s[i] - '0')) == (out[i] - '0'))
                cout << 1;
            else
                cout << 'X';
        }
    }
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