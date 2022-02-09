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
int a[4], b[4];

void sol()
{
	int mx[2] = {0, 0};
	int mn[2] = {INF, INF};
	for (int i = 0; i < 4; i++)	{
		cin >> a[i];
		cmax(mx[0], a[i]);
		cmin(mn[0], a[i]);
	}
	for (int i = 0; i < 4; i++)	{
		cin >> b[i];
		cmax(mx[1], b[i]);
		cmin(mn[1], b[i]);
	}
	int awin = 0, bwin = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (a[i] > b[j])
				awin++;
			if (a[i] < b[j])
				bwin++;
		}
	}
	if (awin == bwin) {
		cout << "no" << endl;
		return;
	}
	// cout << awin << " " << bwin << endl;
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 11; j++) {
			for (int k = 1; k < 11; k++) {
				for (int l = 1; l < 11; l++) {
					int alose = 0, blose = 0, atie = 0, btie = 0;
					for (int it: a)
						alose += (i > it) + (j > it) + (k > it) + (l > it), atie += (i == it) + (j == it) + (k == it) + (l == it);
					for (int it: b)
						blose += (i > it) + (j > it) + (k > it) + (l > it), btie += (i == it) + (j == it) + (k == it) + (l == it);
					if (awin > bwin && blose < 16 - blose - btie && alose > 16 - alose - atie) {
						cout << "yes" << endl;
						cerr << i << " " << j << " " << k << " " << l << endl;
						return;
					}
					if (awin < bwin && blose > 16 - blose - btie && alose < 16 - alose - atie) {
						cout << "yes" << endl;
						cerr << i << " " << j << " " << k << " " << l << endl;
						return;
					}
				}
			}
		}
	}
	cout << "no" << endl;
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
 