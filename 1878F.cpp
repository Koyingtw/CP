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
// #define endl "\n"
#pragma GCC optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 1000005
#define MAXM 1000005 
int n, m;
int p[MAXN];
bitset<MAXN> notPrime;
vector<int> prime;

void pre() {
    p[1] = 1;
    for (int i = 2; i < MAXN; i++) if (!notPrime[i]) {
        prime.pb(i);
        p[i] = i;
        for (int j = i * i; j < MAXN; j += i) {
            notPrime[j] = true;
            if (!p[j])
                p[j] = i;
        }
    }
}

map<int, int> make_fac(int x) {
    map<int, int> ret;
    while (x > 1) {
        ret[p[x]]++;
        x /= p[x];
    }
    return ret;
}

int count_fac(map<int, int> &mp) {
    int ret = 1;
    for (auto it: mp) {
        ret *= (it.S + 1);
    }
    return ret;
}

map<int, int> operator +(map<int, int> &a, map<int, int> &b) {
    map<int, int> ret;
    for (auto it: a)
        ret[it.F] += it.S;
    for (auto it: b)
        ret[it.F] += it.S;
    return ret;
}

map<int, int> operator -(map<int, int> &a, map<int, int> &b) {
    map<int, int> ret = a;
    for (auto it: b)
        ret[it.F] -= it.S;
    return ret;
}

map<int, int> cntmp, res;
void sol() {
    cin >> n >> m;
    int initn = n;
    map<int, int> mp = make_fac(n);
    // bool check_fac(mp)
    int cnt = count_fac(mp);

    int k, x;
    while (m--) {
        cin >> k;
        if (k == 1) {
            cin >> x;
            auto tmp = make_fac(x);
            mp = tmp + mp;
            cnt = count_fac(mp);
            cntmp.clear();
            for (auto it: mp) {
                tmp = make_fac(it.S + 1);
                cntmp = cntmp + tmp;
            }
            res = mp - cntmp;

            bool legal = true;
            for (auto it: res) {
                if (it.S < 0) {
                    legal = false;
                }
            }

            if (!legal) {
                cout << "NO" << endl;
            }
            else
                cout << "YES" << endl;
        }
        else {
            n = initn;
            mp = make_fac(n);
            cnt = count_fac(mp);
        }
    }
    cout << endl;
} 

// 9 * 2 = 18: d(18) -> 1, 2, 3, 6, 9, 18 = 6, d(9) = 3, d(2) = 2;

signed main() {
    Weakoying;
    int t = 1;
    pre();
    while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}