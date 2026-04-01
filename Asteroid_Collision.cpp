// Problem: Asteroid Collision
// URL: https://leetcode.com/problems/asteroid-collision/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<pair<int,int> > st; //{asteroid size,postn}
        vector<pair<int,int > > leftmovingAsteroid;

        for(int i=0;i<asteroids.size();i++){

            if(asteroids[i]>0){
                //right moving
                st.push({asteroids[i],i});
            }
            else{
                bool isleftBachgya=true;
                while(st.empty()==false){
                    
                    if(st.top().first==abs(asteroids[i])){
                        //right and left moving dono explode
                        st.pop();
                        isleftBachgya=false;
                        break;
                    }
                    else if(st.top().first>abs(asteroids[i])){
                        //current asteroids[i] moving left explode
                        isleftBachgya=false;
                        break;
                    }
                    else{
                        //right moving explode
                        st.pop();
                        
                    }
                }
                if(isleftBachgya){
                    leftmovingAsteroid.push_back({i,asteroids[i]});
                }
            }
        } 

        vector<pair<int,int > > temp;
        while(st.empty()==false){
            temp.push_back({st.top().second,st.top().first});
            st.pop();
        }

        for(int i=0;i<leftmovingAsteroid.size();i++){
            temp.push_back(leftmovingAsteroid[i]);
        }

        sort(temp.begin(),temp.end());

        vector<int> ans;

        for(int i=0;i<temp.size();i++){
            ans.push_back(temp[i].second);
        }

        return ans;
    }
};