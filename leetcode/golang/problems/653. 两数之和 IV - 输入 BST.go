package problems

// type TreeNode struct {
//     Val int
//     Left *TreeNode
//     Right *TreeNode
// }

func FindTarget(root *TreeNode, k int) bool {
    hashMap := map[int]int{}
    var dfs func(*TreeNode) bool
    dfs = func(root *TreeNode) bool {
        if root != nil {
            if hashMap[k-root.Val] > 0 {
                return true
            }
            hashMap[root.Val]++
            return dfs(root.Left) || dfs(root.Right)
        }
        return false
    }
    return dfs(root)
}