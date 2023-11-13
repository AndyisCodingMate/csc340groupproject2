#include "fileIOs_wordPairs.h"
#include <fstream>
#include <sstream>
#include <algorithm>

void sentenceSplitter(std::string &fname, std::vector<std::string> &sentences) {
    
}

void wordpairMapping(std::vector<std::string> &sentences, std::map<std::pair<std::string, std::string>, int> &wordpairFreq_map) {
for (const auto& sentence : sentences) {
        std::istringstream iss(sentence);
        std::set<std::string> uniqueWords;

        // Tokenize the sentence
        std::string word;
        while (iss >> word) {
            // Convert to lowercase
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);
            uniqueWords.insert(word);
        }

        // Generate word pairs and update frequency map
        for (const auto& firstWord : uniqueWords) {
            for (const auto& secondWord : uniqueWords) {
                if (firstWord != secondWord) {
                    // Arrange in lexicographical order
                    std::pair<std::string, std::string> wordPair = (firstWord < secondWord) ?
                    std::make_pair(firstWord, secondWord) :
                    std::make_pair(secondWord, firstWord);

                    wordpairFreq_map[wordPair]++;
                }
            }
        }
    }

}

void freqWordpairMmap(std::map<std::pair<std::string, std::string>, int> &wordpairFreq_map, std::multimap<int, std::pair<std::string, std::string>> &freqWordpair_mmap) {
    for (const auto& entry : wordpairFreq_map) {
        const auto& wordPair = entry.first;
        int frequency = entry.second;

        freqWordpair_mmap.insert(std::make_pair(frequency, wordPair));
    }
}

void printWordpairs(std::multimap<int, std::pair<std::string, std::string>> &freqWordpair_multimap, std::string outFname, int topCnt, int botCnt) {
   
}

