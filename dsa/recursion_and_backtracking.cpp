#include <bits/stdc++.h>
using namespace std;

// *** Find all subsequences
void printSubsequence(string input, string output, vector<string> &ans)
{
    if (input.empty()) {
        ans.push_back(output);
        return;
    }
 
    printSubsequence(input.substr(1), output + input[0], ans);
 
    printSubsequence(input.substr(1), output, ans);
}

// *** Subsets -> Given an integer array nums of unique elements, return all possible subsets (the power set).s
void solve(vector<int> nums,vector<vector<int>> &ans,vector<int> output,int i){
    if(i>=nums.size()){
        ans.push_back(output);
        return;
    }
    
    // *** leave the element at index i 
    solve(nums,ans,output,i+1);
    
    // *** take the element at index i 
    output.push_back(nums[i]);
    solve(nums,ans,output,i+1);
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> output;
    solve(nums,ans,output,0);
    return ans;
}

// *** Letter Combinations of a Phone Number
void solve(vector<string> &ans, string digits, int index, string output, vector<string> values){
    if(index==digits.size()){
        ans.push_back(output);
        return;
    }
    string value = values[digits[index]-'0'];
    for(int i=0; i<value.size(); i++){
        output.push_back(value[i]);
        solve(ans,digits,index+1,output,values);
        output.pop_back();
    }
}
vector<string> letterCombinations(string digits) {
    if(digits=="") return {}; 
    vector<string> values = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    int startingIndex = 0;
    string output = "";
    solve(ans, digits, startingIndex, output, values);
    return ans;
}

// *** Permutation of string
void solve(string s, set<string> &st, int idx){
    if(idx==s.size()){
        st.insert(s);
        return;
    }
    
    for(int i=idx; i<s.size(); i++){
        swap(s[idx],s[i]);
        solve(s,st,idx+1);
        swap(s[i],s[idx]);
    }
    
}
vector<string> find_permutation(string s)
{
    set<string> st;
    
    solve(s,st,0);
    vector<string> ans(st.begin(),st.end());
    
    return ans;
}

// *** Permutation of set
void solve(vector<vector<int>> &ans, vector<int> nums, int idx){
    if(idx==nums.size()){
        ans.push_back(nums);
        return;
    }
    
    for(int i=idx; i<nums.size(); i++){
        swap(nums[i],nums[idx]);
        solve(ans,nums,idx+1);
        swap(nums[idx],nums[i]);
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    
    solve(ans,nums,0);
    
    return ans;
}

// *** Rat in a Maze Problem - I
bool isValid(pair<int,int> pr, int n,vector<vector<int>> m){
    return (pr.first>=0 && pr.second>=0 && pr.first<n && pr.second<n && m[pr.first][pr.second]==1);
}
void solve(vector<string> &ans, vector<vector<int>> m, pair<int,int> pr, int n, string path){
    if(!isValid({pr.first,pr.second},n,m)) return;
    
    if(pr.first==n-1 && pr.second==n-1){
        ans.push_back(path);
        return;
    }
    m[pr.first][pr.second]=0;
    
    // left
    path.push_back('L');
    solve(ans,m,{pr.first,pr.second-1},n,path);
    path.pop_back();
    
    // right
    path.push_back('R');
    solve(ans,m,{pr.first,pr.second+1},n,path);
    path.pop_back();

    
    // up
    path.push_back('U');
    solve(ans,m,{pr.first-1,pr.second},n,path);
    path.pop_back();
    
    //down
    path.push_back('D');
    solve(ans,m,{pr.first+1,pr.second},n,path);
    path.pop_back();
    
    
    m[pr.first][pr.second]=1;
}
vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<string> ans;
    if(n==0 || m[0][0]==0) return ans;
    solve(ans,m,{0,0},n,"");
    return ans;
}

int main(){
    
}