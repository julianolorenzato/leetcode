// https://leetcode.com/problems/zigzag-conversion
package leetcode

func convert(s string, numRows int) string {
    if numRows == 1 {
        return s
    }

    res := ""
    periodSize := 2 * numRows - 2

    rows := make([]string, numRows)

    for i, c := range s {
        position := i % periodSize

        if position > numRows - 1 {
            position = numRows * 2 - position - 2
        }
        
        rows[position] += string(c)
    }

    for _, row := range rows {
        res += row
    }

    return res
}
