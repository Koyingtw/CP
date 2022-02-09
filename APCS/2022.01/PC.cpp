#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// #define int long long
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
#define MAXN 50005
#define MAXM 1000005 
int n, m;
set<string> st;

void sol()
{
	cin >> n;
	string x[n];
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		st.insert(x[i]);
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = x[i].size() / 2 + x[i].size() % 2; j < x[i].size(); j++) {
			bool yes = 1;
			for (int k = j; k < x[i].size(); k++) {
				if (x[i][k] != x[i][k - j])
					yes = 0;
			}
			if (yes) {
				string to_find = "";
				for (int k = x[i].size() - j; k < j; k++)
					to_find += x[i][k];
				ans += st.count(to_find);
			}
		}
	}
	cout << ans << endl;
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