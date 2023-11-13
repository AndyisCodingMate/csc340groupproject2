#ifndef fileIOswordPairs_h
#define fileIOswordPairs_h

#include <string>
#include <vector>
#include <map>
#include <set>


void sentenceSplitter(const std::string& fname, std::vector<std::string>& sentences);
void wordpairMapping( std::vector<std::string>& sentences, std::map< std::pair<std::string,std::string>, int> &wordpairFreq_map);
void freqWordpairMmap(std::map< std::pair<std::string,std::string>, int> &wordpairFreq_map, std::multimap<int, std::pair<std::string, std::string> > &freqWordpair_mmap );
void printWordpairs(std::multimap<int, std::pair<std::string, std::string> > &freqWordpair_multimap, std::string outFname, int topCnt, int botCnt);

#endif    