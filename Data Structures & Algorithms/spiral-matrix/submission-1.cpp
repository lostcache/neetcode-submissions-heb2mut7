class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int leftLim = 0;
        int rightLim = matrix[0].size() - 1;
        int topLim = 0;
        int bottomLim = matrix.size() - 1;

        vector<int> res;
        while ((topLim <= bottomLim) && (leftLim <= rightLim)) {
            cout << "limits before" << endl;
            cout << topLim << ", " << bottomLim << endl;
            cout << leftLim << ", " << rightLim << endl;
            cout << endl;
            
            int startR = topLim;
            int startC = leftLim;

            // go right
            cout << "going right" << endl;
            for (int i = 0; i < (rightLim - leftLim + 1); ++i) {
                 cout << topLim << ", " << leftLim + i << endl;
                 res.push_back(matrix[topLim][leftLim + i]);
            }
            topLim++;
            cout << "topLim -> " << topLim << endl;

            // go down
            cout << "going down" << endl;
            for (int j = 0; j < (bottomLim - topLim + 1); ++j) {
                 cout << topLim + j << ", " << rightLim << endl;
                 res.push_back(matrix[topLim + j][rightLim]);
            }
            rightLim--;
            cout << "rightLim -> " << rightLim << endl;

            if ( (leftLim > rightLim) || (topLim  > bottomLim) ) {
                break;
            }

            // go left
            cout << "going left" << endl;
            for (int i = 0; i < (rightLim - leftLim + 1); ++i) {
                 cout << bottomLim << ", " << rightLim - i << endl;
                 res.push_back(matrix[bottomLim][rightLim - i]);
            }
            bottomLim--;
            cout << "bottomLim -> " << bottomLim << endl;

            // go up
            cout << "going up" << endl;
            for (int j = 0; j < (bottomLim - topLim + 1); ++j) {
                 cout << bottomLim - j << ", " << leftLim << endl;
                res.push_back(matrix[bottomLim - j][leftLim]);
            }
            leftLim++;
            cout << "leftLim -> " << leftLim << endl;

            cout << "limits after" << endl;
            cout << topLim << ", " << bottomLim << endl;
            cout << leftLim << ", " << rightLim << endl;
            cout << endl;
            cout << endl;
        }

        return res;
    }
};
