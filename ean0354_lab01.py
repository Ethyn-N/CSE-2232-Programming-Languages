# Ethyn Nguyen
# 1001930354
# Python
# linux ubuntu

import os

# Returns the total size in bytes of all files in the current directory / folder and all sub-folders
def dir_size(path = "."):
    total_size = 0
    dir = os.scandir(path) # Used to get an iterator of os.DirEntry objects corresponding to the entries in the directory
    for file in dir:
        if file.is_dir():
            total_size += dir_size(file.path) # Recursively go through each directory
        else:
            total_size += file.stat().st_size # Add file size to total_size
    dir.close()
    return total_size

print(dir_size(".")) # Call to function