// Ethyn Nguyen
// 1001930354
// Java
// linux ubuntu

// Omega: javac ean0354_lab01.java

import java.io.File;

public class ean0354_lab01 {
    private int dirSize(File directory) {
        int totalSize = 0;
       
        // listFiles() returns an array of pathnames denoting the files in the directory
        File[] files = directory.listFiles();
 
        // Continues to loop until end of directory
        for (File file : files) {
            if (file.isDirectory())
                totalSize += dirSize(file); // Recursively go through each directory
            else
                totalSize += file.length(); // Add file size to totalSize
        }
        return totalSize;
    }

    public static void main(String[] args) {
        ean0354_lab01 lab = new ean0354_lab01(); // Class instance

        int bytes = lab.dirSize(new File(".")); // Total amount of directory size in bytes
 
        System.out.println(bytes);
    }
}
