#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
void printVector(vector<int> v);
void merge(vector<int> &v, int s, int m, int e){
    int i=s,j=m+1,idx=s;
    vector<int> va(v.size());
    while(i<=m && j<=e){
        if(v[i]<v[j]){
            va[idx++] = v[i++];
        }else{
            va[idx++] = v[j++];
            cnt += m-i+1;
        }
    }
    while(i<=m) va[idx++]=v[i++];
    while(j<=e) va[idx++]=v[j++];
    for(int i=s; i<=e; i++){
        v[i]=va[i];
    }
    va.clear();
}

void mergeSort(vector<int> &v, int s, int e){
    if(s>=e) return;
    int m = (s+e)/2;
    mergeSort(v,s,m);
    mergeSort(v,m+1,e);
    merge(v,s,m,e);
}

void printVector(vector<int> v){
    for(int i:v) cout<<i<<" ";
    cout<<endl;
}


int main(){
    vector<int> v{3,5,6,1,2,4};
    mergeSort(v,0,v.size()-1);
    printVector(v);
    cout<<cnt<<endl;
    return 0;
}