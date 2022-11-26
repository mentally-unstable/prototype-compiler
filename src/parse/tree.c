// hello

#include "../defs.h"
#include "../data.h"
#include "../decl.h"

#define ASTNode struct ASTNode

ASTNode *mkastnode(int op, ASTNode *left, ASTNode *right, int val)
{
    ASTNode *n;

    // new node
    n = (ASTNode *) malloc(sizeof(ASTNode));
    if (n == NULL) {
        fprintf(stderr, "[AST] Unable to allocate memory for AST Node\n");
        exit(1);
    }

    // constructing n
    n->op = op;
    n->left = left;
    n->right = right;
    n->intvalue = val;
    return n;
}

ASTNode *mkastleaf(int op, int intvalue) {
    return mkastnode(op, NULL, NULL, intvalue);
}

ASTNode *mkastunary(int op, ASTNode *left, int intvalue) {
    return mkastnode(op, left, NULL, intvalue);
}

#undef ASTNode
