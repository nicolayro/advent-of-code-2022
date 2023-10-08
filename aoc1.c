#include <stdlib.h>
#include <stdio.h>

#define BUFF_SIZE 64
#define MAX(a, b) (((a) > (b) ? (a) : b))

void read_file(char* file_path)
{
    
}

int main(int argc, char** argv)
{
    if (argc < 2) {
        printf("ERROR: no input file was given");
        return 1;
    }

    char *file_path = argv[1];

    FILE *fptr;
    fptr = fopen(file_path, "r");

    if (fptr == NULL) {
        printf("ERROR: Failed to open file %s", file_path);
        return 1;
    }

    int curr_elf = 0;
    int best_elf = 0;
    char *line = malloc(BUFF_SIZE * sizeof(char));
    while (fgets(line, BUFF_SIZE, fptr) != NULL) {
        if (*line == '\n') {
            curr_elf = 0;
        }

        int calories = strtol(line, &line, 10);
        curr_elf += calories;
        best_elf = MAX(curr_elf, best_elf);
    }

    printf("Best elf: %d\n", best_elf);

    fclose(fptr);

    return 0;
}
