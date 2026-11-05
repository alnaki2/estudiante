#include "dictionary.h"

using namespace std;

Dictionary::Dictionary() {
}

Dictionary::Dictionary(const Dictionary &other) : words(other.words) {
}

bool Dictionary::exists(const string &val) const {
    return words.find(val) != words.end();
}

bool Dictionary::insert(const string &val) {
    pair<set<string>::iterator, bool> ret = words.insert(val);
    return ret.second;
}

bool Dictionary::erase(const string &val) {
    return words.erase(val) > 0;
}

void Dictionary::clear() {
    words.clear();
}

bool Dictionary::empty() const {
    return words.empty();
}

unsigned int Dictionary::size() const {
    return words.size();
}

vector<string> Dictionary::wordsOfLength(int length) const {
    vector<string> result;
    for (set<string>::const_iterator it = words.begin(); it != words.end(); ++it) {
        if (static_cast<int>(it->length()) == length) {
            result.push_back(*it);
        }
    }
    return result;
}

int Dictionary::getOccurrences(const char c) const {
    int count = 0;
    for (set<string>::const_iterator it = words.begin(); it != words.end(); ++it) {
        for (char ch : *it) {
            if (ch == c) {
                count++;
            }
        }
    }
    return count;
}