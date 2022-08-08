
#include <bits/stdc++.h>
using namespace std;

// * stack identification =>
//  ?? when solution require two loops in which second loop depends upon variable of first loop

// ! Type-1 N G/S L/R

// TODO 1. Nearest Greater to left
//   * => code
vector<int> solve(vector<int> v)
{
    stack<int> s;
    vector<int> ans;

    for (int i : v)
    {
        while (!s.empty() && s.top() < i)
            s.pop();

        if (s.empty())
            ans.push_back(-1);
        else
            ans.push_back(s.top());

        s.push(i);
    }

    return ans;
}

// TODO 2. Nearest smaller to left
//   * => code
vector<int> solve(vector<int> v)
{
    stack<int> s;
    vector<int> ans;

    for (int i : v)
    {
        while (!s.empty() && s.top() > i)
            s.pop();

        if (s.empty())
            ans.push_back(-1);
        else
            ans.push_back(s.top());

        s.push(i);
    }

    return ans;
}

// TODO 3. Nearest Greater to right
//   * => code
vector<int> solve(vector<int> v)
{
    stack<int> s;
    vector<int> ans;

    for (int ind = v.size() - 1; ind >= 0; ind--)
    {
        int i = v[ind];

        while (!s.empty() && s.top() < i)
            s.pop();

        if (s.empty())
            ans.push_back(-1);
        else
            ans.push_back(s.top());

        s.push(i);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// TODO 4. Nearest smaller to right
//   * => code
vector<int> solve(vector<int> v)
{
    stack<int> s;
    vector<int> ans;

    for (int ind = v.size() - 1; ind >= 0; ind--)
    {
        int i = v[ind];

        while (!s.empty() && s.top() > i)
            s.pop();

        if (s.empty())
            ans.push_back(-1);
        else
            ans.push_back(s.top());

        s.push(i);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// TODO 5. Stock span problem => The span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backward) for which the stock price was less than or equal to today's price.
// ** Link -> https://leetcode.com/problems/online-stock-span/
//   * => code
vector<int> v;
stack<int> s;
int next(int price)
{
    v.push_back(price);
    int ans, ci = v.size() - 1;
    while (!s.empty() && s.top() >= 0 && v[s.top()] <= price)
        s.pop();

    if (s.empty())
        ans = ci + 1;
    else
        ans = ci - s.top();
    s.push(ci);

    return ans;
}

// TODO 6. Largest Rectangle in Histogram => Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
// ** Link -> https://leetcode.com/problems/largest-rectangle-in-histogram/
//   * => code
vector<int> nslf(vector<int> h)
{
    vector<int> ans;
    stack<pair<int, int>> s;

    for (int i = 0; i < h.size(); i++)
    {
        while (!s.empty() && s.top().first >= h[i])
            s.pop();

        if (s.empty())
            ans.push_back(-1);
        else
            ans.push_back(s.top().second);

        s.push({h[i], i});
    }
    return ans;
}

vector<int> nsrf(vector<int> h)
{
    vector<int> ans;
    stack<pair<int, int>> s;

    for (int i = h.size() - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top().first >= h[i])
            s.pop();

        if (s.empty())
            ans.push_back(-1);
        else
            ans.push_back(s.top().second);

        s.push({h[i], i});
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int mah(vector<int> &heights)
{
    vector<int> nsr = nsrf(heights);
    vector<int> nsl = nslf(heights);
    int ans = INT_MIN;
    for (int i = 0; i < heights.size(); i++)
    {
        int dl = nsl[i] == -1 ? i + 1 : i - nsl[i];
        int dr = nsr[i] == -1 ? heights.size() - i : nsr[i] - i;

        int area = (dl + dr - 1) * heights[i];
        ans = max(ans, area);
    }
    return ans;
}

// TODO 7.  Maximal Rectangle => Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
// ** Link -> https://leetcode.com/problems/maximal-rectangle/
//   * => code
vector<int> nslf(vector<int> h)
{
    stack<pair<int, int>> s;
    vector<int> ans;

    for (int i = 0; i < h.size(); i++)
    {
        while (!s.empty() && s.top().first >= h[i])
            s.pop();

        if (s.empty())
            ans.push_back(-1);
        else
            ans.push_back(s.top().second);

        s.push({h[i], i});
    }
    return ans;
}

vector<int> nsrf(vector<int> h)
{
    stack<pair<int, int>> s;
    vector<int> ans;

    for (int i = h.size() - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top().first >= h[i])
            s.pop();

        if (s.empty())
            ans.push_back(-1);
        else
            ans.push_back(s.top().second);

        s.push({h[i], i});
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int mah(vector<int> h)
{
    vector<int> nsl = nslf(h);
    vector<int> nsr = nsrf(h);
    int ans = INT_MIN;
    for (int i = 0; i < h.size(); i++)
    {
        int dl = nsl[i] == -1 ? i + 1 : i - nsl[i];
        int dr = nsr[i] == -1 ? h.size() - i : nsr[i] - i;
        int temp = (dl + dr - 1) * h[i];
        ans = max(ans, temp);
    }
    return ans;
}
int maximalRectangle(vector<vector<char>> &matrix)
{
    int r = matrix.size();
    int c = matrix[0].size();
    int ans = INT_MIN;
    vector<int> vh(c, 0);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (matrix[i][j] == '1')
            {
                vh[j]++;
            }
            else
            {
                vh[j] = 0;
            }
        }
        int temp = mah(vh);
        ans = max(ans, temp);
    }
    return ans;
}


// ! Type-2 Stack Implementation

// TODO 8.  Minimum Element in Stack with Extra space => with the help of supporting stack that carries min element till now.
// ** Link -> https://leetcode.com/problems/min-stack/
//   * => code

// ! Type-3 Infix Postfix Prefix

// TODO 9. Infix to Postfix -> Given an infix expression in the form of string str. Convert this infix expression to postfix expression.
// ** Link -> https://practice.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1
// * => code
int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    return -1;
}

string infixToPostfix(string s)
{
    string ans;
    stack<char> st;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else if (s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-' || s[i] == '^')
        {
            // if(st.empty() || st.top()=='('){
            //     st.push(s[i]);
            // }else if(prec(st.top()) >= prec(s[i])){
            //     ans += st.top();
            //     st.pop();
            //     st.push(s[i]);
            // }else{
            //     while(!st.empty() && prec(st.top())>=prec(s[i])){
            //         ans += st.top();
            //         st.pop();
            //     }
            // }
            while (!st.empty() && prec(s[i]) <= prec(st.top()))
            {
                if (s[i] == '^' && st.top() != '^')
                    break;
                else
                {
                    ans += st.top();
                    st.pop();
                }
            }
            st.push(s[i]);
        }
        else
        {
            ans += s[i];
        }
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    return ans;
}

// TODO 10. Postfix evaluation -> 
// ** Imp -> Could even include strings then stack would be of string
// * => code
int evaluatePostfix(string s)
{
    stack<int> st;
    
    for(int i=0; i<s.size(); i++){
        if(s[i]>='0' && s[i]<='9'){
            st.push((int)(s[i]-'0'));
        }else{
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            int ans = 0;
            if(s[i]=='*') ans = a*b;
            else if(s[i]=='+') ans = a+b;
            else if(s[i]=='-') ans = b-a;
            else if(s[i]=='/') ans = b/a;
            else ans=b^a;
            st.push(ans);
        }
    }
    
    return st.top();
}



// ! Type-4 Parenthesis

// TODO 11. Parenthesis check
bool ispar(string s)
{
    stack<char> st;
    for(char c:s){
        if(c=='{' || c=='(' || c=='['){
            st.push(c);
        }else{
            if(c=='}'){
                if(st.empty() || st.top()!='{') return false;
                else st.pop();
            }else if(c==')'){
                if(st.empty() || st.top()!='(') return false;
                else st.pop();
            }else if(c==']'){
                if(st.empty() || st.top()!='[') return false;
                else st.pop();
            }
        }
    }
    return st.empty();
}