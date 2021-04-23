#ifndef DEMOG_H
#define DEMOG_H

#include <string>
#include<iostream>

using namespace std;

/*
  class to represent county demographic data
  from CORGIS
*/
class demogData {
  public:
    demogData(string inN, string inS, double in65, double in18,
        double in5, double inBA, double inHS, double inPoor, int totPop14) :
            name(inN), state(inS), popOver65(in65), popUnder18(in18),
            popUnder5(in5), popBA(inBA), popHS(inHS), popPoor(inPoor), totalPopulation2014(totPop14) {}

    demogData(string inN, string inS, double in65, double in18,
        double in5, double inPoor, int totPop14) :
            name(inN), state(inS), popOver65(in65), popUnder18(in18),
            popUnder5(in5), popBA(0), popHS(0), popPoor(inPoor), totalPopulation2014(totPop14) {}
    
    string getName() const { return name; }
    string getState() const { return state;  }
    double getpopOver65() const { return popOver65;  }
    double getpopUnder18() const { return popUnder18;  }
    double getpopUnder5()  const { return popUnder5;  }
    double getBAup()  const { return popBA;  }
    double getHSup()  const { return popHS;  }
    double getpopPoor() const { return popPoor; }
    int getPop() const { return totalPopulation2014; }

    double getpopOver65Count() const { return popOver65/100*totalPopulation2014;  }
    double getpopUnder18Count() const { return popUnder18/100*totalPopulation2014;  }
    double getpopUnder5Count()  const { return popUnder5/100*totalPopulation2014;  }
    double getBAupCount()  const { return popBA/100*totalPopulation2014;  }
    double getHSupCount()  const { return popHS/100*totalPopulation2014;  }
    double getpopPoorCount() const { return popPoor/100*totalPopulation2014;  }
  
  friend std::ostream& operator<<(std::ostream &out, const demogData &DD);

private:
    const string name;
    const string state;
    const double popOver65;
    const double popUnder18;
    const double popUnder5;
    const double popBA;
    const double popHS;
    const double popPoor;
    const int totalPopulation2014;
};
#endif
