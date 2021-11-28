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
	while(cin >> n && n)	
	{
		cin.ignore();
		string s;
		cin >> s;
		pii ans = {0, s.size() - 1};
		int tmp = 0;
		map<char, int> mp;
		for(int i = 0; i < n; i++)
		{
			mp[s[i]]++;
			if(mp.size() == 26)	
			{
				if(i - tmp + 1 < ans.S - ans.F + 1)
				{
					ans = {tmp, i};
				}
				for(; mp[s[tmp]] > 1 && tmp < n; tmp++)
				{
					mp[s[tmp]]--;
					if(i - tmp  < ans.S - ans.F + 1)
					{
						ans = {tmp + 1, i};
					}
				}
			}
		}
		if(ans.F == 0 && ans.S == s.size() - 1)
		{
			cout << "not found" << endl;
			continue;
		}
		for(int i = ans.F; i <= ans.S; i++) cout << s[i];
		cout << endl;
	}
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