"""
LeetCode #2: Add Two Numbers
https://leetcode.com/problems/add-two-numbers/
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
"""

from typing import Optional, Union

"""
Non-submittable part of the solution
"""
# Definition for singly-linked list
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


"""
Submittable part of the solution
"""
class NumberAsReversedLinkedList:
    def __init__(self, param: Optional[Union[int, ListNode]] = None):
        self.root: Optional[ListNode] = None
        self.end: Optional[ListNode] = None

        if isinstance(param, int):
            while True:
                self.add_digit(param % 10)
                param = int(param / 10)
                if param == 0:
                    return

        if isinstance(param, ListNode):
            self.root = self.end = param
            while self.end:
                self.end = self.end.next

    def add_digit(self, digit):
        if self.root:
            self.end.next = self.end = ListNode(val=digit)  # Note: The leftmost target is assigned first
        else:
            self.root = self.end = ListNode(val=digit)

    def get_number(self) -> Optional[int]:
        if self.root:
            current = self.root
            result = 0
            power = 1
            while current:
                result = current.val * power + result
                power *= 10
                current = current.next
            return int(result)
        else:
            return None


class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        solution = NumberAsReversedLinkedList()
        carry = 0
        while l1 or l2:
            if l1 is None and l2 is None:
                break
            n1 = l1.val if l1 else 0
            n2 = l2.val if l2 else 0
            n = n1 + n2 + carry
            if n >= 10:
                carry = 1
                n = n % 10
            else:
                carry = 0
            solution.add_digit(n)
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next
        if carry:
            solution.add_digit(carry)
        return solution.root


"""
Runnable part, helpers, and tests
"""
def use_case(number1, number2):
    list1 = NumberAsReversedLinkedList(param=number1)
    list2 = NumberAsReversedLinkedList(param=number2)
    list_result = NumberAsReversedLinkedList(param=Solution().addTwoNumbers(list1.root, list2.root))
    actual_result = list_result.get_number()
    print('PASS' if actual_result == number1 + number2 else 'FAIL', ':', list1.get_number(), '+', list2.get_number(), '=', actual_result)


if __name__ == '__main__':
    use_case(342, 465)
    use_case(0, 0)
    use_case(5, 5)
    use_case(1, 99)
    use_case(9999999, 9999)
