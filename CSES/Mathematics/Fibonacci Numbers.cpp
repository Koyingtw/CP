// Problem: Fibonacci Numbers
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1722
// Memory Limit: 512 MB
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
vector<int> A{1, 1, 1, 0}, B{1, 1, 1, 0};

vector<int> multi(vector<int> a, vector<int> b)
{
	vector<int> tmp{0, 0, 0, 0};
	tmp[0] = a[0] * b[0] + a[1] * b[2];
	tmp[1] = a[0] * b[1] + a[1] * b[3];
	tmp[2] = a[2] * b[0] + a[3] * b[2];
	tmp[3] = a[2] * b[1] + a[3] * b[3];
	return tmp;
}

void mod()
{
	for(int i = 0; i < 4; i++)
		A[i] %= P;
}

void sol()
{
	cin >> n;
	stack<int> st;
	n--;
	if(n <= 0)
	{
		cout << (n == 0) << endl;
		return;
	}
	// cout << multi(A, A)[0] << endl;
	while(n)
	{
		st.push(n & 1);
		n >>= 1;
	}
	st.pop();
	while(st.size())
	{
		A = multi(A, A);
		if(st.top())
			A = multi(A, B);
		st.pop();
		mod();
	}
	cout << A[0]<< endl;
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