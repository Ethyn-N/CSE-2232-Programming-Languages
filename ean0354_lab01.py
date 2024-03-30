# Ethyn Nguyen
# 1001930354
# Python
# linux ubuntu

# Omega: python ean0354_lab01.py

import os

# Returns the total size in bytes of all files in the current directory / folder and all sub-folders
def dir_size(path = "."):
    total_size = 0
    for file in os.listdir(path): # Continues to loop until end of directory
        full_path = os.path.join(path, file)
        if os.path.isdir(full_path):
            total_size += dir_size(full_path) # Recursively go through each directory
        else:
            total_size += os.path.getsize(full_path) # Add file size to total_size
            
    return total_size

print(dir_size(".")) # Call to function
