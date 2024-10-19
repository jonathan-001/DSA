// https://leetcode.com/problems/count-number-of-nice-subarrays/


class Solution {
public:
    
    
    int helper(const vector<int>&nums,int k){
        int oddcount = 0;
        int left = 0;
        int right = 0;
        int maxcount= 0;
        int count = 0;
        
        for(int right = 0; right<nums.size();right++){
            if(nums[right]%2==1){
                oddcount++;
            }
            
            while(oddcount>k){
                if(nums[left]%2==1){
                    oddcount--;
                }
                left++;
            }
            // maxcount = max(maxcount,oddcount);
            // maxcount += oddcount;
            count += (right-left+1); // subarray that end at right and having atmost k odd elements in it
        }
        return count ;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k-1);
    }
};
