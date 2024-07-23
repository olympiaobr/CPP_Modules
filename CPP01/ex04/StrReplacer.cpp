#include "StrReplacer.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cerrno>
#include <cstring>

StrReplacer::StrReplacer(const std::string &filename, const std::string &s1, const std::string &s2)
    : filename(filename), s1(s1), s2(s2) {}

std::string StrReplacer::readFile() const
{
    std::ifstream file(filename.c_str());
    if (!file)
    {
        if (errno == ENOENT)
        {
            std::cerr << "Error: File does not exist - " << filename << std::endl;
        }
        else if (errno == EACCES)
        {
            std::cerr << "Error: No permissions to open file - " << filename << std::endl;
        }
        else
        {
            std::cerr << "Error: Could not open file - " << filename << std::endl;
        }
        return "";
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    if (buffer.str().empty())
    {
        std::cerr << "Error: File is empty - " << filename << std::endl;
        return "";
    }

    return buffer.str();
}


std::string StrReplacer::replaceString(const std::string &content) const
{
    size_t pos = 0;
    std::string result;
    size_t found = content.find(s1, pos);
    if (found == std::string::npos) return "";
    while (found != std::string::npos)
    {
        result.append(content, pos, found - pos);
        result.append(s2);
        pos = found + s1.length();
        found = content.find(s1, pos);
    }
    result.append(content, pos, content.length() - pos);
    return result;
}

bool StrReplacer::writeFile(const std::string &content) const
 {
    std::ofstream file((filename + ".replace").c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: Cannot create output file." << std::endl;
        return false;
    }
    file << content;
    file.close();

    if (file.fail())
    {
        std::cerr << "Error: Failed to write to output file properly." << std::endl;
        return false;
    }

    return true;
}


bool StrReplacer::fileExists(const std::string& filename) const
{
    std::ifstream file(filename.c_str());
    return file.good();
}

bool StrReplacer::process()
{
    if (s1 == s2)
    {
        std::cerr << "No operation needed as the search and replacement strings are identical." << std::endl;
        return false;
    }
    std::string content = readFile();
    if (content.empty())
    {
        return false;
    }
    std::string replacedContent = replaceString(content);
    if (replacedContent.empty())
    {
        std::cerr << "No replacements found" << std::endl;
        return false;
    }
    return writeFile(replacedContent);
}




