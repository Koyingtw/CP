#include<bits/stdc++.h>
#define int long long
#define pr pair<int,int>
#define fr(i,a,b) for(int i=a;i<b;i++)
#define rf(i,a,b) for(int i=a;i>=b;i--)
#define M 100000

using namespace std;
int data[M],l[M],r[M];//設定三個陣列:原始數據、左子樹(l[i]指向data[i]的左子樹index)、右子樹
void insert(int i,int n)//i為判斷的點(由0開始 也就是最上面的節點) n為插入值的index
{
    if(data[n]>data[i])//如果數據較根結點大
    {
        if(r[i]==-1) //如果其根節點沒有右子樹
        {
            r[i]=n;//將其右子樹設為n
            return;
        }
        else return insert(r[i],n);//如果有東西，再從右子樹去判斷
    }
    else //小於等於一樣道理
    {
        if(l[i]==-1) 
        {
            l[i]=n;
            return;
        }
        else return insert(l[i],n);
    }
}

void search(int i,int n)
{
    if(n==data[i])//如果找到欲查詢數據則輸出當下index
    {
        cout<<i<<endl;
        return;
    }
    if(n>data[i])//如果欲查詢數據大於當前根結點
    {
        if(r[i]==-1)//如果該節點沒有右子樹 代表找無此數據
        {
            cout<<-1<<endl;
            return;
        }
        else return search(r[i],n);//否則從右子樹搜尋
    }
    else//小於亦然
    {
        if(l[i]==-1)
        {
            cout<<-1<<endl;
            return;
        }
        else return search(l[i],n);
    }
}

void dfs(int i)
{
    if(l[i]!=-1) dfs(l[i]);
    cout<<data[i]<<" "; 
    if(r[i]!=-1) dfs(r[i]);
}
queue<int> qbfs;
void bfs(int i)
{
    cout<<data[i]<<" ";
    if(l[i]!=-1) qbfs.push(l[i]);
    if(r[i]!=-1) qbfs.push(r[i]);
    if(qbfs.empty()) return;
    int a=qbfs.front();
    qbfs.pop();
    bfs(a);
}

void sol()
{
    int n;
    while(cin>>n)
    {
        cin>>data[0];
        l[0]=-1,r[0]=-1;
        fr(i,1,n)
        {
            cin>>data[i];
            l[i]=-1,r[i]=-1;
            insert(0,i);
        }
        bfs(0);
        int a;
        while(cin>>a)
        {
            search(0,a);
        }
    }
}

signed main()
{
    sol();
}