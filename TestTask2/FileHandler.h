#pragma once
#include <fstream>
#include <vector>
#include "Data.h"
class FileHandler
{
public:
	explicit FileHandler() noexcept = default; // Using explicit modify because C++ 17 recomend to use it, also
	virtual ~FileHandler() = default;
public:
	FileInfo GetFileInfo(std::string& buffer) const; // Function to get FileInfo
	std::string GetFileHashContent(std::string FilePath) const; // Function to get file content as binary
	std::vector<std::string> SplitInputString(std::string Input) const; // Just split the input string
};

