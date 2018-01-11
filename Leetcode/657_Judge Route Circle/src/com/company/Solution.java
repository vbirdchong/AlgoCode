package com.company;

/**
 * 657. Judge Route Circle
 */

/*Initially, there is a Robot at position (0, 0). Given a sequence of its moves,
judge if this robot makes a circle, which means it moves back to the original place.

The move sequence is represented by a string. And each move is represent by a character. T
he valid robot moves are R (Right), L (Left), U (Up) and D (down).
The output should be true or false representing whether the robot makes a circle.

        Example 1:
        Input: "UD"
        Output: true
        Example 2:
        Input: "LL"
        Output: false*/

/**
 * Created by chonchen on 2017/8/30.
 */
public class Solution {
    public boolean judgeCircle(String moves) {

        int step = 0;
        for (int i = 0; i < moves.length(); i++){
            char val = moves.charAt(i);
            if (val == 'U') {
                step += 1;
            }
            else if (val == 'D') {
                step -= 1;
            }
            else if (val == 'R') {
                step += 1;
            }
            else if (val == 'L') {
                step -= 1;
            }
        }

        return step == 0;
    }
}
