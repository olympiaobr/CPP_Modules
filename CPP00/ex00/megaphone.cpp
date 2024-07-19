#include <iostream>
#include <cctype>
#include <string>

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
