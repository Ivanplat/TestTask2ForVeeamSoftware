#include "HashHandler.h"
#include <iostream>
#include "boost/algorithm/string.hpp"
#include <memory>


HashHandler::HashHandler() noexcept
{
	fh = new FileHandler(); // Create new FileHandler object
}

HashHandler::~HashHandler() noexcept
{
	if (fh)
	{
		delete fh; // Delete FileHandler object
	}
}

void HashHandler::CheckHashSumm(std::string Input)
{
	auto strs = fh->SplitInputString(Input); // String with files path info
	std::ifstream file(strs[0]); // Open a file with hash summas and hash rules
	std::string buffer; //Just a buffer
	while (std::getline(file, buffer)) // Check each line in the file
	{
		FileInfo fi = fh->GetFileInfo(buffer); // Get the FileInfo stucture
		CheckFileHashSumm(strs[1], fi); // Check hash summ of each file
	}

}

void HashHandler::CheckFileHashSumm(std::string FolderPath, FileInfo& fi)
{
	auto hash1 = CreateHashFunction(fi.HashFunction); // Create hash function, using fabric methode
	std::string hashContext = fh->GetFileHashContent(FolderPath + "/" + fi.FileName); // Get file content as binary
	if (hashContext != "ERROR")
	{
		hash1->update(hashContext); //Update the hash
		if (boost::to_upper_copy(fi.HashSumm) == Botan::hex_encode(hash1->final())) // Check if prefab hash summ  (in *.txt file) equals with now combed out hash summ
		{
			std::cout << fi.FileName << " OK" << std::endl; // if true: *FILENAME* OK
			return;
		}
		else
		{
			std::cout << fi.FileName << " FAIL" << std::endl; // if false: *FILENAME* FAIL
			return;
		}
	}
	std::cout<< fi.FileName << " NOT FOUND" << std::endl; // if fail does not found: *FILENAME* NOT FOUND
}

std::unique_ptr<Botan::HashFunction> HashHandler::CreateHashFunction(std::string HashFunction)
{
	//This function designed as fabric methode, because we have to create different hash functions by their name
	if (HashFunction == "md5")
	{
		//Create MD5 hash function
		return std::unique_ptr<Botan::HashFunction>(Botan::HashFunction::create("MD5"));
	}
	if (HashFunction == "sha1")
	{
		//Create SHA-1 hash function
		return std::unique_ptr<Botan::HashFunction>(Botan::HashFunction::create("SHA-1"));
	}
	if (HashFunction == "sha256")
	{
		//Create SHA-256 hash function
		return std::unique_ptr<Botan::HashFunction>(Botan::HashFunction::create("SHA-256"));
	}
}
