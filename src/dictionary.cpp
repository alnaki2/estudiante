/**
 * @file dictionary.cpp
 * @brief Implementación del TDA Dictionary
 */
#include "dictionary.h"

using namespace std;

Dictionary::Dictionary() {}

Dictionary::Dictionary(const Dictionary &other) : words(other.words) {}

Dictionary::~Dictionary() {
    words.clear();
}

Dictionary& Dictionary::operator=(const Dictionary &dic) {
    if (this != &dic)
        words = dic.words;
    return *this;
}

bool Dictionary::insert(const string &val) {
    return words.insert(val).second;
}

void Dictionary::clear() {
    words.clear();
}

unsigned int Dictionary::size() const {
    return words.size();
}

vector<string> Dictionary::wordsOfLength(int length) const {
    vector<string> result;
    for (set<string>::const_iterator it = words.begin(); it != words.end(); ++it)
        if (static_cast<int>(it->length()) == length)
            result.push_back(*it);
    return result;
}

int Dictionary::getOccurrences(const char c) const {
    int count = 0;
    for (set<string>::const_iterator it = words.begin(); it != words.end(); ++it)
        for (size_t i = 0; i < it->size(); i++)
            if ((*it)[i] == c)
                count++;
    return count;
}

void Dictionary::anade(const Dictionary &dic) {
    words.insert(dic.words.begin(), dic.words.end());
}

istream& operator>>(istream &is, Dictionary &dic) {
    dic.clear();
    string w;
    while (getline(is, w)) {
        if (!w.empty() && w[w.size()-1] == '\r')   // ficheros con fin de línea Windows
            w.erase(w.size()-1);
        if (!w.empty())
            dic.insert(w);
    }
    return is;
}

ostream& operator<<(ostream &os, const Dictionary &dic) {
    for (Dictionary::const_iterator it = dic.begin(); it != dic.end(); ++it)
        os << *it << endl;
    return os;
}