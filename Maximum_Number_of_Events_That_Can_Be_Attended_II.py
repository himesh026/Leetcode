// Problem: Maximum Number of Events That Can Be Attended II
// URL: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/?envType=daily-question&envId=2025-07-08

from typing import List
import bisect

class Solution:
    def maxValue(self, events: List[List[int]], k: int) -> int:
        events.sort()  # sort by start time
        n = len(events)

        # Extract just the start times for binary search
        starts = [e[0] for e in events]

        from functools import lru_cache

        @lru_cache(None)
        def f(i: int, k: int) -> int:
            if i == n or k == 0:
                return 0

            # Option 1: skip current event
            not_take = f(i + 1, k)

            # Option 2: take current event, go to next non-overlapping
            # Use binary search to find next event whose start > current end
            next_i = bisect.bisect_right(starts, events[i][1])
            take = events[i][2] + f(next_i, k - 1)

            return max(take, not_take)

        return f(0, k)
