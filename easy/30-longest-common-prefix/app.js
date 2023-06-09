/*
    Write a function to find the longest common prefix string amongst an array of strings.

    If there is no common prefix, return an empty string "".

    Example 1:

    Input: strs = ["flower","flow","flight"]
    Output: "fl"
    
    Example 2:

    Input: strs = ["dog","racecar","car"]
    Output: ""
    Explanation: There is no common prefix among the input strings.
*/

var longestCommonPrefix = function(strs) {
    let i = 0;
    let j = strs.length - 1;
    let longest_common_prefix = "";

    while (true) {
        if(i < strs[0].length() && strs[0][i] == strs[j][i]) {
            if(j == 1) {
                longest_common_prefix += strs[0][i];
                i += 1;
                j = strs.length - 1;
            } else {
                j -= 1;
            }
        } else break;
    }

    return longest_common_prefix;
};

console.log(longestCommonPrefix([""]));