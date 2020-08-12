#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int HOTPLATE_ARRAY_SIZE = 10;
const int PRECISION = 3;
const int WIDTH = HOTPLATE_ARRAY_SIZE-1;

void InitializeHotplate(double hotplateTemps[HOTPLATE_ARRAY_SIZE][HOTPLATE_ARRAY_SIZE]){
    for(int i = 0; i < HOTPLATE_ARRAY_SIZE; ++i){
        for(int j = 0; j < HOTPLATE_ARRAY_SIZE; ++j){
            if(j == 0 || j == HOTPLATE_ARRAY_SIZE-1){
                hotplateTemps[i][j] = 0.000;
            }
            else if((i == 0 || i == HOTPLATE_ARRAY_SIZE-1) && (j != 0 && j != HOTPLATE_ARRAY_SIZE-1)){
                hotplateTemps[i][j] = 100.000;
            }
            else {
                hotplateTemps[i][j] = 0.000;
            }
        }
    }
}

void PrintHotplate(double hotplateTemps[HOTPLATE_ARRAY_SIZE][HOTPLATE_ARRAY_SIZE]){

    for(int i = 0; i < HOTPLATE_ARRAY_SIZE; ++i){
        for(int j = 0; j < HOTPLATE_ARRAY_SIZE; ++j){
            if(j == HOTPLATE_ARRAY_SIZE-1){
                cout << fixed << setprecision(PRECISION) << setw(WIDTH) << hotplateTemps[i][j] << endl;
            }
            else {
                cout << fixed << setprecision(PRECISION) << setw(WIDTH) << hotplateTemps[i][j] << ",";
            }
        }
    }
}

void UpdateHotplate(double newTempValues[][HOTPLATE_ARRAY_SIZE], double oldTempValues[][HOTPLATE_ARRAY_SIZE]){

    for(int i = 0; i < HOTPLATE_ARRAY_SIZE; ++i) {
        for (int j = 0; j < HOTPLATE_ARRAY_SIZE; ++j) {
            oldTempValues[i][j] = newTempValues[i][j];
        }
    }
    for(int i = 1; i < HOTPLATE_ARRAY_SIZE-1; ++i){
        for(int j = 1; j < HOTPLATE_ARRAY_SIZE-1; ++j){
            newTempValues[i][j] = (oldTempValues[i][j+1] + oldTempValues[i][j-1] + oldTempValues[i+1][j]
                    + oldTempValues[i-1][j])/4;
        }
    }
}

bool StopUpdating(double currentTempValues[][HOTPLATE_ARRAY_SIZE], double oldTempValues[][HOTPLATE_ARRAY_SIZE]){
    double largestChangeInTemp = 0.000;
    for(int i = 0; i < HOTPLATE_ARRAY_SIZE; ++i){
        for(int j = 0; j < HOTPLATE_ARRAY_SIZE; ++j){
            if((currentTempValues[i][j] - oldTempValues[i][j]) > largestChangeInTemp){
                largestChangeInTemp = currentTempValues[i][j] - oldTempValues[i][j];
            }
        }
    }
    return (largestChangeInTemp <= 0.100);
}
void WriteDataToFile(double currentTempValues[][HOTPLATE_ARRAY_SIZE]){
    ofstream stablePlate;
    stablePlate.open("Hotplate.csv");
    cout << "Writing final plate to \"Hotplate.csv\"..." << endl;
    for(int i = 0; i < HOTPLATE_ARRAY_SIZE; ++i){
        for(int j = 0; j < HOTPLATE_ARRAY_SIZE; ++j){
            if(j == HOTPLATE_ARRAY_SIZE-1){
                stablePlate << fixed << setprecision(PRECISION) << setw(WIDTH) << currentTempValues[i][j] << endl;
            }
            else {
                stablePlate << fixed << setprecision(PRECISION) << setw(WIDTH) << currentTempValues[i][j] << ",";
            }
        }
    }
    stablePlate.close();
}

void ReadInputplate(double currentTempValues[][HOTPLATE_ARRAY_SIZE]){
    ifstream inputFile;
    inputFile.open("Inputplate.txt");
    for(int i = 0; i < HOTPLATE_ARRAY_SIZE; ++i){
        for(int j = 0; j < HOTPLATE_ARRAY_SIZE; ++j){
            inputFile >> currentTempValues[i][j];
        }
    }
}
int main(){

    double currentHotplateTemps[HOTPLATE_ARRAY_SIZE][HOTPLATE_ARRAY_SIZE];
    double oldHotplateTemps[HOTPLATE_ARRAY_SIZE][HOTPLATE_ARRAY_SIZE];

    cout << "Hotplate simulator" << endl << endl;
    cout << "Printing the initial plate values..." << endl;

    InitializeHotplate(currentHotplateTemps);
    InitializeHotplate(oldHotplateTemps);

    PrintHotplate(currentHotplateTemps);

    cout << "Printing plate after one iteration..." << endl;
    UpdateHotplate(currentHotplateTemps, oldHotplateTemps);
    PrintHotplate(currentHotplateTemps);

    while(true) {
        UpdateHotplate(currentHotplateTemps, oldHotplateTemps);
        if(StopUpdating(currentHotplateTemps, oldHotplateTemps)){
            break;
        }
        else {
            continue;
        }
    }

    cout << "Printing final plate..." << endl;
    PrintHotplate(currentHotplateTemps);

    WriteDataToFile(currentHotplateTemps);
    ReadInputplate(currentHotplateTemps);

    for(int i = 0; i < 3; ++i){
        UpdateHotplate(currentHotplateTemps, oldHotplateTemps);
    }
    cout << "Printing input plate after 3 updates..." << endl;
    PrintHotplate(currentHotplateTemps);
}