link of the question----> https://leetcode.com/problems/maximal-score-after-applying-k-operations/

date--> 14 oct 2024

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        
        //use of priority queue(max heap for easy access of max element)
        //take max element and sum it up 
        //pop it and divide by 3 and again push
        //iterate till k
        
        
         long long sum = 0;
        priority_queue<int>qs(nums.begin(),nums.end());

         while(k--){
            int temp = qs.top();
            qs.pop();

            sum += temp;

            temp = ceil(temp/3.0);
            qs.push(temp);
        }
        return sum;
    }
};
