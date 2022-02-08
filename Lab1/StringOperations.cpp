#include <string>
#include <vector>
#include "Header.h"

void fillOtherFiles(std::string str, std::vector<std::string>& fileA, std::vector<std::string>& fileB) {
    std::string::size_type pos = 0;
    std::string::size_type prev = 0;
    bool toA = true;
    while ((pos = str.find('\n', prev)) != std::string::npos) {
        if (toA) {
            fileA.push_back(str.substr(prev, pos - prev));
        } else {
            fileB.push_back(str.substr(prev, pos - prev));
        }
        prev = pos + 1;
        toA = !toA;
    }
    if (toA) {
        fileA.push_back(str.substr(prev, pos - prev));
    } else {
        fileB.push_back(str.substr(prev, pos - prev));
    }
}

std::string sortWords(std::vector<std::string>& arr) {
    std::string result = "";
    for (int i = 0; i < arr.size(); i++) {
        std::string str = arr[i];
        std::vector<std::string> words;
        std::string::size_type pos = 0;
        std::string::size_type prev = 0;
        while ((pos = str.find(' ', prev)) != std::string::npos) {
            words.push_back(str.substr(prev, pos - prev));
            prev = pos + 1;
        }
        words.push_back(str.substr(prev, pos - prev));

        sort(words);
        result += ((i > 0) ? "\n" : "") + join(words, " ");
    }
    return result;
}

void sort(std::vector<std::string>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        int k = i;
        while (k > 0 && arr[k] < arr[k - 1]) {
            std::string tmp = arr[k];
            arr[k] = arr[k - 1];
            arr[k - 1] = tmp;
            k--;
        }
    }
}

std::string join(std::vector<std::string>& arr, std::string del) {
    std::string result = "";
    for (int i = 0; i < arr.size(); i++) {
        result += ((i > 0) ? del : "") + arr[i];
    }
    return result;
}

std::string sortRows(std::vector<std::string>& rows) {
    sort(rows);
    return join(rows, "\n");
}