// Definition for a Node.
class Node {
    constructor(val, children) {
        this.val = val;
        this.children = children;
    }
};

/**
 * @param {Node|null} root
 * @return {number}
 */
 var maxDepth = function(root) {
    if (!root) {
        return 0;
    }
    let depth = 0;
    const children = root.children;
    for (const child of children) {
        const childepth = maxDepth(child);
        depth = Math.max(depth, childepth);
    }
    return depth + 1;
};