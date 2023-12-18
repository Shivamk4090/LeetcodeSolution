class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        map = [0] * 256
        map2 = [0] * 256
        ans = True
        for i in range(len(s)):
            pos = ord(s[i])
            pos2 = ord(t[i])
            if map[pos] == 0:
                if map2[pos2] == 1:
                    return False
                map[pos] = t[i]
                map2[pos2] = 1
            elif map[pos] != t[i]:
                ans = False
        return ans