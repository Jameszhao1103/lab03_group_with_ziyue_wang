#include "demogState.h"
#include "demogData.h"
#include <sstream>
#include <string>
#include <assert.h>
#include <iomanip>
#include <iomanip>
//add member functions here

/* print state data - as aggregate of all the county data */
std::ostream& operator<<(std::ostream &out, const demogState&SD) {
    // cout<<fixed<<setprecision(2);
    // cout.setf(ios::fixed,ios::floatfield);
    out << "State Info: " << SD.getState();
    out << "\nNumber of Counties: " << SD.getNumber();
    out << "\nPopulation info: \n(\% over 65): " << double(int(SD.getpopOver65()*100))/100<<"\%";
    out <<  " and total: " << SD.getpopOver65Count();
    out << "\n(\% under 18): " << double(int(SD.getpopUnder18()*100))/100<<"\%";
    out <<  " and total: " << SD.getpopUnder18Count();
    out << "\n(\% under 5): " << double(int(SD.getpopUnder5()*100))/100<<"\%";
    out <<  " and total: " << SD.getpopUnder5Count();
    out << "\nEducation info: ";
    out << "\n(\% Bachelor degree or more): " << double(int(SD.getBAup()*100))/100<<"\%";
    out <<  " and total: " << SD.getBAupCount();
    out << "\n(\% high school or more): " << double(int(SD.getHSup()*100))/100<<"\%";
    out <<  " and total: " << SD.getHSupCount();
    out << "\npersons below poverty: " << double(int(SD.getpopPoor()*100))/100<<"\%";
    out <<  " and total: " << SD.getpopPoorCount();
    out << "\nTotal population: " << SD.totalPopulation2014;
    return out;
}
