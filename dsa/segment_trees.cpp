#include <bits/stdc++.h>
using namespace std;

//* implemented using array(like a heap)
// ? currNode = i then leftChild = (2*i)+1 and rightChild = (2*i)+2 and parent=floor((i-1)/2)
// ? height of segment tree = log(N+1) and size of segment tree array = 2^h-1
// ! construction = O(N), Query = O(logN) amd update = O(logN) -> only useful when updates are frequent otherwise prefix array

int constructST(int* st, int si, int *arr, int l, int r){
    if(l==r) {   // * leaf node
        st[si]=arr[l];
        return arr[l];
    }
    int mid = (l+r)/2;
    st[si] = constructST(st,2*si+1,arr,l,mid) + constructST(st,2*si+2,arr,mid+1,r);
    return st[si];
}

int getSum(int *st, int si, int sl, int sr, int l, int r){
    if(l<=sl && r>=sr){   // TODO CASE-1 Total Overlap
        return st[si];
    }
    if(sr<l || sl>r){     // TODO CASE-2 No Overlap
        return 0;
    }
    int mid = (sl+sr)/2;  // TODO CASE-3 Partial Overlap
    return getSum(st,2*si+1,sl,mid,l,r)+getSum(st,2*si+2,mid+1,sr,l,r);
}

void update(int* st, int si, int sl, int sr, int pos, int diff){
    if(sl>pos || sr<pos){
        return;
    }
    st[si] += diff;
    if(sl!=sr){
        int mid = (sl+sr)/2;
        update(st,2*si+1,sl,mid,pos,diff);
        update(st,2*si+2,mid+1,sr,pos,diff);
    }
}


int main(){
    int arr[3];
    // arr[0]=;
    // arr[1]=;
    // arr[2]=;

    return 0;
}