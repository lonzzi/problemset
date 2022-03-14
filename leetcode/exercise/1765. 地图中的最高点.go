package exercise

type pair struct{x, y int}
var dirs = []pair{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}

func HighestPeak(isWater [][]int) [][]int {
	m, n := len(isWater), len(isWater[0])
	height := make([][]int, m)
	for i := range height {
		height[i] = make([]int, n)
		for j := range height[i] {
			height[i][j] = -1
		}
	}
	q := []pair{}
	for i := range isWater {
		for j := range isWater[i] {
			if isWater[i][j] == 1 {
				height[i][j] = 0
				q = append(q, pair{i, j})
			}
		}
	}
	for len(q) > 0 {
		p := q[0]
		q = q[1:]
		for _, d := range dirs {
			if x, y := p.x + d.x, p.y + d.y; 0 <= x && x < m && 0 <= y && y < n && height[x][y] == -1 {
				height[x][y] = height[p.x][p.y] + 1
				q = append(q, pair{x, y})
			}
		}
	}
	return height
}