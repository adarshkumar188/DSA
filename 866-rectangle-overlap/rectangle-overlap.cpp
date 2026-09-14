class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        /*Intuition*/

        /*
            For two rectangles to overlap , they must have some positive width and positive height in common.

            Instead of directly checking whether they overlap it is easier to chekc when they do not overlap.

            Only four cases:

            1) rec1 is complectely to the left of rec2
            2) rec1 is completely below rec2
            3) rec1 is completely to the right of rec2
            4) rec1 is completely above rec2.

            If any of these is true, the rectangles don't overlap.
        */

        /*Approach*/

        /*
            For the left case : rec1[2] <= rec2[0]
            For the bottom case : rec1[3] <= rec2[1]
            For the top case : rec1[1] >= rec2[3]
            For the right case : rec1[0] >= rec2[2]

            Notice that <= and >= are important because rectangles that only touch an edge or corner have zero intersection area, so they should return false.

            Finally we negate all four conditions. If none of them is true, the rectangles must overlap.
        */

        /*Code*/

        return !(rec1[2] <= rec2[0] ||  //LEFT
                 rec1[3] <= rec2[1] ||  //BOTTOM
                 rec1[1] >= rec2[3] ||  //TOP
                 rec1[0] >= rec2[2] //RIGHT
                 );
    }
};