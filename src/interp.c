// hello
#include "defs.h"
#include "data.h"
#include "decl.h"

static char *ASTop[] = { "+", "-", "*", "/", "%" };

int interpretAST(struct ASTNode *n) { // can't use typedef because of n->left, recursion
    int leftval, rightval;

    if (n->left)
        leftval = interpretAST(n->left);
    if (n->right)
        rightval = interpretAST(n->right);

    // just some debug IO stuff
    if (n->op == aINT)
        printf("int %d\n", n->intvalue);
    else
        printf("%d %s %d\n", leftval, ASTop[n->op], rightval);

    switch (n->op) {
        case aADD:
            return (leftval + rightval);
        case aSUB:
            return (leftval - rightval);
        case aMUL:
            return (leftval * rightval);
        case aDIV:
            return (leftval / rightval);
        case aMOD:
            return (leftval % rightval);
        case aINT:
            return (n->intvalue);
        default:
            fprintf(stderr, "[PARSER] Unknown operator %d\n", n->op);
            exit(1);
    }
}
