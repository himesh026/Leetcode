// Problem: Meeting Rooms III
// URL: https://leetcode.com/problems/meeting-rooms-iii/?envType=daily-question&envId=2025-07-11

import heapq

class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        meetings.sort()
        room_count = [0] * n
        available = list(range(n))  # rooms free
        heapq.heapify(available)

        busy = []  # min heap (end_time, room number)

        for start, end in meetings:
            duration = end - start

            # Free up rooms 
            while busy and busy[0][0] <= start:
                _, room = heapq.heappop(busy)
                heapq.heappush(available, room)

            if available:
                room = heapq.heappop(available)
                heapq.heappush(busy, (start + duration, room))
            else:
                end_time, room = heapq.heappop(busy)
                heapq.heappush(busy, (end_time + duration, room))

            room_count[room] += 1

        return room_count.index(max(room_count))
