// https://leetcode.com/problems/binary-subarrays-with-sum/

class Solution {
public:
    //using presum approach
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>map;
        int count = 0;
        int sum = 0;
        int n = nums.size();
        map[0]=1;// helps when goal will be equal to sum 
        // note-- count will be increased by 1 at a time by this
        for(int i = 0;i<n;i++){
            sum += nums[i];
            
            int rem = sum-goal;
            if(map.find(rem) != map.end()){
                count += map[rem];
            }
            
            map[sum]++;
        }
        return count;
    }
};
