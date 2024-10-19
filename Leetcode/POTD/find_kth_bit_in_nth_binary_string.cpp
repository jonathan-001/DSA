// https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/
// 19 oct 2024


class Solution {
public:
    // find the middle of the string
    // use bottom up recurrsive approach
    // if k is less than middle , find in lesser string
    // if k is equal to middle , return 1(as 1 is added in middle)
    // else other part is just reversed and inverted, first find the char corresponding to it in the first half and recursive call
    //  for inversion, just 0 to 1 and 1 to 0
    // for the base case , it is known that length 1 will be only '0';
    
    
    char findKthBit(int n, int k) {
        if(n==1){  //only contain 0
            return '0';
        }
        
        int middle = (1 << n)-1; // pow(2,n)-1
        
        if(k < ceil(middle/2.0)){
           return findKthBit(n-1,k); //if left half, call for lesser value of n
        }
        else if(k == ceil(middle/2.0)){ // if middle , 1 will be output
            return '1';
        }
        else{
            char ch = findKthBit(n-1,middle-k+1); // reversed call for first half
            // if(ch == '0') return '1';
            // else  return '0';
            return (ch =='0')?'1':'0'; //invert
        }
        return '-1';
    }
};
