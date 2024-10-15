//https://leetcode.com/problems/lemonade-change/
// use of greedy approach
// if there is five just add 
// if it is ten, if five exist , add ten , sub. five else return false
// if it is twenty, if five and ten exist sub. from both , other case will be if 
// there are more than 3 five(15 required) sub 3 from five else return false


class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
       int five = 0;
        int ten = 0;
        for(int it:bills){

            //if its 5 add it
            if(it == 5){
                five++;
            }
            //if 10 , add 1 to ten and less 1 to five
            else if(it == 10){
                if(five >=1){
                    ten++;
                    five--;
                }
                else{
                    return false;
                }
            }
            //if it is 20 , 
            else{
                if(ten and five){
                    ten--;
                    five--;
                }
                else if(five >= 3){
                    five -= 3;
                }
                else{
                    return false;
                }
            }


        }
        return true; 
    }
};
