//https://leetcode.com/problems/assign-cookies/
// using greedy approach
// sort both array 
// traverse cookies while checking with the greed and return greed 


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
         int g_size = g.size();
        int s_size = s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int greed = 0;
        int cookie = 0;
        while(greed < g_size and cookie < s_size ){

            if(s[cookie] >= g[greed]){
                greed++;
            }

            cookie++;
        }
        return greed;
    }
};
