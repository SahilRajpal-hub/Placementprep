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


// *** <------------------- Variable Size sliding window problems ------------------------------>
// *** Largest/Smallest subarray of sum K

// *** Largest substring of k distinct character

// *** Length of largest substring of No repeating character

// *** Pick Toy

// *** Minimum window substring



int main(){

    return 0;
}