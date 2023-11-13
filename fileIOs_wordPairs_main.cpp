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

    int topCount, botCount;
    std::string outputFileName = "output.txt"; 
    cout<<"Enter desired Count of top word pairs: ";
    cin >> topCount;
    cout<<endl;
    cout<<"Enter desired Count of bottom word pairs: ";
    printWordpairs(freqWordpair_mmap, outputFileName, topCount, botCount);
    cout<<endl;
    cout<<"Check directory for output"<<endl;    
    return 0;
}
