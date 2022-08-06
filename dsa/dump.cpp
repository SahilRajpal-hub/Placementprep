#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int i, int j){
    cout<<i<<" "<<j<<endl;
    if(i==j) return true;
    while(i<j){
        cout<<s[i]<<" "<<s[j]<<endl;
        if(s[i]!=s[j]) return false;
        i++;j--;
    }
    return true;
}

int main(){
    string s = "ababab";
    cout<<isPalindrome(s,0,s.size()-1);
    return 0;
}