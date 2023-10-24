#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// #define int long long
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
#define MAXN 1000005
#define MAXM 1000005 
int n, m;
vector<char> v;
vector<int> lc, rc;

int cursor = 0;

void append(char c) {
    v.pb(c);
    lc.pb(-1);
    rc.pb(-1);
    if (rc[cursor] != -1) {
        lc[rc[cursor]] = v.size() - 1;
        rc[v.size() - 1] = rc[cursor];
    }
    rc[cursor] = v.size() - 1;
    lc[v.size() - 1] = cursor;
    cursor = v.size() - 1;
}

void print() {
    int i = rc[0];
    while (i != -1) {
        cout << v[i];
        i = rc[i];
    } 
    cout << endl;
}

void Move(int step) {
    int delta = step / abs(step);
    for (int i = 0; i < abs(step); i++) {
        if (delta == -1) {
            if (lc[cursor] != -1)
                cursor = lc[cursor];
        }
        else {
            if (rc[cursor] != -1)
                cursor = rc[cursor];
        }
    }
}

void Backspace() {
    if (lc[cursor] == -1)
        return;
    if (rc[cursor] != -1) {
        lc[rc[cursor]] = lc[cursor];
    }
    if (lc[cursor] != -1) {
        rc[lc[cursor]] = rc[cursor];
    }
    cursor = lc[cursor];
}

void sol() {
    v.pb('\0');
    lc.pb(-1);
    rc.pb(-1);
    
    int cnt = 0;
    string op;
    while (cin >> op) {
        string s;
        if (op == "Type") {
            cin >> s;
            for (int i = 0; i < s.size(); i++) {
                append(s[i]);
            }
        }
        if (op == "Print") {
            print();
        }
        if (op == "Move") {
            int step;
            cin >> step;
            Move(step);
        }
        if (op == "Backspace") {
            Backspace();
        }
    }
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