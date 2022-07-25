// Problem: C. Sum of Substrings
// Contest: Codeforces - CodeCraft-22 and Codeforces Round #795 (Div. 2)
// URL: https://codeforces.com/contest/1691/problem/C
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
int n, m;

void sol() {
	cin >> n >> m;
	string s;
	cin >> s;
	reverse(all(s));
	pii mn = {s[0] - '0', 0};
	for (int i = 0; i < n && i <= m; i++) {
		if (s[i] - '0' > mn.F)
			mn = {s[i] - '0', i};
	}
	m -= mn.S;
	for (int i = mn.S; i > 0; i--)
		swap(s[i], s[i - 1]);
	reverse(all(s));
	pii mx = {s[0] - '0', 0};
	for (int i = 0; i < n - 1 && i <= m; i++) {
		if (s[i] - '0' > mx.F)
			mx = {s[i] - '0', i};
	}
	m -= mx.S;
	for (int i = mx.S; i > 0; i--)
		swap(s[i], s[i - 1]);	
	int ans = 0;
	for (int i = 0; i < n - 1; i++)
		ans += (s[i] - '0') * 10 + (s[i + 1] - '0');
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