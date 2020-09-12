#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int actionChooser = 0;
ifstream dataRead;
string tempReceiver;
int i = 0;

struct event{
    string month;
    string day;
    int hour;
    int minute;
    int second;
    char c;
    string IP;
    string description;
};
vector<event> eventVec;


void welcome(){
    cout << "\n============== Welcome, do you want to make a consult? ==========Type========" << endl;
    cout << "======================== Make Consult ============================[1]==========" << endl;
    cout << "======================== Exit ====================================[2]==========" << endl;
    cin >> actionChooser;
}

void loadData(){
    dataRead.open("C:\\VS CODE\\C++\\3erSemestre\\CByAF\\bitacora.txt", ifstream::in); 
    string eventConcept;
    string month, IP, description;
    string day, hour, minute, second;
    string c;
    if (!dataRead) {
        cout << "Unable to open file bitacora.txt";
        exit(1);
    }
    
    while (dataRead >> tempReceiver){
        //cout << tempReceiver << endl;
        //Push back new event created with default constructor.
        eventVec.push_back(event());
        getline(dataRead, eventConcept);
        
        //Vector now has 1 element @ index 0, so modify it.
        eventVec[i].month = eventConcept;
        //eventVec[i].day = "10";


    }

    dataRead.close();
}


int main(){

    loadData();
    welcome();
    do {
        if (actionChooser == 1){
            cout << "Here I will make a consult " << endl;
            cout << eventVec[i].month << endl;
            //cout << eventVec[i].day << endl;
        }


        else if (actionChooser == 2){
            break;
        } else {
            cout << "Insert valid number" << endl;
        }
        welcome();
    } while (actionChooser != 2);
    cout << "Thanks for making your consults" << endl;

    system("pause");
}