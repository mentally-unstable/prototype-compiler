// hello
#include "../defs.h"
#include "../data.h"
#include "../decl.h"

int mathop(int tok) {
    switch (tok) {
        case tLPAREN:
            return aLPAREN;
        case tRPAREN:
            return aRPAREN;
        case tADD:
            return aADD;
        case tSUB:
            return aSUB;
        case tMUL:
            return aMUL;
        case tDIV:
            return aDIV;
        case tMOD:
            return aMOD;
        case tINT:
            return aINT;
        default:
            fprintf(stderr, "[PARSER] Unknown token on line %d\n", State.line);
            exit(1);
    }
}

// just a utility for better error messages
char *which_token(int tkn) {
    switch (tkn) {
        case 0:
        case 1:
            return "parentheses";
        case 2:
            return "`+'";
        case 3:
            return "`-'";
        case 4:
            return "`*'";
        case 5:
            return "`/'";
        case 6:
            return "`%'";
        case 8:
            return "end of file";
        default:
            return "int";
    }
}

// Parse a primary factor
// and return an AST Node
static struct ASTNode *primary(void)
{
    struct ASTNode *n;

    // make a leaf node for any
    // primitive/literal type (since that's
    // the only logical thing that can be a leaf
    // node) & scan in the next token
    //
    // fails if token is not a primitive/literal
    switch (State.curtoken.token) {
        // currently our only type
        case tINT:
            n = mkastleaf(aINT, State.curtoken.intvalue);
            scan(&State.curtoken);
            return n;
        default:
            fprintf(stderr, "[PARSER] Syntax error on line %d: unexpected %s\n", State.line, which_token(State.curtoken.token));
            exit(1);
    }
}

struct ASTNode *binexpr(void) {
    struct ASTNode *n, *left, *right;
    int nodetype;

    left = primary();

    if (State.curtoken.token == tEOF)
        return left;

    nodetype = mathop(State.curtoken.token);

    scan(&State.curtoken);

    right = binexpr();

    n = mkastnode(nodetype, left, right, 0);
    return n;
}
