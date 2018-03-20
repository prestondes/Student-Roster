//
//  roster.h
//  Class Roster
//
//  Created by Preston Desbordes on 2/25/18.
//  Copyright © 2018 Preston Desbordes. All rights reserved.
//

#include <string>
#include "softwareStudent.h"
#include "networkStudent.h"
#include "securityStudent.h"

#ifndef roster_h
#define roster_h

class roster
{
public:
    int main();
    void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree study);
    void remove(std::string studentID);
    void printAll();
    void printDaysInCourse(std::string studentID);
    void printInvalidEmail();
    void printByDegreeProgram(int degreeProgram);
    ~roster();
    student *classRosterArray[5];
};

#endif /* roster_h */
