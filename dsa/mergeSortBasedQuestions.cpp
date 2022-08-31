#include <bits/stdc++.h>
using namespace std;

// *** Analysis on this patterns =>  https://leetcode.com/problems/count-of-smaller-numbers-after-self/discuss/445769/merge-sort-CLEAR-simple-EXPLANATION-with-EXAMPLES-O(n-lg-n)

// *** mergesort
void merge(vector<int> &v, int s, int m, int e){
    int i=s,j=m+1,idx=s;
    vector<int> tmp(v.size());

    while(i<=m && j<=e){
        if(v[i]>v[j]){
            tmp[idx++]=v[j++];
        }else{
            tmp[idx++]=v[i++];
        }
    }

    while(i<=m) tmp[idx++]=v[i++];
    while(j<=e) tmp[idx++]=v[j++];
    for(int i=s; i<=e; i++) v[i]=tmp[i];
    tmp.clear();
}
void mergeSort(vector<int> &v, int s, int e){
    if(s>=e) return;
    int mid = (s+e)/2;
    mergeSort(v,s,mid);
    mergeSort(v,mid+1,e);
    merge(v,s,mid,e);
}

// *** merge sort in linked list
// ?  <<---- availiable in linked list code file ------------>

// *** count inversions
int cnt = 0;
void merge(vector<int> &v, int s, int m, int e)
{
    int i = s, j = m + 1, idx = s;
    vector<int> va(v.size());
    while (i <= m && j <= e)
    {
        if (v[i] < v[j])
        {
            va[idx++] = v[i++];
        }
        else
        {
            va[idx++] = v[j++];
            cnt += m - i + 1;
        }
    }
    while (i <= m)
        va[idx++] = v[i++];
    while (j <= e)
        va[idx++] = v[j++];
    for (int i = s; i <= e; i++)
    {
        v[i] = va[i];
    }
    va.clear();
}
void mergeSort(vector<int> &v, int s, int e)
{
    if (s >= e)
        return;
    int m = (s + e) / 2;
    mergeSort(v, s, m);
    mergeSort(v, m + 1, e);
    merge(v, s, m, e);
}

// *** Count of Smaller Numbers After Self
void merge(vector<pair<int,int>> &nums,int s, int m, int e,vector<int>& ans){
    vector<pair<int,int>> tmp;
    int i=s,j=m+1,idx=0;
    while(i<=m && j<=e){
        if(nums[i].first<=nums[j].first){
            tmp.push_back({nums[j].first,nums[j++].second});
        }else{
            if(nums[i].second<nums[j].second) ans[nums[i].second]+=(e-j+1);
            tmp.push_back({nums[i].first,nums[i++].second});
        }
    }
    
    while(i<=m) tmp.push_back({nums[i].first,nums[i++].second});
    while(j<=e) tmp.push_back({nums[j].first,nums[j++].second});
    for(int i=s; i<=e; i++){
        nums[i]=tmp[idx++];
    }
}
void mergeSort(vector<pair<int,int>> &nums, int s, int e,vector<int>& ans){
    if(s>=e) return;
    int m = (s+e)/2;
    mergeSort(nums,s,m,ans);
    mergeSort(nums,m+1,e,ans);
    merge(nums,s,m,e,ans);
}
vector<int> countSmaller(vector<int>& num) {
    vector<int> ans(num.size(),0);
    vector<pair<int,int>> nums;
    for(int i=0; i<num.size(); i++){
        nums.push_back({num[i],i});
    }
    mergeSort(nums,0,nums.size()-1,ans);
    return ans;
}

// *** Reverse Pairs
int cnt = 0;
void merge(vector<int> &nums, int s,int m, int e){
    int i=s,j=m+1,idx=0;
    
    for(i=s; i<=m; i++){
        while(j<=e && nums[i]>2*(long)nums[j]) j++;
        cnt += j-(m+1);
    }
    i=s,j=m+1,idx=0;
    
    vector<int> tmp;
    while(i<=m && j<=e){
        if(nums[i]<nums[j]){
            tmp.push_back(nums[i++]);
        }else{
            tmp.push_back(nums[j++]);
        }
    }
    while(i<=m) tmp.push_back(nums[i++]);
    while(j<=e) tmp.push_back(nums[j++]);
    for(int i=s; i<=e; i++){
        nums[i]=tmp[idx++];
    }
}
void mergeSort(vector<int> &nums, int s, int e){
    if(s>=e) return;
    int m = (s+e)/2;
    mergeSort(nums,s,m);
    mergeSort(nums,m+1,e);
    merge(nums,s,m,e);
}
int reversePairs(vector<int>& nums) {
    mergeSort(nums,0,nums.size()-1);
    return cnt;
}

// *** count of range sum [still not clear]
int countRangeSum(vector<int>& nums, int lower, int upper) {
    int size=nums.size();
    if(size==0)  return 0;
    vector<long> sums(size+1, 0);
    for(int i=0; i<size; i++)  sums[i+1]=sums[i]+nums[i];
    return help(sums, 0, size+1, lower, upper);
}
/*** [start, end)  ***/
int help(vector<long>& sums, int start, int end, int lower, int upper){
    /*** only-one-element, so the count-pair=0 ***/
    if(end-start<=1)  return 0;
    int mid=(start+end)/2;
    int count=help(sums, start, mid, lower, upper)
            + help(sums, mid, end, lower, upper);
    
    int m=mid, n=mid, t=mid, len=0;
    /*** cache stores the sorted-merged-2-list ***/
    /*** so we use the "len" to record the merged length ***/
    vector<long> cache(end-start, 0);
    for(int i=start, s=0; i<mid; i++, s++){
        /*** wrong code: while(m<end && sums[m++]-sums[i]<lower);  ***/
        while(m<end && sums[m]-sums[i]<lower) m++;
        while(n<end && sums[n]-sums[i]<=upper) n++;
        count+=n-m;
        /*** cache will merge-in-the-smaller-part-of-list2 ***/
        while(t<end && sums[t]<sums[i]) cache[s++]=sums[t++];
        cache[s]=sums[i];
        len=s;
    }
    
    for(int i=0; i<=len; i++)  sums[start+i]=cache[i];
    return count;
}


void printVector(vector<int> v){
    for(int i:v) cout<<i<<" ";
}

int main(){
    vector<int> v{6,5,1,3,4,2};
    mergeSort(v,0,5);
    printVector(v);
    return 0;
}