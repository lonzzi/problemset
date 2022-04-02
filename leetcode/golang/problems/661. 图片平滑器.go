package problems

func ImageSmoother(img [][]int) [][]int {
    m, n := len(img), len(img[0])
    ans := make([][]int, m)
    for i := range ans {
        ans[i] = make([]int, n)
        for j := range ans[i] {
            sum, num := 0, 0
            for _, row := range img[max(i-1, 0): min(i+1+1, m)] {
                for _, v := range row[max(j-1, 0): min(j+1+1, n)] {
                    sum += v
                    num++
                }
            }
            ans[i][j] = sum / num
        }
    }
    return ans
}
