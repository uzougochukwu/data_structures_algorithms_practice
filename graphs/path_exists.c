bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {

bool containsNode(int position, int node){
    if (edges[position][0] == node){
        return true;
    }
    if (edges[position][1] == node){
        return true;
    }
    return false;
}

    // find all nodes that source connects with
int find_number = source;

for (int i = 0; i < edgesSize; i++){
    if (containsNode(i, find_number) == true){
        // check if other number is destination
        if (containsNode(i, destination) == true) {
            return true;
        }
        // now extract the other number
        if (edges[i][0] == find_number){
            find_number = edges[i][1];
        } else {
            find_number = edges[i][0];
        }

    }
}
return false;
    // find all nodes that destination connects with

}
