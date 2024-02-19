// https://leetcode.com/problems/longest-substring-without-repeating-characters
package leetcode

func lengthOfLongestSubstring(s string) int {
    max := 0

    have := make(map[rune]int)

    start := 0

    for end, v := range s {
        for have[v] != 0 {
            have[rune(s[start])]--
            start++
        }

        have[v]++

        if end - start + 1 > max {
            max = end - start + 1
        }
    }

    return max
}