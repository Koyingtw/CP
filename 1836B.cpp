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
int n, k, g;

void sol() {
    cin >> n >> k >> g;
    int avg = (g - 1) / 2;
    int sum = 0;
    int last = k * g;
    int round;
    if (avg)
        round = last / avg;
    else
        round = INF;
    if (round >= n - 1) {
        sum += avg * (n - 1);
        last -= avg * (n - 1);
    }
    else {
        sum += avg * round;
        last -= avg * round;
        sum += last;
        last = 0;
    }
    int pay;
    if (last % g >= (g + 1) / 2)
        pay = last + (g - last % g);
    else
        pay = last - last % g;
    sum += last - pay;
    cout << sum << endl;
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