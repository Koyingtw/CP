#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define ll long long
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
#define SZ(v) ((int)v.size())
#if !LOCAL
#define endl "\n"
#pragma GCC optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;

struct matrix {
    vector<vector<int>> cont;

    matrix(int n, int m) {
        for (int i = 0; i < n; i++)
            cont.pb(vector<int>(m, 0));
    }


    matrix operator *(matrix _a) {
        matrix res(cont.size(), _a.cont[0].size());
        for (int i = 0; i < cont.size(); i++) {
            for (int j = 0; j < _a.cont[0].size(); j++) {
                for (int k = 0; k < cont[0].size(); k++) {
                    res.cont[i][j] += cont[i][k] * _a.cont[k][j];
                }
            }
        }
        return res;
    }

    void operator %=(int P) {
        for (int i = 0; i < cont.size(); i++)
            for (int j = 0; j < cont[0].size(); j++)
                cont[i][j] %= P;
    }
};

matrix fpow(matrix a, int b, int P) {
    matrix res(a.cont.size(), a.cont[0].size());
    res.cont[0][0] = res.cont[1][1] = 1;
    while (b) {
        if (b % 2) {
            res = res * a;
            res %= P;
        }
        a = a * a;
        a %= P;
        b /= 2;
    }
    return res;
}

void sol() {
    matrix A(2, 2), B(2, 1);
    cin >> B.cont[1][0] >> B.cont[0][0];
    cin >> A.cont[0][1] >> A.cont[0][0];
    cin >> n;
    A.cont[1][0] = 1;
    A = fpow(A, n - 2, P);
    A = A * B;

    cout << A.cont[0][0] % P << endl;
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