package main

import (
	"fmt"
	"strconv"
)

/*
	Given an integer n, add a dot (".") as the thousands separator and return it in string format.

	Example 1:

	Input: n = 987
	Output: "987"

	Example 2:

	Input: n = 1234
	Output: "1.234"
*/

func thousandSeparator(n int) string {
	// kalo angkanya dibawah ribuan, return langsung dalam bentuk string
	if n < 1000 {
		return strconv.Itoa(n)
	}

	var threeDigitsArr []string
	var threeDigitsStr string = ""

	// convert integer menjadi string
	nStr := strconv.Itoa(n)

	// setiap iterate 3 digit string, push kedalam array (loop dimulai dari belakang)
	for i := len(nStr) - 1; i >= 0; i-- {
		threeDigitsStr += string(nStr[i])

		if len(threeDigitsStr) == 3 {
			threeDigitsArr = append(threeDigitsArr, threeDigitsStr)
			threeDigitsStr = ""
		}
	}

	// variable untuk menyimpan string akhir hasil operasi
	var result = ""

	// jika ada sisa string yang tidak masuk ke dalam array, masukkan kedalam array.(loop dari belakang)
	if len(threeDigitsStr) < 2 {
		result += threeDigitsStr
	} else {
		for i := len(threeDigitsStr) - 1; i >= 0; i-- {
			result += string(threeDigitsStr[i])
		}
	}

	// sisipkan karakter "." (dot)
	result += "."

	// looping array yang berisi kumpulan 3 digit string, lalu concat dengan variable result. (loop dari belakang)
	for i := len(threeDigitsArr) - 1; i >= 0; i-- {
		for j := 2; j >= 0; j-- {
			result += string(threeDigitsArr[i][j])
		}
		result += string(".")
	}

	// bersihkan titik di akhir string
	if result[len(result)-1] == '.' {
		// menyingkirkan tanda dot di akhir string dengan teknik slicing
		result = result[0 : len(result)-1]
	}

	if result[0] == '.' {
		// menyingkirkan tanda dot di awal string dengan teknik slicing
		result = result[1:]
	}

	return result
}

func main() {
	fmt.Println(thousandSeparator(12000))
}
