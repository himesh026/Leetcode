// Problem: The k-th Lexicographical String of All Happy Strings of Length n
// URL: https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/?envType=daily-question&envId=2026-03-14

class Solution {
public:
    void solve(string &curr,int n,int k,vector<string> &happyStrings){

        if(curr.size()==n){
            happyStrings.push_back(curr);
            return;
        }
        if(curr.size()>n) return;

        //check last char
        if(curr.back()=='a'){
            curr.push_back('b');
            solve(curr,n,k,happyStrings);
            curr.pop_back();
            curr.push_back('c');
            solve(curr,n,k,happyStrings);
            curr.pop_back();
        }
        else if(curr.back()=='b'){
            curr.push_back('c');
            solve(curr,n,k,happyStrings);
            curr.pop_back();
            curr.push_back('a');
            solve(curr,n,k,happyStrings);
            curr.pop_back();

        }
        else{
            curr.push_back('b');
            solve(curr,n,k,happyStrings);
            curr.pop_back();
            curr.push_back('a');
            solve(curr,n,k,happyStrings);
            curr.pop_back();

        }

    }
    string getHappyString(int n, int k) {
        vector<string> happyStrings;
        string curr="a";
        solve(curr,n,k,happyStrings);
        curr="b";
        solve(curr,n,k,happyStrings);
        curr="c";
        solve(curr,n,k,happyStrings);

        sort(happyStrings.begin(),happyStrings.end());

        if(k>happyStrings.size()) return "";

        return happyStrings[k-1];
    }
};

