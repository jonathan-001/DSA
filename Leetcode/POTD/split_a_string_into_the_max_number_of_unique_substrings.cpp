// https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/
// 21 oct 2024

// not correct approach
// class Solution {
// public:
//     int maxUniqueSplit(string s) {
//         int n = s.size();
//         unordered_set<string>set;
//         string ch = "";
//         int count = 0;
        
        
//         for(int i = 0; i<n;i++){
            
//             ch = ch+s[i];
            
//             //if it is not present in the set
//             // insert into the set and count++
//             // reset char
//             if(set.find(ch) == set.end()){
//                 set.insert(ch);
//                 cout<<ch<<" ";
//                 count++;
//                 ch = "";
//             }
//             // if present in the set
//             // concat into existing ch and continue;
// //             else{
                
// //             }
//         }
        
//         return count;
//     }
// };




// backtracking approach
class Solution {
public:

    void solve(string& s, int idx, unordered_set<string>& st, int currCount, int& maxCount) {
        if(currCount + (s.length() - idx) <= maxCount) { //Pruning for slight improvement
            return;
        }

        if(idx == s.length()) {
            maxCount = max(maxCount, currCount);
        }

        for(int j = idx; j < s.length(); j++) {
            string sub = s.substr(idx, j-idx+1);
            if(st.find(sub) == st.end()) {
                st.insert(sub);
                solve(s, j+1, st, currCount+1, maxCount);
                st.erase(sub);
            }
        }
    }

    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        int maxCount  = 0;
        int currCount = 0;
        solve(s, 0, st, currCount, maxCount);

        return maxCount;
    }
};
