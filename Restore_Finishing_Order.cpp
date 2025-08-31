// Problem: Restore Finishing Order
// URL: https://leetcode.com/problems/restore-finishing-order/

class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_map<int,int> hash;
        for(int i=0;i<order.size();i++){
            hash[order[i]]=i;
        }
        vector<int> arr(order.size(),-1);
        for(int i=0;i<friends.size();i++){
            if(hash.find(friends[i])!=hash.end()){
                arr[hash[friends[i]]]=friends[i];
            }
        }
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==-1) continue;
            ans.push_back(arr[i]);
        }

        return ans;
    }
};