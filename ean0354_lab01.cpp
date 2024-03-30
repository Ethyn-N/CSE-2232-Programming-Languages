// Ethyn Nguyen
// 1001930354
// C++
// linux ubuntu

// Omega: g++ -o lab01 ean0354_lab01.cpp

#include <iostream>
#include <fstream>
#include <dirent.h>
#include <cstring>

#define MAX_LENGTH 500

int calculateSize(std::string path);
int dirSize(std::string dir_name);

// calculate size of file
int calculateSize(std::string path) {
    // opening file stream
    std::ifstream ist(path.c_str());

    // checking if the file exist or not
    if (!ist) {
        std::cout << "File Not Found!" << std::endl;
        return 0;
    }

    ist.seekg(0, std::ios_base::end);

    // calculating the size of the file
    int size = ist.tellg();

    // closing the file
    ist.close();

    return size;
}


int dirSize(std::string dir_name) {
// Input: std::string dir_name
// Output: int. Returns the total size in bytes of all files in the current directory / folder and all sub-folders
// Processing: (O(log(n)) time).

    int total_size = 0;
    std::string path;
    
    // Opens directory stream
    DIR *dir = opendir(dir_name.c_str());
    if (!dir) {
        return 0;
    }

    struct dirent *dirent;

    // Continues to loop until end of directory
    while ((dirent = readdir(dir)) != NULL) {
        if (strcmp(dirent->d_name, ".") != 0 && strcmp(dirent->d_name, "..") != 0) { // If directory is not itself or parent directory
            path = dir_name + "/" + dirent->d_name;
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

// 1) Out of all the languages, Python was the easiest and fastest in writing the code. 
//    Since Python is an interpreted language, not much is needed for the interpreter to understand what the program is trying to do. 
//    With the built-in modules and easy readability Python provides, I had the least hassle writing the program compared to the other two languages.

// 2) An alternative to using recursion would be the use of an iterative function. 
//    I would use an iterative procedure to iterate over files for a directory. 
//    However, the limitation of this approach is that I would need to call this function multiple times 
//    non-recursively any time there is another directory within a directory. 
//    Ultimately, I would have to summarize the results of all the function calls.
