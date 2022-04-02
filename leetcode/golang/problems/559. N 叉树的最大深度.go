package problems

func maxDepth(root *Node) (ans int) {
    if root == nil {
        return
    }
	q := []*Node{}
	q = append(q, root)
	for len(q) > 0 {
        size := len(q)
        ans++
        for size > 0 {
            node := q[0]
            q = q[1:]
            for i := 0; i < len(node.Children); i++ {
                q = append(q, node.Children[i])
            }
            size--
        }
	}
	return
}