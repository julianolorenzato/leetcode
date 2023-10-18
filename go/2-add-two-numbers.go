// https://leetcode.com/problems/add-two-numbers
package leetcode

type ListNode struct {
	Val int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    resHead := &ListNode{Val: -1, Next: nil}
    curr1 := l1
    curr2 := l2
    currRes := resHead
    carry := 0

    for {
        if curr1 == nil && curr2 == nil {
            if carry == 0 {
                break
            } else {
                currRes.Next = &ListNode{Val: carry}
                break
            }
        }

        var sum int

        if curr1 == nil {
            sum = curr2.Val + carry
            curr2 = curr2.Next

        } else if curr2 == nil {
            sum = curr1.Val + carry
            curr1 = curr1.Next
            
        } else {
            sum = curr1.Val + curr2.Val + carry
            curr1 = curr1.Next
            curr2 = curr2.Next
        }

        if sum >= 10 {
            carry = sum / 10
            currRes.Next = &ListNode{Val: sum % 10}
        } else {
            carry = 0
            currRes.Next = &ListNode{Val: sum}
        }
        
        currRes = currRes.Next
    }

    return resHead.Next
}

// Short version
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    resHead := &ListNode{Val: -1, Next: nil}
    currRes := resHead
    carry := 0

    for l1 != nil || l2 != nil {
        var sum int

        if l1 != nil {
            sum += l1.Val
            l1 = l1.Next
        }

        if l2 != nil {
            sum += l2.Val
            l2 = l2.Next 
        }

        sum += carry

        if sum >= 10 {
            carry = sum / 10
            currRes.Next = &ListNode{Val: sum % 10}
        } else {
            carry = 0
            currRes.Next = &ListNode{Val: sum}
        }
        
        currRes = currRes.Next
    }

    if carry != 0 {
        currRes.Next = &ListNode{Val: carry}
    }

    return resHead.Next
}