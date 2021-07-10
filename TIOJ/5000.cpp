/*
.-..-.             _             
: :' ;            :_;            
:   '  .--. .-..-..-.,-.,-. .--. 
: :.`.' .; :: :; :: :: ,. :' .; :
:_;:_;`.__.'`._. ;:_;:_;:_;`._. ;
             .-. :          .-. :
             `._.'          `._.'
*/

#include<bits/stdc++.h>
#define int long long
#define pr pair<int,int>
#define fr(i,a,b) for(int i=a;i<b;i++)
#define rf(i,a,b) for(int i=a;i>=b;i--)
#define Koying ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);


using namespace std;

pr x[50005];

bool cmpx(pr a, pr b)
{
    return a.first*a.second < b.first*b.second;
}

bool cmpy(pr a, pr b)
{
    if(a.first == b.first)
        return a.second < b.second;
    else return a.first < b.first;
}

double DQ(int l, int r)
{
    int m = (l+r) / 2;
    double mn = 1e20;

    if(r-l == 1)
    {
        return 1e20;
    }
    if(r-l == 2)
    {
        double rtn;
        rtn = (x[r].first-x[l].first)*(x[r].first-x[l].first);
        rtn += (x[r].second-x[l].second)*(x[r].second-x[l].second);
        rtn = sqrt(rtn); 
        return rtn;
    }
    if(r-l == 3)
    {
        double rtn; 
        
        fr(i,l,r-1)
        {
            fr(j,i+1,r)
            {                
                rtn = (x[j].first-x[i].first)*(x[j].first-x[i].first);
                rtn += (x[j].second-x[i].second)*(x[j].second-x[i].second);
                rtn = sqrt(rtn);
                mn = min(mn, rtn);
            }
        }
        return mn;
    }

    sort(x+l,x+r,cmpy);

    mn = min(DQ(l,m), DQ(m,r));
    fr(i,l,m)
    {
        fr(j,m,r)
        {
            double rtn;
            rtn = (x[j].first-x[i].first)*(x[j].first-x[i].first);
            rtn += (x[j].second-x[i].second)*(x[j].second-x[i].second);
            rtn = sqrt(rtn);
            mn = min(mn, rtn);
        }
    }
    return mn;
}

void sol()
{
    int n;
    while(cin >> n)
    {
        double mn = 1e9;
        fr(i,0,n)
        {
            cin >> x[i].first >> x[i].second;
        }
        
        sort(x,x+n,cmpx);
        cout << fixed << setprecision(6) << DQ(0,n) << endl;
    }
}


signed main()
{
    Koying
    sol();
    return 0;
}