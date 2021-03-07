#include <string>
#include <iostream>
using namespace std;

// Could use sliding window of increasing size!
//Expand Around center optimum = TO(n^2) SO(1)
class Solution {
    
    string findNextToLength(string s){
        int longest = 0;
        string st = s.substr(0,1);
        if(s.size()<2)return st;
        for(int i = 1;i<s.size();i++){
            if(s[i]==s[i-1]){
                int length=2;
                        int dev = 1;

                while(i-1-dev>=0 && i+dev<s.size()){
                    if(s[i-1-dev]==s[i+dev]){
                        length+=2;
                        dev++;
                    }
                    else break;
                }
                if(length>longest){
                    longest=length;
                    st = s.substr(i-dev,length);
                }
                
            }
        }
        return st;
    }
    string findCenterLength(string s){
        int longest = 0;
        string st = s.substr(0,1);
        if(s.size()<3)return st;
        for(int i = 2;i<s.size();i++){
        if(s[i-2]==s[i]){
            int length =3;
            int dev = 2;

            while(i-1-dev>=0 && i + dev <= s.size()){
                if(s[i-1-dev]==s[i-1+dev]){
                    length+=2;
                    dev++;
                }
                else break;
            }
            if(length>longest){
                longest = length;
                st = s.substr(i-dev,longest);

            }
        }
        }
        return st;
    }
public:
    string longestPalindrome(string s) {
        string longestCurr = s.substr(0,1);
        int longestLength=0;
        //" a s b s d d s b v"
        //          | |
        
        //" a s b s d s b v"
        //        i | i
        string NextToLength = findNextToLength(s);
        string centerLength = findCenterLength(s);
        return NextToLength.size() > centerLength.size() ? NextToLength : centerLength;
    
}};

int main()
{
    Solution s;
    string test = "xaabacxcabaaxcabaax";
    s.longestPalindrome(test);
    return 0;
}