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


int f(int x, int a) {
    int cnt = 0;
    int tmp = x;
    while (tmp) {
        cnt += (tmp % a == 4);
        tmp /= a;
    }
    return cnt;
}
int trans(int x, int a, int b) {
    return f(x, a) - f(x, b);
}

void sol() {
    int op, x, b;
    cin >> op;
    if (op == 1 && cin >> x >> b) {
        int cnt = 0;
        string s = to_string(x);
        for (auto it: s)
            cnt += (it == '4');
        while (x) {
            cnt -= (x % b == 4);
            x /= b;
        }
        cout << (cnt < 0 ? "Yes" : "No") << endl;
    }
    else if (op == 2 && cin >> x) {
        int ans = 0;
        string s = to_string(x);

        if (x >= 9 || x == 4) {
            cout << "INF" << endl;
        }
        else
            cout << 0 << endl;
        return;

        for (auto it: s) {
            if (it == '4') {
                cout << "INF" << endl;
                return;
            }
        }
        for (int i = 2; i <= x + 1; i++) {
            for (int j = 2; j <= x + 1; j++) {
                if (trans(x, i, j) < 0)
                    ans++;
            }
        }
        cout << ans << endl;
    }
    else if (cin >> x >> b) {
        int ans = 0;

        // if (b <= 100) {

        //     for (int i = 2; i <= min(b, 101); i++) {
        //         for (int j = 2; j <= min(b, 101); j++) {
        //             if (trans(x, i, j) < 0)
        //                 ans++;
        //         }
        //     }
        //     cout << ans << endl;
        //     return;
        // }

        int cnt[35] = {};

        int owo = 0;
        int Stop = x;
        int mx = 0;
        for (int i = 2; i <= min(b, x); i++) {
            int a = f(x, i);
            cnt[a]++;

            if (!a)
                owo++;
            else {
                
                owo = 0;
            }

            if (owo > 50000000) {
                // cout << owo << ' ' << i << endl;
                // Stop = i + 1;
                break;
            }
            
            // cout << i << ' ' << f(x, i) << endl;
        }

        for (int i = 1; i < 35; i++) {
            ans += cnt[i] * cnt[i - 1];
            cnt[i] += cnt[i - 1];
        }
        
        string s = to_string(x);
        int tmp = f(x, x + 1);
        // for (auto it: s) {
        //     if (it == '4') {
        //         tmp++;
        //     }
        // }
        if (b > x)
            ans += (cnt[34] - cnt[tmp] + (tmp ? cnt[tmp - 1] : 0)) * (b - x);
        cout << ans << endl;
    }
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