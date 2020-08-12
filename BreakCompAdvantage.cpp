#include <iostream>
#include <ctime>
#include <cstdlib>

/*
    This was a little program I wrote for fun. I learned about "Comparative Advantage" in American Heritage
    , and I was told that it isn't possible for someone to have a comparative advantage in everything.
    
    For info about comparative advantage --> https://www.econlib.org/library/Topics/Details/comparativeadvantage.html
*/
using namespace std;
typedef unsigned long li;
float MattOppCostFood(float& foodProdMatt, float& techProdMatt){
    return techProdMatt / foodProdMatt;
}
float MattOppCostTech(float& foodProdMatt, float& techProdMatt){
    return foodProdMatt / techProdMatt;
}
float RyanOppCostFood(float& foodProdRyan, float& techProdRyan){
    return techProdRyan / foodProdRyan;
}
float RyanOppCostTech(float& foodProdRyan, float& techProdRyan){
    return foodProdRyan / techProdRyan;
}
int main(){
    srand(time(0));
    long int halfWayMark = 0;
    bool broken = false;
    for(long int i = 0; i < 1000000000000; i++) {
        float foodProdMatt = rand();
        float techProdMatt = rand();
        float foodProdRyan = rand();
        float techProdRyan = rand();

        if (MattOppCostFood(foodProdMatt, techProdMatt) < RyanOppCostFood(foodProdRyan, techProdRyan) &&
            MattOppCostTech(foodProdMatt, techProdMatt) < RyanOppCostTech(foodProdRyan, techProdRyan)) {
            cout << "Broken!" << endl;
            cout << "Matt's OppCostTech: " << MattOppCostTech(foodProdMatt, techProdMatt) << endl;
            cout << "Matt's OppCostFood: " << MattOppCostFood(foodProdMatt, techProdMatt) << endl;
            cout << "Ryan's OppCostTech: " << RyanOppCostTech(foodProdRyan, techProdRyan) << endl;
            cout << "Ryan's OppCostFood: " << RyanOppCostFood(foodProdRyan, techProdRyan) << endl;
            broken = true;
        } else if (MattOppCostFood(foodProdMatt, techProdMatt) > RyanOppCostFood(foodProdRyan, techProdRyan) &&
                   MattOppCostTech(foodProdMatt, techProdMatt) > RyanOppCostTech(foodProdRyan, techProdRyan)) {
            cout << "Broken!" << endl;
            cout << "Matt's OppCostTech: " << MattOppCostTech(foodProdMatt, techProdMatt) << endl;
            cout << "Matt's OppCostFood: " << MattOppCostFood(foodProdMatt, techProdMatt) << endl;
            cout << "Ryan's OppCostTech: " << RyanOppCostTech(foodProdRyan, techProdRyan) << endl;
            cout << "Ryan's OppCostFood: " << RyanOppCostFood(foodProdRyan, techProdRyan) << endl;
            broken = true;
        }
        ++halfWayMark;
        if (1000000000000.0 / halfWayMark == 2) cout << "Halfway there..." << endl;
        if ((1000000000000.0 / 2) / 2 == i) cout << "Quarter finished..." << endl;
    }
    if(broken) cout << "BROKEN";
    else if (!broken) cout << "NOT BROKEN";
}
