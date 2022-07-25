// Problem: E. Preorder
// Contest: Codeforces - Educational Codeforces Round 127 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1671/problem/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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
const int P = 998244353;

using namespace std;
/******************************************************************************/
#define MAXN 100005
#define MAXM 1000005 
int n, m;
string s;

pair<int, string> dfs(int i) {
	if (__lg(i) == n - 1) {
		return {1, to_string(s[i])};
	}
	pair<int, string> l = dfs(i * 2);
	pair<int, string> r = dfs(i * 2 + 1);
	int tmp = l.F * r.F;
	string rtn = to_string(s[i]);
	rtn += l.S;
	rtn += r.S;
	string str1 = s[i] + l.S + r.S;
	string str2 = s[i] + r.S + l.S;
	if (str1 != str2)
		tmp *= 2;
	tmp %= P;
	return {tmp, min(str1, str2)};
}

void sol() {
	cin >> n;
	string tmp;
	s = "O";
	cin >> tmp;
	s += tmp;
	
	auto ans = dfs(1);
	cout << ans.F << endl;
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