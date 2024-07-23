#include "StrReplacer.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 4)
	{
        std::cerr << "Usage: " << argv[0] << " <filename> <string1> <string2>" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    StrReplacer replacer(filename, s1, s2);
    if (!replacer.process())
	{
        return 1;
    }
    return 0;
}
