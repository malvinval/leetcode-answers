package main

import (
	"fmt"
	"strings"
	"unicode"
)

/*
	A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

	Given a string s, return true if it is a palindrome, or false otherwise.

	Example 1:

	Input: s = "A man, a plan, a canal: Panama"
	Output: true
	Explanation: "amanaplanacanalpanama" is a palindrome.

	Example 2:

	Input: s = "race a car"
	Output: false
	Explanation: "raceacar" is not a palindrome.

	Example 3:

	Input: s = " "
	Output: true
	Explanation: s is an empty string "" after removing non-alphanumeric characters.
	Since an empty string reads the same forward and backward, it is a palindrome.
*/

func isPalindrome(s string) bool {
	// remove whitespaces

	var cleanString string = ""

	for i := 0; i < len(s); i++ {
		// unicode.IsLetter() is a function provided by the "unicode" package.
		// it is used to determine whether a given unicode code point represents a letter or not.

		// unicode.IsNumber() is a function provided by the "unicode" package.
		// it is used to determine whether a given unicode code point represents a number or not.
		if unicode.IsLetter(rune(s[i])) || unicode.IsNumber(rune(s[i])) {
			cleanString += string(s[i])
		}
	}

	// convert string to lowercase using ToLower() function provided by strings package
	lowercaseCleanString := strings.ToLower(cleanString)

	// palindrome check
	j := len(lowercaseCleanString) - 1
	for i := 0; i < j; i++ {
		if lowercaseCleanString[i] != lowercaseCleanString[j] {
			return false
		}
		j--
	}

	return true
}

func main() {
	fmt.Println(isPalindrome("0P"))
}
