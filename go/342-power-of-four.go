// https://leetcode.com/problems/power-of-four
package leetcode

func isPowerOfFour(n int) bool {
    logBase4 := math.Log(float64(n)) / math.Log(4)
    return math.Mod(logBase4, 1) == 0
}