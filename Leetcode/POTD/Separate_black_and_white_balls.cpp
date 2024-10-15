// 15 oct 2024
// as we move forward , count the 1's when encounter 0 
// no of 1's will be swapped value

class Solution {
public:
    long long minimumSteps(string s) {
        long long black = 0;
        long long  swap = 0;
        
        for(char ch : s){
            
            // if white , till point blacks will be no of swaps
            // for it
            if(ch == '0'){
                swap += black;
            }
            // if it is black just count on 
            else{
                black++;
            }
        }
        
        return swap;
    }
};
