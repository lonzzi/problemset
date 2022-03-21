package problems

import (
	"fmt"
	"strconv"
)

// 低效率版本
// func Tree2str(root *TreeNode) string {
// 	ans := ""
//     var preorder func(*TreeNode)
//     preorder = func(root *TreeNode) {
//         if root != nil {
//             ans += fmt.Sprintf("(%v", root.Val)
//             if root.Left == nil && root.Right != nil {
//                 ans += "()"
//             }
//             preorder(root.Left)
//             preorder(root.Right)
//             ans += ")"
//         }
//     }
//     preorder(root)
//     return ans[1:len(ans)-1]
// }

func Tree2str(root *TreeNode) string {
	switch {
	case root == nil:
		return ""
	case root.Left == nil && root.Right == nil:
		return strconv.Itoa(root.Val)
	case root.Right == nil:
		return fmt.Sprintf("%s(%s)", strconv.Itoa(root.Val), Tree2str(root.Left))
	default:
		return fmt.Sprintf("%s(%s)(%s)", strconv.Itoa(root.Val), Tree2str(root.Left), Tree2str(root.Right))
	}
}