#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "demogData.h"
#include "parse.h"
#include "dataAQ.h"

using namespace std;
//Group members: Ziyue Wang, Jiayang Zhao
int main() {

    dataAQ theAnswers;

    //read in a csv file and create a vector of objects representing each counties data
    std::vector<shared_ptr<demogData>> theData = read_csv(
            "county_demographics.csv", DEMOG);

     //debug print out - uncomment if you want to double check your data
    
    // for (const auto &obj : theData) {
    //     std::cout << *obj << std::endl;
    // }
    

    theAnswers.createStateData(theData);

    


    //one example of how to print required - ADD OTHERS
    cout << "*** the state that needs the most pre-schools**" << endl;
    string needPK = theAnswers.youngestPop();
    cout << "Name of state: " << needPK << endl;
    if (theAnswers.getStateData(needPK) != nullptr){
        cout << *(theAnswers.getStateData(needPK)) << endl;
    } else{
        cout << "Did you read the lab instructions?" << endl;
    }

    //NOW fill in these too
    cout << "*** the state that needs the most high schools**" << endl;
    string needHS = theAnswers.teenPop();
    cout << "Name of state: " << needHS << endl;
    if (theAnswers.getStateData(needHS) != nullptr){
        cout << *(theAnswers.getStateData(needHS)) << endl;
    } else{
        cout << "Did you read the lab instructions?" << endl;
    } 

    cout << "*** the state that needs the most vaccines**" << endl;
    string needMV = theAnswers.wisePop();
    cout << "Name of state: " << needMV << endl;
    if (theAnswers.getStateData(needMV) != nullptr){
        cout << *(theAnswers.getStateData(needMV)) << endl;
    } else{
        cout << "Did you read the lab instructions?" << endl;
    } 

    cout << "*** the state that needs the most help with education**" << endl;
    string needE = theAnswers.underServeHS();
    cout << "Name of state: " << needE << endl;
    if (theAnswers.getStateData(needE) != nullptr){
        cout << *(theAnswers.getStateData(needE)) << endl;
    } else{
        cout << "Did you read the lab instructions?" << endl;
    }

    cout << "*** the state with most college grads**" << endl;
    string needCG = theAnswers.collegeGrads();
    cout << "Name of state: " << needCG << endl;
    if (theAnswers.getStateData(needCG) != nullptr){
        cout << *(theAnswers.getStateData(needCG)) << endl;
    } else{
        cout << "Did you read the lab instructions?" << endl;
    } 

    cout << "*** the state with largest percent of the population below the poverty line**" << endl;
    string needPL = theAnswers.belowPoverty();
    cout << "Name of state: " << needPL << endl;
    if (theAnswers.getStateData(needPL) != nullptr){
        cout << *(theAnswers.getStateData(needPL)) << endl;
    } else{
        cout << "Did you read the lab instructions?" << endl;
    }

    return 0;
}

