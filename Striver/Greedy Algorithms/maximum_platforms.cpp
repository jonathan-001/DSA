// https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    //brute force -> checking every train with other if greater increase platform count
    // at last take the max of all
    // greedy approach-->
    // overlapping intervals
    
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        //sort the both array
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        
        int maxi_platform = 0;
        int count = 0;
        int n = arr.size();
        int i = 0;
        int j = 0;
        
        //iteration 
        while(i<n and j<n){
            
            //if arrival time is less or equal , means platform required
            if(arr[i] <= dep[j]){
                count++;
                i++;
            }
            else if(arr[i] > dep[j]){
                count--;
                j++;
            }
            
            maxi_platform = max(maxi_platform, count);
        }
        return maxi_platform;
    }
};
