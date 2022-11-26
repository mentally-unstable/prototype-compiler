// hello
#ifndef SCANNER_INCLUDE
#define SCANNER_INCLUDE

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

/* Tokens for the Lexer */
struct Token {
    int token;
    int intvalue;
};

enum {
    tLPAREN,
    tRPAREN,

    tADD,
    tSUB,
    tMUL,
    tDIV,
    tMOD,

    tINT,

    tEOF
};


/* the Abstract Syntax Tree */
struct ASTNode {
    int op;
    struct ASTNode *left;
    struct ASTNode *right;
    int intvalue;
};

enum {
    aLPAREN,
    aRPAREN,

    aADD,
    aSUB,
    aMUL,
    aDIV,
    aMOD,

    aINT,

    aEOF
};

#endif

