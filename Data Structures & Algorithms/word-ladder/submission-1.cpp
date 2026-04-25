#include <iostream>
#include <queue>
#include <stdint.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  Solution() {
    this->adj.clear();
    this->adj.resize(103, vector<int>());
    this->vst.resize(103, false);
  }

  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    for (int i = 0; i < wordList.size(); ++i) {
      for (int j = i + 1; j < wordList.size(); ++j) {
        int diff = 0;
        for (int k = 0; k < beginWord.size(); ++k) {
          if (wordList[i][k] != wordList[j][k])
            diff++;
        }

        if (diff == 1) {
          adj[i].push_back(j);
          adj[j].push_back(i);
        }
      }
    }

    for (int i = 0; i < wordList.size(); ++i) {
      int diff = 0;
      for (int k = 0; k < beginWord.size(); ++k) {
        if (wordList[i][k] != beginWord[k])
          diff++;
      }
      if (diff == 1) {
        adj[i].push_back(wordList.size() + 1);
        adj[wordList.size() + 1].push_back(i);
      }
    }

    queue<tuple<int, int>> q;
    q.push({wordList.size() + 1, 0});
    this->vst[wordList.size() + 1] = true;

    while (!q.empty()) {
      auto [curr, step] = q.front();
      q.pop();

      // cout << "curr" << endl;
      // cout << curr << " -> " << wordList[curr] << endl;

      if (wordList[curr] == endWord) {
        return step + 1;
      }

      // cout << "pushed" << endl;
      for (int nei : adj[curr]) {
        if (this->vst[nei])
          continue;
        q.push({nei, step + 1});
        this->vst[nei] = true;
        // cout << nei << " -> " << wordList[nei] << endl;
      }
    }

    return 0;
  }

private:
  vector<vector<int>> adj;
  vector<bool> vst;
};