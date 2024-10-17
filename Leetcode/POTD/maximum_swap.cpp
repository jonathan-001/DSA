// https://leetcode.com/problems/maximum-swap/
// 17 oct 2024
class Solution {
public:
    int maximumSwap(int num) {
        //find the min and max element and swap
//         int maxindex = 0;
//         int minindex = 0;
//         string number = to_string(num);
//         for(int i  = 0;i<number.size();i++){
//             if(number[maxindex]<number[i]){
//                 maxindex = i;
//             }
//             if(number[minindex]>number[i]){
//                 minindex = i;
//             }
//         }
//         // if(maxindex>minindex)
//             swap(number[maxindex],number[minindex]);
        
        
//        return stoi(number); 
         string numStr = to_string(num);
    int n = numStr.size();
    
    // Record the last occurrence of each digit (0-9)
    vector<int> lastIndex(10, -1);
    
    for (int i = 0; i < n; ++i) {
        lastIndex[numStr[i] - '0'] = i;
    }
    
    // Traverse the number and find the first digit that can be swapped
    for (int i = 0; i < n; ++i) {
        // Look for a larger digit to swap with numStr[i]
        for (int d = 9; d > numStr[i] - '0'; --d) {
            if (lastIndex[d] > i) {
                // Swap the digits
                swap(numStr[i], numStr[lastIndex[d]]);
                return stoi(numStr); // Return the new number
            }
        }
    }
    
    // If no swap can maximize the number, return the original number
    return num;
    }
};
