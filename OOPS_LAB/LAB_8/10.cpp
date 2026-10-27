#include <iostream>
using namespace std;

class Recommender {
public:
    virtual void generateRecommendation(int userRating, int popularity) {
        cout << "Base recommender engine." << endl;
    }
};

class PersonalizedRecommender : public Recommender {
public:
    void generateRecommendation(int userRating, int popularity) override {
        double score = 0.7 * userRating + 0.3 * popularity;
        cout << "Personalized Recommendation Score: " << score << endl;
    }
};

class TrendingRecommender : public Recommender {
public:
    void generateRecommendation(int userRating, int popularity) override {
        double score = 0.3 * userRating + 0.7 * popularity;
        cout << "Trending Recommendation Score: " << score << endl;
    }
};

int main() {
    Recommender* rec1 = new PersonalizedRecommender();
    Recommender* rec2 = new TrendingRecommender();
    
    int userRating = 85;
    int popularity = 90;
    
    rec1->generateRecommendation(userRating, popularity);
    rec2->generateRecommendation(userRating, popularity);
    
    delete rec1;
    delete rec2;
    return 0;
}