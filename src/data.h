// hello

#ifndef DATA_INCLUDE
#define DATA_INCLUDE

#ifndef extern_
#define extern_ extern
#endif

/*
   extern_ int     Line;
   extern_ int     Putback;
   extern_ FILE    *Infile;
   extern_ Token   Token; // <-- causes issues lol
 */

extern_ struct {
    int line;
    int col;
    int putback;
    FILE *infile;
    struct Token curtoken;
} State;

#endif
