bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {
    // check all the arrays that contain the source
    // that becomes new source`
    // must have at least one element from previous
    // array in current array
    for (int i = 1; i < edgesSize; i++){
        int first_prev = edges[i-1][0];
        int second_prev = edges[i-1][1];

        bool first_check;
        bool second_check;

        if ( (edges[i][0] != first_prev)  && (edges[i][0] != second_prev) ) {
            first_check = false;
        } else {
            first_check = true;
        }

        if ( (edges[i][1] != first_prev)  && (edges[i][1] != second_prev) ) {
            second_check = false;
        } else {
            second_check = true;
        }

        if ( (second_check == false) && (first_check == false) ) {
            return false;
        }
    }
    return true;
}
