#include <bits/stdc++.h>
using namespace std;

// *** <------------------- Fixed Size sliding window problems ------------------------------>
// *** Max/Min subarray of size K
long maximumSumSubarray(int K, vector<int> &Arr , int N){
    long long res=INT_MIN,sum = 0;
    int i=0,j=0;
    while(j<N){
        sum += Arr[j];

        if(j-i+1==K){    // ? window size hit, Update the answer and move the start pointer
            res=max(res,sum);
            sum -= Arr[i];
            i++;
        }
        j++;
    }
    return res;
}

// *** First Negative in every window of size k
vector<int> printFirstNegativeInteger(int A[], int N,int K) {
    int i=0,j=0;
    vector<int> ans;
    queue<int> fn;
    while(j<N){
        if(A[j]<0) fn.push(j);
        if(j-i+1==K){
            if(fn.empty()) ans.push_back(0);
            else ans.push_back(A[fn.front()]);
            if(!fn.empty() && fn.front()==i) fn.pop();
            i++;
        }
        j++;
    }
    return ans;
}

// *** Count occurence of anagram
bool isAnagram(int* countT, int* countP){
    for(int i=0; i<256; i++){                    // ? This is O(1) as 256 is contant
        if(countT[i]!=countP[i]) return false;
    }
    return true;
}
int search(string pat, string txt) {
    int ans = 0;
    int countP[256];
    memset(countP,0,sizeof(countP));
    
    for(int i=0; i<pat.size(); i++){
        countP[pat[i]]++;
    }
    
    int countT[256];
    memset(countT,0,sizeof(countT));
    int i=0,j=0;
    while(j<txt.size()){
        countT[txt[j]]++;
        if(j-i+1==pat.size()){
            if(isAnagram(countT,countP)) ans++;
            countT[txt[i]]--;
            i++;
        }
        j++;
    }
    return ans;
}

// *** Maximum of all subarray of size k
vector<int> maxSlidingWindow(vector<int>& arr, int k) {
    vector<int> ans;
    int n = arr.size();
    int i=0,j=0;
    deque<int> dq;
    while(j<n){
        while(!dq.empty() && dq.back()<arr[j]){
            dq.pop_back();
        }
        dq.push_back(arr[j]);
        if(j-i+1==k){
            ans.push_back(dq.front());
            if(!dq.empty() && dq.front()==arr[i]) dq.pop_front();
            i++;
        }
        j++;
    }
    return ans;
}

// *** Maximum of min for every window size
vector<int> nextSmallerLeft(int arr[], int n){
    stack<int> s;
    vector<int> ans;
    ans.push_back(-1);
    s.push(0);
    for(int i=1; i<n; i++){
        while(!s.empty() && arr[i]<=arr[s.top()]){
            s.pop();
        }
        
        if(s.empty()) ans.push_back(-1);
        else ans.push_back(s.top());
        s.push(i);
    }
    return ans;
}
vector<int> nextSmallerRight(int arr[], int n){
    stack<int> s;
    vector<int> ans;
    ans.push_back(n);
    s.push(n-1);
    for(int i=n-2; i>=0; i--){
        while(!s.empty() && arr[i]<=arr[s.top()]){
            s.pop();
        }
        
        if(s.empty()) ans.push_back(n);
        else ans.push_back(s.top());
        s.push(i);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
vector<int> maxOfMin(int arr[], int n)
{
    vector<int> nsl = nextSmallerLeft(arr,n);
    vector<int> nsr = nextSmallerRight(arr,n);
    vector<int> wins(n,0);
    for(int i=0; i<n; i++){
        wins[nsr[i]-nsl[i]-2]=max(arr[i],wins[nsr[i]-nsl[i]-2]);
    }
    for(int i=n-2; i>=0; i--){
        wins[i] = max(wins[i],wins[i+1]);
    }
    return wins;
}

// *** Substring with Concatenation of All Words
bool contains(map<string,int> scount, string s, int ns){
    map<string,int> mp;
    for(int i=0; i<s.size(); i+=ns){
        if(scount.count(s.substr(i,ns))==0) return false;
        mp[s.substr(i,ns)]++;
    }
    return mp==scount;
}
vector<int> findSubstring(string s, vector<string>& words) {
    map<string,int> scount;
    for(int i=0; i<words.size(); i++){
        scount[words[i]]++;
    }
    
    int ws = words[0].size()*words.size();
    if(s.size()<ws) return {};
    int i=0,j=0;
    vector<int> ans;
    
    for(int i=0; i<=s.size()-ws; i++){
        cout<<i<<endl;
        if(contains(scount,s.substr(i,ws),words[0].size())){
            cout<<s.substr(i,ws)<<endl;
            ans.push_back(i);
        }
    }
    
    return ans;
}


// *** <------------------- Variable Size sliding window problems ------------------------------>
// *** Largest/Smallest subarray of sum K
// TODO -> For Non Negative Integers
int lenOfLongSubarr(int A[],  int N, int k) 
{ 
    int i=0,j=0;
    int sum = 0;
    int ans = 0;
    while(j<N){
        if(sum<k){
            sum += A[j];
            j++;
        }
        else if(sum==k){
            ans = max(ans,j-i);
            sum -= A[i];
            i++;
        }
        else if(sum>k){
            sum -= A[i];
            i++;
        }
    }
    return ans;
}
// TODO -> For Negative Intergers <--- doesn't use sliding window approach --->
int lenOfLongSubarr(int A[],  int N, int k) 
{ 
    int cs=0;
    unordered_map<int,int> mp;
    mp[0]=-1;
    int ans = 0;
    for(int i=0; i<N; i++){
        cs += A[i];
        if(mp.count(cs-k)>0){
            ans = max(ans,i-mp[cs-k]);
        }
        if(mp.count(cs)==0){
            mp[cs]=i;
        }
    }
    return ans;
} 

// *** Largest substring of k distinct character
int longestKSubstr(string s, int k) {
    unordered_map<char,int> mp;
    int i=0,j=0,n=s.size();
    int ans = -1;
    while(j<n){
        mp[s[j]]++;
        int sz = mp.size();
        if(sz<k){
            j++;
        }else if(sz==k){
            ans=max(ans,j-i+1);
            j++;
        }else if(sz>k){
            while(mp.size()>k){
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
            }
            j++;
        }
    }
    return ans;
}

// *** Length of largest substring of No repeating character
int lengthOfLongestSubstring(string s) {
    set<char> st;
    int i=0,j=0,n=s.size();
    int ans = 0;
    while(j<n){
        if(st.find(s[j])==st.end()){
            st.insert(s[j]);
            ans = max(ans,j-i+1);
            j++;
        }else{
            while(i!=j && s[i]!=s[j]){
                st.erase(s[i]);
                i++;
            }
            st.erase(s[i++]);
            st.insert(s[j]);
            ans = max(ans,j-i+1);
            j++;
        }
    }
    return ans;
}


// *** subarray with given sum
vector<int> subarraySum(int arr[], int n, long long s)
{
    if(n==1) return {1,1};
    if(s==0) return {-1};
    int i=0,j=0;
    long long sum=0;
    while(j<=n){
        if(sum<s){
            sum += arr[j++];
        }else if(sum==s){
            return {i+1,j};
        }else{
            sum -= arr[i++];
        }
    }
    return {-1};
}

// *** Pick Toy

// *** Minimum window substring




int main(){

    return 0;
}