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
pii x[MAXN];

void sol()
{
	cin >> n >> m;
	set<int> st;
	for (int i = 0; i < n; i++)	{
		cin >> x[i].S;
		st.insert(x[i].S);
	}
	st.insert(0), st.insert(m);
	for (int i = 0; i < n; i++)	{
		cin >> x[i].F;
	}
	sort(x, x + n);
	int ans = 0, mx = 0;
	int t = 10;	
	while(t--)
	for (int i = 0; i < n; i++) {
		if (!st.count(x[i].S)) continue;
		
		int l = *--st.find(x[i].S);
		int r = *++st.find(x[i].S);
		
		if (l <= x[i].S - x[i].F || r >= x[i].S + x[i].F) {
			ans++;
			st.erase(st.find(x[i].S));
			cmax(mx, x[i].F);
		}
		
	}
	
	
	cout << ans << endl << mx << endl;
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