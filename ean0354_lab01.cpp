// Ethyn Nguyen
// 1001930354
// C++
// linux ubuntu

#include <iostream>
#include <fstream>
#include <dirent.h>
#include <cstring>

#define MAX_LENGTH 500

void concatenatePath(char *path , const char *dir_name, struct dirent *dirent);
int calculateSize(std::string path);
int dirSize(const char *dir_name);

void concatenatePath(char *path , const char *dir_name, struct dirent *dirent) {
// Input: char *path - stores the directory path of where the file is
//        const char *dir_name - parent directory
//        struct dirent *dirent - struct that holds name of file of interest
// Output: void. Returns the path to file within directory that can be used with fopen
// Processing: (O(1) time).

    strcpy(path, dir_name);
    strcat(path, "/");
    strcat(path, dirent->d_name);
}

// calculate size of file
int calculateSize(std::string path) {
    // opening file stream
    std::ifstream ist;
    ist.open(path);

    // checking if the file exist or not
    if (!ist) {
        throw std::runtime_error{"File Not Found!\n"};
        return 0;
    }

    ist.seekg(0, std::ios_base::end);

    // calculating the size of the file
    int size = ist.tellg();

    // closing the file
    ist.close();

    return size;
}

int dirSize(const char *dir_name) {
// Input: char *dir_name
// Output: int. Returns the total size in bytes of all files in the current directory / folder and all sub-folders
// Processing: (O(log(n)) time).

    float total_size = 0;
    char path[MAX_LENGTH];
    
    // Opens directory stream
    DIR *dir = opendir(dir_name);
    if (dir == NULL) {
        return -1;
    }

    struct dirent *dirent;

    // Continues to loop until end of directory
    while ((dirent = readdir(dir)) != NULL) {
        if (strcmp(dirent->d_name, ".") != 0 && strcmp(dirent->d_name, "..") != 0) { // If directory is not itself
            concatenatePath(path, dir_name, dirent);
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
    
    std::cout << bytes << std::endl;

    return 0;
}