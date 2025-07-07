// Problem: Maximum Number of Events That Can Be Attended
// URL: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/description/?envType=daily-question&envId=2025-07-07

class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        n=len(events)
        maxDay=0
        for i in range(n):
            maxDay=max(maxDay,events[i][1])
        pq=[]
        events.sort()
        ans=0
        j=0
        
        for i in range(1,maxDay+1):

            while j<n and events[j][0]<=i:
                heapq.heappush(pq,events[j][1])
                j+=1
            
            while pq and pq[0]<i: # meeting that end before curr day i pop them
                heapq.heappop(pq)
            
            if pq:
                heapq.heappop(pq)
                ans+=1


        return ans