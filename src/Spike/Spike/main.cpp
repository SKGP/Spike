#include "Blockchain.h"

void main() {
	Blockchain bChain = Blockchain();

	std::cout << "Mining block no 1" << std::endl;
	bChain.addBlock(Block(1, "Block 1"));

	std::cout << "Mining block no 2" << std::endl;
	bChain.addBlock(Block(2, "Block 2"));

	std::cout << "Mining block no 3" << std::endl;
	bChain.addBlock(Block(3, "Block 3"));
}