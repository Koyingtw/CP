#pragma region
#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define pr pair<int, int>
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define DB(a) cout << a << endl;
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#if ONLINE_JUDGE
#define endl "\n"
#endif
#define lowbit(x) x &(-x)
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/
#define MAXN 200005
int timestamp = 0, sccID = 0;
int D[MAXN], L[MAXN], contract[MAXN];
vector<int> v[MAXN];
stack<int> st;
bitset<MAXN> inSt;
void dfs(int i, int fa)
{
    D[i] = L[i] = timestamp++;
    st.push(i);
    inSt[i] = true;

    for (int w : v[i])
    {
        if (w == fa)
            continue;
        if (!D[i])
        {
            dfs(w, i);
            L[i] = min(L[i], L[w]);
        }
        else if (inSt[w])
            L[i] = min(L[i], D[e]);
    }

    if (D[i] == L[i])
    {
        int a;
        do
        {
            a = st.top();
            st.pop();
            inSt[a] = false;
            contract[a] = sccID;
        } while (a != i);
        sccID++;
    }
}

void sol()
{
}

signed main()
{
    Koying;
    int t = 1;
    while (cin >> t)
        while (t--)
        {
            sol();
        }
    return 0;
}