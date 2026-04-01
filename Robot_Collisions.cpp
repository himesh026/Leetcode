// Problem: Robot Collisions
// URL: https://leetcode.com/problems/robot-collisions/?envType=daily-question&envId=2026-04-01

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<tuple<int,int,char,int>> arr;
        for(int i=0;i<positions.size();i++){
            arr.push_back({positions[i],healths[i],directions[i],i});
        }

        sort(arr.begin(),arr.end());

        stack<pair<char,pair<int,int > > > st;
        vector<pair<int,int> > leftRobo;
        for(int i=0;i<positions.size();i++){
            auto [pos,h,dir,indx]=arr[i];


            if(dir=='R'){
                st.push({dir,{h,indx}});
            }
            else{
                bool isleftbachgya=true;
                while(st.empty()==false){
                    if(st.top().second.first==h){
                        isleftbachgya=false;
                        st.pop();
                        break;
                    }
                    else if(st.top().second.first>h){
                        st.top().second.first--;
                        isleftbachgya=false;
                        if(st.top().second.first==0){
                            st.pop();
                        }
                        break;
                    }
                    else{
                        h--;
                        st.pop();
                        if(h==0){
                            isleftbachgya=false;
                            break;
                        }
                    }

                }
                if(isleftbachgya){
                    leftRobo.push_back({indx,h});
                }
            }
        }

        vector<pair<int,int>> temp;
        while(st.empty()==false){
            temp.push_back({st.top().second.second,st.top().second.first});
            st.pop();
        }

        for(int i=0;i<leftRobo.size();i++){
            temp.push_back(leftRobo[i]);
        }

        sort(temp.begin(),temp.end());

        vector<int> ans;

        for(int i=0;i<temp.size();i++){
            ans.push_back(temp[i].second);
        }

        return ans;
    }
};