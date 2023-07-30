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
int ten[] = {0, 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};

void sol() {
    int A, B, C, k;
    cin >> A >> B >> C >> k;
    
    // int la = ten[A], ra = ten[A + 1] - 1;
    // int lb = ten[B], rb = ten[B + 1] - 1;
    // while (la < ra) {
    //     int mida = (la + ra) / 2;
    //     lb = ten[B], rb = ten[B + 1] - 1;
    //     while (lb < rb) {
    //         int midb = (lb + rb) / 2;
    //         if (mida + midb < ten[C]) {
    //             lb = midb + 1;
    //         }
    //         else if (mida + midb >= ten[C + 1]) {
    //             rb = midb - 1;
    //         }
    //         else
    //             rb = midb;
    //     }
    //     if (mida + rb < ten[C]) {
    //         la = mida + 1;
    //     }
    //     else if (mida + rb >= ten[C + 1]) {
    //         ra = mida - 1;
    //     }
    //     else
    //         ra = mida;
    // }

    // if (ra + rb < ten[C] || ra + rb >= ten[C + 1]) {
    //     cout << -1 << endl;
    //     return;
    // }

    for (int i = ten[A]; i < ten[A + 1]; i++) if (i + ten[B + 1] - 1 >= ten[C]) {
        if (i + ten[B] >= ten[C + 1]) {
            cout << -1 << endl;
            return;
        }
        int tmpb = ten[C] - i;
        int tmpc = ten[C];

        if (tmpb < ten[B]) {
            tmpc += ten[B] - tmpb;
            tmpb = ten[B];
        }

        if (tmpb >= ten[B + 1]) {
            cout << -1 << endl;
            return;
        }
        
        if (tmpc >= ten[C + 1]) {
            cout << -1 << endl;
            return;
        }

        int mn = min(ten[B + 1] - tmpb, ten[C + 1] - tmpc);
        // cout << i << ' ' << tmpb << ' ' << mn << endl;
        if (k > mn)
            k -= mn;
        else {
            cout << i << " + " << tmpb + k - 1 << " = " << tmpc + k - 1 << endl;
            assert(i + tmpb + k - 1 == tmpc + k - 1);
            assert(i + tmpb + k - 1 >= ten[C] && i + tmpb + k - 1 < ten[C + 1]);
            return;
        }
    }
    cout << -1 << endl;
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