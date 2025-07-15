// Problem: Valid Word
// URL: https://leetcode.com/problems/valid-word/?envType=daily-question&envId=2025-07-15

class Solution:
    def isValid(self, word: str) -> bool:
        vowels=['a','e','i','o','u','A','E','I','O','U']
        isvowel=False
        isconsonant=False
        for i in range(len(word)):
            if word[i] in vowels:
                isvowel=True
            elif (ord(word[i]) in range(97,123) or ord(word[i]) in range (65,91)) and word[i] not in vowels:
                isconsonant=True
            elif ord(word[i]) in range(48,58):continue
            else: return False
        
        print(isvowel)
        print(isconsonant)
        return (isvowel and isconsonant) and len(word)>=3

        