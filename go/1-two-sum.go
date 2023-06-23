func twoSum(nums []int, target int) []int {
    for i := range nums {
        for j := range nums {
            if i == j {
                continue
            }

            if nums[i] + nums[j] == target {
                return []int{i, j}
            }
        }
    }

    return []int{}
}