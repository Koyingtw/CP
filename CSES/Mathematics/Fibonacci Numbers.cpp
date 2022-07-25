#pragma GCC optimize("Ofast")
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
#define MAXN 200005
#define MAXM 1000005 
int n, m;

vector<vector<int>> operator %(vector<vector<int>> a, int P) {
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a[i].size(); j++)
			a[i][j] %= P;
	}
	return a;
}

vector<vector<int>> operator *(vector<vector<int>> a, vector<vector<int>> b) {
	vector<vector<int>> res;
	for (int i = 0; i < a.size(); i++) {
		res.pb(vector<int>{});
		for (int j = 0; j < b[0].size(); j++) {
			res[i].pb(0);
			for (int k = 0; k < a[0].size(); k++) {
				res[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return res % P;
}



vector<vector<int>> matrixpow(vector<vector<int>> a, int x) {
	if (x == 1)
		return a;
	if (x % 2) {
		return (matrixpow(a, x - 1) * a);
	}
	else {
		vector<vector<int>> tmp = matrixpow(a, x / 2);
		tmp = (tmp * tmp);
		return tmp;
	}
}

void sol() {
	cin >> n;
	
	if (n == 0) {
		cout << 0 << endl;
		return;
	}
	
	vector<vector<int>> A{
		{0},
		{1}
	};
	vector<vector<int>> T{
		{0, 1},
		{1, 1}
	};
	A = matrixpow(T, n) * A;
	cout << A[0][0] << endl;
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