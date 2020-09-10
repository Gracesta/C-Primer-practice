#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>

using namespace std;
using namespace std::placeholders;

void elimDups(vector<string>& words){
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(),words.end());
    words.erase(end_unique, words.end());
}
bool isShorter(const string &s1, const string &s2){
    return s1.size() < s2.size();
}
bool longerthanFive(const string &s){
    return s.size() >= 5;
}
void biggies(vector<string> &words, size_t sz){
    elimDups(words);
    stable_sort(words.begin(),words.end(), isShorter);
    
}
bool check_size(string s, size_t sz){
    return s.size() >= sz;
}


int main(){
    vector<string> words;
    size_t sz = 4;
    words.push_back("Where");words.push_back("there");
    words.push_back("is");words.push_back("a");words.push_back("will");
    words.push_back("there");words.push_back("is");
    words.push_back("a");words.push_back("way");
    //auto it = partition(words.begin(), words.end(), longerthanFive);
    // cout << *it << endl;
    // for(auto &w : words)
    //     cout << w << " ";
    // for(auto &s : words) cout << s << " ";
    // sort(words.begin(), words.end(),
    //             bind(isShorter, _2, _1));
    cout << count_if(words.begin(), words.end(),
                bind(check_size, "aaaa", 1,2));
    //for(auto &s : words) cout << s << endl;
    return 0;
}