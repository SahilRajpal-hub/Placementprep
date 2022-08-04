#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> v){
    stack<int> s;
    vector<int> ans;

    for(int ind=v.size()-1; ind>=0; ind--){
        int i=v[ind];

        while(!s.empty() && s.top()>i) s.pop();

        if(s.empty()) ans.push_back(-1);
        else ans.push_back(s.top());

        s.push(i);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    // vector<int> v{1,3,0,2,5};
    vector<int> v{10,5,11,6,20,12};
    vector<int> ans = solve(v);
    for(int el:ans){
        cout<<el<<" ";
    }
    return 0;
}