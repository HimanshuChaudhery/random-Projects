#include <iostream> // Required for input/output operations (cout, cin)
#include <fstream>  // Required for file stream operations (ofstream)
#include <string>   // Required for using string data type

int main() {
    std::ofstream outputFile; // Declare an output file stream object
    std::string fileName = "D:/bill.txt"; // Name of the file to create/write to
    std::string textToWrite = "This is some sample text to save."; // Text to save

    // Open the file in write mode. If the file doesn't exist, it will be created.
    // ios::out specifies output mode.
    outputFile.open(fileName, std::ios::app);

    // Check if the file was successfully opened
    if (outputFile.is_open()) {
        // Write the text to the file
        outputFile << textToWrite;

        // Close the file stream
        outputFile.close();

        std::cout << "Text successfully written to '" << fileName << "'." << std::endl;
    } else {
        std::cerr << "Error: Unable to open or create the file '" << fileName << "'." << std::endl;
    }

    return 0;
}