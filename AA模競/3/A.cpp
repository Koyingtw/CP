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
int r[MAXN], x[MAXN];

bool check(int r1, int x1, int r2, int x2) {
	if (__gcd(r1, r2) == 1)
		return true;
	int g = __gcd(r1, r2);
	if (x1 == x2 && x1 != 0) 
		return abs(r1 - r2) % x1 == 0;
	return ((x1 % g == x2 % g));
	if (x1 == x2)
		return true;
	if (r1 > r2 && x2 == 0)
		return x1 % r2 == 0;
	if (r1 > r2 && x2 != 0)
		return (x1 % g == x2 % g);
	if (r1 == r2)
		return x1 == x2;
	if (r1 < r2 && x1 == 0) 
		return x2 % r1 == 0;
	if (r1 < r2 && x1 != 0) 
		return (x1 % g == x2 % g);
}

void sol()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> r[i] >> x[i];
	
	for (int i = 1; i < n; i++) {
		bool nooo = 0;
		for (int j = 0; j < i; j++) {
			if (!check(r[j], x[j], r[i], x[i]))
				nooo = 1;
		}
		if (!nooo)
			continue;
		for (int k = 0; k < n; k++) {
			bool yes = 1;
			for (int j = 0; j < i; j++) {
				if (!check(r[j], x[j], r[i], k))
					yes = false;
			}
			if (yes) {
				// cout << r[i] << " " << x[i] << endl;
				x[i] = k;
				break;	
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << r[i] << " " << x[i] << endl;
	// cout << check(6, 1, 4, 3) << endl;
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