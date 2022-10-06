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
int dp[MAXN][MAXN];
int pre[MAXN], mn[MAXN][2];

void sol() {
    string s;
    cin >> s;
    n = s.size();
    deque<char> dq;
    string a, b;
    for (auto it: s)
        dq.push_back(it);
    while (dq.size()) {
        if (dq.front() == dq.back()) {
            dq.pop_front();
            dq.pop_back();
        }
        else {
            break;
        }
    }

    while (dq.size()) {
        if (dq[0] == dq[1]) {
            dq.pop_front();
            dq.pop_front();
        }
        else {
            break;
        }
    }

    cout << (dq.size() > 0 ? "Alice" : "Draw") << endl;
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