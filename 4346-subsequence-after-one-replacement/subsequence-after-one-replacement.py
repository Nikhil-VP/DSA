class Solution:
    def canMakeSubsequence(self, s: str, t: str) -> bool:
        n, m = len(s), len(t)
        if n > m:
            return False

        # left[i] stores the earliest index in t to match prefix s[0...i]
        left = [-1] * n
        t_idx = 0
        for i in range(n):
            while t_idx < m and t[t_idx] != s[i]:
                t_idx += 1
            if t_idx < m:
                left[i] = t_idx
                t_idx += 1
            else:
                break

        # Check if s is already a subsequence of t without replacing anything
        if left[-1] != -1:
            return True

        # right[i] stores the latest index in t to match suffix s[i...n-1]
        right = [-1] * n
        t_idx = m - 1
        for i in range(n - 1, -1, -1):
            while t_idx >= 0 and t[t_idx] != s[i]:
                t_idx -= 1
            if t_idx >= 0:
                right[i] = t_idx
                t_idx -= 1
            else:
                break

        # Check if replacing character s[i] creates a valid subsequence
        for i in range(n):
            l_bound = left[i - 1] if i > 0 else -1
            r_bound = right[i + 1] if i < n - 1 else m

            # Ensure both prefix and suffix were validly matched
            prefix_valid = (i == 0) or (left[i - 1] != -1)
            suffix_valid = (i == n - 1) or (right[i + 1] != -1)

            # Check if there is at least one unused slot between l_bound and r_bound
            if prefix_valid and suffix_valid and (r_bound - l_bound > 1):
                return True

        return False