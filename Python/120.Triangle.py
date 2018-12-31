# 120. Triangle
# https://leetcode.com/problems/triangle/

# Input:
# [
#      [2],
#     [3,4],
#    [6,5,7],
#   [4,1,8,3]
# ]

# Output:
# 11

def minimumTotal(triangle):
    """
    :type triangle: List[List[int]]
    :rtype: int
    """
    result = 0
    if len(triangle) == 0:
        return result
    prev = []
    for t in triangle:
        if len(t) == 1:
            next = t
        else:
            next = []
            for i in range(len(t)):
                if i == 0:
                    next.append(t[0] + prev[0])
                elif i == len(t)-1:
                    next.append(t[-1] + prev[-1])
                else:
                    next.append(t[i]+min(prev[i-1], prev[i]))
        prev = next
    return min(prev)
    
tri = [
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

print(minimumTotal(tri))
print(minimumTotal([]))
print(minimumTotal([[100]]))