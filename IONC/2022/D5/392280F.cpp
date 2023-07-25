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
#pragma optimize("Ofase", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;

vector<vector<int>> operator %(vector<vector<int>> a, int P) {
	for (int i = 0; i < (int)a.size(); i++) {
		for (int j = 0; j < (int)a[i].size(); j++)
			a[i][j] %= P;
	}
	return a;
}

vector<vector<int>> operator *(vector<vector<int>> a, vector<vector<int>> b) {
	vector<vector<int>> res;
	for (int i = 0; i < (int)a.size(); i++) {
		res.pb(vector<int>{});
		for (int j = 0; j < (int)b[0].size(); j++) {
			res[i].pb(0);
			for (int k = 0; k < (int)a[0].size(); k++) {
				res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= P;
			}
		}
	}
	return res;
}

vector<vector<int>> matrixpow(vector<vector<int>> a, int x) {
    vector<vector<int>> res = {{1, 0, 0, 0, 0}, {0, 1, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 1, 0}, {0, 0, 0, 0, 1}}, tmp = a;


	for (; x; x >>= 1, tmp = tmp * tmp) {
        if (x & 1)
            res = res * tmp;
    }
    // res = res * a;
    // for (int i = 0; i < 5; i++) {
    //     for (int j = 0; j < 5; j++) {
    //         cout << res[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return res;
}

void sol() {
    cin >> n;
    char st, fin;
    cin >> st >> fin;
	vector<vector<int>> T {{0, 1, 0, 0, 1}, {1, 0, 0, 0, 1}, {0, 0, 0, 1, 1}, {0, 0, 1, 0, 1}, {1, 1, 1, 1, 0}};
    vector<vector<int>> A {{0, 0, 0, 0, 0}};
    A[0][st - 'A'] = 1;
    A = A * matrixpow(T, n);
    cout << A[0][fin - 'A'] << endl;
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