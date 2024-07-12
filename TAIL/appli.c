#include <stdio.h>
#include <stdlib.h>
#include "liat.h"


int main(int argc, char *argv[])
{
    version_or_help(argv, argc);
    
    char *filename = argv[argc-1];
    FILE *fichier = open_file(filename, "r");

    int nbr = count_lines(filename);

    int n_tail;
    get_args(argv, argc,fichier);

    //tail_n(fichier, nbr, n_tail);

    return (0);
}

