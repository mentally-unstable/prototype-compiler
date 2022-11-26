// hello
#include "../defs.h"
#include "../data.h"
#include "../decl.h"

static int chrpos(char *s, int c) {
    char *p;

    p = strchr(s, c);
    return p ?  p - s : -1;
}

static int next(void) {
    int c;

    if (State.putback) {
        c = State.putback;
        State.putback = 0;
        return c;
    }

    c = fgetc(State.infile);
    if (c == '\n')
        State.line++;

    return c;
}

static void putback(int ch) {
    State.putback = ch;
}

static int skip(void) {
    int c;

    do {
        c = next();
    } while (c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == '\f');

    return c;
}

static int scanint(int c) {
    int k, val = 0;

    while ( (k = chrpos("0123456789", c)) >= 0 ) {
        val = val * 10 + k;
        c = next();
    }

    // non-integer; put back
    putback(c);
    return val;
}

int scan(struct Token *t) {
    int c;

    c = skip(); // skip whitespace

    switch (c) {
        case EOF:
            t->token = tEOF;
            return 0;
        case '+':
            t->token = tADD;
            break;
        case '-':
            t->token = tSUB;
            break;
        case '*':
            t->token = tMUL;
            break;
        case '/':
            t->token = tDIV;
            break;
        case '(':
            t->token = tLPAREN;
            break;
        case ')':
            t->token = tRPAREN;
            break;
        default:
            if (isdigit( c )) {
                t->intvalue = scanint(c);
                t->token = tINT;
                break;
            }

            printf("Unrecognized character %c on line %d\n", c, State.line);
            exit(1);
    }

    return 1;
}
