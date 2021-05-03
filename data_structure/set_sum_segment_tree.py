#include <bits/stdc++.h>
using namespace std;
struct Node{
    int left, right;
    int num=0;
    int setnum=0;
};

#define N 100005
#define INF 94879487
struct Node seg_tree[100005]; 

void build(int left, int right, int index=1){
    seg_tree[index].left = left;
    seg_tree[index].right = right;

    if (left != right){
        int mid = (left + right) >> 1;
        build(left, mid, index*2);
        build(mid + 1, right, index*2 + 1);
    }
}

void push_down(int index){
    if (seg_tree[index].setnum != INF){
        seg_tree[2*index].setnum = seg_tree[index].setnum;
        seg_tree[2*index + 1].setnum = seg_tree[index].setnum;

        seg_tree[2*index].num =
            (seg_tree[2*index].right - seg_tree[2*index].left + 1) *
            seg_tree[index].setnum;
        
        seg_tree[2*index+1].num =
            (seg_tree[2*index+1].right - seg_tree[2*index+1].left + 1) *
            seg_tree[index].setnum;
        
        seg_tree[index].setnum = INF;

        return;
    }
}

void setnum(int left, int right, int num, int index=1){
    if (left == seg_tree[index].left && right == seg_tree[index].right){
        seg_tree[index].setnum = num;
        seg_tree[index].num = num * (right - left + 1);
        return;
    }
    push_down(index);
    
    int mid = (seg_tree[index].left + seg_tree[index].right) >> 1;

    if (mid < left){
        setnum(left, right, num, index*2 + 1);
    } else if (mid >= right){
        setnum(left, right, num, index*2);
    } else {
        setnum(left, mid, num, index*2);
        setnum(mid+1, right, num, index*2 + 1);
    }
    seg_tree[index].num = seg_tree[index*2].num + seg_tree[index*2+1].num;
}

int getsum(int left, int right, int index=1){
    if (left == seg_tree[index].left && right == seg_tree[index].right){
        return seg_tree[index].num;
    }

    push_down(index);

    int mid = (seg_tree[index].left + seg_tree[index].right) >> 1;
    int ans;
    if (mid < left){
        ans = getsum(left, right, index*2 + 1);
    } else if (mid >= right){
        ans = getsum(left, right, index*2);
    } else {
        ans = getsum(left, mid, index*2) +
              getsum(mid+1, right, index*2 + 1);
    }
    seg_tree[index].num = seg_tree[index*2].num + seg_tree[index*2+1].num;
    return ans;
}

int main(){
    build(1,10);
    setnum(1,1,5);
    setnum(2,5,4);
    setnum(2,2,3);
    cout << getsum(1,3) << endl;
}
