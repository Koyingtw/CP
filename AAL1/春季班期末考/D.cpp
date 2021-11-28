// Problem: D. 計算時間複雜度
// Contest: Codeforces - 2021 AA 競程 Level 1 春季期末考
// URL: https://codeforces.com/gym/331434/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
	vector<string> v;
	string s;
	string loop;
	while(getline(cin, s))
	{
		if(s.size() > 3 && s[0] == 'f' && s[1] == 'o' && s[2] == 'r')
			loop  = s;
	}	
	int mx = 0, cnt = 0;
	for(int i = 0; i < loop.size(); i++)
	{
		if(loop[i] == '{')
			cnt++;
		else if(loop[i] == '}')
			cnt--;
		cmax(mx, cnt);
	} 
	if(mx == 0)
		cout << "Theta(1)" << endl;
	else cout << "Theta(n^" << mx << ")" << endl;

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