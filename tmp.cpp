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
/******************************************************************************/#define MAXN 5005
#define MAXM 1000005
int n, m;
bitset<MAXN> notPrime;
vector<int> prime;
void pre() {
	    for (int i = 2; i < MAXN; i++) {
		            if (!notPrime[i]) {
				                prime.push_back(i);
						            for (int j = i * i; j < MAXN; j += i)
								                    notPrime[j] = true;
							            }
			        }
}
void sol() {
	    set<int> st;
	        for (int i = 0; i < prime.size(); i++) {
			        for (int j = i + 1; j < prime.size(); j++) {
					            if (prime[i] + prime[j] <= 65)
							                    st.insert(prime[i] + prime[j]);
						            }
				    }
		    for (int i = 5; i <= 65; i++) if (!st.count(i)) {
			            bool can = true;
				            for (int j = 2; j < i; j++) {
						                if (i - j >= 2 * j && ((!notPrime[j]) || (!notPrime[i - j]))) {
									                can = false;
											            }
								        }
					            cout << i << ' ' << can << endl;
						        }
}
signed main() {
	    Weakoying;
	        int t = 1;
		    pre();
		        // while (cin >> t)
			//         {
			//                 while (t--) {
			//                             sol();
			//                                     }
			//                                         }
			//                                             return 0;
			//                                             }
