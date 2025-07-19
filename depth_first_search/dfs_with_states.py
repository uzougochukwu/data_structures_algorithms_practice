def ternary_tree_paths(root):
    def dfs(root, path, res): #dfs helper function
        if all(c is None for c in root.children): # exit condition: when a leaf node is reached, append the path to the results
            res.append('->'.join(path) + '->' + str(root.val))
            return

        #dfs on each non-null child
        for child in root.children:
            if child is not None:
                dfs(child, path + [str(root.val)], res)

    res = []
    if root: dfs(root, [], res)
    return res
        
