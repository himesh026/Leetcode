// Problem: Reschedule Meetings for Maximum Free Time I
// URL: https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/?envType=daily-question&envId=2025-07-09

class Solution:
    def maxFreeTime(self, eventTime: int, k: int, startTime: List[int], endTime: List[int]) -> int:
        
        n=len(startTime)

        gaps=[]
        prev=0
        for i in range(n):

            gaps.append(startTime[i]-prev)
            prev=endTime[i]

        gaps.append(eventTime-endTime[n-1])

        # print(gaps)
        # print("xxx")

        windowSize=k+1
        ans=0
        for i in range(windowSize):
            ans+=gaps[i]
        
        left=0
        curr=ans
        
        for right in range(windowSize,len(gaps)):
            curr+=gaps[right]
            curr-=gaps[left]
            left+=1
            ans=max(curr,ans)
        

        return ans


        