// Problem: Reschedule Meetings for Maximum Free Time II
// URL: https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-ii/

from typing import List
import bisect

class Solution:
    def maxFreeTime(self, eventTime: int, startTime: List[int], endTime: List[int]) -> int:
        gaps = []
        prev = 0
        for i in range(len(startTime)):
            gaps.append(startTime[i] - prev)
            prev = endTime[i]
        gaps.append(eventTime - endTime[-1])

        if sum(gaps) == 0:
            return 0

        meetings = [endTime[i] - startTime[i] for i in range(len(startTime))]
        ans = 0
        sorted_gaps = sorted(gaps)

        for i in range(1, len(gaps)):
            mt = meetings[i - 1]
            curr = gaps[i] + gaps[i - 1]

            idx = bisect.bisect_left(sorted_gaps, mt)
            total_ge_mt = len(sorted_gaps) - idx

            used_ge_mt = (gaps[i] >= mt) + (gaps[i - 1] >= mt) #current gaps 

            if total_ge_mt > used_ge_mt:
                ans = max(ans, curr + mt)
            else:
                ans = max(ans, curr)

        return ans
