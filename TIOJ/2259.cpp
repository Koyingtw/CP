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
#pragma optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;

struct matrix {
    vector<vector<int>> v;

    matrix(int _n, int _m) {
        for (int i = 0; i < _n; i++)
            v.push_back(vector<int>(_m, 0));
    }
    matrix(int _n) {
        for (int i = 0; i < _n; i++)
            v.push_back(vector<int>(_n, 0));
        for (int i = 0; i < _n; i++)
            v[i][i] = 1;
    }

    matrix operator *(matrix _a) {
        matrix res(v.size(), _a.v[0].size());
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < _a.v[0].size(); j++) {
                for (int k = 0; k < v[0].size(); k++) {
                    res.v[i][j] += v[i][k] * _a.v[k][j];
                    res.v[i][j] %= P;
                }
            }
        }
        return res;
    }

    void operator %=(int P) {
        for (int i = 0; i < v.size(); i++)
            for (int j = 0; j < v[0].size(); j++)
                v[i][j] %= P;
    }

    matrix operator ^(int _a) {
        matrix res(v.size());
        matrix tmp = *this;
        while (_a) {
            if (_a & 1) res = res * tmp;
            tmp = tmp * tmp;
            tmp %= P;
            _a >>= 1;
        }
        return res;
    }
};

template<typename T>
T fpow(T a, int b, const int P) {
    T res(a.v.size());
    
    while (b) {
        if (b % 2) {
            res = res * a;
            // res %= P;
        }
        a = a * a;
        // a %= P;
        b >>= 1;
    }


    return res;
}

void sol() {
    matrix A = matrix(6, 1), T = matrix(6, 6);
    A.v = {{0}, {0}, {1}, {2}, {3}, {2}};
    T.v = {
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 1, 1},
        {0, 0, 2, 0, 0, 1}
    };

    cin >> n;
    if (n <= 3) {
        cout << A.v[2 * n - 2][0] << endl;
        return;
    }
    // T = fpow(T, n - 3, P);
    T = T ^ (n - 3);
    A = T * A;
    cout << A.v[4][0] % P << endl;
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