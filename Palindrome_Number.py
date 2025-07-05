# Problem: Palindrome Number
# URL: https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    // bool f(int num){

    //     string str=to_string(num);
    //     int left=0;
    //     int right=str.size()-1;

    //     while(left<=right){
    //         if(str[left]!=str[right]){
    //             return false;
    //         }
    //         left++;
    //         right--;
    //     }

    //     return true;
    // }
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        long long temp=x;
        long long reversedX=0;
        
        while(temp!=0){
            int lastdigit=temp%10;
            reversedX=reversedX*10+lastdigit;
            temp=temp/10;
        }

        return x==reversedX;
    }
};

