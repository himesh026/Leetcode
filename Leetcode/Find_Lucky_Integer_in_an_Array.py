# Problem: Find Lucky Integer in an Array
# URL: https://leetcode.com/problems/find-lucky-integer-in-an-array/submissions/1687129918/?envType=daily-question&envId=2025-07-05

class Solution:
    def findLucky(self, arr: List[int]) -> int:
        hash=defaultdict(int,sorted=True)
        for i in range(len(arr)):
            hash[arr[i]]+=1
        
        ans=-1
        for key,value in hash.items():
            if(value==key):
