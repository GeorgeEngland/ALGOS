#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int findno(vector<int>& nums, int k)
{
	unordered_map<int,int> hashmap;
	int j=0,count=0;
	for(int i=0;i<nums.size();i++)
	{
		hashmap[nums[i]]++;
		while(hashmap.size()>k)
		{
			hashmap[nums[j]]--;
			if(hashmap[nums[j]]==0)
				hashmap.erase(nums[j]);
			j++;
		}
		count=count+i-j+1;
	}
	return count;
}
int subarraysWithKDistinct(vector<int>& nums, int k) {
	return findno(nums,k)-findno(nums,k-1);
}

int main(){

    vector<int> in={1,2,1,2,3};
    cout<<subarraysWithKDistinct(in,2);


    return 0;
}