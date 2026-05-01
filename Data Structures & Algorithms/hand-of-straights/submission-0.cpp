class Solution {
public:
  bool isNStraightHand(vector<int> &hand, int groupSize) {
    if (hand.size() % groupSize)
      return false;

    int nGrps = hand.size() / groupSize;

    vector<bool> used(hand.size(), false);

    sort(hand.begin(), hand.end());

    for (int _ = 0; _ < nGrps; ++_) {
      int prev = -1;
      int currGrpSize = 0;
      for (int i = 0; i < hand.size(); ++i) {
        if (used[i]) {
          continue;
        }

        if (prev == -1 || hand[i] - prev == 1) {
          prev = hand[i];
          used[i] = true;
          currGrpSize++;
        }

        if (currGrpSize == groupSize) {
          break;
        }
      }

      if (currGrpSize < groupSize) {
        return false;
      }
    }

    return true;
  }
};