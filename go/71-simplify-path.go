// https://leetcode.com/problems/simplify-path
package leetcode

type Stack []string

func (s *Stack) Push(c string) {
    *s = append(*s, c)
}

func (s *Stack) Pop() {
    if len(*s) != 0 {
        last := len(*s) - 1
        *s = (*s)[:last]
    }
}

func (s *Stack) Concat(c string) {
    last := len(*s) - 1
    (*s)[last] += c
}

func simplifyPath(path string) string {
    var stack Stack

    splitted := strings.FieldsFunc(path, func (c rune) bool {
        return c == '/'
    })

    for _, str := range splitted {
        switch str {
            case ".":
                continue
            case "..":
                stack.Pop()
            default:
                stack.Push(str)
        }
    }

    res := ""

    for _, el := range stack {
        res += "/" + el
    }

    if res == "" {
        res = "/"
    }

    return res
}