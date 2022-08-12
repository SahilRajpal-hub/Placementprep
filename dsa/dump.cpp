#include <bits/stdc++.h>
using namespace std;

int prec(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}

int operationPerform(int a, int b, char c)
{
    switch (c)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }

    return 0;
}

int evaluate(string exprr)
{
    int i;
    stack<int> st;

    stack<char> ops;

    for (i = 0; i < exprr.length(); i++)
    {
        if (exprr[i] == ' ')
            continue;
        else if (exprr[i] == '(')
        {
            ops.push(exprr[i]);
        }
        else if (isdigit(exprr[i]))
        {
            int val = 0;
            while (i < exprr.length() &&
                   isdigit(exprr[i]))
            {
                val = (val * 10) + (exprr[i] - '0');
                i++;
            }

            st.push(val);
            i--;
        }

        else if (exprr[i] == ')')
        {
            while (!ops.empty() && ops.top() != '(')
            {
                int val2 = st.top();
                st.pop();

                int val1 = st.top();
                st.pop();

                char op = ops.top();
                ops.pop();

                st.push(operationPerform(val1, val2, op));
            }

            if (!ops.empty())
                ops.pop();
        }

        else
        {
            while (!ops.empty() && prec(ops.top()) >= prec(exprr[i]))
            {
                int val2 = st.top();
                st.pop();

                int val1 = st.top();
                st.pop();

                char op = ops.top();
                ops.pop();

                st.push(operationPerform(val1, val2, op));
            }

            ops.push(exprr[i]);
        }
    }

    while (!ops.empty())
    {
        int val2 = st.top();
        st.pop();

        int val1 = st.top();
        st.pop();

        char op = ops.top();
        ops.pop();

        st.push(operationPerform(val1, val2, op));
    }

    return st.top();
}


int solve(vector<int> v){
    priority_queue<int,vector<int>,greater<int>> pq;

    for(int i=0; i<v.size(); i++){
        pq.push(v[i]);
        if(pq.size()>4){
            pq.pop();
        }
    }

    int sum = 0;
    while(!pq.empty()){
        sum += pq.top();
        pq.pop();
    }
    return sum;
}



int firstNonRepeating(string str)
{
    int n = 256;
    int arr[n];
    for (int i = 0; i < n; i++)
        arr[i] = -1;
 

    for (int i = 0; str[i]; i++) {
        if (arr[str[i]] == -1)
            arr[str[i]] = i;
        else
            arr[str[i]] = -2;
    }
 
    int res = INT_MAX;
    for (int i = 0; i <n; i++)
        if (arr[i] >= 0)
            res = min(res, arr[i]);
 
    return res;
}





int main(){
    vector<int> v;

    int ans = solve(v);
    cout<<ans<<endl;
    return 0;
}
















string ls[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

int getValue(string temp)
{
	for (int x = 0; x < 10; x++)
	{
		if (temp == ls[x])
		{
			return x;
		}
	}

	return -1;
}

string getExpression(char digit)
{
	int index = int(digit) - 48;

	return ls[index];
}

string StringExpression(string str)
{
	string temp;
	string number = "";
	vector <int> numberls;


	for (int x = 0; x < str.length(); x++)
	{
		temp.push_back(str[x]);

		int value = getValue(temp);
		if (value >= 0 && value <= 9)
		{
			stringstream convert;
			convert << value;
			number += convert.str(); 
			temp.clear();
		}

		if (temp == "plus" || temp == "minus" || x == str.length()-1)
		{
			int result;
			istringstream(number) >> result;
			numberls.push_back(result);

			number = "";

			if (temp == "plus") numberls.push_back(0);
			else if (temp == "minus") numberls.push_back(1);
			temp.clear();
		}
	}

	int total = numberls[0];
	for (int x = 1; x < numberls.size() - 1; x += 2)
	{
		if (numberls[x] == 0) total += numberls[x + 1];
		else total -= numberls[x + 1];
	}

	stringstream convert;
	convert << total;
	number = convert.str();
	string finalString= "";

	if (total < 0) finalString += "negative";

	for (int x = 0; x < number.length(); x++)
	    finalString += getExpression(number[x]);
	

	return finalString;
}