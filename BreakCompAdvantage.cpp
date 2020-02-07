#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
typedef long long ll;
double MattOppCostFood(double& foodProdMatt, double& techProdMatt){
    return techProdMatt / foodProdMatt;
}
double MattOppCostTech(double& foodProdMatt, double& techProdMatt){
    return foodProdMatt / techProdMatt;
}
double RyanOppCostFood(double& foodProdRyan, double& techProdRyan){
    return techProdRyan / foodProdRyan;
}
double RyanOppCostTech(double& foodProdRyan, double& techProdRyan){
    return foodProdRyan / techProdRyan;
}
int main(){
    ll halfWayMark = 0;
    bool broken = false;
    while(true) {
        for(ll i = 0; i < 1000000000; i++) {
            srand(time(0));
            double foodProdMatt = rand();
            double techProdMatt = rand();
            double foodProdRyan = rand();
            double techProdRyan = rand();

            if (MattOppCostFood(foodProdMatt, techProdMatt) < RyanOppCostFood(foodProdRyan, techProdRyan) &&
            MattOppCostTech(foodProdMatt, techProdMatt) < RyanOppCostTech(foodProdRyan, techProdRyan)){
                cout << "Broken!" << endl;
                cout << "Matt's OppCostTech: " << MattOppCostTech(foodProdMatt, techProdMatt) << endl;
                cout << "Matt's OppCostFood: " << MattOppCostFood(foodProdMatt, techProdMatt) << endl;
                cout << "Ryan's OppCostTech: " << RyanOppCostTech(foodProdRyan, techProdRyan) << endl;
                cout << "Ryan's OppCostFood: " << RyanOppCostFood(foodProdRyan, techProdRyan) << endl;
            }
            else if (MattOppCostFood(foodProdMatt, techProdMatt) > RyanOppCostFood(foodProdRyan, techProdRyan) &&
            MattOppCostTech(foodProdMatt, techProdMatt) > RyanOppCostTech(foodProdRyan, techProdRyan)){
                cout << "Broken!" << endl;
                cout << "Matt's OppCostTech: " << MattOppCostTech(foodProdMatt, techProdMatt) << endl;
                cout << "Matt's OppCostFood: " << MattOppCostFood(foodProdMatt, techProdMatt) << endl;
                cout << "Ryan's OppCostTech: " << RyanOppCostTech(foodProdRyan, techProdRyan) << endl;
                cout << "Ryan's OppCostFood: " << RyanOppCostFood(foodProdRyan, techProdRyan) << endl;
            }
            ++halfWayMark;
            if (1000000000.0/halfWayMark == 2) cout << "Halfway there..." << endl;
            cout << halfWayMark << endl;
        }
        cout << "Finished? y/n: ";
        string response;
        cin >> response;
        if (response == "y") break;
        else continue;
    }
    cout << "Is this broken? " << broken << endl;
}
