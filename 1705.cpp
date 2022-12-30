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
        for (auto &it: cont)
            for (auto &it2: it)
                it2 %= P;
    }
};

matrix Make_T() {
    matrix res((1 << 7), (1 << 7));
    for (int mask = 0; mask < (1 << 6); mask++)
        res.cont[mask][mask + (1 << 6)] = 1;
    for (int mask1 = 0; mask1 < (1 << 6); mask1++) { // i - 2
        if (__builtin_popcount(mask1) != 2)
            continue;
        for (int mask2 = 0; mask2 < (1 << 6); mask2++) { // i - 1
            if (__builtin_popcount(mask2) != 2)
                continue;
            
            for (int mask3 = 0; mask3 < (1 << 6); mask3++) { // i
                bool legal = true;
                if (__builtin_popcount(mask2) != 3)
                    legal = false;

                for (int i = 0; i < 6; i++) if (mask1 & (1 << i)) {
                    if (i + 1 < 6 && mask3 & (1 << (i + 1)))
                        legal = false;
                    if (i - 1 >= 0 && mask3 & (1 << (i - 1)))
                        legal = false;
                }

                for (int i = 0; i < 6; i++) if (mask2 & (1 << i)) {
                    if (i + 2 < 6 && mask3 & (1 << (i + 2)))
                        legal = false;
                    if (i - 2 >= 0 && mask3 & (1 << (i - 2)))
                        legal = false;
                }

                res.cont[mask3][mask1]++;
            }
        }
    }
    return res;
}

matrix fpow(matrix a, int b, int P) {
    matrix res((1 << 7), (1 << 7));
    while (b) {
        a = a * a;
        a %= P;
        if (b % 2) {
            res = res * a;
            res %= P;
        }
        b /= 2;
    }
    return res;
}

void sol() {
    cin >> n;

    matrix T = Make_T();
    matrix A = matrix((1 << 7), 1);

    for (int mask1 = 0; mask1 < (1 << 6); mask1++) {
        if (__builtin_popcount(mask1) != 2)
            continue;
        A.cont[mask1][0]++;
    }

    auto ans = fpow(T, n - 2, 10000) * A;
    int sum = 0;
    for (auto &it: ans.cont)
        sum += it[0];
    cout << sum << endl;
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