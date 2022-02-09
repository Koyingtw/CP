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
#define MAXN 200005
#define MAXM 1000005 
int n, m;
pii x[MAXN];
void sol()
{
	cin >> n >> m;
	int mm = m * 100, sum = 0;
	int tmp = 0, cnt = m;
	for (int i = 0; i < n; i++) {
		cin >> x[i].F >> x[i].S;	
	}	
	int l = 0, r = m + 1, mid = (l + r) / 2;
	bool yes = 0;
	while (l < r) {
		mid = (l + r) / 2;
		tmp = 0, cnt = mid;
		bool can = 1;
		for (int i = 0; i < n; i++) {
			if (x[i].F == 0) {
				if (cnt > 0) {
					tmp += 100 - x[i].S;
					cnt--;
				}
				else tmp -= x[i].S;
			}
			else tmp -= x[i].S;
			if (tmp < 0)
				can = 0;
		}
		if (can) {
			r = mid;
			yes = 1;
		}
		else l = mid + 1;
	}
	if (yes) {
		cout << m - r << endl;
	}
	else cout << -1 << endl;
	
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