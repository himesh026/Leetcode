// Problem: Maximum Sum Obtained of Any Permutation
// URL: https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation/

class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n=nums.size();
        priority_queue<int> maxHeap;
        for(int i=0;i<n;i++){
            maxHeap.push(nums[i]);
        }
        //sweep line algo
        vector<int> freq(n,0);

        for(int i=0;i<requests.size();i++){
            int start=requests[i][0];
            int end=requests[i][1];
            freq[start]++;
            if(end+1<n) freq[end+1]--;
        }
        vector<int> arr(n,0);
        arr[0]=freq[0];
        for(int i=1;i<n;i++){
            arr[i]=freq[i]+arr[i-1];
        }
        //now we make pair of index freq and index
        vector<pair<int,int> > hash; //{indexfreq,index}
        for(int i=0;i<arr.size();i++){
            hash.push_back({arr[i],i});
        }

        sort(hash.rbegin(),hash.rend());

        int ans=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            //jo index sbse jyada bar aaya h vhi maxhap k top element hona chaiye
            int topElem=maxHeap.top();
            maxHeap.pop();
            ans=(ans+(long long)hash[i].first*topElem)%mod; 
        }

        return ans;
    }
};

//simple requests m koi index kitni bar aaya vo pta lgg gya to j sbse jyada bar index aaya h vha pr apna sabse bda element hona chaiuye