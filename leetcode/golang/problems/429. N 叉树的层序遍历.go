package problems

/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

 func levelOrder(root *Node) (ans [][]int) {
    q := [](*Node){}
	q = append(q, root)
	ans = make([][]int, 0)
	ans = append(ans, []int{root.Val})
	for len(q) > 0 {
		size := len(q)
		path := []int{}
		for i := 0; i < size; i++ {
			node := q[0]
			q = q[1:]
			for j := 0; j < len(node.Children); j++ {
				q = append(q, node.Children[j])
				path = append(path, node.Children[j].Val)
			}
		}
        temp := make([]int, len(path))
        copy(temp, path)
        ans = append(ans, temp)
	}
	return
}