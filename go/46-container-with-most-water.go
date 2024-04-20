// https://leetcode.com/problems/container-with-most-water
package leetcode

func maxArea(height []int) int {
    maxArea := 0
    var i, j = 0, len(height) - 1

    for i < j {
        area := min(height[i], height[j]) * (j - i)
        if maxArea < area {
            maxArea = area
        }

        if height[i] > height[j] {
            j--
        } else {
            i++
        }
    }

    return maxArea
}