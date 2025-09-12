//Question: Convert Roman Numerals to Integer
/*
 * Example 1:
Input: s = "III"
Output: 3
Explanation: III = 3.

Example 2:
Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

Example 3:
Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 */

import java.util.HashMap;
import java.util.Map;

class Solution {
    public int romanToInt(String s) {
        // Step 1: Mapping of Roman numerals
        Map<Character, Integer> map = new HashMap<>();
        map.put('I', 1);
        map.put('V', 5);
        map.put('X', 10);
        map.put('L', 50);
        map.put('C', 100);
        map.put('D', 500);
        map.put('M', 1000);

        int total = 0;
        int prev = 0; // previous numeral's value

        // Step 2: Iterate from right to left
        for (int i = s.length() - 1; i >= 0; i--) {
            int curr = map.get(s.charAt(i));

            if (curr < prev) {
                total -= curr; // subtraction case
            } else {
                total += curr; // normal case
            }

            prev = curr; // update previous
        }

        return total;
    }
}

//Time Complexity: O(n) where n is the length of the string
//Space Complexity: O(1) since the map size is constant (7 Roman numerals)