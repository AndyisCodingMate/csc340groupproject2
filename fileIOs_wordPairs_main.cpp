#include "fileIOs_wordPairs.h"
#include <iostream>

int main() {
    std::string inputFileName = "SteveJobsSpeech2005.txt"; 
    std::vector<std::string> sentences;
    sentenceSplitter(inputFileName, sentences);

    std::map<std::pair<std::string, std::string>, int> wordpairFreq_map;
    wordpairMapping(sentences, wordpairFreq_map);

    std::multimap<int, std::pair<std::string, std::string>> freqWordpair_mmap;
    freqWordpairMmap(wordpairFreq_map, freqWordpair_mmap);

    int topCount, botCount;
    std::string outputFileName = "output.txt"; 
    std::cout<<"Enter desired Count of top word pairs: ";
    std::cin >> topCount;
    std::cout<<std::endl;
    std::cout<<"Enter desired Count of bottom word pairs: ";
    std::cin>> botCount;
    printWordpairs(freqWordpair_mmap, outputFileName, topCount, botCount);
    std::cout<<std::endl;
    std::cout<<"Check directory for output"<<std::endl;    
    return 0;
}
