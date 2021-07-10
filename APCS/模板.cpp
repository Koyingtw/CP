#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        if(n==1) cout<<"Yes\n";
        else 
        {
            bool b=1;
            while(n)
            {
                if(n%2&&n!=1) 
                {
                    cout<<"No\n";
                    b=0;
                    break;
                }
                n/=2;
            }
            if(b) cout<<"Yes\n";
        }
    }

    return 0;
}