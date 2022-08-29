#include <bits/stdc++.h>
using namespace std;

// *** Distribute Candy
int candy(vector<int> &ratings)
{
    int n = ratings.size();
    vector<int> left(n, 1), right(n, 1);
    int ans = 0;

    for (int i = 1; i < n; i++)
    {
        if (ratings[i] > ratings[i - 1])
        {
            left[i] = left[i - 1] + 1;
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
        {
            right[i] = right[i + 1] + 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        ans += max(left[i], right[i]);
    }

    return ans;
}

// *** Minimum Lights to Activate
int solve(vector<int> &A, int B) {
    int n = A.size();
    int i = 0;
    int count = 0;
    
    while(i<n){
        int left = max(i-B+1,0);
        int right = min(i+B-1,n-1);
        bool bulbFound = false;
        
        while(left<=right){
            if(A[right]==1){
                bulbFound=true;
                break;
            }
            right--;
        }
        
        if(!bulbFound) return -1;
        else{
            count++;
            i=right+B;
        }
        
    }
    return count;
}

// *** Circular tour Or gas station problem
struct petrolPump{
    int petrol;
    int distance;
};
int tour(petrolPump p[],int n)
{
    int sumP=0,sumD=0;
    for(int i=0; i<n; i++){
        sumP+=p[i].petrol;
        sumD+=p[i].distance;
    }
    if(sumP<sumD) return -1;
    int rmn = 0;
    int ans = 0;
    for(int i=0; i<n; i++){
        rmn += (p[i].petrol-p[i].distance);
        if(rmn<0){
            rmn=0;
            ans = i + 1;
        }
    }
    return ans;
}

// *** Maximum Units on a Truck
int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(boxTypes.begin(),boxTypes.end(),[](const auto &a, const auto &b){
        return a[1]>b[1];
    });
    
    int ans = 0;
    int rem = truckSize;
    for(int i=0; i<boxTypes.size(); i++){
        if(rem==0) break;
        if(boxTypes[i][0]<=rem){
            rem -= boxTypes[i][0];
            ans += (boxTypes[i][0]*boxTypes[i][1]);
        }else{
            ans += (rem*boxTypes[i][1]);
            break;
        }
    }
    
    return ans;
}

// *** Minimum Number of Refueling Stops
int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    if(startFuel>=target) return 0;
    if(stations.size()==0) return -1;
    
    priority_queue<int> pq;
    int count = 0;
    int distance = startFuel;
    int idx = 0;
    
    while(distance<target){
        
        while(idx<stations.size() && stations[idx][0]<=distance){
            pq.push(stations[idx][1]);
            idx++;
        }
        
        if(pq.empty()) return -1;
    
        distance += pq.top();
        pq.pop();
        count++;
    }
    
    return count;
}

// *** Jump Game
bool canJump(vector<int>& nums) {
    int n = nums.size();
    if(n<=1) return true;
    if(nums[0]==0) return false;
    
    int minToCover = n-1;
    
    for(int i=n-2; i>=0; i--){
        if(i+nums[i]>=minToCover){
            minToCover = i;
        }
    }
    
    return minToCover==0;
}

// *** jump game 2
int jump(vector<int>& nums) {
    int farthest = 0;
    int jumps = 0;
    int current = 0;
    
    for(int i=0; i<nums.size()-1; i++){
        farthest = max(farthest, nums[i]+i);
        
        if(i==current){
            current = farthest;
            jumps++;
        }
    }
    
    return jumps;
}

// *** maximum icecream bars
int maxIceCream(vector<int>& costs, int coins) {
    sort(costs.begin(),costs.end());
    int rem = coins;
    int n = costs.size();
    int idx = 0;
    int count = 0;
    
    while(idx<n){
        if(rem>=costs[idx]){
            rem -= costs[idx];
            count++;
        }else break;
        
        idx++;
    }
    
    return count;
}

// *** Wiggle sequence length || sum of peaks and valleys || Longest alternating subsequence
int wiggleMaxLength(vector<int>& nums) {
    int n = nums.size();
    int v=1,p=1;
    for(int i=1; i<n; i++){
        if(nums[i]>nums[i-1]) p=v+1;
        else if(nums[i]<nums[i-1]) v=p+1;
    }
    
    return max(p,v); 
}

// *** two city scheduling
static bool comp(vector<int> &a, vector<int>& b){
    return a[1]-a[0]>b[1]-b[0];
}
int twoCitySchedCost(vector<vector<int>>& costs) {
    sort(costs.begin(),costs.end(),comp);
    int n = costs.size()/2;
    int sum = 0;
    
    for(int i=0; i<n; i++){
        sum += costs[i][0];
        
        sum += costs[(2*n)-1-i][1];
    }
    
    return sum;
}

// *** Can Place Flowers
bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    if(n==0) return true;
    if(flowerbed.size()==1) return n<=1?flowerbed[0]==0:false;
    
    for(int i=0; i<flowerbed.size(); i++){
            if(flowerbed[i]==0 && (i-1<0 || flowerbed[i-1]!=1) && (i+1>=flowerbed.size() || flowerbed[i+1]!=1) ){
                flowerbed[i]=1; 
                n--;
            }
            if(n==0) return true;
        }
    
    return false;
}

// *** 7 Segment Display
string sevenSegments(string S, int N) {
    int segments[10] = {6,2,5,5,4,5,6,3,7,5};
    int ns = 0;
    string ans = "";
    for(char c:S){
        ns += segments[c-'0'];
    }
    
    ns = ns-(2*N);
    for(int i=0; i<N; i++){
        ans.push_back('1');
    }
    
    for(int i=0; i<N; i++){
        if(ns>=4){
            ans[i]='0';
            ns -= 4;
        }else if(ns==0){
            return ans;
        }else if(ns==1){
            ans[N-1]='7';
            return ans;
        }else if(ns==2){
            ans[N-1]='4';
            return ans;
        }else if(ns==3){
            ans[N-1]='2';
            return ans;
        }
    }
    
    if(ns>0){
        int i = N-1;
        while(ns--){
            ans[i--]='8';
        }
    }
    
    
    return ans;
}


// *** Minimum Operations to Reduce X to Zero
int maxLengthSubarrayOfSum(vector<int> nums, int sum){
    int s=0,e=0,n=nums.size();
    int ans = -1;
    int tmp=0;
    while(e<n){
        tmp+=nums[e];
        
        while(s<e && tmp>sum){
            tmp-=nums[s];
            s++;
        }
        
        if(tmp==sum){
            ans = max(ans,e-s+1);
        }
        e++;
    }
    return ans;
}
int minOperations(vector<int>& nums, int x) {
    int sum = accumulate(nums.begin(),nums.end(),0);
    if(sum==x) return nums.size();
    int length = maxLengthSubarrayOfSum(nums,sum-x);
    if(length==-1) return -1;
    return nums.size()-length;
}

// *** Minimize the sum of product
long long int minValue(int a[], int b[], int n)
{
    sort(a,a+n);
    sort(b,b+n,greater<int>());
    long long ans = 0;
    for(int i=0; i<n; i++){
        ans += (a[i]*b[i]);
    }
    return ans;
}

// *** N meetings in one room
int maxMeetings(int start[], int end[], int n)
{
    vector<pair<int,int>> v;
    for(int i=0; i<n; i++) v.push_back({start[i],end[i]});
    sort(v.begin(),v.end(), [](const auto &a, const auto &b){
        return a.second<b.second;
    });
    int cnt = 1;
    auto prev = v[0];
    for(int i=1; i<n; i++){
        if(v[i].first>prev.second){
            cnt++;
            prev = v[i];
        }
    }
    
    return cnt;
}

// *** Maximum Meetings in One Room
vector<int> maxMeetings(int n,vector<int> &start,vector<int> &end){
    vector<pair<int,int>> v;
    for(int i=0; i<n; i++) v.push_back({end[i],i});
    sort(v.begin(),v.end());
    vector<int> ans;
    
    int prev = v[0].first;
    ans.push_back(v[0].second+1);
    for(int i=1; i<n; i++){
        if(start[v[i].second]>prev){
            ans.push_back(v[i].second+1);
            prev = v[i].first;
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}

// *** Shop in Candy Store
vector<int> candyStore(int candies[], int N, int K)
{
    int mn=0,mx=0;
    
    int numElementsToBeTaken = ceil((float)N/(K+1));
    sort(candies,candies+N);
    for(int i=0; i<numElementsToBeTaken; i++){
        mn += candies[i];
        mx += candies[N-1-i];
    }
    
    
    return {mn,mx};
}

// *** Activity Selection
int activitySelection(vector<int> start, vector<int> end, int n)
{
    vector<pair<int,int>> vp;
    for(int i=0; i<n; i++){
        vp.push_back({start[i],end[i]});
    }
    sort(vp.begin(),vp.end(),[](const auto &a, const auto &b){
        return a.second<b.second;
    });
    pair<int,int> prev=vp[0];
    int cnt = 1;
    for(int i=1; i<n; i++){
        if(vp[i].first>prev.second){
            prev=vp[i];
            cnt++;
        }
    }
    return cnt;
}

// *** Check if it is possible to survive on Island
int minimumDays(int S, int N, int M){
    if(M>N) return -1;
    if(S==1) return 1;
    
    if(M==N && S<=6) return S;
    
    // using equation 6*N - 6*M >= M
    float a=(((float)N)/M);
    float b = 1.166666;
    if(a<b && S>6) return -1;
    
    int needed = S*M;
    float ans = M;
    ans *= S;
    ans = ans/N;
    return ceil(ans);
}

// *** Reverse words in a given string
string reverseWords(string s) 
{ 
    vector<string> v;
    int st=0;
    for(int i=1; i<s.length(); i++){
        if(s[i]=='.'){
            v.push_back(s.substr(st,i-st));
            st=i+1;
        }
    }
    v.push_back(s.substr(st));
    reverse(v.begin(),v.end());
    string ans;
    for(string e:v){
        ans += e;
        ans.push_back('.');
    }
    ans.pop_back();
    return ans;
}

// *** Chocolate Distribution Problem
long long findMinDiff(vector<long long> a, long long n, long long m){
    sort(a.begin(),a.end());
    long long ans = INT_MAX;
    int idx = 0;
    int prev = a[idx++];
    
    for(int i=m-1; i<n; i++){
        ans = min(ans,a[i]-prev);
        prev = a[idx++];
    }
    
    return ans;
}   

// *** fractional knapsack
struct Item{
    int value;
    int weight;
}; 
static bool comp(const Item &i1,const Item &i2){
    return ((double)i1.value/(double)i1.weight) > ((double)i2.value/(double)i2.weight);
}
double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr,arr+n,comp);
    double val=0;
    for(int i=0; i<n; i++){
        if(arr[i].weight<=W){
            val += (double)arr[i].value;
            W -= arr[i].weight;
        }else{
            double tmp = arr[i].value;
            tmp *= W;
            tmp /= arr[i].weight;
            val += tmp;
            break;
        }
    }
    return val;
}


// *** Job Sequencing Problem


// *** Huffman Encoding

int main()
{

    return 0;
}