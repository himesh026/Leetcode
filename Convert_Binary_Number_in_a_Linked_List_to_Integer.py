// Problem: Convert Binary Number in a Linked List to Integer
// URL: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/?envType=daily-question&envId=2025-07-14

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def getDecimalValue(self, head: Optional[ListNode]) -> int:
        #length of ll
        length=0
        temp=head
        while temp!=None:
            length+=1
            temp=temp.next
        
        temp=head
        x=length-1
        ans=0
        while temp!=None:
            if(temp.val==1):
                ans+=2**x
            x-=1
            temp=temp.next
        

        return ans

            
        