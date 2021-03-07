#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include <unordered_map>
std::unordered_map<int,string> u= {
    {1,"I"},
    {5,"V"},
    {10,"X"},
    {50,"L"},
    {100,"C"},
    {500,"D"},
    {1000,"M"}
};

class Solution {
private: 
    string parseColumn(int remainder,int tens){
        if(remainder==4){
            return u[1*tens]+u[5*tens];
        }
        if(remainder==9){
            return u[1*tens]+u[10*tens];
        }
        int ans=remainder;
        string res = "";
        if(ans>=5){
            res = res + u[5*tens];
            ans = ans-5;
        }
        while(ans>0){
            res = res + u[1*tens];
            ans = ans-1; 
        }
        return res;
        
    }
public:
    string intToRoman(int num){
        string answer = "";
        int resNum = num;
        answer = answer + parseColumn(num%10,1);
        resNum = (resNum - resNum%10)/10;
        answer =  parseColumn(resNum%10,10) + answer;
        resNum = (resNum - resNum%10)/10;
        answer = parseColumn(resNum%10,100) + answer;
        resNum = (resNum - resNum%10)/10;
        answer = parseColumn(resNum%10,1000) + answer;
        
        std::cout<<answer;
        return answer;
    }
    
};
int main(){
    Solution s;
    s.intToRoman(58);
    return 0;
}