#include <bits/stdc++.h>
using namespace std;


int sum(vector<int> v){
    int s = 0;
    for(int i:v) s+=i;
    return s;
}

int solve(const vector<int> &A) {
    vector<int> a=A;
    int n = A.size();
    if(n==1) return 0;
    int s = sum(A);
    int rem = s/2;
    
    sort(a.begin(), a.end(), greater<int>());
    
    int cnt = 0;
    for(int i=0; i<n; i++){
        cout<<rem<<" "<<cnt<<" ";
        if(a[i]<=rem){
            rem -= a[i];
            cnt++;
            if(rem==0) break;
        }
    }
    cout<<endl;
    return cnt;
}



int main()
{
    vector<int> v = {8, 4, 5, 7, 6, 2 };
    cout<<solve(v)<<endl;

}