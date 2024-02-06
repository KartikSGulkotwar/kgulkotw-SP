C program which takes teo filenames as command line arguments and will concatenates with the content of second file.
### Functionality 
void concat_Files(char *filename1, char *filename2):
Opens two files, the first one in append mode and the second one in read mode. It checks if the filenames are the same and terminates if true. Then, it copies the contents of the second file to the end of the first file.
### Compilation
To compile, open the terminal and navigate to the directory for the source code and enter command: gcc Lab4.c -o concatenate
After compiling concatenate the two files and ensure that the filenames are different and if the filenames are same, an error message will be displayed.
 
