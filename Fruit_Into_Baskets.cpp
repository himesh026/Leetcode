// Problem: Fruit Into Baskets
// URL: https://leetcode.com/problems/fruit-into-baskets/?envType=daily-question&envId=2025-08-04

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        unordered_map<int,int> hash;
        int ans=-1;
        int left=0;
        for(int right=0;right<fruits.size();right++){
            if(hash.find(fruits[right])!=hash.end()) hash[fruits[right]]++;
            else if(hash.size()<2){
                hash[fruits[right]]++;
            }
            else{
                while(hash.size()!=1){
                    hash[fruits[left]]--;
                    if(hash[fruits[left]]==0){
                        hash.erase(fruits[left]);
                    }
                    left++;
                }
                hash[fruits[right]]++;
            }
            int curr=0;
            for(auto it:hash){
                curr+=it.second;
            }
            ans=max(ans,curr);
        }

        return ans;
    }

};