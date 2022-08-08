#include <bits/stdc++.h>
using namespace std;

// ? (Alisha) Searching / Sorting -> https://www.youtube.com/playlist?list=PLLT4EuYB4kIaWgO_-unJeY4huZlP3Uln9
// ? (Alisha) Array and Maths -> https://www.youtube.com/playlist?list=PLLT4EuYB4kIb0G4k2LxdIs2dCaj9vebqCs
// ? {DONE} Striver Array -> https://www.youtube.com/playlist?list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2

// *** Subarray with given sum
int subarraySum(vector<int> &nums, int k)
{
    map<int, int> mp;
    int c = 0;
    int ans = 0;
    mp[0] = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        c += nums[i];
        if (mp.count(c - k) > 0)
            ans += mp[c - k];
        mp[c]++;
    }

    return ans;
}

// *** Count the triplets
// ! not so good method O(n2);
int countTriplet(int arr[], int n)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (mp.count(arr[i] + arr[j]) > 0)
                ans++;
        }
    }
    return ans;
}

// *** Largest Sum Contiguous Subarray OR Kadane’s Algorithm
int maxSubArray(vector<int> &nums)
{
    int sum = 0;
    int maxSum = nums[0];

    for (int el : nums)
    {
        sum += el;
        maxSum = max(sum, maxSum);
        if (sum < 0)
            sum = 0;
    }

    return maxSum;
}

// *** Missing number in array
// ? Simple approach
int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int sum = (n * (n + 1)) / 2;
    int t = 0;
    for (int i = 0; i < n; i++)
        t += nums[i];
    return sum - t;
}
// ? bit manipulation approach
int missingNumber(vector<int> &nums)
{
    int res = nums.size();
    for (int i = 0; i < nums.size(); i++)
    {
        res ^= i;
        res ^= nums[i];
    }
    return res;
}

// *** merger two sorted array
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (nums1[i] <= nums2[j])
        {
            i++;
        }
        else
        {
            swap(nums1[i], nums2[j]);
            int tmp = j;
            while (tmp + 1 < n && nums2[tmp] > nums2[tmp + 1])
            {
                swap(nums2[tmp], nums2[tmp + 1]);
                tmp++;
            }
            i++;
        }
    }
    i = m;
    j = 0;
    while (i < m + n && j < n)
    {
        swap(nums2[j], nums1[i]);
        i++;
        j++;
    }
}

// *** Rearrange array alternatively
// ? with O(N) space
void rearrange(long long *arr, int n)
{
    long long *a = new long long[n];
    int i = 0, j = n - 1, idx = 0;
    while (i <= j && idx < n)
    {
        if (i == j)
        {
            a[idx] = arr[j];
            break;
        }
        a[idx++] = arr[j--];
        a[idx++] = arr[i++];
    }
    for (long long i = 0; i < n; i++)
        arr[i] = a[i];
    delete a;
}
// ? with with O(1) space -> to be done

// *** Number of pairs

// *** sort array of 0s,1s and 2s
// ! the below approach is not in-place and takes two passes to complete
void sortArray(vector<int> &nums)
{
    int nz = 0, no = 0, nt = 0;
    for (int i : nums)
    {
        if (i == 0)
            nz++;
        else if (i == 1)
            no++;
        else
            nt++;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (nz && nz--)
            nums[i] = 0;
        else if (no && no--)
            nums[i] = 1;
        else if (nt && nt--)
            nums[i] = 2;
    }
}
// ! dutch natinal flag algorithm
void sortColors(vector<int> &nums)
{
    int lo = 0;
    int hi = nums.size() - 1;
    int mid = 0;

    while (mid <= hi)
    {
        switch (nums[mid])
        {

        // If the element is 0
        case 0:
            swap(nums[lo++], nums[mid++]);
            break;

        // If the element is 1 .
        case 1:
            mid++;
            break;

        // If the element is 2
        case 2:
            swap(nums[mid], nums[hi--]);
            break;
        }
    }
}

// *** find the duplicate number in array
// ? O(N) SC and O(N) TC
int findDuplicate(vector<int> &nums)
{
    if (nums.size() <= 2)
        return nums[0];
    vector<int> aux;
    int n = nums.size();

    for (int i = 0; i < (n + 1); i++)
    {
        aux.push_back(0);
    }

    for (int i = 0; i < n; i++)
    {
        aux[nums[i]]++;
        if (aux[nums[i]] == 2)
        {
            return nums[i];
        }
    }
    return 0;
}
// ? O(1) SC and O(N) TC => using linked list loop method
int findDuplicate(vector<int> &nums)
{
    int fastPointer = nums[nums[0]], slowPointer = nums[0];

    while (nums[fastPointer] != nums[slowPointer])
    {
        cout << fastPointer << " " << slowPointer << endl;
        fastPointer = nums[nums[fastPointer]];
        slowPointer = nums[slowPointer];
    }
    fastPointer = 0;
    while (nums[fastPointer] != nums[slowPointer])
    {
        cout << fastPointer << " " << slowPointer << endl;
        slowPointer = nums[slowPointer];
        fastPointer = nums[fastPointer];
    }
    return nums[fastPointer];
}

// *** merge intervals
static bool comp(vector<int> &v1, vector<int> &v2)
{
    return v1[0] < v2[0];
}
bool isOverlapping(vector<int> v1, vector<int> v2)
{
    return v2[0] >= v1[0] && v2[0] <= v1[1];
}
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), comp);
    vector<vector<int>> ans;
    vector<int> prev = intervals[0];
    ans.push_back(prev);
    for (int i = 1; i < intervals.size(); i++)
    {
        vector<int> curr = intervals[i];
        if (isOverlapping(prev, curr))
        {
            curr[0] = prev[0];
            curr[1] = max(prev[1], curr[1]);
            ans.pop_back();
            ans.push_back(curr);
            prev = curr;
        }
        else
        {
            ans.push_back(curr);
            prev = curr;
        }
    }
    return ans;
}

// *** set matrix zeroes
// ? with O(N) SC
void setZeroes(vector<vector<int>> &matrix)
{
    vector<pair<int, int>> mp;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == 0)
                mp.push_back({i, j});
        }
    }

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        int r = it->first;
        int c = it->second;
        for (int i = 0; i < matrix.size(); i++)
            matrix[i][c] = 0;
        for (int i = 0; i < matrix[0].size(); i++)
            matrix[r][i] = 0;
    }
}
// ? with O(1) SC
void setZeroes(vector<vector<int>> &matrix)
{
    vector<pair<int, int>> mp;
    bool col = false, row = false;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                if (j == 0)
                    col = true;
                if (i == 0)
                    row = true;
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < matrix.size(); i++)
    {
        for (int j = 1; j < matrix[0].size(); j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }
    if (col)
    {
        for (int i = 0; i < matrix.size(); i++)
            matrix[i][0] = 0;
    }
    if (row)
    {
        for (int j = 0; j < matrix[0].size(); j++)
            matrix[0][j] = 0;
    }
}

// *** Pascal's Triangle
// TODO 1. to get value at pascal's triangle row r and col r, (r-1)C(c-1) , C-> combinations
// TODO 2. to just get value at pascal's triangle row r, use point 1, r times -> O(N) TC
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;
    if (numRows == 0)
        return ans;
    ans.push_back({1});
    if (numRows == 1)
        return ans;
    ans.push_back({1, 1});
    if (numRows == 2)
        return ans;

    for (int i = 3; i <= numRows; i++)
    {
        vector<int> tmp;
        tmp.push_back(1);
        vector<int> prev = ans[ans.size() - 1];
        for (int i = 1; i < prev.size(); i++)
        {
            tmp.push_back(prev[i - 1] + prev[i]);
        }
        tmp.push_back(1);
        ans.push_back(tmp);
    }

    return ans;
}

// *** Next Permutation
// ? using stl next_permutation and prev_permutation (Not allowed)
void nextPermutation(vector<int> &nums)
{
    int infP = -1;
    int toSwap = -1;
    for (int i = nums.size() - 1; i > 0; i--)
    {
        if (nums[i] > nums[i - 1])
        {
            infP = i;
            toSwap = i - 1;
            break;
        }
    }
    if (infP == -1)
    {
        sort(nums.begin(), nums.end());
        return;
    }
    int nextGreater = -1;
    for (int i = nums.size() - 1; i >= infP; i--)
    {
        if (nums[i] > nums[toSwap])
        {
            if (nextGreater == -1 || nums[nextGreater] > nums[i])
            {
                nextGreater = i;
            }
        }
    }
    // cout<<toSwap<<" "<<nextGreater<<endl;
    swap(nums[toSwap], nums[nextGreater]);
    sort(nums.begin() + infP, nums.end());
}

// *** count inversions
long long cnt = 0;
void merge(long long v[], int s, int m, int e)
{
    int i = s, j = m + 1, idx = 0;
    vector<long long> va;
    while (i <= m && j <= e)
    {
        if (v[i] <= v[j])
        {
            va.push_back(v[i++]);
        }
        else
        {
            va.push_back(v[j++]);
            cnt += m - i + 1;
        }
    }
    while (i <= m)
        va.push_back(v[i++]);
    while (j <= e)
        va.push_back(v[j++]);
    for (int i = s; i <= e; i++)
    {
        v[i] = va[idx++];
    }
    va.clear();
}
void mergeSort(long long v[], int s, int e)
{
    if (s >= e)
        return;
    int m = (s + e) / 2;
    mergeSort(v, s, m);
    mergeSort(v, m + 1, e);
    merge(v, s, m, e);
}
long long int inversionCount(long long v[], long long N)
{
    mergeSort(v, 0, N - 1);
    return cnt;
}

// *** best time to buy and sell stocks
int maxProfit(vector<int> &prices)
{
    int minOnLeft = prices[0];
    int pf = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        minOnLeft = min(minOnLeft, prices[i]);
        pf = max(pf, prices[i] - minOnLeft);
    }
    return pf;
}

// *** Rotate Image
void rotate(vector<vector<int>> &matrix)
{
    // ? swap diagonally / transpose of matrix --> learn as transpose of matrix also
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // ? swap vertically / reverse cols
    /*
        for(int j=0; j<n; j++) reverse(matrix[i].begin(),matrix[i].end());
    */
    int n = matrix.size();
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            swap(matrix[i][j], matrix[i][n - 1 - j]);
        }
    }
}

// *** search in a 2d matrix
// ? sorted 2d array, do simple binary search
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int rs = matrix.size();
    int cs = matrix[0].size();
    int l = 0, r = rs * cs - 1;
    while (l != r)
    {
        int m = (l + r) >> 1;
        if (matrix[m / cs][m % cs] < target)
            l = m + 1;
        else
            r = m;
    }
    return matrix[r / cs][r % cs] == target;
}

// *** power function implementation
double myPow(double x, int n)
{
    if (n == 0)
        return 1;
    double ans = 0;
    int p = abs(n);
    if (n % 2 == 0)
        ans = myPow(x * x, p / 2);
    else
        ans = x * myPow(x, p - 1);
    return n > 0 ? ans : 1 / ans;
}

// *** <------ Moree voting algorihtm ----------->
// *** majority element
int majorityElement(vector<int> &nums)
{
    int cand = nums[0];
    int life = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (life > 0)
        {
            if (nums[i] == cand)
                life++;
            else
                life--;
        }
        else
        {
            cand = nums[i];
            life++;
        }
    }
    return cand;
}
// *** majority element 2
vector<int> majorityElement2(vector<int> &nums)
{
    int cand1 = INT_MIN;
    int life1 = 0;
    int cand2 = INT_MIN;
    int life2 = 0;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == cand1)
        {
            life1++;
        }
        else if (nums[i] == cand2)
        {
            life2++;
        }
        else if (life1 == 0)
        {
            cand1 = nums[i];
            life1 = 1;
        }
        else if (life2 == 0)
        {
            cand2 = nums[i];
            life2 = 1;
        }
        else
        {
            life1--;
            life2--;
        }
    }

    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == cand1)
            cnt1++;
        if (nums[i] == cand2)
            cnt2++;
    }
    if (cnt1 > nums.size() / 3)
        ans.push_back(cand1);
    if (cnt2 > nums.size() / 3)
        ans.push_back(cand2);

    return ans;
}

// *** Unique Paths (Do this with the help of combinatorics)

// *** reverse pairs

// *** fractional knapsack
struct Item
{
    int weight;
    int value;
};
static bool comp(const Item &i1, const Item &i2)
{
    return ((double)i1.value / (double)i1.weight) > ((double)i2.value / (double)i2.weight);
}
double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr, arr + n, comp);
    double val = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].weight <= W)
        {
            val += (double)arr[i].value;
            W -= arr[i].weight;
        }
        else
        {
            double tmp = arr[i].value;
            tmp *= W;
            tmp /= arr[i].weight;
            val += tmp;
            break;
        }
    }
    return val;
}

// *** Non-overlapping Intervals
int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    vector<int> prev = intervals[0];
    int ans = 0;
    for (int i = 1; i < intervals.size(); i++)
    {
        vector<int> curr = intervals[i];
        if (curr[0] < prev[1])
        {
            ans++;
            if (prev[1] > curr[1])
                prev = curr;
        }
        else
        {
            prev = curr;
        }
    }
    return ans;
}

// *** Rearrange an array with O(1) extra space
int currValue(int num, int n)
{
    return num / n;
}
int prevValue(int num, int n)
{
    return num % n;
}
void arrange(long long arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = prevValue(arr[i], n) + prevValue(arr[arr[i]], n) * n;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = currValue(arr[i], n);
    }
}

// *** Maximum Sum Triplet
int solve(vector<int> &A)
{
    int n = A.size();
    int *suffix = new int[n];
    suffix[n - 1] = A[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = max(suffix[i + 1], A[i]);
    }
    set<int> s;
    s.insert(A[0]);
    int ans = INT_MIN;
    for (int i = 1; i < n - 1; i++)
    {
        s.insert(A[i]);
        auto it = s.find(A[i]);
        if (it != s.begin() && suffix[i] != A[i])
            ans = max(ans, (*--it) + A[i] + suffix[i]);
    }
    return ans;
}

// *** max consecutive 1s
int findMaxConsecutiveOnes(vector<int> &nums)
{
    int omx = 0;
    int cmx = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
            cmx++;
        else
        {
            omx = max(omx, cmx);
            cmx = 0;
        }
    }
    omx = max(omx, cmx);
    return omx;
}

// *** Rain water trapping
int trap(vector<int> &height)
{
    int n = height.size();
    vector<int> greaterLeft(n, 0);
    vector<int> greaterRight(n, 0);
    int ans = 0;

    greaterLeft[0] = height[0];
    for (int i = 1; i < n; i++)
    {
        greaterLeft[i] = max(greaterLeft[i - 1], height[i]);
    }

    greaterRight[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        greaterRight[i] = max(greaterRight[i + 1], height[i]);
    }

    for (int i = 1; i < height.size() - 1; i++)
    {
        int mxLeft = greaterLeft[i - 1];
        int mxRight = greaterRight[i + 1];
        if (height[i] > mxLeft || height[i] > mxRight)
        {
            ans += 0;
        }
        else
        {
            ans += (min(mxLeft, mxRight) - height[i]);
        }
    }
    return ans;
}

// *** Shortest Unsorted Continuous Subarray
// ? TC -> O(NlogN)
int findUnsortedSubarray(vector<int>& nums) {
    vector<int> ga = nums;
    sort(nums.begin(),nums.end());
    int li=-1,ri=-1;
    int n = nums.size();
    for(int i=0; i<n; i++){
        if(ga[i]!=nums[i]){
            li=i;
            break;
        }
    }
    for(int i=n-1; i>=0; i--){
        if(ga[i]!=nums[i]){
            ri=i;
            break;
        }
    }
    if(li==ri) return 0;
    return ri-li+1;
}
// ? TC -> O(N)
int findUnsortedSubarray(vector<int>& nums) {
    int mn=INT_MAX;
    int mx=INT_MIN;
    int n = nums.size();
    
    for(int i=0; i<n; i++){
        if((i+1<n && nums[i]>nums[i+1]) || (i-1>=0 && nums[i]<nums[i-1])){
            mn=min(mn,nums[i]);
            mx=max(mx,nums[i]);
        }
    }
    if(mn==INT_MAX && mx==INT_MIN) return 0;
    int li=-1,ri=-1;
    for(int i=0; i<n-1; i++){
        if(nums[i]>mn){
            li=i;
            break;
        }
    }
    for(int i=n-1; i>0; i--){
        if(nums[i]<mx){
            ri=i;
            break;
        }
    }
    return ri-li+1;
}

// *** Longest Consecutive Sequence
int longestConsecutive(vector<int>& nums) {
    map<int,int> mp;
    for(int i=0; i<nums.size(); i++){
        mp[nums[i]]++;
    }
    if(mp.size()==0) return 0;
    
    int prev = INT_MIN;
    int best = 0;
    int temp = 0;
    for(auto it=mp.begin(); it!=mp.end(); it++){
        if(prev==INT_MIN) prev=it->first;
        else{
            if(prev+1==it->first){
                temp++;
                best = max(best,temp);
                prev=it->first;
            }else{
                temp=0;
                prev=it->first;
            }
        }
    }
    return best+1;
}


int main()
{
    // AMCAT ID ->
    return 0;
}