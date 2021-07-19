#pragma once
#include <string>
#include <botan/hash.h>
#include <botan/hex.h>
#include "FileHandler.h"

//This class using botan C++ library
//Documentation of botan: https://botan.randombit.net
//How to install for Windows (because vcpkg doesn't work with this library at this moment): https://stackoverflow.com/questions/57309574/setting-up-botan-in-visual-c


class HashHandler
{
public:
	explicit HashHandler() noexcept; // Using explicit modify because C++ 17 recomend to use it, also
	virtual ~HashHandler() noexcept;
public:
	virtual void CheckHashSumm(std::string Input); // This function is for the ALL files
private:
	virtual void CheckFileHashSumm(std::string FolderPath, FileInfo fi); // This function is for each single file
	virtual std::unique_ptr<Botan::HashFunction> CreateHashFunction(std::string HashFunction); // It's a fabric method function for create a hash function object prt
private:
	FileHandler* fh; //Pointer to FileHandle
};

