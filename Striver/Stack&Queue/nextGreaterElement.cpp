//find the next greater elememt

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        stack<int>st;
        unordered_map<int,int>map;
        // vector<int>temp(m,-1);
        
        for(int i = m-1; i>=0 ;i--){
            while( !st.empty() and st.top()<nums2[i]){
                st.pop();
            }
            
            
            int temp = st.empty()?-1:st.top();
            map[nums2[i]] = temp;
            // temp[i] = temp;
            st.push(nums2[i]);
        }
        vector<int>ans;
        for(int i = 0 ; i< n ;i++){
            ans.push_back(map[nums1[i]]);
        }
        
        return ans;
        
    }
};
