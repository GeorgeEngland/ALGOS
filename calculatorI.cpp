#include <stack>
#include <string>
#include <iostream>
using namespace std;

double solution(string input){
    //intialise stack
    stack<double> calcStack;
    //keep track of result and current value to process
    double result = 0, currNumber = 0;
    //keep track of previous sin for precedence assessment
    char prevSign = '+';
    //iterate through entire string
    for(int i = 0;i<input.size();i++){
        //if current char is a digit, append to current number
        if(isdigit(input[i])) currNumber = currNumber*10 + ((int)input[i]-48);
        //if not a digit OR we have reached the end of the string,
            //Process currentNumber
        if(!isdigit(input[i]) || i ==input.size()-1){
            double multValue;
            switch (prevSign)
            {
            case '-':
                calcStack.push(-currNumber);
                prevSign = '-';
                break;
            case '+':
                calcStack.push(currNumber);
                prevSign= '+';
                break;
            //Operators below take precedence and so top of stack has operation performed on it (i.e. before summation)
            //Divide and multiply are commutative, therefore can be applied one after the other
            case '*':
                multValue = calcStack.top() * currNumber;
                calcStack.pop();
                calcStack.push(multValue);
                break;
            case '/':
                multValue = calcStack.top() * (1 / currNumber);
                calcStack.pop();
                calcStack.push(multValue);
                break;
            }
            currNumber = 0;
            prevSign = input[i];
        }
    }
    
    //Sum over stack
    while(!calcStack.empty()){
        result+=calcStack.top();
        calcStack.pop();
    }
    return result;
}

int main(){
    string test{"3*3/3/3*4/3*2"};
    cout<<solution(test);
}