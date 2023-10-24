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
#define MAXN 105
#define MAXM 1000005 
int n, m, k;
int x[MAXN], y[MAXN];
multiset<pii> A, B;
map<int, int> v;
map<pii, int> played;


void sol() {
    cin >> n >> m >> k;
    int ans = 0;
    A.clear(), B.clear();
    played.clear();
    v.clear();

    for (int i = 0; i < n; i++) {
        cin >> x[i];
        ans += x[i];
        A.insert(pii(x[i], x[i]));
    }   
    for (int i = 0; i < m; i++) {
        cin >> y[i];
        B.insert(pii(y[i], y[i]));
    }

    v[0] = ans;
    // played[As] = 0;

    
    for (int i = 1; i <= k; i++) {
        if ((*A.begin()).F == (*A.rbegin()).F && (*A.begin()).F == (*B.rbegin()).F && (*B.begin()).F == (*B.rbegin()).F) {
            cout << ans << endl;
            return;
        }
        if (i % 2) {
            auto aa = *A.begin(), bb = *B.rbegin();
            if (aa.F < bb.F) {
                if (i > 1 && played.find(pii(aa.S, bb.S)) != played.end()) {
                    k %= i - played[pii(aa.S, bb.S)];
                    int last = (*v.begin()).S;
                    for (auto it: v) {
                        if (it.F == k) {
                            cout << v[k] << endl;
                            return;
                        }
                        else if (it.F > k) {
                            cout << last << endl;
                            return;
                        }
                        last = it.S;
                    }
                    return;
                }
                ans = ans - aa.F + bb.F;
                A.erase(A.find(aa));
                B.erase(B.find(bb));
                A.insert(bb);
                B.insert(aa);
                played[pii(aa.S, bb.S)] = i;
                v[i] = ans;
            }
        }
        else {
            auto aa = *A.rbegin(), bb = *B.begin();
            if (aa.F > bb.F) {
                if (i > 1 && played.find(pii(aa.S, bb.S)) != played.end()) {
                    k -= played[pii(aa.S, bb.S)] - 1;
                    k %= i - played[pii(aa.S, bb.S)];
                    k += played[pii(aa.S, bb.S)] - 1;
                    int last = (*v.begin()).S;
                    for (auto it: v) {
                        if (it.F == k) {
                            cout << v[k] << endl;
                            return;
                        }
                        else if (it.F > k) {
                            cout << last << endl;
                            return;
                        }
                        last = it.S;
                    }
                    return;
                }
                ans = ans - aa.F + bb.F;
                A.erase(A.find(aa));
                B.erase(B.find(bb));
                A.insert(bb);
                B.insert(aa);
                played[pii(aa.S, bb.S)] = i;
                v[i] = ans;
            }
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