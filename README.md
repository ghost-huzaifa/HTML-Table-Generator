# HTML Table Generator

This C++ program generates HTML code for a table based on user input. It allows users to specify the number of rows and columns, as well as the content for each cell. The program ensures that the generated HTML is well-formed and can be easily integrated into any web page.

## Features

- User-defined number of rows and columns
- Customizable cell content
- Generates well-formed HTML code
- Easy to integrate into existing web pages

## Usage

1. Compile the C++ program using a C++ compiler.
2. Run the executable and follow the prompts to enter the number of rows and columns.
3. Enter the content for each cell as prompted.
4. The program will output the HTML code for the table.

## Example

```cpp
#include <iostream>
#include <vector>
#include <string>

int main() {
    int rows, cols;
    std::cout << "Enter number of rows: ";
    std::cin >> rows;
    std::cout << "Enter number of columns: ";
    std::cin >> cols;

    std::vector<std::vector<std::string>> table(rows, std::vector<std::string>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "Enter content for cell (" << i + 1 << "," << j + 1 << "): ";
            std::cin >> table[i][j];
        }
    }

    std::cout << "<table>\n";
    for (const auto& row : table) {
        std::cout << "  <tr>\n";
        for (const auto& cell : row) {
            std::cout << "    <td>" << cell << "</td>\n";
        }
        std::cout << "  </tr>\n";
    }
    std::cout << "</table>\n";

    return 0;
}
```

This example demonstrates how to create a simple HTML table generator using C++. The program prompts the user for the number of rows and columns, then for the content of each cell, and finally outputs the corresponding HTML code.
