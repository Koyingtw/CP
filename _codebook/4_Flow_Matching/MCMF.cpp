struct Cost_flow{
    static const int N=5E3+6;
    static const int INF =0x3f3f3f3f;
    struct Edge{
        int to,cap,rev,cost;
        Edge(){}
        Edge(int _to,int _cap,int _rev,int _cost):to(_to),
        cap(_cap),rev(_rev),cost(_cost){}
    };
    vector<Edge> G[N];
    void add_edge(int from,int to,int cap,int cost){
        G[from].push_back(Edge(to,cap,(int)G[to].size(),cost));
        G[to].push_back(Edge(from,0,(int)G[from].size()-1,-cost));
    }
    int n,s,t;
    void init(int _n,int _s,int _t){
        n=_n,s=_s,t=_t;
        for(int i=0;i<=n;++i)
            G[i].clear();
    }
    int par[N],par_id[N],dis[N];
    bool in_que[N];
    pair<int,int> flow(){
        int flow=0,cost=0;
        while(true){
            memset(dis,INF,sizeof(dis));
            memset(in_que,0,sizeof(in_que));
            dis[s]=0;
            queue<int> que;que.push(s);
            while(!que.empty()){
                int tmp=que.front();que.pop();
                in_que[tmp]=false;
                for(int eid=0;eid<(int)G[tmp].size();++eid){
                    Edge e=G[tmp][eid];
                    if(e.cap>0 && dis[e.to]>dis[tmp]+e.cost){
                        dis[e.to]=dis[tmp]+e.cost;
                        par[e.to]=tmp;
                        par_id[e.to]=eid;
                        if(!in_que[e.to]){
                            in_que[e.to]=true;
                            que.push(e.to);
                        }
                    }
                }
            }
            if(dis[t]>=INF) break;
            int mn_flow=INF;
            for(int i=t;i!=s;i=par[i]){
                mn_flow=min(mn_flow,G[par[i]][par_id[i]].cap);
            }
            flow+=mn_flow,cost+=mn_flow*dis[t];
            for(int i=t;i!=s;i=par[i]){
                G[par[i]][par_id[i]].cap-=mn_flow;
                G[i][G[par[i]][par_id[i]].rev].cap+=mn_flow;
            }
        }
        return make_pair(flow,cost);
    }
}mcmf;
