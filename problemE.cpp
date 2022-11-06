#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// #define int long long
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
int x[MAXN];
multiset<int> st;
string s;

void sub1() {
    int ans = 0;
    
    for (int i = 0; i < m; i++) {
        switch (s[i]) {
        case '1':
            ans += *st.begin();
            st.erase(st.begin());
            break;
        case '2':
            ans += *(--st.end());
            st.erase(--st.end());
            break;
        case '3':
            for (int j = 0; j <= n + m; j++) {
                if (st.find(j) == st.end()) {
                    ans += j;
                    st.insert(j);
                    break;
                }
            }
            break;
        }

        if (i % 10 == 9) {
            cout << ans << endl;
            ans = 0;
        }
    }

    if (m % 10)
        cout << ans << endl;
}

void sub3() {
    int ans = 0;

    int mx = (st.size() ? *(--st.end()) : 0);
    int mex = 0;
    for (int i = 0; i <= n; i++) {
        if (st.find(i) == st.end()) {
            mex = i;
            break;
        }
    }

    bool toge = false;
    
    for (int i = 0; i < m; i++) {
        switch (s[i]) {
        case '2':
            if (!toge) {
                ans += *(--st.end());
                st.erase(--st.end());

                if (!st.size() || *(--st.end()) < mex) {
                    toge = true;
                    mx = mex - 1;
                }
                else if (st.size())
                    mx = *(--st.end());
            }
            else {
                ans += mx;
                mex--;
                mx--;
            }

            break;
        case '3':
            if (!toge) {
                ans += mex;
                for (int j = mex + 1; j <= n + m; j++) {
                    if (st.find(j) == st.end()) {
                        mex = j;
                        st.insert(j);
                        break;
                    }
                }
                if (mex > mx) {
                    toge = true;

                }
            }
            else {
                ans += mex;
                mex++;
                mx++;
            }
            break;
        }

        // cout << ans << endl;

        if (i % 10 == 9) {
            cout << ans << endl;
            ans = 0;
        }
    }

    if (m % 10)
        cout << ans << endl;
}

void sub4() {
    int ans = 0;
    int l1 = 0, l2 = 0, r1 = 0, r2 = 0;
    multiset<int> st2;
    for (int i = 0; i <= n + m; i++)
        st2.insert(i);

    int tmp;
    for (int i = 0; i < m; i++) {
        switch (s[i]) {
        case '1':
            tmp = *st.begin();
            st.erase(st.begin());
            st2.insert(tmp);
            ans += tmp;
            break;
        case '2':
            ans += *(--st.end());
            st2.insert(*(--st.end()));
            st.erase(--st.end());
            break;
        case '3':
            tmp = *st2.begin();
            st2.erase(tmp);
            st.insert(tmp);
            ans += tmp;
            break;
        }

        if (i % 10 == 9) {
            cout << ans << endl;
            ans = 0;
        }

        // cout << ans << endl;
    }

    if (m % 10)
        cout << ans << endl;
}

void sol() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    cin >> s;

    for (int i = 0; i < n; i++)
        st.insert(x[i]);

    bool isSub2 = true, isSub3 = true;

    if (n == 0) {
        sub4();
        return;
    }
    
    for (auto it: s) {
        if (it == '3')
            isSub2 = false;
        if (it == '1')
            isSub3 = false;
    }


    if (isSub3) {
        sub3();
        return;
    }

    if ((n <= 1000 && m <= 1000)|| isSub2) {
        sub1();
        return;
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