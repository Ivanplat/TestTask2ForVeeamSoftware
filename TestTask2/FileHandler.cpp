#include <vector>
#include <iostream>
#include "FileHandler.h"
#include "boost/algorithm/string.hpp"

FileInfo FileHandler::GetFileInfo(std::string& buffer) const
{
    FileInfo fi; //Create FileInfo struct variable
    std::vector<std::string> strs; // Create vector of string for next spliting the string

    boost::split(strs, buffer, boost::is_any_of(" ")); // Split the string on every " ", using boost C++ library
    fi.FileName = strs[0]; //Field FileName in FileInfo structure
    fi.HashFunction = strs[1]; //Field HashFunction in FileInfo structure
    fi.HashSumm = strs[2]; //Field HashSumm in FileInfo structure
  
    return fi;
}

std::string FileHandler::GetFileHashContent(std::string FilePath) const
{
    std::ifstream file(FilePath, std::ios::binary); //Open a file in binary mode
    if (file) // If we open the file
    {
        std::string content((std::istreambuf_iterator<char>(file)),
            (std::istreambuf_iterator<char>())); //Get the file content
        return content;
    }
    return "ERROR"; // If file did not open
}

std::vector<std::string> FileHandler::SplitInputString(std::string Input) const
{
    std::vector<std::string> strs; // Create vector of string for next spliting the string
    boost::split(strs, Input, boost::is_any_of(" ")); // Split the string on every " ", using boost C++ library
    return strs;
}
