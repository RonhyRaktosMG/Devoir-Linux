#include <stdio.h>
#include <stdlib.h>
#include <string.h>


FILE *open_file(char *path, char* mode);
int count_lines(char *name);
int count_size(char *name);
int count_char(char *name);
int count_word(char *name);
int count_max_line_length(char *name);
void get_args(FILE *file, int argc,char** argv);


int main(int argc, char **argv)
{
    FILE *fic = open_file(argv[argc-1], "r");

    get_args(fic, argc, argv);
    return (0);
}

void get_args(FILE *file, int argc,char** argv)
{
    if (argc > 3){
        printf("ERREUR TROP D'ARGUMENTS");
        exit(1);
    }
    else if (argc<2){
        printf("ERREUR, PAS ASSEZ D'ARGUMENTS");
        exit(1);
    }
    else if (argc == 2)
    {
        int l, w, c;
        l = count_lines(argv[argc-1]);
        w = count_word(argv[argc-1]);
        c = count_char(argv[argc-1]);

        printf("%d %d %d -> %s", l, w, c, argv[argc-1]);    
        exit(1);
    }
    else{
        int c = 0;

        if (strcmp(argv[1],"-l") == 0)
            c = count_lines(argv[argc-1]);
        else if (strcmp(argv[1],"-m") == 0)
            c = count_char(argv[argc-1]);
        else if (strcmp(argv[1],"-c") == 0)
            c = count_size(argv[argc-1]);
        else if (strcmp(argv[1],"-w") == 0)
            c = count_word(argv[argc-1]);
        else if (strcmp(argv[1],"-L") == 0)
            c = count_max_line_length(argv[argc-1]);
        else{
            printf("ARGUMENT INVALIDE, Voir le cw --help");
            exit(1);
        }
            

        printf("%d -> %s", c, argv[argc-1]);

    }
    
}

FILE *open_file(char *path, char* mode)
{
    FILE *a = NULL;
    a = fopen(path, mode);
    if (a==NULL)
    {
        printf("Erreur ouverture");
        exit(1);
    }
    return a;
}

int count_lines(char *name)
{
    int c = 0;
    char l[255];
    FILE *a = NULL;
    a = fopen(name, "r");
    if (a==NULL)
    {
        printf("Erreur ouverture");
        exit(1);
    }
    while (!feof(a))
    {
        fgets(l, 254, a);
        c++;
    }
    fclose(a);
    return c-1;
}

int count_char(char *name)
{
    int c = 0;
    int l;
    FILE *a = NULL;
    a = fopen(name, "r");
    if (a==NULL)
    {
        printf("Erreur ouverture");
        exit(1);
    }
    while ((l=fgetc(a)) != EOF)
    {
        if ((l & 0xC0) != 0x80)
        {
            c++;
        }
    }
    fclose(a);
    return c+1;
}

int count_size(char *name)
{
    int c = 0;
    int l;
    FILE *a = NULL;
    a = fopen(name, "r");
    if (a==NULL)
    {
        printf("Erreur ouverture");
        exit(1);
    }
    while ((l=fgetc(a)) != EOF)
    {
        c++;
    }
    fclose(a);
    return c;
}

int count_word(char *name)
{
    int c = 0;
    char l[255];
    int espace = 0;
    FILE *a = NULL;
    a = fopen(name, "r");
    if (a==NULL)
    {
        printf("Erreur ouverture");
        exit(1);
    }
    while (!feof(a))
    {
        fgets(l, 254, a);
        for (int i=0; i<strlen(l); i++)
        {
            if ((l[i] != ' ' && l[i] != '\n') && espace == 0)
            {
                c++;
                espace = 1;
            }
            else if ((l[i] == ' ') || (l[i] == '\n'))
            {
                espace = 0;
            }
        }
    }
    fclose(a);
    return c;   
}

int count_max_line_length(char *name)
{
    int c = 0;
    char l[255];
    FILE *a = NULL;
    a = fopen(name, "r");
    if (a==NULL)
    {
        printf("Erreur ouverture");
        exit(1);
    }
    while (!feof(a))
    {
        fgets(l, 254, a);
        if (strlen(l) > c)
            c = strlen(l);
    }
    fclose(a);
    return c-1;
}