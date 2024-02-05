#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void concat_Files(char *filename1, char *filename2) {
    FILE *file_1, *file_2;
    char ch;

    // Opening the first file
    file_1 = fopen(filename1, "a");

    if (file_1 == NULL) {
        perror("Error while opening the first file");
        exit(EXIT_FAILURE);
    }

    // Opening the second file
    file_2 = fopen(filename2, "r");

    if (file_2 == NULL) {
        perror("Error while opening the second file");
        fclose(file_1);
        exit(EXIT_FAILURE);
    }

    // Checking if the file names are the same
    if (strcmp(filename1, filename2) == 0) {
        fprintf(stderr, "Error:Two filenames are same.\n");
        fclose(file_1);
        fclose(file_2);
        exit(EXIT_FAILURE);
    }

    // Copying the contents of the second file to the first file.
    while ((ch = fgetc(file_2)) != EOF) {
        fputc(ch, file_1);
    }

    // To Close the files
    fclose(file_1);
    fclose(file_2);
}

int main(int argc, char *argv[]) {
    // to Check if two filenames are provided as command-line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <filename1> <filename2>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Concatenating the content of the second file to the first file
    concat_Files(argv[1], argv[2]);

    printf("Files is concatenated successfully.\n");

    return 0;
}

