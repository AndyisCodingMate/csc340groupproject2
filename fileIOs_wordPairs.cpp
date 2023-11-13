#include "fileIOs_wordPairs.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm> 

void sentenceSplitter(const std::string &fname, std::vector<std::string> &sentences) {
    std::ifstream myFile(fname);
    std::string line, temp;
    if (!myFile.is_open()) {
        std::cerr << "Error opening file: " << fname << std::endl;
        return;
    }
    while (std::getline(myFile, line)) {
        // Skip empty lines
        if (line.empty()) {
            continue;
        }
        size_t targetPos = std::min({line.find('.'), line.find('?'), line.find('!'), line.find(':')});
        // Handle cases where a sentence ends with a quotation mark
        if (line[targetPos] == '"') {
            targetPos++;
        }
        temp = line.substr(0, targetPos);
        sentences.push_back(temp);
        // Skip remaining spaces and characters after the end of the sentence
        line.erase(0, targetPos + 1);
    }
    myFile.close();
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
   std::ofstream myFile;
   myFile.open(outFname);
   //print top X frequency
    myFile<<"Top 10 most frequent word pairs: "<<std::endl;
   int topCount = 0;
   for (auto it = freqWordpair_multimap.rbegin(); it != freqWordpair_multimap.rend() && topCount>0; it++, topCount++){
       myFile << "<" << it->second.first << "," << it->second.second << ">" <<": "<< it->first << std::endl;
   }

   myFile<<std::endl;

    //print lowest X frequency
    myFile<<"Bottom 10 least frequent word pairs: "<<std::endl;
   int bottomCount = 0;
    for (auto it = freqWordpair_multimap.begin(); it != freqWordpair_multimap.end() && bottomCount<botCnt; it++, bottomCount++){
         myFile << "<" << it->second.first << "," << it->second.second << ">" <<": "<< it->first << std::endl;
    }
   
   
   
   
   myFile.close();
}

