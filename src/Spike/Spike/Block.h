#pragma once
#include <cstdint>
#include <iostream>
#include <ctime>
#include <vector>
#include <sstream>

class Block
{
public:
	// const/dist
	Block(uint32_t nIndexIn, const std::string& sDataIn);

	
	void mineBlock(uint32_t nDifficulty);
	std::string getHash();
	std::string _prevHash;

private:
	uint32_t _nIndex;
	int64_t _nNonce;
	std::string _sData;
	std::string _sHash;
	time_t _tTime;

	std::string _calculateHash() const;

};

