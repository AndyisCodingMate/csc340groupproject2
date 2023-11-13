#include "fileIOs_wordPairs.h"
#include <iostream>

int main() {
    std::string inputFileName = "test.txt"; 
    std::vector<std::string> sentences;
    sentenceSplitter(inputFileName, sentences);

    std::map<std::pair<std::string, std::string>, int> wordpairFreq_map;
    wordpairMapping(sentences, wordpairFreq_map);

    std::multimap<int, std::pair<std::string, std::string>> freqWordpair_mmap;
    freqWordpairMmap(wordpairFreq_map, freqWordpair_mmap);

    std::string outputFileName = "test.txt"; 
    int topCount = 10; 
    int botCount = 10; 
    printWordpairs(freqWordpair_mmap, outputFileName, topCount, botCount);

    return 0;
}
