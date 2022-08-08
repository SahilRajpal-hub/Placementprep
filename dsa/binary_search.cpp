#include <bits/stdc++.h>
using namespace std;


// *** main code
// ? retruns the index of target element
int search(vector<int>& nums, int target) {
    int low = 0,high=nums.size()-1;
    
    while(low<=high){
        int mid = (low+(high-low)/2);
        if(nums[mid]==target) return mid;
        else if(nums[mid]>target) high=mid-1;
        else low=mid+1;
    }
    return -1;
}

// *** Order agoustic Binary Search
int orderAgnosticBS(vector<int>& arr, int target, int start, int end){
    bool isAscending = arr[start] < arr[end];

    while(start <= end) {
        int mid = start + (end - start) / 2;

        if(target == arr[mid]){
            return mid;
        }

        if(isAscending){
            if(target < arr[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        } else {
            if(target > arr[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
    }
    return -1;
}

// *** first and last occurence of an element in a sorted array
int firstOccr(vector<int>& nums, int target){
    int low = 0, high = nums.size()-1;
    int fo=-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(nums[mid]==target){
            fo=mid;
            high = mid-1;
        }
        else if(target>nums[mid]) low=mid+1;
        else high=mid-1;
    }
    return fo;
}
int lastOccr(vector<int>& nums, int target){
    int low = 0, high = nums.size()-1;
    int lo=-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(nums[mid]==target){
            lo=mid;
            low = mid+1;
        }
        else if(target>nums[mid]) low=mid+1;
        else high=mid-1;
    }
    return lo;
}
vector<int> searchRange(vector<int>& nums, int target) {
    int fo=firstOccr(nums,target),lo=lastOccr(nums,target);
    
    vector<int> ans = {fo,lo};
    return ans;
}

// *** count of an element in a sorted array
int firstOccr(vector<int>& nums, int target){
    int low = 0, high = nums.size()-1;
    int fo=-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(nums[mid]==target){
            fo=mid;
            high = mid-1;
        }
        else if(target>nums[mid]) low=mid+1;
        else high=mid-1;
    }
    return fo;
}
int lastOccr(vector<int>& nums, int target){
    int low = 0, high = nums.size()-1;
    int lo=-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(nums[mid]==target){
            lo=mid;
            low = mid+1;
        }
        else if(target>nums[mid]) low=mid+1;
        else high=mid-1;
    }
    return lo;
}
int countOfElement(vector<int>& nums, int target) {
    int fo=firstOccr(nums,target),lo=lastOccr(nums,target);
    
    return fo==-1?0:lo-fo+1;
}

// *** Number of times a array is rotated OR Find minimum element in rotated sorted array
int findKRotation(int arr[], int n) {
    int low=0,high=n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]<arr[(mid+n-1)%n] && arr[mid]<arr[(mid+1)%n]){
            return mid;  // ? for minimum element send arr[mid] instead
        }else if(arr[mid]<arr[high]){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return 0;
}

// *** Find an element in a rotated sorted array
int findMin(vector<int>& arr) {
    int n = arr.size();
    if(n==1) return 0;
    int low=0,high=n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]<arr[(mid+n-1)%n] && arr[mid]<arr[(mid+1)%n]){
            return mid;
        }else if(arr[mid]<arr[high]){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return 0;
}
int search(vector<int>& nums, int target, int l, int h) {
    int low = l,high=h;

    while(low<=high){
        int mid = (low+(high-low)/2);
        if(nums[mid]==target) return mid;
        else if(nums[mid]>target) high=mid-1;
        else low=mid+1;
    }
    return -1;
}
int search(vector<int>& nums, int target) {
    int mvi = findMin(nums);
    if(target>=nums[mvi] && target<=nums[nums.size()-1]){
        return search(nums,target,mvi,nums.size()-1);
    }
    return search(nums,target,0,mvi-1);
}

// *** Searching in nearly sorted array
int searchNearlySortedArray(vector<int> nums, int target){
    int low = 0,high=nums.size()-1;
    
    while(low<=high){
        int mid = (low+(high-low)/2);
        if(nums[mid]==target) return mid;
        else if(mid-1>=low && nums[mid-1]==target) return mid-1;
        else if(mid+1<=high && nums[high+1]==target) return mid+1;
        else if(nums[mid]>target) high=mid-2;
        else low=mid+2;
    }
    return -1;
}

// *** Floor/Ceil of an element
int findFloor(vector<int> v, int n, int x){
    if(x>v[n-1]) return n-1;
    int low = 0,high=n-1;
    int idx = -1;
    int mid =0;
    while(low<=high){
        mid = low + (high-low)/2;
        if(v[mid]==x){
            idx=mid;
            high=mid-1;
        }else if(mid-1>=low && v[mid-1]<x && v[mid]>x){
            idx=mid-1;
            break;
        }else if(mid+1<=high && v[mid+1]>x && v[mid]<x){
            idx=mid;
            break;
        }else if(x>v[mid]){
            low=mid+1;
        }else high=mid-1;
    }
    return idx;
}
int findCeil(vector<int>& v, int x) {
    int n = v.size();
    if(x>v[n-1]) return n;
    int low = 0,high=n-1;
    int idx = 0;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(v[mid]==x){
            idx=mid;
            high=mid-1;
        }else if(mid-1>=low && v[mid-1]<x && v[mid]>x){
            idx=mid;
            break;
        }else if(mid+1<=high && v[mid+1]>x && v[mid]<x){
            idx=mid+1;
            break;
        }else if(x>v[mid]){
            low=mid+1;
        }else high=mid-1;
    }
    return idx;
}

// *** Next Letter
char nextGreatestLetter(vector<char>& v, char x) {
    int n = v.size();
    if(x>v[n-1]) return v[0];
    int low = 0,high=n-1;
    int idx = 0;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(v[mid]==x){
            idx=(mid+1)%n;
            low=mid+1;
        }else if(mid-1>=low && v[mid-1]<x && v[mid]>x){
            idx=mid;
            break;
        }else if(mid+1<=high && v[mid+1]>x && v[mid]<x){
            idx=mid+1;
            break;
        }else if(x>v[mid]){
            low=mid+1;
        }else high=mid-1;
    }
    return v[idx];
}

// *** Find the index of an element in an infinte sorted array
int search(int nums[],int l, int h, int target) {
    int low = l,high=h;

    while(low<=high){
        int mid = (low+(high-low)/2);
        if(nums[mid]==target) return mid;
        else if(nums[mid]>target) high=mid-1;
        else low=mid+1;
    }
    return -1;
}
int findPos(int arr[], int key)
{
    int l = 0, h = 1;
    int val = arr[0];
 
    while (val < key)
    {
        l = h;        
        h = 2*h;      
        val = arr[h]; 
    }
    return search(arr, l, h, key);
}

// *** Index of last 1 in an infinite sorted array
int searchFirstOne(int nums[],int l, int h, int target) {
    int low = l,high=h;
    int res = -1;
    while(low<=high){
        int mid = (low+(high-low)/2);
        if(nums[mid]==target){
            res=mid;
            high=mid-1;
        }
        else if(nums[mid]>target) high=mid-1;
        else low=mid+1;
    }
    return -1;
}
int findPos(int arr[], int key)
{
    int l = 0, h = 1;
    int val = arr[0];
 
    while (val < key)
    {
        l = h;        
        h = 2*h;      
        val = arr[h]; 
    }
    return searchFirstOne(arr, l, h, key);
}

// *** minimum difference element in a sorted array
int minDiff(vector<int> nums, int x){
    int floorValueOfX = findFloor(nums,nums.size()-1,x);
    int ceilValueOfX = findCeil(nums,x);
    return min(abs(floorValueOfX-x),abs(ceilValueOfX-x));
}

// *** Find peak element
int findPeakElement(vector<int>& nums) {
    int low = 0,high=nums.size()-1;
    
    while(low<=high){
        int mid = low + (high-low)/2;
        if( ((mid-1>=low && nums[mid]>nums[mid-1]) || mid==low) &&
            ((mid+1<=high && nums[mid]>nums[mid+1]) || mid==high) )
        {
            return mid;    
        }
        else if(mid+1<=high && nums[mid]<nums[mid+1]){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return -1;
}

// *** bitonic array max element
int findMaximum(int nums[], int n) {
    int low = 0,high=n-1;

    while(low<=high){
        int mid = low + (high-low)/2;
        if( ((mid-1>=low && nums[mid]>nums[mid-1]) || mid==low) &&
            ((mid+1<=high && nums[mid]>nums[mid+1]) || mid==high) )
        {
            return nums[mid];    
        }
        else if(mid+1<=high && nums[mid]<nums[mid+1]){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return nums[n-1];
}

// *** search in a bitonic array
int findPeakElement(vector<int>& nums) {
    int low = 0,high=nums.size()-1;
    
    while(low<=high){
        int mid = low + (high-low)/2;
        if( ((mid-1>=low && nums[mid]>nums[mid-1]) || mid==low) &&
            ((mid+1<=high && nums[mid]>nums[mid+1]) || mid==high) )
        {
            return mid;    
        }
        else if(mid+1<=high && nums[mid]<nums[mid+1]){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return -1;
}
int incSearch(vector<int> nums, int target, int l, int h) {
    int low = l,high=h;
    
    while(low<=high){
        int mid = (low+(high-low)/2);
        if(nums[mid]==target) return mid;
        else if(nums[mid]>target) high=mid-1;
        else low=mid+1;
    }
    return -1;
}
int decSearch(vector<int> nums, int target, int l, int h) {
    int low = l,high=h;
    
    while(low<=high){
        int mid = (low+(high-low)/2);
        if(nums[mid]==target) return mid;
        else if(nums[mid]<target) high=mid-1;
        else low=mid+1;
    }
    return -1;
}
int solve(vector<int> &A, int B) {
    int idx = findPeakElement(A);
    // cout<<idx<<endl;
    int ii = incSearch(A,B,0,idx);
    // cout<<ii<<endl;
    if(ii!=-1) return ii;
    int di = decSearch(A,B,idx+1,A.size()-1);
    // cout<<di<<endl;
    return di==-1?-1:di;
}

// *** search in a row wise and column wise sorted matrix

// *** find element in a sorted array that appears only once

// *** allocate minimum number of pages
bool isValid(int A[], int n, int m, int mx){
    int nums = 1;
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += A[i];
        if(sum>mx){
            sum = 0;
            nums++;
            if(nums>m || A[i]>mx){
                return false;
            }
            i--;
        }
    }
    return true;
}
int findPages(int A[], int N, int M) 
{
    if(N<M) return -1;
    int low = 0;
    int high = accumulate(A, A+N,0);
    int res = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(isValid(A,N,M,mid)){
            res = mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return res;
}

// *** The Painter's Partition Problem
bool isValid(int arr[], int n, int k, long long mid){
    int numOfPainters = 1;
    long long sum = 0;
    for(int i=0; i<n; i++){
        if(sum+arr[i]<=mid){
            sum += arr[i];
        }else{
            sum=arr[i];
            numOfPainters++;
            if(numOfPainters>k || arr[i]>mid){
                return false;
            }
        }
    }
    return true;
}
long long minTime(int arr[], int n, int k)
{
    int maxElement = INT_MIN;
    long long sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
        maxElement=max(maxElement,arr[i]);
    }
    if(n==k) return maxElement;
    long long low = maxElement;
    long long high = sum;
    long long res = -1;
    while(low<=high){
        long long mid = low + (high-low)/2;
        if(isValid(arr,n,k,mid)){
            res=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return res;
}

// *** aggresive cows
bool isValid(vector<int> &stalls, int k, int mid, int n) {
    int cowCount = 1;
    int lastPos = stalls[0];

    for(int i=0; i<n; i++ ){
        
        if(stalls[i]-lastPos >= mid){
            cowCount++;
            if(cowCount==k)
            {
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
    }
int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
   	int start = 0;
    int n = stalls.size();
    int end=stalls[n-1];
    int ans = -1;
    
    while(start<=end) {
        int mid = start + (end-start)/2;
        if(isValid(stalls, k, mid, n)) {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        
    }
    return ans;
}

int main(){
    int a = 2147483640;
    int b = 10;
    int res = a + (b-a)/2;
    cout<<res<<endl;
    return 0;
}