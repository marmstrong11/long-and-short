#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    if(argc < 4)
    {
        printf("Error: must supply 3 filenames.\n");
        exit(1);
    }

    FILE *read = fopen(argv[1], "r");
    if(read == NULL)
    {
        printf("File(s) could not open.\n");
        exit(1);
    }
    
    FILE *write1 = fopen(argv[2], "w");
    if(write1 == NULL)
    {
        printf("File(s) could not open.\n");
        exit(1);
    }

    FILE *write2 = fopen(argv[3], "w");
    if(write2 == NULL)
    {
        printf("File(s) could not open.\n");
        exit(1);
    }

    char line[255];
    int numLines1 = 0;
    int numLines2 = 0;

    while(fgets(line, 255, read) != NULL)
    {
        if(strlen(line) < 20)
        {
            for(int i=0; line[i] != '\0'; i++)
            {
                line[i] = toupper(line[i]);
            }
            fputs(line, write1);
            numLines1++;
        }
        else
        {
            for(int i=0; line[i] != '\0'; i++)
            {
                line[i] = tolower(line[i]);
            }

            fputs(line, write2);
            numLines2++;
        }
    }

    fclose(read); //I've learned to write the fopen and fclose statements back-to-back before I forget to close them
    fclose(write1);
    fclose(write2);

    printf("%d lines to %s\n", numLines1, argv[2]);
    printf("%d lines to %s\n", numLines2, argv[3]);
    
}