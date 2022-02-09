// Problem: F. Interacdive Problem
// Contest: Codeforces - Codeforces Round #764 (Div. 3)
// URL: https://codeforces.com/contest/1624/problem/F
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
#define putarr(x) for(int i = 0; i < sizeof(x); i++) cout << x[i] << (" \n")[i == sizeof(x) - 1]; 
#define all(v) v.begin(), v.end()
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
// #define endl "\n"
#endif
const int INF = 0x3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 100005
#define MAXM 1000005 
int n, m;

void sol()
{
	cin >> n;
	int tmp = 0;
	
	// cout << "+" << " " << 1 << endl;
	
	// cin >> m;
	int l = 1, r = n, mid = (l + r) / 2;
	int ouo = 0;
	int now = 0, times = 0;
	int add = 0;
	int sum = 0;
	int cnt = 0;
	m = 0;
	while (l < r && cnt < 10) {
		mid = (l + r) / 2;
		cnt++;
		if (mid <= now) {
			cout << "+ " << n + mid - now << endl;
			now = n + mid - now;
		}
		else {
			cout << "+ " << mid - now << endl;
			now = mid - now;
		}
		sum += now;
		cin >> ouo;
		
		// if (cnt == 1) m = ouo;
		if (times != ouo) {
			r = mid;
			add = 0;
		}
		else {
			l = mid + 1;
			add += now;
		}
		now = mid;
		times = ouo;
	}
	// if (l != n) {
	// }
	// else {
// 		
	// }
	r %= n;
	cerr << r << endl;
	int awa = (sum - r) % n - 1;
	// put(awa)
	if (awa < 0)
		times++;
	if (r == 0)
		m--;
	cout << "! " <<  n * (m + 1) - r  + sum << endl;
	// cout << "! " << l << endl;
}

signed main()
{
    Weakoying;
    int t = 1;
    //while (cin >> t)
    {
    	while (t--)
        {
            sol();
        }
    }
        
    return 0;
}