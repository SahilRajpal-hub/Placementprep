#include <bits/stdc++.h>
using namespace std;


int equilibriumPoint(long long arr[], int n) {
    if(n==1) return 1;
    long long sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    long long ps = 0;
    for(int i=0; i<n; i++){
        long long tmp = sum-arr[i];
        if(tmp%2==0 && tmp/2==ps){
            return i+1;
        }
        ps+=arr[i];
    }
    return -1;
}



int main(){
    return 0;
}