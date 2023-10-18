package main

import (
	"fmt"
	"strings"
)

/*
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.

Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.

Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
*/

func lengthOfLastWord(s string) int {
	// trim string (remove leading or trailing whitespaces)
	cleanString := strings.TrimSpace(s)

	length := 0

	// iteration the end of string (stop when the character is ' ')
	for i := len(cleanString) - 1; cleanString[i] != ' '; i-- {
		length++

		// handle if input is a word without any space
		if i == 0 {
			break
		}
	}

	return length
}

func main() {
	fmt.Println(lengthOfLastWord("aa"))
}
