"""
LeetCode #24: Swap Nodes in Pairs
https://leetcode.com/problems/swap-nodes-in-pairs/

Given a linked list, swap every two adjacent nodes and return its head.
You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

Example 1:
Input: head = [1,2,3,4]
Output: [2,1,4,3]

Example 2:
Input: head = []
Output: []

Example 3:
Input: head = [1]
Output: [1]
"""

from typing import Optional, List, Tuple

"""
Non-submittable part of the solution
"""
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


"""
Submittable part of the solution
"""
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        swapped = self.swapPairs(head.next.next)
        result = head.next
        head.next.next = head
        head.next = swapped
        return result


"""
Runnable part, helpers, and tests
"""
def build_linked_list(given: List) -> Tuple[Optional[ListNode], str]:
    head = None
    for item in given[::-1]:
        head = ListNode(val=item, next=head)
    return head, list_to_str(head)


def list_to_str(head: Optional[ListNode]):
    result = ''
    while head:
        result += ('->' if result else '') + f'{head.val}'
        head = head.next
    return result


def use_case(given_list: List, expected_list: List):
    given, given_str = build_linked_list(given=given_list)
    expected, expected_str = build_linked_list(given=expected_list)
    actual = Solution().swapPairs(head=given)
    actual_str = list_to_str(head=actual)
    print('PASS' if actual_str == expected_str else 'FAIL', given_str, expected_str, actual_str, sep=' : ')


if __name__ == '__main__':
    use_case([], [])
    use_case([1], [1])
    use_case([1, 2], [2, 1])
    use_case([1, 2, 3], [2, 1, 3])
    use_case([1, 2, 3, 4], [2, 1, 4, 3])
    use_case([1, 2, 3, 4, 5, 6], [2, 1, 4, 3, 6, 5])
