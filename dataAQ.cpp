/* aggregate data */
#include "dataAQ.h"
#include "demogData.h"
#include <iostream>
#include <algorithm>

dataAQ::dataAQ() {}

/* necessary function to aggregate the data - this CAN and SHOULD vary per
   student - depends on how they map, etc. */
void dataAQ::createStateData(std::vector<shared_ptr<demogData> > theData)
{
  //FILL in
  string statename = "";
  for (const auto obj : theData)
  {
    if (statename == "")
    {
      statename = obj->getState();
      statedata[obj->getState()] = make_shared<demogState>(obj->getState(), 1, obj->getpopOver65Count(), obj->getpopUnder18Count(),
                                                           obj->getpopUnder5Count(), obj->getBAupCount(), obj->getHSupCount(), obj->getpopPoorCount(), obj->getPop());
    }
    else if (obj->getState() != statename)
    {
      statename = obj->getState();
      statedata[obj->getState()] = make_shared<demogState>(obj->getState(), 1, obj->getpopOver65Count(), obj->getpopUnder18Count(),
                                                           obj->getpopUnder5Count(), obj->getBAupCount(), obj->getHSupCount(), obj->getpopPoorCount(), obj->getPop());
    }
    else
    {
      int number = statedata[obj->getState()]->getNumber();
      double popOver65Count = statedata[obj->getState()]->getpopOver65Count();
      double popUnder18Count = statedata[obj->getState()]->getpopUnder18Count();
      double popUnder5Count = statedata[obj->getState()]->getpopUnder5Count();
      double popBACount = statedata[obj->getState()]->getBAupCount();
      double popHSCount = statedata[obj->getState()]->getHSupCount();
      double popPoorCount = statedata[obj->getState()]->getpopPoorCount();
      int totalPopulation2014 = statedata[obj->getState()]->getTotalPopulationCount();

      statedata[obj->getState()] = make_shared<demogState>(obj->getState(), number += 1, obj->getpopOver65Count() + popOver65Count, obj->getpopUnder18Count() + popUnder18Count,
                                                           obj->getpopUnder5Count() + popUnder5Count, obj->getBAupCount() + popBACount, obj->getHSupCount() + popHSCount, obj->getpopPoorCount() + popPoorCount,
                                                           obj->getPop() + totalPopulation2014);
    }
  }
}

//return the name of the state with the largest population under age 5
string dataAQ::youngestPop()
{
  double youngest = -999.0;
  string youngeststate = "";
  for (auto entry : statedata)
  {
    if (entry.second->getpopUnder5() > youngest)
    {
      youngest = entry.second->getpopUnder5();
      youngeststate = entry.first;
    }
  }
  return youngeststate;
}

//return the name of the state with the largest population under age 18
string dataAQ::teenPop()
{
  double youngest = -999.0;
  string youngeststate = "";
  for (auto entry : statedata)
  {
    if (entry.second->getpopUnder18() > youngest)
    {
      youngest = entry.second->getpopUnder18();
      youngeststate = entry.first;
    }
  }
  return youngeststate;
}

//return the name of the state with the largest population over age 65
string dataAQ::wisePop()
{
  double oldest = -999.0;
  string state = "";
  for (auto entry : statedata)
  {
    if (entry.second->getpopOver65() > oldest)
    {
      oldest = entry.second->getpopOver65();
      state = entry.first;
    }
  }
  return state;
}

//return the name of the state with the largest population who did not receive high school diploma
string dataAQ::underServeHS()
{
  double HS = 999;
  string state = "";
  for (auto entry : statedata)
  {
    if (entry.second->getHSup() < HS)
    {
      HS = entry.second->getHSup();
      state = entry.first;
    }
  }
  return state;
}

//return the name of the state with the largest population who did receive bachelors degree and up
string dataAQ::collegeGrads()
{
  double BA = -999;
  string state = "";
  for (auto entry : statedata)
  {
    if (entry.second->getBAup() > BA)
    {
      BA = entry.second->getBAup();
      state = entry.first;
    }
  }
  return state;
}

//return the name of the state with the largest population below the poverty line
string dataAQ::belowPoverty()
{
  double Poor = -999;
  string state = "";
  for (auto entry : statedata)
  {
    if (entry.second->getpopPoor() > Poor)
    {
      Poor = entry.second->getpopPoor();
      state = entry.first;
    }
  }
  return state;
}

std::ostream &operator<<(std::ostream &out, const dataAQ &allStateData)
{
//   for (const auto &obj : (allStateData.statedata)) {
//     std::cout << *obj << std::endl;
//  }
}