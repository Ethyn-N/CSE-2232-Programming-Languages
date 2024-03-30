// Ethyn Nguyen
// 1001930354
// C
// linux ubuntu

#include <stdio.h>
#include <string.h>
#include <dirent.h>

#define MAX_LENGTH 500

int calculateSize(char path[]);
int dirSize(const char *dir_name);

// calculate size of file
int calculateSize(char path[]) {
    // opening the file in read mode
    FILE *fp = fopen(path, "r");

    // checking if the file exist or not
    if (fp == NULL) {
        printf("File Not Found!\n");
        return 0;
    }

    fseek(fp, 0L, SEEK_END);

    // calculating the size of the file
    int size = ftell(fp);

    // closing the file
    fclose(fp);

    return size;
}

int dirSize(const char *dir_name) {
// Input: char *dir_name
// Output: int. Returns the total size in bytes of all files in the current directory / folder and all sub-folders
// Processing: (O(log(n)) time).

    int total_size = 0;
    char path[MAX_LENGTH];
    
    // Opens directory stream
    DIR *dir = opendir(dir_name);
    if (!dir) {
        return 0;
    }

    struct dirent *dirent;

    // Continues to loop until end of directory
    while ((dirent = readdir(dir)) != NULL) {
        if (strcmp(dirent->d_name, ".") != 0 && strcmp(dirent->d_name, "..") != 0) { // If directory is not itself
            strcpy(path, dir_name); 
            strcat(path, "/");
            strcat(path, dirent->d_name);

            if (dirent->d_type == DT_DIR) 
                total_size += dirSize(path); // Recursively go through each directory
            else
                total_size += calculateSize(path); // Add file size to total_size
        }
    }

    closedir(dir);

    return total_size;
}

int main(int argc, char *argv[]) {
    int bytes = dirSize("."); // Calculate size of current directory of the program
    
    printf("%d\n", bytes);

    return 0;
}

// 1) Out of all the languages, Python was the easiest and fastest in writing the code. 
//    Since Python is an interpreted language, not much is needed for the interpreter to understand what the program is trying to do. 
//    With the built-in modules and easy readability Python provides, I had the least hassle writing the program compared to the other two languages.

// 2) An alternative to using recursion would be the use of an iterative function. 
//    I would use an iterative procedure to iterate over files for a directory. 
//    However, the limitation of this approach is that I would need to call this function multiple times 
//    non-recursively any time there is another directory within a directory. 
//    Ultimately, I would have to summarize the results of all the function calls.
