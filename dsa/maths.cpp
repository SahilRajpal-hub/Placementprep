#include <bits/stdc++.h>
using namespace std;

// *** trailing zeros in n factorial
int tarilingZero(int n){
    int res = 0;
    for(int i=5; i<=n; i*=5){
        res += (n/i);
    }
    return res;
}

// *** check if number is palindrome
// ?? Hint -> how to get last digit == (n%10)
bool isPalindromeNumber(int num){
    int n = num;
    int reverseNum = 0;
    while(n){
        int lastDigit = n%10;
        reverseNum = reverseNum*10;
        reverseNum += lastDigit;
        n = n - lastDigit;
        n/=10;
        
    }
    if(reverseNum==num) return true;
    return false;
}

// for number greater than 10^18
bool isPalindromeNumber2(long long num){
    string numString = to_string(num);
    string reverseString = numString;
    reverse(numString.begin(),numString.end());
    return numString==reverseString;
}

// *** check if number is Prime
bool isPrime(int n){
    if(n<=2) return true;
    for(int i=2; i*i<n; i++){
        if(n%i==0) return false;
    }
    return true;
}

// *** tell the prime numbers in range using Sieve of Eratosthenes
bool* sieveOfEratosthenes(int n){
    bool * arr = new bool[n+1];
    memset(arr,true,n+1);
    arr[0]=arr[1]=false;

    for(int i=2; i*i<=n; i++){
        for(int j=2*i; j<=n; j+=i){
            arr[j]=false;
        }
    }

    return arr;
}

// *** GCD/HCF of two numbers
// ? GCD(a,b) = GCD(a-b,b) = GCD(b, a%b);
int gcd(int a,int b){
    // return b==0 ? a:gcd(b,a%b);  ---> one liner function
    if(b==0) return a;
    return gcd(b,a%b);
}

// *** LCM of two numbers
// ? LCM(a,b) = (a*b)/GCD(a,b);
int lcm(int a,int b){
    return (a*b)/gcd(a,b);
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

// *** modulo formulae
int m = 1e9+7;
// ? (a+b)%m = ((a%m) + (b%m))%m
// ? (a*b)%m = ((a%m) * (b%m))%m
// ? (a-b)%m = ((a%m) - (b%m))%m

// *** (x^y)%p efficent approach
int power(long long x, unsigned int y, int p)
{
    int res = 1;     // Initialize result
 
    x = x % p; // Update x if it is more than or
                // equal to p
  
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

// *** calculation of nCr = (n!) / (r! * (n-r)!)
int binomialCoeff(int n, int r)
{
    int res = 1;
 
    // Since C(n, k) = C(n, n-k)
    if (r > n - r)
        r = n - r;
 
    // Calculate value of
    // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
    for (int i = 0; i < r; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
 
    return res;
}


int main(){
    // bool* arr = sieveOfEratosthenes(31);
    // for(int i=0; i<=31; i++){
    //     cout<<i<<" "<<arr[i]<<endl;
    // }
    cout<<lcm(27,3)<<endl;
    cout<<lcm(3,27)<<endl;
    return 0;
}