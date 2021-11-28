const int MAXN = 5e5+5;

struct Line{
    int m,b;
    int operator()(int x) {
        return m*x+b;
    }
};

Line tr[MAXN<<2]; 

void insert(Line seg, int idx = 1, int l = 0, int r = N-1){
    if(l==r){
        if(seg(l) > tr[idx](l)){
            tr[idx] = seg;
        }
        return;
    }   
    int mid = l+r>>1;
    if(tr[idx].m > seg.m) swap(tr[idx],seg);
    if(tr[idx](mid) < seg(mid)){
        swap(tr[idx],seg);
        insert(seg,idx<<1,l,mid);
    }else insert(seg,idx<<1|1,mid+1,r);
}

int query(int x, int idx = 1, int l = 0, int r = N-1){
    if(l==r) return tr[idx](x);
    int mid = l+r>>1;
    if(x <= mid) return max(tr[idx](x), query(x, idx<<1, l, mid));
    else return max(tr[idx](x),query(x,idx<<1|1,mid+1,r));
}