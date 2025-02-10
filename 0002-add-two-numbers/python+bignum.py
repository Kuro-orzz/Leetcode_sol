# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        num1, num2 = "", ""
        while l1:
            num1 = str(l1.val)+num1
            l1 = l1.next
        while l2:
            num2 = str(l2.val)+num2
            l2 = l2.next
        sum = int(num1) + int(num2)
        ans = ListNode()
        p = ans
        for i in range(len(str(sum))):
            p.next = ListNode(sum % 10)
            sum /= 10
            p = p.next
        return ans.next

        """
        :type l1: Optional[ListNode]
        :type l2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        