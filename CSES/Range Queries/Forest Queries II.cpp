// Problem: Forest Queries II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1739
// Memory Limit: 512 MB
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
#define MAXN 1005
#define MAXM 1000005 
int n, m;
int BIT[MAXN][MAXN];
bool x[MAXN][MAXN];

void update(int i, int j, int val) {
	while (i < MAXN) {
		int y = j;
		while (y < MAXN) {
			BIT[i][y] += val;
			y += lowbit(y);
		}
		i += lowbit(i);
	}
	return;
}

int query(int i, int j) {
	int sum = 0;
	while (i) {
		int y = j;
		while (y) {
			sum += BIT[i][y];
			y -= lowbit(y);
		}
		i -= lowbit(i);
	}
	return sum;
}

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char c;
			cin >> c;
			x[i][j] = (c == '*');
			// if (x[i][j])
				// cout << i << " " << j << endl;
			update(i, j, x[i][j]);
		}
	}
	// cout << query(4, 4) << endl;
	int k, x1, x2, y1, y2;
	while (m--) {
		cin >> k;
		if (k == 1) {
			cin >> x1 >> y1;
			if (x[x1][y1]) {
				update(x1, y1, -1);
			}
			else {
				update(x1, y1, 1);
			}
			x[x1][y1] = !x[x1][y1];
		}
		else {
			cin >> x1 >> y1 >> x2 >> y2;
			cout << query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1) << endl;
		}
	}
}

signed main() {
    Weakoying;
    int t = 1;
    //while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}