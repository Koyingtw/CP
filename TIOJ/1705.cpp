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
#define SZ(x) ((int)x.size())
#if !LOCAL
#define endl "\n"
#pragma optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 10000;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
vector<int> masks;

struct matrix {
    vector<vector<int>> cont;

    matrix(const int _n, const int _m) {
        for (int i = 0; i < _n; i++)
            cont.emplace_back(vector<int>(_m, 0));

    }

    matrix(const int _n) {
        for (int i = 0; i < _n; i++)
            cont.emplace_back(vector<int>(_n, 0));
        for (int i = 0; i < _n; i++)
            cont[i][i] = 1;
    }

    matrix operator *(const matrix &_a) {
        matrix res(SZ(cont), SZ(_a.cont[0]));

        for (int i = 0; i < SZ(cont); i++) {
            for (int j = 0; j < SZ(_a.cont[0]); j++) {
                res.cont[i][j] = 0;
                for (int k = 0; k < SZ(_a.cont); k++) {
                    res.cont[i][j] += cont[i][k] * _a.cont[k][j];
                }
                res.cont[i][j] %= P;
            }
        }

        return res;
    }

    void operator %=(const int P) {
        for (auto &col: cont)
            for (auto &it: col)
                it %= P;
    }


    int operator () (){
        int res = 0;
        for (auto &col: cont)
            for (auto &it: col) {
                res += it;
            }
        res %= P; 
        return res;
    }
};

bool check(int i) {
    return (i >= 0 && i < 6);
}

matrix make_T() {
    matrix res(SZ(masks), SZ(masks));

    for (int i = 0; i < SZ(masks); i++) {
        int mask1 = (masks[i] >> 6); // i - 1
        int mask2 = masks[i] & 0b111111; // i
        for (int j = 0; j < SZ(masks); j++) {
            int mask3 = (masks[j] >> 6); // i - 2
            int mask4 = masks[j] & 0b111111; // i - 1

            res.cont[i][j] = (mask4 == mask1);
            

            for (int x = 0; x < 6; x++) if (mask3 & (1 << x)) {
                for (int y = 0; y < 6; y++) if (mask4 & (1 << y)) {
                    for (int z = 0; z < 6; z++) if (mask2 & (1 << z)) {
                        if (abs(x - z) == 1 || abs(x - y) == 2 || abs(y - z) == 2) {
                            res.cont[i][j] = 0;
                            goto fin;
                        }
                    }
                } 
            }
            fin:;
        }
    }
    return res;
}

template<typename T>
T fpow(T a, int b, const int P) {
    T res(SZ(masks));
    
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
    cin >> n;

    if (n == 1) {
        int ans = 0;
        for (int mask = 0; mask < (1 << 6); mask++)
            ans += __builtin_popcount(mask) == 2;
        cout << ans << endl;
        return;
    }
    
    for (int mask1 = 0; mask1 < (1 << 6); mask1++) {
        if (__builtin_popcount(mask1) != 2)
            continue;
        for (int mask2 = 0; mask2 < (1 << 6); mask2++) {
            if (__builtin_popcount(mask2) != 2)
                continue;

            bool legal = true;

            for (int x = 0; x < 6; x++) if (mask1 & (1 << x)) {
                for (int y = 0; y < 6; y++) if (mask2 & (1 << y)) {
                    if (abs(x - y) == 2)
                        legal = false;
                }
            }

            if (legal) {
                masks.emplace_back((mask1 << 6) + mask2);
            }

        }
    }


    auto T = make_T();
    matrix A(SZ(masks), 1);
    for (int i = 0; i < SZ(masks); i++)
        A.cont[i][0] = 1;

    T = fpow(T, n - 2, 10000);
    A = T * A;

    if (n >= 6) {
        cout << string(4 - to_string(A()).size(), '0');
    }

    cout << A() % 10000 << endl;
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