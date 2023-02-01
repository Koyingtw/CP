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

void multi(stack<int> &st, int tmp) {
    bool success = false;
    if (st.size() && st.top() >= 0) {
        tmp = st.top();
        st.pop();
        success = true;
    }
    cerr << tmp << endl;
    while (st.size() && st.top() == -3) {
        st.pop();
        if (st.top() == -2) {
            break;
        }
        tmp *= st.top();
        success = true;
    }
    if (success)
        st.push(tmp);
    cerr << "multi: " << tmp << ' ' << success << endl;
}

void add(stack<int> &st, int tmp) {
    bool success = false;
    if (st.size() && st.top() >= 0) {
        tmp = st.top();
        st.pop();
        success = true;
    }
    cerr << tmp << endl;
    while (st.size() && st.top() == -1) {
        st.pop();
        tmp += st.top();
        st.pop();
        success = true;
    }
    cerr << "add: " << tmp << ' ' << success << endl;
    if (success)
        st.push(tmp);
}


void sol() {
    string s;
    cin >> s;
    stack<int> st;
    int tmp = 0;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        cerr << c << ' ' << tmp << endl;
        if (isdigit(c)) {
            tmp *= 10;
            tmp += c - '0';
            continue;
        }
        if (c == '+') {
            st.push(tmp);
            tmp = 0;
            st.push(-1);
        }
        if (c == '*') {
            add(st, tmp);
            st.push(-3);
            tmp = 0;
        }
        if (c == 'f' || c == ',') {
            if (i && isdigit(s[i - 1])) {
                st.push(tmp);
                tmp = 0;
            }
        }
        if (c == '(') {
            st.push(-2);
        }
        if (c == ')') {
            st.push(tmp);
            tmp = 0;
            add(st, tmp);
            multi(st, tmp);
            int mx, mn;
            mx = mn = st.top();
            while (st.top() != -2) {
                mx = max(mx, st.top());
                mn = min(mn, st.top());
                st.pop();
            }
            st.pop();
            cerr << st.top() << endl;
            st.push(mx - mn);
            cerr << "f: " << mx - mn << ' ' << mx << ' ' << mn << endl;
            add(st, tmp);
            multi(st, tmp);
        }
    }

    add(st, tmp);
    multi(st, tmp);
    cout << st.top() << endl;
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