#include <iostream>
#include <cctype>

int main(int argc, char* argv[])
{
    if (argc < 2)
	{
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
	else
    {
        for (int i = 1; i < argc; ++i)
        {
            for (char* p = argv[i]; *p != '\0'; ++p)
            {
                int upperChar = std::toupper(*p);
                std::cout << (char)upperChar;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}

#include <iostream>
#include <cctype> // Include the cctype library for character conversion functions

int main(int argc, char* argv[])
{
    // Check if there are enough arguments
    if (argc < 2)
    {
        // Print a message if no arguments are provided
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    else
    {
        // Loop through each argument (starting from 1 to skip the program name)
        for (int i = 1; i < argc; ++i)
        {
            char* currentArgument = argv[i]; // Pointer to the current argument

            // Loop through each character in the current argument
            for (char* p = currentArgument; *p != '\0'; ++p)
            {
                char currentChar = *p; // Get the current character
                char upperChar = std::toupper(currentChar); // Convert to uppercase
                std::cout << upperChar; // Print the uppercase character
            }
        }
        std::cout << std::endl; // Print a newline at the end
    }
    return 0; // Return 0 to indicate successful execution
}
