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
#define MAXN 25
#define MAXM 1000005 
int n, m;
int ans[5];
int s[MAXN];
int x;
void sol()
{
	cin >> n;
	cin.ignore();
	string in;
	string X;
	cin >> in;
	for(int j = 0; j < in.size(); j++)
		x += 1 << (in[j] - 'a');
	X = in;
	for(int i = 0, tmp; i < n; i++)
	{
		cin >> in;
		s[i] = 0;
		for(int j = 0; j < in.size(); j++)
			s[i] += 1 << (in[j] - 'a');	
	}
	for(int i = 0; i < n; i++)
		ans[0] += ((x & s[i]) == 0);
	for(int i = 0; i < n; i++)
		ans[1] += ((x & s[i]) == x);
	for(int i = 0; i < n; i++)
		ans[2] += ((x & s[i]) == s[i]);
	for(int i = 0; i < n; i++)
		ans[3] += ((x & s[i]) != 0 && !((x & s[i]) == s[i]) && !((x & s[i]) == x));
	for(int mask = 0; mask < (1 << X.size()); mask++)
	{
		int a1 = 0, a2 = 0;
		for(int i = 0; i < X.size(); i++)
		{
			if(mask & (1 << i))
				a1 += 1 << (X[i] - 'a');
			else a2 += 1 << (X[i] - 'a');
		}
		bool check = 1;
		for(int i = 0; i < n; i++)
			check &= !(!((a1 & s[i]) == 0) && !((a1 & s[i]) == a1) && !((a1 & s[i]) == s[i]));
		for(int i = 0; i < n; i++)
			check &= !(!((a2 & s[i]) == 0) && !((a2 & s[i]) == a2) && !((a2 & s[i]) == s[i]));
		ans[4] += check;
	}
	
	for(int it: ans) cout << it << " ";
	cout << endl;
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