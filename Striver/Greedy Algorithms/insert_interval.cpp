// https://leetcode.com/problems/insert-interval/
class Solution {
public:
    //left part remain as it is----just insert into the ans vector
    //so do right part
    // find the middle range of elements and find starting and end point
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>>ans;
        int i = 0;
        
        //checking for empty array
        if(n==0){
            ans.push_back({newInterval[0],newInterval[1]});
            return ans;
        }
        //insertion of left part
        // till current end is less than given node start
        while(i<n and intervals[i][1] < newInterval[0]){
            ans.push_back({intervals[i]});
            i++;
        }
        
        //operation on middle range
        int starting = newInterval[0];
        int ending = newInterval[1];
        while(i<n and ending >= intervals[i][0]){
            starting = min(starting,intervals[i][0]);
            ending = max(ending, intervals[i][1]);
            i++;
        }
        ans.push_back({starting,ending});
        
        
        //insertion of right half
        //insert the remaining array
        while(i<n){
            ans.push_back({intervals[i]});
            i++;
        }
        
        
        
        //return ans vector
        return ans;
    }
};
