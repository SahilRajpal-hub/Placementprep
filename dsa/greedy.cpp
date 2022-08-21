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

int main()
{

    return 0;
}