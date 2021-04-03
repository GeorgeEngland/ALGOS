

#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int slow = 0;
        int fast = 1;
        int min=prices[0];
        int  profit = 0;
        while(fast<prices.size()){
            //if price goes down since buy in, set that as when you buy in.
            if(prices[fast]<min){
                min = prices[fast];
                slow=fast;
                fast++;
                continue;
            }
            
            //if most recent price bigger than current price,sell
            if(prices[fast]>prices[slow]){
                profit+=prices[fast]-prices[slow];
                slow = fast;
                min=prices[slow];
                fast++;
            }
            else{
                fast++;
            }
            
            
            
        }
        return profit;
    }
};
int main(){
    Solution s;
    vector<int> prices={1,2,3,4,9,0,4};
    cout<<"Max Profit = "<<s.maxProfit(prices)<<endl;
    return 0;
}