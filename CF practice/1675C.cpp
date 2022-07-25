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
string s;

void sol() {
    cin >> s;
    n = s.size();

    int ans = 0;

    int one = 0, zero = 0, ques = 0;

    for (char c: s) {
        if (c == '1') {
            one++;
        } 
        else if (c == '0') {
            zero = 0;
        }
        else {
            ques++;
        }
    }


    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            one--;
            if (!one)
                ans++;
        }
        if (s[i] == '0') {
            if (!zero)
                ans++;
            zero++;
        }
        if (s[i] == '?') {
            if (!one && !zero)
                ans++;
        }
    }

    cout << ans << endl;
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
