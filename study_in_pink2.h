/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Submit code for Assignment 1
* Programming Fundamentals Spring 2024
* Author: Nguyen Phuc Nhan
* ID: 2312438
* Date: 10.03.2024
*/

#ifndef _H_STUDY_IN_PINK_2_H_
#define _H_STUDY_IN_PINK_2_H_

#include "main.h"

////////////////////////////////////////////////////////////////////////
// STUDENT'S ANSWER BEGINS HERE
////////////////////////////////////////////////////////////////////////

// Forward declaration
//Check init Map
 class MapElement;
 class Map;
 class Position;
 
 //Check init Objects
 class MovingObject;
 class Sherlock;
 class Watson;
 class Criminal;

 //Check init array
 class ArrayMovingObject;

 //Check config
 class Configuration;

 //Recheck Object
 class Character;

 //Check init Robot
 class Robot;
 class RobotC;
 class RobotS;
 class RobotW;
 class RobotSW;

 //Check init Item
 class BaseItem;
 class MagicBook;
 class EnergyDrink;
 class FirstAid;
 class ExcemptionCard;
 class PassingCard;

 //Check init Bag
 class BaseBag;
 class SherlockBag;
 class WatsonBag;
 class StudyPinkProgram;

//TestStudyInPink declare in main.cpp
//We call it to avoid error calling 
 class TestStudyInPink;

class StudyPinkProgram
{
private:
    Map *map;
    Sherlock *sherlock;
    Watson *watson;
    Criminal *criminal;
    Configuration *config;
    void exchangeCard();
public:
    string infoProgram = "";
    StudyPinkProgram(const string &config_file_path);
    bool isStop() const;
    void printResult() const
    {
        if (sherlock->getCurrentPosition().isEqual(criminal->getCurrentPosition()))
        {
            cout << "Sherlock caught the criminal" << endl;
        }
        else if (watson->getCurrentPosition().isEqual(criminal->getCurrentPosition()))
        {
            cout << "Watson caught the criminal" << endl;
        }
        else
        {
            cout << "The criminal escaped" << endl;
        }
    }
    void printStep(int si) const
    {
        cout << "Step: " << setw(4) << setfill('0') << si
             << "--"
             << sherlock->str() << "--|--" << watson->str() << "--|--" << criminal->str() << endl;
        
    }
    void printResult(bool option)
    {
        if (sherlock->getCurrentPosition().isEqual(criminal->getCurrentPosition()))
            infoProgram += "Sherlock caught the criminal\n";
        else if (watson->getCurrentPosition().isEqual(criminal->getCurrentPosition()))
            infoProgram += "Watson caught the criminal\n";
        else
            infoProgram += "The criminal escaped\n";
    }
    void printStep(int si, bool option)
    {
        infoProgram += "Step: " + to_string(si) + "--" + sherlock->str() + "--|--" + watson->str() + "--|--" + criminal->str() + "\n";
    }
    void run(bool);
    ~StudyPinkProgram();
    friend class TestStudyInPink;
};

#endif /* _H_STUDY_IN_PINK_2_H_ */