#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;


class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        
        int slow =0;
        int ans = 0;
        //while slow < size - K
        while(slow<A.size()){
            bool firstpass=true;
            //initialise map, initialise fast, unique elems
            unordered_map<int,int> db; int fast = slow; int uniqueElems = 0;
                // while unique elems <= K && fast < size
                while(uniqueElems<=K && fast < A.size()){

                    // if( unique elems < K){ increment fast; is item in hash map ? increment in hash map : incrememnt unique elems, increment in hash map; continue
                    if(uniqueElems<K){
                        if(!db[A[fast]]){
                            uniqueElems++;db[A[fast]]=1;
                            if(uniqueElems!=K){fast++;continue;
                            }}
                        else{
                            db[A[fast]]++;fast++;continue;}
                    }
                    //}
                    // if( A[fast] is in hash map) ans++;increment fast
                    if(db[A[fast]]){ans++;fast++;}
                    //else break;
                    else break;
                }
            //increment slow
            slow++; 
        }
        return ans;
    }
};

int main(){

    Solution s;
    vector<int> in={1,2,1,2,3};
    cout<<s.subarraysWithKDistinct(in,2);


    return 0;
}