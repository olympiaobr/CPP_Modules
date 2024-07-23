#ifndef STRREPLACER_HPP
#define STRREPLACER_HPP

#include <string>

class StrReplacer
{
public:
    StrReplacer(const std::string &filename, const std::string &s1, const std::string &s2);
    bool process();

private:
    std::string filename;
    std::string s1;
    std::string s2;

    std::string readFile() const;
    std::string replaceString(const std::string &content) const;
    bool writeFile(const std::string &content) const;
    bool fileExists(const std::string& filename) const;
};

#endif
