#include "Block.h"
#include "sha256.h"

Block::Block(uint32_t nIndexIn, const std::string& sDataIn) : _nIndex(nIndexIn), _sData(sDataIn) {
	_nNonce = -1;
	_tTime = time(nullptr);
}

std::string Block::getHash() {
	return this->_sHash;
}

/*
In order to mine a block we need the right number of 0
at the first of the hash as the number of difficulty 
for example hash at difficulty 3 will have the start with 000
hash at level 4 will have to start with 0000 etc...
the hash are made of the data we input
*/
void Block::mineBlock(uint32_t nDifficulty) {
	char* cstr = new char[nDifficulty + 1];
	for (uint32_t i = 0; i < nDifficulty; i++) {
		cstr[i] = '0';
	}
	cstr[nDifficulty] = '\0';
	
	std::string str(cstr);

	do {
		_nNonce++;
		_sHash = _calculateHash();
	} while (_sHash.substr(0, nDifficulty) != str);

	std::cout << "Blocked mined: " << _sHash << std::endl;
}

inline std::string Block::_calculateHash() const {
	std::stringstream ss;
	ss << _nIndex << _tTime << _sData << _nNonce << _prevHash;

	return sha256(ss.str());
}