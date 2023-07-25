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

void sol() {
    string s;
    cin >> s;
    map<char, int> mp;
    for (char c: s) {
        if (c <= 'C')
            mp[c]++;
        else    
            mp[c - 3]--;
    }
    for (char c = 'A'; c < 'D'; c++) {
        if (mp[c] < 0) {
            mp[c + 3] += -mp[c];
            mp[c] = 0;
        }
    }
    while (1) {
        bool can = 0;

        int mn = min(mp['A'], min(mp['C'], mp['E']));
        if (mn > 0) {
            mp['A'] -= mn;
            mp['C'] -= mn;
            mp['E'] -= mn;
            can = 1;
        }

        mn = min(mp['B'], min(mp['D'], mp['F']));
        if (mn > 0) {
            mp['B'] -= mn;
            mp['D'] -= mn;
            mp['F'] -= mn;
            can = 1;
        }

        mn = min(mp['A'], mp['C']);
        if (mn > 0) {
            mp['A'] -= mn;
            mp['C'] -= mn;
            mp['B'] += mn;
            can = 1;
        }

        mn = min(mp['B'], mp['D']);
        if (mn > 0) {
            mp['B'] -= mn;
            mp['D'] -= mn;
            mp['C'] += mn;
            can = 1;
        }

        mn = min(mp['C'], mp['E']);
        if (mn > 0) {
            mp['C'] -= mn;
            mp['E'] -= mn;
            mp['D'] += mn;
            can = 1;
        }

        mn = min(mp['D'], mp['F']);
        if (mn > 0) {
            mp['D'] -= mn;
            mp['F'] -= mn;
            mp['E'] += mn;
            can = 1;
        }

        mn = min(mp['E'], mp['A']);
        if (mn > 0) {
            mp['E'] -= mn;
            mp['A'] -= mn;
            mp['F'] += mn;
            can = 1;
        }

        mn = min(mp['F'], mp['B']);
        if (mn > 0) {
            mp['F'] -= mn;
            mp['B'] -= mn;
            mp['A'] += mn;
            can = 1;
        }

        if (!can)
            break;
    }

    int ans = 0;
    for (pii it: mp)
        ans += it.S;
    cout << ans << endl;
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