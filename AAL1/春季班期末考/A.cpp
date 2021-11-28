// Problem: A. 好看排列
// Contest: Codeforces - 2021 AA 競程 Level 1 春季期末考
// URL: https://codeforces.com/gym/331434/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma region
#pragma optimize("O3")
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
#define putarr(x) for(int i = 0; i < sizeof(x); i++) cout << x[i] << (" \n")[i == sizeof(x) - 1]; 
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f;
const int P = 1e9+7;

using namespace std;
#pragma endregion
/******************************************************************************/
#define MAXN 100005
#define MAXM 1000005 
int n, m;

void sol()
{
	cin >> n;
	cin.ignore();
	string s;
	cin >> s;
	int cnt = 0;
	sort(s.begin(), s.end(), greater<char>());
	do
	{
		bool yes = 1;
		for(int i = 1; i < n; i++)
			yes &= (s[i] != s[i - 1]);
		if(yes) cout << s << endl;
		cnt += yes;
	}while(prev_permutation(s.begin(), s.end()));
	if(!cnt) cout << "Scandalous!" << endl;
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