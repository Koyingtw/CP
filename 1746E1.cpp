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
// #define endl "\n"
#pragma optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;

string query(int l1, int r1, int l2, int r2) {
    cout << "? " << (r1 - l1 + 1) + (r2 - l2 + 1) << " ";
    for (int i = l1; i <= r1; i++) {
        cout << i << " ";
    }
    for (int i = l2; i <= r2; i++) {
        cout << i << " ";
    }
    cout << endl;
    string s;
    cin >> s;
    return s;
}

void sol() {
    cin >> n;
    cout << "? " << n - 1 << ' ';
    for (int i = 1; i < n; i++)
        cout << i << ' ';
    cout << endl;

    string res1;
    cin >> res1;

    cout << "? " << n - 1 << ' '; 
    for (int i = 1; i < n - 1; i++)
        cout << i << ' ';
    cout << n << endl;

    string res2;
    cin >> res2;

    ///

    if (res1 == "NO") {
        cout << "! " << n << endl;
    }
    else {
        cout << "! " << n - 1 << endl;
    }

    string res3;
    cin >> res3;
    int lie;

    if (res3 == ":)") {
        return;
    }
    else if (res1 == "NO" && res2 == "NO") {
        cout << "! " << n - 1 << endl;
        return;
    }
    else if (res1 == "NO" && res2 == "YES") {
        lie = 1;
    }
    else if (res1 == "YES" && res2 == "NO") {
        lie = 2;
    }
    else {
        cout << "! " << n << endl;
    }

    int l = 1, r = n - 2;
    while (l < r) {
        int mid = (l + r) / 2;
        vector<bool> res;
        pii rng[4];
        vector<pii> rngs;
        for (int i = 0; i < 4; i++) {
            rng[i] = {l + i * (mid - l + 1) / 4, l + (i + 1) * (mid - l + 1) / 4 - 1};
        }
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < n; j++) {
                string s = query(rng[i].F, rng[i].S, rng[j].F, rng[j].S);
                if (s == "YES") {
                    res.pb(1);
                }
                else {
                    res.pb(0);
                }
                rngs.pb({i, j})
            }
        }


        for (int mask = 0; mask < (1 << 5); mask++) {
            int last = (lie == 1);
            int has[4] = {-1, -1, -1, -1};
            bool legal = true;
            for (int i = 0; i < 5; i++) {
                if (mask & (1 << i)) {
                    if (has[rngs[i].F] != -1 && has[rngs[i].F] != last) {
                        legal = false;
                        break;
                    }
                    if (has[rngs[i].S] != -1 && has[rngs[i].S] != last) {
                        legal = false;
                        break;
                    }
                    has[rngs[i].F] = 1;
                    has[rngs[i].S] = 1;
                    last = 1;
                }
                else if (last == 0 || has[rngs[i].F] == 1 || has[rngs[i].S] == 1) {
                    legal = false;
                    break;
                }
                else {
                    has[rngs[i].F] = 0;
                    has[rngs[i].S] = 0;
                    last = 0;
                }
            }
            if (legal) {
                for (int i = 0; i < 5; i++) {
                    if (mask & (1 << i)) {
                        l = max(l, rng[rngs[i].F].F);
                        r = min(r, rng[rngs[i].F].S);
                        l = max(l, rng[rngs[i].S].F);
                        r = min(r, rng[rngs[i].S].S);
                    }
                }
                break;
            }
        }
    }
    cout << "! " << l << endl;
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