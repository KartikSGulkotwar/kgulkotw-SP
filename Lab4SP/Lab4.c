#include <stdio.h>
#include <stdlib.h>

void concatenateFiles(char *filename1, char *filename2) {
    FILE *file1, *file2;
    char ch;

    // Open the first file for reading
    file1 = fopen(filename1, "a");

    if (file1 == NULL) {
        perror("Error opening first file");
        exit(EXIT_FAILURE);
    }

    // Open the second file for reading
    file2 = fopen(filename2, "r");

    if (file2 == NULL) {
        perror("Error opening second file");
        fclose(file1);
        exit(EXIT_FAILURE);
    }

    // Check if filenames are the same
    if (strcmp(filename1, filename2) == 0) {
        fprintf(stderr, "Error: The two filenames are the same.\n");
        fclose(file1);
        fclose(file2);
        exit(EXIT_FAILURE);
    }

    // Copy the contents of the second file to the first file
    while ((ch = fgetc(file2)) != EOF) {
        fputc(ch, file1);
    }

    // Close the files
    fclose(file1);
    fclose(file2);
}

int main(int argc, char *argv[]) {
    // Check if two filenames are provided as command-line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <filename1> <filename2>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Concatenate the contents of the second file to the first file
    concatenateFiles(argv[1], argv[2]);

    printf("Files concatenated successfully.\n");

    return 0;
}

