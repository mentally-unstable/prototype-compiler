// hello

#define ASTNode struct ASTNode *

int scan(struct Token *t);

ASTNode mkastnode(int op, ASTNode left,
        ASTNode right, int intvalue);
ASTNode mkastleaf(int op, int intvalue);
ASTNode mkastunary(int op, ASTNode left, int intvalue);

ASTNode binexpr(void);

int interpretAST(ASTNode n);

#undef ASTNode

