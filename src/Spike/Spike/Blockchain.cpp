#include "Blockchain.h"

Blockchain::Blockchain() {
	_vChain.emplace_back(Block(0, "Genesis Block"));
	_nDifficulty = 3;
}

void Blockchain::addBlock(Block newBlock) {
	newBlock._prevHash = _getLastBlock().getHash();
	newBlock.mineBlock(_nDifficulty);
	_vChain.push_back(newBlock);
}

Block Blockchain::_getLastBlock() const {
	return _vChain.back();
}