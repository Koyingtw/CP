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
#define MAXN 1005
#define MAXM 1000005 
int n, m;
int x[MAXN];

void sol()
{
	cin >> n >> m;
	stack<int> b, s, tmp;
	s.push(-1), tmp.push(-1);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	bool yes = 1;
	for (int i = 1; i <= n; i++) {
		while (s.size() && s.top() == x[b.size()]) {
			b.push(s.top());
			s.pop();
		}
		if (i == x[b.size()])
			b.push(i);
		else s.push(i);
	}
	// cout << b.size() << endl;
	while (s.size() && yes) {
		while (tmp.size() && tmp.top() == x[b.size()]) {
			b.push(tmp.top());
			tmp.pop();
		}
		if (s.size() && s.top() == x[b.size()]) {
			b.push(s.top());
			s.pop();
		}
		if (s.top() != x[b.size()] && tmp.top() != x[b.size()]) {
			tmp.push(s.top());
			s.pop();
		}
		// cout << b.size() << endl;
		yes &= tmp.size() <= m + 1;
	}
	yes &= b.size() == n;
	cout << (yes ? "yes" : "no") << endl;
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