// https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/
//18 oct 2024

class Solution {
public:
    int count =  0;
    int maxor = 0;
    void helper(vector<int>nums,int index,int curr_or){
        
        if(nums.size()==index){
            if(curr_or == maxor){
                count++;
            }
            return;
        }
        
        //first call with or
        helper(nums,index+1,nums[index]|curr_or);
        //second call without or
        helper(nums,index+1,curr_or);
        
        
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        for(auto it:nums){
            maxor = maxor|it;
        }
        helper(nums,0,0);
        return count;
    }
};
