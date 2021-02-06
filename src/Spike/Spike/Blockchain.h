#pragma once
#include <cstdint>
#include <vector>
#include "Block.h"

class Blockchain {
public:
	Blockchain();

	void addBlock(Block newBlock);

private:
	uint32_t _nDifficulty;
	std::vector<Block> _vChain; 

	Block _getLastBlock() const;
};