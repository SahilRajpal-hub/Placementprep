#include <bits/stdc++.h>
using namespace std;

// ***? Link -> https://leetcode.com/discuss/study-guide/1437879/Dynamic-Programming-Patterns

// TODO 1. 0-1 Knapsack
//   * => Main Code
int solve(int w, int wt[], int val[], int n)
{
    // initialize dp array with 0
    // ? n->size and w->weight
    int dp[n + 1][w + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][w];
}

//   ? Subset Sum Problem -> Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.
//   * => code
bool solve(vector<int> arr, int sum, int n)
{
    bool dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}

//   ? Equal sum partition ->  Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
//   * => code
bool subset_sum_problem(vector<int> &nums, int sum, int n); // ! defined above
bool solve(vector<int> &nums)
{
    int sum = 0;
    for (int el : nums)
    {
        sum += el;
    }
    if (sum % 2 == 1)
        return false;
    sum = sum / 2;
    return subset_sum_problem(nums, sum, nums.size());
}

//   ? count of subset sum -> Given an array arr[] of length N and an integer X, the task is to find the number of subsets with a sum equal to X.
//   * => code
int subsetSum(int a[], int n, int sum)
{
    int dp[n + 1][sum + 1];
    dp[0][0] = 1;
    for (int i = 1; i <= sum; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (a[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}

//  ? minimum subset sum diff. ->
//   * => code

//  ? Target Sum ->
//   * => code

//  ? # of subsets with given diff. ->
//   * => code

// TODO 2. Unbounded Knapsack
//   * => Main Code
int solve(int w, int wt[], int val[], int n)
{
    // initialize dp array with 0
    // ? n->size and w->weight
    int dp[n + 1][w + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(val[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][w];
}

//   ? Rod Cutting Problem -> Given a rod of length w inches and an array of prices that includes prices of pieces of size smaller than w. Determine the maximum value obtainable by cutting up the rod and selling the pieces.
//   * => code
int cutRod(int price[], int n)
{
    int wt[n];
    for (int i = 1; i <= n; i++)
        wt[i - 1] = i;

    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(price[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][n];
}

//  ? Coin Change Proble 1 Problem -> You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money. Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1
//  * => code
int coinChange(vector<int> &coins, int amount)
{
    int dp[coins.size() + 1][amount + 1];
    for (int i = 0; i <= coins.size(); i++)
        for (int j = 0; j <= amount; j++)
        {
            if (j == 0)
                dp[i][j] = 0;
            if (i == 0)
                dp[i][j] = INT_MAX - 1;
        }

    for (int i = 1; i <= coins.size(); i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            if (coins[i - 1] <= j)
            {
                dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[coins.size()][amount] == INT_MAX - 1 ? -1 : dp[coins.size()][amount];
}

//  ? Coin Change Proble 2 Problem -> You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money. Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
//  * => code
int change(int amount, vector<int> &coins)
{
    int size = coins.size();
    int dp[size + 1][amount + 1];
    for (int i = 0; i <= size; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            if (j == 0)
                dp[i][j] = 1;
        }
    }

    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            if (coins[i - 1] <= j)
            {
                dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[size][amount];
}

//   ? Maximum Ribbon Cut Problem ->
//   * => code

//   ? Combination Sum IV Problem ->
//   * => code

//   ? Perfect Squares Problem ->
//   * => code
int numSquares(int n)
{
    int val[100];
    for (int i = 1; i <= 100; i++)
    {
        val[i - 1] = i * i;
    }

    int dp[101][n + 1];
    for (int i = 0; i <= 100; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0)
                dp[i][j] = INT_MAX - 1;
            if (j == 0)
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= 100; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (val[i - 1] <= j)
            {
                dp[i][j] = min(1 + dp[i][j - val[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[100][n];
}

//   ? Integer Break Problem ->
//   * => code

// TODO 3. Fibonacci / digit dp / ugly numbers

// TODO 4. LCS => Longest Common Subsequence
//   * => Main Code

// ?**** <------------------   Recursive -------------------------------------------->
int lcs(string s1, string s2, int m, int n)
{
    if (m < 0 || n < 0)
        return 0;

    int ans = 0;
    if (s1[m] == s2[n])
        ans = 1 + lcs(s1, s2, m - 1, n - 1);
    else
        ans = max(lcs(s1, s2, m, n - 1), lcs(s1, s2, m - 1, n));
    return ans;
}

// ?**** <------------------   DP -------------------------------------------->
int longestCommonSubsequence(string text1, string text2)
{
    int m = text1.size();
    int n = text2.size();
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

//   ? Print LCS ->
//   * => code
string printLongestCommonSubsequence(string text1, string text2)
{
    int m = text1.size();
    int n = text2.size();
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string ans = "";
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (text1[i - 1] == text2[j - 1])
        {
            ans += text1[i - 1];
            i--;
            j--;
        }
        else
        {
            if (dp[i][j - 1] > dp[i - 1][j])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }
    reverse(ans.begin(), ans.end());

    return ans;
}

//   ? Length of Shortest Common Supersequence ->
//   * => code
int lengthOfSCS(string s1, string s2, int m, int n)
{
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int ans = m + n - dp[m][n];
    return ans;
}

//   ? Print Shortest Common Supersequence ->
//   * => code
string printSCS(string s1, string s2, int m, int n)
{
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int i = m, j = n;
    string ans = "";
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans.push_back(s1[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                ans.push_back(s1[i - 1]);
                i--;
            }
            else
            {
                ans.push_back(s2[j - 1]);
                j--;
            }
        }
    }

    while (i > 0)
    {
        ans.push_back(s1[i - 1]);
        i--;
    }
    while (j > 0)
    {
        ans.push_back(s2[j - 1]);
        j--;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

//   ? Length of Longest Common Substring ->
//   * => code
int longestCommonSubstr(string s1, string s2, int n, int m)
{
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    int ans = INT_MIN;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}

//   ? Print LC Substr ->
//   * => code
string printLongestCommonSubstr(string s1, string s2, int n, int m)
{
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    int ans = INT_MIN;
    pair<int, int> pr;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (dp[i][j] > ans)
            {
                ans = dp[i][j];
                pr = {i, j};
            }
        }
    }
    string sst = s2.substr(pr.second - ans, ans);
    return sst;
}

//   ? Minimum # of insertions and deletions to convert a to b ->
//   * => code
int minOperations(string s1, string s2)
{
    int m = s1.size();
    int n = s2.size();
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return m + n - 2 * dp[m][n];
}

//   ? largest Repeating subsequence ->
//   * => code
int LongestRepeatingSubsequence(string s)
{
    int n = s.size();
    int dp[n + 1][n + 1];

    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == s[j - 1] && i != j)
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][n];
}

//   ? Length of largest subsequence of a which is a substring in b ->
//   * => code

//   ? Subsequence pattern matching ->
//   * => code
// TODO just check if length of lcs and string a is same or not

//   ? Count how many times a appears as subsequence in b ->
//   * => code

//   ? Largest palindromic subsequence ->
//   * => code
int lcs(string s1, string s2)
{
    int m = s1.size();
    int dp[m + 1][m + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][m];
}
int longestPalindromeSubseq(string s)
{
    string rs = s;
    reverse(rs.begin(), rs.end());
    return lcs(s, rs);
}

//   ? Count of palindromic substring ->
//   * => code

//   ? Minimum # of deletions/insertions in string to make it palindromic ->
//   * => code
int minDeletions(string s, int n)
{
    string rs = s;
    reverse(rs.begin(), rs.end());
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == rs[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return n - dp[n][n];
}

// TODO 5. LIS

// TODO 6. Kadane's Algorithm

// TODO 7. Matrix Chain Multiplication (Only recursive and memoize work well in this type of question, top down causes confusion)
//   * => Main Code

//   ? Printing MCM ->
//   * => code

//   ? Evaluate expression to true/ Boolean parenthesis ->
//   * => code

//   ? Min/Max value of a parenthesis ->
//   * => code

//   ? Palindromic partitioning ->
//   * => code

//   ? Scramble String ->
//   * => code

//   ? Egg Droping problem ->
//   * => code

//   ? Burst Balloons ->
//   * => code



// TODO 8. DP on trees

// TODO 9. DP on grid

// TODO 10. Others