#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return (a>b);
}
int main()
{
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int x[n],a=0,b=0,ca=0,cb=0;
        vector<int> va,vb;
        
        for(int i=0;i<n;i++)
        {
            cin>>x[i];
            
            if(x[i]%2==0) 
            {
                a+=x[i];
                ca++;
                va.push_back(x[i]);
            }
            else if(x[i]%2) 
            {
                b+=x[i];
                cb++;
                vb.push_back(x[i]);
            }
            
        }
        sort(va.begin(),va.end(),cmp);
        sort(vb.begin(),vb.end(),cmp);
        if(ca==cb||ca*cb==0) 
        {
            if(a>b||ca) cout<<"Alice\n";
            else if(b>a||cb) cout<<"Bob\n";
        }
        else 
        {
            if(ca<cb)
            {
                int q=(cb-ca)/2+(cb-ca)%2,i=0;
                if(q>=n/2)
                {
                    cout<<"Bob\n";
                    continue;
                }
                while(q--)
                {
                    b-=vb[i];
                    i+=2;
                }
            }
            else
            {
                int q=(ca-cb)/2+(ca-cb)%2,i=1;
                if(q>=n/2)
                {
                    cout<<"Alice\n";
                    continue;
                }
                while(q--)
                {
                    a-=va[i];
                    i+=2;
                }
            }
            if(a>b) cout<<"Alice\n";
            else if(b>a) cout<<"Bob\n";
            else cout<<"Tie\n";
        }


        
        
        
    }
    

    return 0;
}