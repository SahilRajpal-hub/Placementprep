#include <bits/stdc++.h>
using namespace std;

// *** Single Number
int singleNumber(vector<int>& nums) {
    int ans = 0;
    for(int i=0; i<nums.size(); i++){
        ans ^= nums[i];
    }
    return ans;
}

// *** Non repeating Number
vector<int> singleNumber(vector<int> nums) 
{
    int n1=0,n2=0;
    int xr = 0;
    for(int i=0; i<nums.size(); i++){
        xr ^= nums[i];
    }
    
    int rsbm = (xr&-xr);
    
    for(int i=0; i<nums.size(); i++){
        if(rsbm&nums[i]){
            n1^=nums[i];
        }else{
            n2^=nums[i];
        }
    }
    
    return {min(n1,n2),max(n1,n2)};
}

// *** swap two numbers without temporary variable
void swapNum(int &a, int &b){
    int xr = a^b;
    a = a^xr;
    b = b^xr;
}

// *** Single Number II
int singleNumber(vector<int>& nums) {
    int ans = 0;
    for(int i=0; i<32; i++){    // set the all 32 bits of digit
        int msk = 1<<i;         // mask with the i'th bit set
        int zb=0,ob=0;
        
        for(int j=0; j<nums.size(); j++){
            if(nums[j]&msk){    // check if i'th bit is set
                ob++;           // increase one bit counter
            }else{              // check if i'th bit is unset
                zb++;           // increase zero bit counter
            }
        }
        if(ob%3!=0){
            // set the bit at i'th position
            ans = ans|msk;
        }else{
            // bit is by default unset so no need to do anything
        }
    }
    return ans;
}

// *** Number of 1 Bits
int hammingWeight(uint32_t n) {
    int no=0;
    while(n){
        n=(n&(n-1));
        no++;
    }
    return no;
}

// *** trailing zeros in integer
int trailingZeros(int n){
    int tz=0;
    while(n%2==0){
        n=n>>1;
        tz++;
    }
    return tz;
}

// *** Reverse Bits
bool isKthBitSet(int k, int n){
    int kthBitSetMask = 1<<(k-1);
    if((kthBitSetMask&n) != 0){
        return true;
    }
    return false;
}
uint32_t reverseBits(uint32_t n) {
    int ans;
    for(int i=1; i<=32; i++){
        if(isKthBitSet(i,n)){
            ans = (1<<(32-i))|ans;
        }
    }
    return ans;
}

// *** Sum of pairwise Hamming Distance
int hammingDistancePairWise(const vector<int> &A) {
    long long cnt = 0;
    int md = 1000000007;

    for(int i=0; i<32; i++){
        long long count0=0;
        long long count1=0;
        for(int j=0; j<A.size(); j++){
            if((A[j]&(1<<i))==0){
                count0++;
            }else{
                count1++;
            }
        }
        cnt += (count0*count1*2)%md;
    }

    return ((cnt%md)%md);
}

// *** Missing Number
int missingNumber(vector<int>& nums) {
    int res = nums.size();
    for(int i=0; i<nums.size(); i++){
        res ^= i;
        res ^= nums[i];
    }
    return res;
}

// *** find position of set bit
int findPosition(int N) {
    if(N==0) return -1;
    if((N&(N-1))==0){
        return log2(N)+1;
    }
    return -1;
}

// *** Excel Sheet Column Number
int titleToNumber(string columnTitle) {
    int ans = 0;
    int factor = 0;
    for(int i=columnTitle.size()-1; i>=0; i--){
        int val = columnTitle[i]-'A'+1;
        ans += (val*pow(26,factor));
        factor++;
    }
    return ans;
}

// *** Excel Column name from a given column number
string colName(long long int n)
{
    string s = "";
    while(n){
        long long val = n%26;
        n=n/26;
        char c;
        if(val==0){
            n--;
            c='Z';
        }
        else c = val+'A'-1;
        s.push_back(c);
    }
    reverse(s.begin(),s.end());
    return s;
}


// *** Find Missing And Repeating
 int *findTwoElement(int *arr, int n) {
    int *ans = new int[2];
    int xr=0;
    for(int i=0; i<n; i++){
        xr^=arr[i];
        xr^=(i+1);
    }
    int rsbOfXr = (xr&-xr);
    int set1=0,set2=0;
    for(int i=0; i<n; i++){
        if((arr[i]&rsbOfXr)==0){
            set1^=arr[i];
        }else{
            set2^=arr[i];
        }
        
        if(((i+1)&rsbOfXr)==0){
            set1^=(i+1);
        }else{
            set2^=(i+1);
        }
    }
    
    
    for(int i=0; i<n; i++){
        if(arr[i]==set1){
            ans[0]=set1;
            ans[1]=set2;
        }else if(arr[i]==set2){
            ans[0]=set2;
            ans[1]=set1;
        }
    }
    
    return ans;
}



int main(){
    int a = 34;
    bitset<32> b(a);
    string s = b.to_string();
    cout<<s<<endl; 
    return 0;
}