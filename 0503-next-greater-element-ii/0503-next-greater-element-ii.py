class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        nums *= 2
        ans = []
        stack = []
        for i, v in enumerate(nums[::-1]):
            if i == 0:
                ans.append(-1)
            else:
                while len(stack) > 0 and v >= stack[-1]:
                    stack.pop()
                if len(stack) == 0:
                    ans.append(-1)
                else:
                    ans.append(stack[-1])
            stack.append(v)

        return ans[::-1][0 : len(nums) // 2]