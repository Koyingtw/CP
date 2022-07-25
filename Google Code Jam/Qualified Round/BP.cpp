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
#define DB(x) cerr << #x << " " << x << endl
#define all(v) v.begin(), v.end()
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 100005
#define MAXM 1000005 
int n, m;
int x[3][4];
int Case = 0;

void sol() {
	Case++;
	cout << "Case #" << Case << ": ";
	for (int i = 0; i < 3; i++)	{
		for (int j = 0; j < 4; j++) {
			cin >> x[i][j];
		}
	}
	int mn[4];
	MEM(mn, 63);
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 3; i++) {
			cmin(mn[j], x[i][j]);
		}
	}
	int sum = mn[0] + mn[1] + mn[2] + mn[3];
	if (sum < 1000000) {
		cout << "IMPOSSIBLE" << endl;
		// cout << mn[0] << " " << mn[1] << " " << mn[2] << endl;
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (sum > 1000000) {
				int tmp = sum - 1000000;
				if (tmp > mn[i])
					tmp = mn[i];
				mn[i] -= tmp;
				sum -= tmp;
			}
		}
		for (int i = 0; i < 4; i++) {
			cout << mn[i];
			cout << (i == 3 ? "\n" : " ");
		}
		// cout << endl;
	}
}

signed main() {
    Weakoying;
    int t = 1;
    while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}