// Problem: Minimum Initial Energy to Finish Tasks
// URL: https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/?envType=daily-question&envId=2026-05-12

class Solution {
public:
    static bool fxn(vector<int> a,vector<int> b){

        if((a[1]-a[0])==(b[1]-b[0])){
            return a[0]>b[0];
        }

        return (a[1]-a[0])>(b[1]-b[0]);
    }
    bool isPossible(vector<vector<int>>& tasks, int energy){
        
        for(int i=0;i<tasks.size();i++){
            int actuali=tasks[i][0]; 
            int minimumi=tasks[i][1];
            if(energy<minimumi) return false;
            if(energy<actuali) return false;
            energy=energy-actuali;
        }

        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        
        int energyConsumed=0;
        int totalminimumEnergyRequire=0;
        sort(tasks.begin(),tasks.end(),fxn);
        for(int i=0;i<tasks.size();i++){
            energyConsumed+=tasks[i][0];
            totalminimumEnergyRequire+=tasks[i][1];
        }

        int left=energyConsumed;
        int right=totalminimumEnergyRequire;
        int ans=0;
        while(left<=right){
            int mid=(left+right)/2;

            if(isPossible(tasks,mid)){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }

        return ans;
    }
};

// binary search on answer if enerfy E sare tasks solve kr skti to (E+1) garranty se solve kr degi isliye binary search lga diya , phle tasks array ko sort krdi diffrence k basis pr