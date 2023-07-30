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
string ans[MAXN];

string delspace(string s) {
    for (int i = 0; i < s.size(); i++) if (s[i] != ' ')
        return s.substr(i);
}

int getspace(string s) {
    for (int i = 0; i < s.size(); i++) if (s[i] != ' ')
        return i;
}

void sol() {
    string s;
    int line = 0;
    int lastspace = 0;
    int lastanal = 0;
    int lastemptyline = 0;
    vector<string> tmp;
    while (getline(cin, s)) {
        ++line;
        int space = getspace();
        string raw = delspace();

        if (lastemptyline == line - 1) {
            ans[lastemptyline] += to_string(line);
        }

        if (space > lastspace && space - lastspace > 2) {
            cout << "ERR!" << endl;
            return;
        }
        if (space != lastspace) {
            tmp.clear();
        }

        if (raw == "safe") {
            ans[line] = string(" ", space) + "!!!Analyze(";
            for (int i = 0; i < (int)tmp.size() - 1; i++) {
                ans[line] += tmp[i] + ",";
            }
            ans[line] += tmp.back() + ")";
            tmp.clear();
        }
        else if (raw == "emptyline") {
            if (lastemptyline && lastemptyline == line - 1) {
                ans[line - 1] = string(" ", getspace(ans[line - 1])) + "emptyline";
            }
            ans[line] = string(" ", space) + "//Describe(";
        }
        else {
            if (space == lastspace)
                tmp.pb(raw);
        }
    }
}

// 30 / 10 / 10 / 10 / 10 / 10 / 15 / 20 / 20 / 20 / 20 / 20 / 25 / 25 / 25

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