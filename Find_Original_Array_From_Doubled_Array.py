// Problem: Find Original Array From Doubled Array
// URL: https://leetcode.com/problems/find-original-array-from-doubled-array/

class Solution:
    def findOriginalArray(self, changed: List[int]) -> List[int]:
        n=len(changed)
        if(n%2!=0): return []
        hash=SortedDict(int)
        for num in changed:
            if num in hash:
                hash[num] += 1
            else:
                hash[num] = 1
        ans=[]
        for key,value in hash.items():
            if(value==0):continue

            if(key==0):
                if(value%2==0):
                    for i in range(value//2):
                        ans.append(0)
                    continue
                else: return []
    
            elif(2*key in hash and hash[2*key]>=value):
                for i in range(value):
                    ans.append(key)
                hash[2*key]-=value
            elif(2*key not in hash or hash[2*key]<value):
                return []
                
        # print(ans)
        return ans
        