// Problem: D - Strange Balls
// Contest: AtCoder - AtCoder Beginner Contest 240
// URL: https://atcoder.jp/contests/abc240/tasks/abc240_d
// Memory Limit: 1024 MB
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

void sol()
{
	cin >> n;
	stack<pii> s;
	int cnt = 0;
	for (int i = 0, a; i < n; i++) {
		cin >> a;
		if (s.size() == 0) {
			s.push({a, 1});
			cnt++;
			cout << cnt << endl;
			continue;
		}
		if (s.size() && s.top().F == a) {
			pii now = s.top();
			s.pop();
			now.S++;
			cnt++;
			if (now.S == now.F) {
				cnt -= now.S;
				cout << cnt << endl;
				continue;
			}
			s.push(now);
		}
		else {
			cnt++;
			s.push({a, 1});
		}
		cout << cnt << endl;
	}
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