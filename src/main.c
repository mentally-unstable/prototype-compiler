// hello
#include "defs.h"

#define extern_ /* nothing */
#include "data.h"
#undef extern_
#include "decl.h"

#include <errno.h>

// initializing global state, basically
// allows `extern` to work, this being the EXTERNal definition of them
static void init(void) {
    State.line = 1;
    State.putback = '\n';
}

static void usage(char *prog) {
    printf("Usage: %s <file>\n", prog);
    exit(1);
}

char *tokstr[] = { "(", ")", "+", "-", "*", "/", "%", "int literal" };


int main(int argc, char **argv) {
    struct ASTNode *n;

    if (argc != 2)
        usage(argv[0]);

    init();
    if ((State.infile = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Unable to open %s: %s\n", argv[1], strerror(errno));
        exit(1);
    }

    scan(&State.curtoken);			// Get the first token from the input
    n = binexpr();		// Parse the expression in the file
    printf("equals %d\n", interpretAST(n));	// Calculate the final result

    free(n);
    return 0;
}
