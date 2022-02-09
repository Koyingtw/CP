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
	string x[3];
	string y[3];
	map<char, int> mp;
	int a = 0, b = 0;
	for (int i = 0; i < 3; i++) {
		cin >> x[i];
		for (int j = 0; j < 3; j++)
			mp[x[i][j]]++;
	}
	for (int i = 0; i < 3; i++) {
		cin >> y[i];
		for (int j = 0; j < 3; j++) {
			if (y[i][j] == x[i][j]) {
				a++;
				if (!mp[y[i][j]])
					b--;
				mp[y[i][j]]--;
			}
			else if (mp[y[i][j]] > 0)
				b++, mp[y[i][j]]--;
		}
	}
	cout << a << endl << b << endl;
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