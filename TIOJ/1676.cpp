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
#define MAXN 500005
#define MAXM 1000005 
int n, k;
int x[MAXN], pre[MAXN], dp[MAXN];

struct Line {
    int a, b;
    int operator ()(int _x) {
        return a * _x + b;
    }
};

bool check(Line l1, Line l2, Line l3, int _x) {
    // double v12 = (l1.b - l2.b) / (l2.a - l1.a);
    // double v23 = (l2.b - l3.b) / (l3.a - l2.a);
    // return v12 >= v23
    return ((l1.b - l2.b) * (l3.a - l2.a) > (l2.a - l1.a) * (l2.b - l3.b) && (_x + k) * (l3.a - l2.a) > (l2.b - l3.b));
}

void sol() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    reverse(x + 1, x + n + 1);
    for (int i = 1; i <= n; i++)   
        pre[i] = pre[i - 1] + x[i];

    deque<pair<Line, int>> dq;
    dq.push_back({{0, 0}, 0});

    for (int i = 1; i <= n; i++) {
        while (dq.size() && dq.front().S < i - k)
            dq.pop_front();
        while (dq.size() >= 2 && dq[0].F(i) < dq[1].F(i))
            dq.pop_front();

        dp[i] = -i * i + dq.front().F(i);

        Line now = {2 * i, dp[i] - i * i + pre[i]};
        while (dq.size() >= 2 && check(dq[dq.size() - 2].F, dq[dq.size() - 1].F, now, dq[dq.size() - 2].S))
            dq.pop_back();
        dq.push_back({now, i});
    }
    cout << dp[n] << endl;
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