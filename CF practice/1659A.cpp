// Problem: A. Red Versus Blue
// Contest: Codeforces - Codeforces Round #782 (Div. 2)
// URL: https://codeforces.com/contest/1659/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("O3")
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
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 100005
#define MAXM 1000005 
int n, r, b;

void sol() {
	cin >> n >> r >> b;
	int owo = (r) / (b + 1);
	// cout << owo << endl;
	string ans = "";
	for (int i = 0; i < r - (b + 1) * owo; i++) {
		for (int j = 0; j <= owo; j++)
			ans += "R";
		ans += "B";
		// cout << ans << endl;
	}
	b -= (r - (b + 1) * owo);
	for (int i = 0; i < b; i++) {
		for (int j = 0; j < owo; j++)
			ans += "R";
		ans += "B";
	}	
	
	for (int i = 0; i < owo; i++)
		ans += "R";
	
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