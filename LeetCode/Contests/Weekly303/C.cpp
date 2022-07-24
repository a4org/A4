#include <vector>
#include <set>
#include <map>
#include <string>

using namespace::std;

class FoodRatings {
public:
  map<string, map<string, int>> fcr;
  map<string, string> fc; // food -> cuisine
  map<string, set<int>> rating;

  FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
    rating = {};
    fcr = {};
    const int n = foods.size();
    for (int i = 0; i < n; i++) {
      string c = cuisines[i];
      string f = foods[i];
      int r = ratings[i];
      fcr[c][f] = r;
      fc[f] = c;
      rating[c].insert(r);
    }
  }
  
  void changeRating(string food, int newRating) {
    string cuisine = fc[food];
    int old = fcr[cuisine][food];
    fcr[cuisine][food] = newRating;
    rating[cuisine].insert(newRating);
    for (auto it = rating[cuisine].begin(); it != rating[cuisine].end(); it++) {
      if (*it == old) {
	rating[cuisine].erase(it);
      }
    }
  }
  
  string highestRated(string cuisine) {
    int hi = *rating[cuisine].rbegin();

    for (auto rit = fcr[cuisine].begin(); rit != fcr[cuisine].end(); rit++) {
      if (rit->second == hi) return rit->first;
    }

    return "";
  }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
