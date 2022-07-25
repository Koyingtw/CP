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

bool check(string s) {
    bool legal = true;
    stack<int> st;

    for (char c: s) {
        if (c == '(') {
            st.push(c);
        } else {
            if (st.empty()) {
                legal = false;
                break;
            }
            st.pop();
        }
    }
    return legal && st.empty();
}

void sol() {
	string s;
    cin >> s;
    
    int cnt = 0;
    for (char c: s)
        cnt += (c == '(');

    int f1 = 0, f2 = INF;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '?') {
            if (cnt < s.size() / 2) {
                s[i] = '(';
                cmax(f1, i);
                cnt++;
            }
            else {
                s[i] = ')';
                cmin(f2, i);
            }
        }
    }

    if (!check(s)) {
        cout << "NO" << endl;
        return;
    }

    if (f2 < s.size())
        swap(s[f1], s[f2]);
    cout << (check(s) == true && f2 < s.size() ? "NO" : "YES") << endl;
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