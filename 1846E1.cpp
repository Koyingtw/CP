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
// bitset<MAXM> b;
set<int> st;
int a[1000000];

#pragma constexpr_depth 100000000


void pre() {
    int N = pow(10, 18); // to get all terms <= N
    // vector<int> V(N, 0);

    int now = 0;
    for (int b = 2; (pow(b, 3) - 1)/(b - 1) <= N; b++) {
        vector<int> inds;
        int limit = floor(log(N * (b - 1) + 1) / log(b));
        
        for (int k = 3; k <= limit; k++) {
            int index = (pow(b, k) - 1) / (b - 1);
            a[now++] = index;
            // inds.push_back(index);
        }
        
        // for (int i : inds) {
        //     // V[i] = 1;
        //     st.insert(i);
        // }
    }
    cout << "Done" << endl;
}

// 6, 8, 10, 12, ...
// 25, 45, 65

// constexpr std::array<int, 1000000> calculateSequence() {
//     std::array<int, 1000000> sequence{};
//     int now = 0;

//     for (int b = 2; (std::pow(b, 3) - 1) / (b - 1) <= 1e18; b++) {
//         int limit = std::floor(std::log(1e18 * (b - 1) + 1) / std::log(b));

//         for (int k = 3; k <= limit; k++) {
//             int index = (std::pow(b, k) - 1) / (b - 1);
//             sequence[now++] = index;
//         }
//     }

//     return sequence;
// }

void sol() {
    cin >> n;
    // cout << (b[n] ? "YES" : "NO") << endl;

    // constexpr std::array<int, 1000000> sequence = calculateSequence();
    
}

signed main() {
    Weakoying;
    int t = 1;
    pre();
    while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}