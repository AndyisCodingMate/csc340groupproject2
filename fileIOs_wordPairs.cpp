#include "fileIOs_wordPairs.h"
#include <fstream>
#include <sstream>
#include <algorithm>

void sentenceSplitter(std::string &fname, std::vector<std::string> &sentences) {
    
}

void wordpairMapping(std::vector<std::string> &sentences, std::map<std::pair<std::string, std::string>, int> &wordpairFreq_map) {

}

void freqWordpairMmap(std::map<std::pair<std::string, std::string>, int> &wordpairFreq_map, std::multimap<int, std::pair<std::string, std::string>> &freqWordpair_mmap) {
    
}

void printWordpairs(std::multimap<int, std::pair<std::string, std::string>> &freqWordpair_multimap, std::string outFname, int topCnt, int botCnt) {
   
}

