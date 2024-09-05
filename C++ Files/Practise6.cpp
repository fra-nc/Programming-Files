
#include <iostream>

int main() {
    // Define the number of rows and columns for the table
    int rows = 5;
    int columns = 3;

    // Use nested loops to create the table
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= columns; j++) {
            // Calculate the value for the cell (i, j)
            int result = i * j;

            // Print the value with formatting
            std::cout << result;

            // Add tab ("\t") to align the columns
            if (j < columns) {
                std::cout << "\t";
            }
        }

        // Move to the next row
        std::cout << std::endl;
    }

    return 0;
}
