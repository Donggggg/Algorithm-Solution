#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <math.h>
#include <algorithm>
using namespace std;

char prio[3]; 
bool check[3] = { false, }; 
long long ans = 0;
vector<string> sp;
stack<long long> numStack;
stack<char> opStack;
string expList;

long long calculate(long long num1, long long num2, char op)
{
    long long res;

    switch(op) {
        case '*' :
            res = num1*num2;
            break;
        case '+' :
            res = num1+num2;
            break;
        case '-' :
            res = num1-num2;
            break;
    }
    return res;
}

string extractExprsseion(string exp)
{
    string list;

    if(exp.find("*") != -1)
        list.push_back('*');
    if(exp.find("+") != -1)
        list.push_back('+');
    if(exp.find("-") != -1)
        list.push_back('-');

    string nums;
    for(int i = 0; i < exp.length(); i++) {
        if(list.find(exp[i]) != -1) {
            sp.push_back(nums);
            string op(1,exp[i]);
            sp.push_back(op);
            nums.clear();
        } 
        else {
            nums.push_back(exp[i]);
        }
    }
    sp.push_back(nums);

    return list;
}

void getMaxPrize(string expr)
{
    int opPrio[256];
    for(int i = 0; i < 3; i++) 
        opPrio[prio[i]] = 2-i;  

    for(string item : sp) {
        if(expList.find(item) != -1) {
            opStack.push(item[0]);
            
            if(opStack.size() == 1)
                continue;
            
            while(opStack.size() > 1) {
                char cur = opStack.top();
                opStack.pop();

                if(opPrio[opStack.top()] >= opPrio[cur]) {
                    long long num1= numStack.top();
                    numStack.pop();
                    long long num2 = numStack.top();
                    numStack.pop();
                    char op = opStack.top();
                    opStack.pop();
                    long long res = calculate(num2,num1,op);
                    numStack.push(res);
                    opStack.push(cur);
                }
                else {
                    opStack.push(cur);
                    break;
                }
            }
        }
        else {
            numStack.push(stoll(item));
        }
    }
    
    while(!opStack.empty()) {
        long long num1= numStack.top();
                numStack.pop();
                long long num2 = numStack.top();
                numStack.pop();
                char op = opStack.top();
                opStack.pop();
                long long res = calculate(num2,num1,op);
                numStack.push(res);
    }
    
    ans = max(ans, abs(numStack.top()));
}

void permuation(int depth, string expression)
{
    if(expList.length() == depth) {
        getMaxPrize(expression);
        return ;
    }

    for(int i = 0; i < expList.length(); i++) {
        if(!check[i]) {
            check[i] = true;
            prio[depth] = expList[i]; 
            permuation(depth+1, expression);
            check[i] = false;
        }
    }
}

long long solution(string expression) {
    long long answer = 0;    

    expList = extractExprsseion(expression);
    permuation(0, expression);

    answer = ans;
    return answer;
}