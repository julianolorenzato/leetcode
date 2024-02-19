// https://leetcode.com/problems/intersection-of-two-arrays/
package leetcode

func intersection(nums1 []int, nums2 []int) []int {
    in1 := make(map[int]bool)
    in2 := make(map[int]bool)
    l1 := len(nums1)
    l2 := len(nums2)

    for i := 0; i < max(l1, l2); i++ {
        if i < l1 {
            in1[nums1[i]] = true
        }

        if i < l2 {
            in2[nums2[i]] = true
        }
    }

    res := make([]int, 0)

    if len(in1) < len(in2) {
        for k := range in1 {
            if in2[k] {
                res = append(res, k)
            }
        }
    } else {
        for k := range in2 {
            if in1[k] {
                res = append(res, k)
            }
        }
    }

    return res
}