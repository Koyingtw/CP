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
int pre[MAXN];
string s;
bitset<MAXN> used;

void sol() {
    cin >> n;
    cin >> s;
    s = " " + s;
    int sum = 0;
    for (int i = 1; i <= 2 * n; i++) {
        sum += s[i] - '0';
        pre[i] = pre[i - 1] + s[i] - '0';
    }
    if (sum & 1) {
        puts("-1");
        return;
    }
    
    zero:
    int a, b = 3 * n;
    for (char c = '0'; c < '2'; c++) {
        // cout << c << ':' << endl;
        vector<int> ans, ans2;
        for (int i = 1; i <= 2 * n; i++) {
            if (s[i] == c) {
                a = i;
                break;
            }
        }
        for (int i = 2 * n; i > a; i--) {
            if (s[i] == c) {
                b = i;  
                break;
            }
        }
        if (b > 2 * n) {
            continue;
        }

        used[a] = used[b] = true;
        ans.pb(a);
        ans2.pb(b);
        a++, b = 1;

        int i = a, j = b, revcnt = 1;
        for (; i <= 2 * n; i++) {
            if (used[i])
                continue;
            while (j <= 2 * n && (s[j] != s[i] || used[j] || i == j)) {
                j++;
            }
            if (j > 2 * n) {
                break;
            }
            ans.pb(i);
            ans2.pb(j);
            used[i] = true;
            used[j] = true;
            j++;
        }


        used.reset();

        if (ans.size() == n && revcnt <= 1) {
            if (revcnt) {
                vector<int> rev;
                for (int it: ans2)
                    if (it <= ans2[0])
                        rev.pb(it);

                cout << rev.size() << ' ';
                sort(all(rev));
                for (int it: rev)
                    cout << it << ' ';
                cout << endl;
            }
            else
                cout << 0 << endl;
            for (int it : ans)
                cout << it << ' ';
            cout << endl;
            return;
        }

    }
    cout << endl;
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