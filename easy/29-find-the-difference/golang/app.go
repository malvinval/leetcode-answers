package main

import (
	"fmt"
	"sort"
)

/*
	You are given two strings s and t.

	String t is generated by random shuffling string s and then add one more letter at a random position.

	Return the letter that was added to t.

	Example 1:

	Input: s = "abcd", t = "abcde"
	Output: "e"
	Explanation: 'e' is the letter that was added.

	Example 2:

	Input: s = "", t = "y"
	Output: "y"
*/

func strSort(s string) string {
	chars := []rune(s)

	// function sort.Slice butuh 2 argumen, yaitu slice yang akan diurutkan dan fungsi komparasi (comparator function).
	// return chars[i] < chars[j] artinya sorting dilakukan secara ascending.

	sort.Slice(chars, func(i, j int) bool {
		return chars[i] < chars[j]
	})

	return string(chars)
}

func findTheDifference(s string, t string) byte {
	s = strSort(s)
	t = strSort(t)

	for i := 0; i < len(s); i++ {
		if s[i] != t[i] {
			return t[i]
		}
	}

	return t[len(t)-1]
}

func main() {
	fmt.Println(string(findTheDifference("leet", "leetc")))
}