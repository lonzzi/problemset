package main

import (
	"fmt"
	"leetcode/golang/problems"
)

func main() {
	// fmt.Println(problems.CountValidWords("!"))
	// fmt.Println(problems.NumberOfWeakCharacters([][]int{{10,1},{5,1},{7,10},{4,1},{5,9},{6,9},{7,2},{1,10}}))
	// fmt.Println(problems.HighestPeak([][]int{{0, 1}, {0, 0}}))
	// fmt.Println(problems.FindLUSlength("aaa", "baa"))
	// fmt.Println(problems.FindRestaurant(
	// 	[]string{"Shogun", "Tapioca Express", "Burger King", "KFC"},
	// 	[]string{"KFC", "Shogun", "Burger King"},
	// ))
	fmt.Println(problems.FindContentChildren([]int{3, 4, 5, 7, 10}, []int{1, 2, 3, 8}))
}
