class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        ngr = {}
        stack = []
        for i, v in enumerate(nums2[::-1]):
            if i == 0:
                ngr[v] = -1
            else:
                while len(stack) > 0 and v > stack[-1]:
                    stack.pop()
                if len(stack) == 0:
                    ngr[v] = -1
                else:
                    ngr[v] = stack[-1]
            stack.append(v)

        ans = []
        for e in nums1:
            ans.append(ngr.get(e))
            
        return ans