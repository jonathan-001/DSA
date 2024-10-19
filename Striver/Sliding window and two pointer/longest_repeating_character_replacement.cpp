// https://leetcode.com/problems/longest-repeating-character-replacement/


class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char,int>map;
        int maxlength = 0;
        int count = 0;
        int right = 0;
        int left = 0;
        
        for(int right = 0; right<n;right++){
            map[s[right]]++;
            
            count = max(count,map[s[right]]);
            
            while( left<n and ((right-left+1)-count)>k ){
                map[s[left]]--;
                // count--;
                left++;
            }
            
            maxlength = max(maxlength,right-left+1);
        }
        return maxlength;
    }
};
