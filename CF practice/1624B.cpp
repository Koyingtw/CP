// Problem: B. Make AP
// Contest: Codeforces - Codeforces Round #764 (Div. 3)
// URL: https://codeforces.com/contest/1624/problem/B
// Memory Limit: 256 MB
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
#define putarr(x) for(int i = 0; i < sizeof(x); i++) cout << x[i] << (" \n")[i == sizeof(x) - 1]; 
#define all(v) v.begin(), v.end()
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 100005
#define MAXM 1000005 
int n, m;
int a, b, c;
void sol()
{
	cin >> a >> b >> c;
	if (a - b == b - c) {
		cout << "YES" << endl;
		return;
	}
	int cc = b - (a - b);
	if (cc && cc / c > 0 && cc % c == 0) {
		// cerr << a << " " << b << " " << cc << endl;
		cout << "YES" << endl;
		return;
	}
	if ((a + c) % 2 == 0) {
		int bb = (a + c) / 2;
		if (bb && bb / b > 0&& bb % b == 0) {
			// cerr << a << " " << bb << " " << c << endl;
			cout << "YES" << endl;
			return;
		}
	}
	int aa = b - (c - b);
	if (aa && aa / a > 0 && aa % a == 0) {
		// cerr << aa << " " << b << " " << c << endl;
		cout << "YES" << endl;
		return;
	}
	cout << "NO" << endl;
}

signed main()
{
    Weakoying;
    int t = 1;
    while (cin >> t)
    {
    	while (t--)
        {
            sol();
        }
    }
        
    return 0;
}