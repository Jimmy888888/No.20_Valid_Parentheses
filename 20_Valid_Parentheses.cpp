#include <iostream>
#include <string>
#include <map>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        map<char, char> myMap;
        myMap['('] = ')';
        myMap['['] = ']';
        myMap['{'] = '}';
        stack<char> myStack;
        
        for(int i=0; i < s.size(); i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                myStack.push(s[i]);
            }
            else if(s[i] == ')' || s[i] == ']' || s[i] == '}')
            {
                if(myStack.empty())
                {
                    //stack empty means right parentheses is more
                    //so return false
                    //and, in c++, if stack empty, it can't do top()
                    //or program will break, so here get return
                    return false;
                }
                char x = myStack.top();
                myStack.pop();
                if( myMap[x] != s[i])
                {
                    return false;
                }
            }
        }
        return (myStack.empty());
    }
};

int main()
{
    string ss;
    ss = "(())";

    Solution test;
    cout << "test : " << test.isValid(ss);
    return 0;
}