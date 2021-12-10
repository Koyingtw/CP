#pragma region
#pragma GCC optimize("O3")
#pragma GCC target("avx")
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
#define putarr(x) for(int i = 0; i < sizeof(x); i++) cout << x[i] << (" \n")[i == sizeof(x) - 1]; 
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f;
const int P = 1e9;
const int PP = 2e9;
using namespace std;
#pragma endregion
/******************************************************************************/
#define MAXN 1000005
#define MAXM 1000005 
int n, m;

// unordered_set<int> sx, sy, s1, s2;
bitset<3000000010> bx, by;
bitset<5000000010> b1, b2;
// map<int, int> cntx, cnty, cnt1, cnt2;
void sol()
{
	cin >> n;
	int ans = 0;
	for(int i = 0, a, b; i < n; i++)
	{
		cin >> a >> b;
		ans += bx[a + P];
		ans += by[b + P];
		ans += b1[a + b + PP];
		ans += b2[a - b + PP];
		bx[a + P] = 1;
		by[b + P] = 1;
		b1[a + b + PP] = 1;
		b2[a - b + PP] = 1;
		// ans += !sx.insert(a).S;
		// ans += !sy.insert(b).S;
		// ans += !s1.insert(a + b).S;
		// ans += !s2.insert(a - b).S;
	}

	
	cout << ans << endl;
}

signed main()
{
    Weakoying;
    int t = 1;
    //while (cin >> t)
    {
    	while (t--)
        {
            sol();
        }
    }
        
    return 0;
}