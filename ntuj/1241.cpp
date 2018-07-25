#include <bits/stdc++.h>
using namespace std;

struct node{
    int l,r;
    int seg, l_seg, r_seg;
    int nsame;
} seg_tree[201000 * 4];

// 閉閉區間
void build_tree(int index, int l, int r){
    seg_tree[index].l = l;
    seg_tree[index].r = r;
    seg_tree[index].nsame = 0;
    seg_tree[index].l_seg = 0;
    seg_tree[index].r_seg = 0;
    seg_tree[index].seg = 0;

    if (l == r)
        return;

    int mid = (l+r) / 2;

    build_tree(index*2,l,mid);
    build_tree(index*2 + 1, mid+1, r);
}

void update(int node, int pos){
    if (seg_tree[node].l  > pos || seg_tree[node].r < pos )
        return;

    if (seg_tree[node].r == seg_tree[node].l){
        seg_tree[node].nsame = 1 - seg_tree[node].nsame;  
        seg_tree[node].l_seg = seg_tree[node].r_seg = seg_tree[node].seg = seg_tree[node].nsame; 
        return;
    }




    int left = node << 1, right = (node << 1) + 1;
    
    update(left, pos);
    update(right, pos);
    
    if (seg_tree[left].l_seg == (seg_tree[left].r - seg_tree[left].l + 1))
        seg_tree[node].l_seg = seg_tree[left].l_seg + seg_tree[right].l_seg;
    else
        seg_tree[node].l_seg = seg_tree[left].l_seg;

    if (seg_tree[right].r_seg == (seg_tree[right].r - seg_tree[right].l + 1))
        seg_tree[node].r_seg = seg_tree[left].r_seg + seg_tree[right].r_seg;
    else
        seg_tree[node].r_seg = seg_tree[right].r_seg;
    
    seg_tree[node].seg = max(seg_tree[node].l_seg,seg_tree[node].r_seg);
    seg_tree[node].seg = max(seg_tree[right].l_seg + seg_tree[left].r_seg, seg_tree[node].seg);
    seg_tree[node].seg = max(seg_tree[right].seg, seg_tree[node].seg);
    seg_tree[node].seg = max(seg_tree[left].seg, seg_tree[node].seg);
}

int main(){
    int N, Q;
    while(cin >> N){
        if (cin.eof()){
            break;
        }
        cin >> Q;

        build_tree(1,1,N-1); // record change only XD

        while(Q--){
            int pos;
            cin >> pos;
            if (pos != 1)
                update(1,pos-1);
            if (pos != N-1)
                update(1,pos);         
            cout << seg_tree[1].seg + 1 << endl;
        }
    }
}
