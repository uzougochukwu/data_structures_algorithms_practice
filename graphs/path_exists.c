bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {
int source_connect[n] = {};
int destination_connect[n] = {};

bool containsNode(int position, int node, int i){
    if (edges[position][0] == node){
        source_connect[i] = edges[position][1];
        return true;
    }
    if (edges[position][1] == node){
        source_connect[i] = edges[position][0];
        return true;
    }
    return false;
}


int node = source;
// get all nodes connected to source
for (int i = 0; i < edgesSize; i++){
    containsNode(i, source, i);   
    
}
//printf("%d", source_connect[0]);
//return false;
// get all nodes connected to destination
node = destination;
for (int i = edgesSize-1; i >= 0; i--){
    containsNode(i, destination, i);   
    
}

//printf("%d", destination_connect[1]);
//return false;
// find intersection, if any

//printf("%d", sizeof(destination_connect[0]));

int dest_connect_len = sizeof(destination_connect)/sizeof(destination_connect[0]);
int source_connect_len = sizeof(source_connect)/sizeof(source_connect[0]);

// see if there is a match
for (int i = 0; i < source_connect_len; i++){
    for (int j = 0; j < dest_connect_len; j++){
        if (source_connect[i] == destination_connect[j]){
            return true;
        }
    }
}

return false;
}
