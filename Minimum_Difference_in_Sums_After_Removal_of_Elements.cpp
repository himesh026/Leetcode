// Problem: Minimum Difference in Sums After Removal of Elements
// URL: https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/?envType=daily-question&envId=2025-07-18

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n=nums.size();
        int k=n/3;
        priority_queue<int,vector<int>,greater<int> > min_heap;
        priority_queue<int> max_heap;
        vector<long long> part1(k+1,0);
        long long sum=0;
        //max_heap
        //insert first k elem
        for(int i=0;i<k;i++){
            max_heap.push(nums[i]);
            sum+=nums[i];
        }
        part1[0]=sum;
        int j=1;
        //now from [k,2k) we find minimum k elem sum and store in part1
        for(int i=k;i<2*k;i++){
            sum+=nums[i];
            max_heap.push(nums[i]);
            sum-=max_heap.top();
            max_heap.pop();
            part1[j]=sum;
            j++;
        }

        //min_heap
        long long part2=0;
        for(int i=n-1;i>=2*k;i--){
            min_heap.push(nums[i]);
            part2+=nums[i];
        }
        long long ans=part1[k]-part2;
        for(int i=2*k-1;i>=k;i--){
            part2+=nums[i];
            min_heap.push(nums[i]);
            part2-=min_heap.top();
            min_heap.pop();
            //now we have index i se n tk k max k elm ka sum and we also have index 0 to i tk k min k elm ka sum in our part1 vector
            ans=min(ans,part1[i-k]-part2);
            j--;

        }
        for(int i=0;i<part1.size();i++){
            cout<<part1[i]<<" ";
        }
        return ans;


        
    }
};