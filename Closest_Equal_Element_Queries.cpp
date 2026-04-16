// Problem: Closest Equal Element Queries
// URL: https://leetcode.com/problems/closest-equal-element-queries/?envType=daily-question&envId=2026-04-16

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();

        unordered_map<int,vector<int>> hash;

        for(int i=0;i<nums.size();i++){
            hash[nums[i]].push_back(i);
        }
        vector<int> ans(queries.size());
        for(int i=0;i<queries.size();i++){
            int indx=queries[i];
            int elem=nums[indx];
            if(hash[elem].size()==1){
                ans[i]=-1;
            }
            else{
             
                int j=lower_bound(hash[elem].begin(),hash[elem].end(),indx)-hash[elem].begin();
                int mindist=INT_MAX;
                if(j==0){
                    int previous=hash[elem].back();
                    mindist=min(n-previous+hash[elem][j],hash[elem][j+1]-hash[elem][j]);
                }
                else if(j==hash[elem].size()-1){
                    int next=hash[elem][0];
                    mindist=min(n-hash[elem][j]+next,hash[elem][j]-hash[elem][j-1]);
                }
                else{
                    mindist=min(hash[elem][j]-hash[elem][j-1],hash[elem][j+1]-hash[elem][j]);
                }

                ans[i]=mindist;
            }
        }

        return ans;
    }
};

// //problem statement
// given array => nums size => n
// given queries array 
// for each query i, we need to find its minimum distance where a simmilar elemnt exsist
// example
// nums[1,2,3,2,2,4,2]
// indx 0,1,2,3,4,5,6
// now q[1,3,6] so now we need to return an answer array of size same as q array
// first we make a hash map
// elem-> its index where i exsist in nums
// 1->0
// 2->1,3,4,6
// 3->2
// 4->5

// observation 1 ki agr koi element sirf ek baar hi aaya h to uska answer hoga -1
// now for each query in q[1,3,6]
// q[0]=1
// nums[q[0]]=2
// ab 2 aaya h 1,3,4,6
// 2 multiple time aaya h to iska !=-1 hoga ab find krte h
// jo element 2 k coresponding vector hoga hash m => [1,3,4,6]
//                                                     0,1,2,3
// ab q[0]=1 to 1 dhundege upr vali array m jo aaya 0 index pr kyunki ye 0th index pr h iske previous koi nhi h to apne ko wrap krk last vale se distance calclulate krna hoga 