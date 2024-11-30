#include <iostream>
#include <fstream>
#include <string>

int main() {
    // 1. Writing to a file
    std::ofstream outfile("example.txt");  // Open file for writing
    if (outfile.is_open()) {
        outfile << "Hello, World!" << std::endl;
        outfile.close();
    } else {
        std::cerr << "Failed to open the file for writing!" << std::endl;
        return 1;
    }

    // 2. Appending to the same file
    std::ofstream appendfile("example.txt", std::ios::app);  // Open file in append mode
    if (appendfile.is_open()) {
        appendfile << "Appending some text." << std::endl;
        appendfile.close();
    } else {
        std::cerr << "Failed to open the file for appending!" << std::endl;
        return 1;
    }

    // 3. Reading from the file
    std::ifstream infile("example.txt");  // Open file for reading
    if (infile.is_open()) {
        std::string line;
        while (std::getline(infile, line)) {  // Read line by line
            std::cout << line << std::endl;  // Print each line
        }
        infile.close();
    } else {
        std::cerr << "Failed to open the file for reading!" << std::endl;
        return 1;
    }

    return 0;
}
