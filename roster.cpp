//
//  roster.cpp
//  Class Roster
//
//  Created by Preston Desbordes on 2/25/18.
//  Copyright © 2018 Preston Desbordes. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include "roster.h"

int main()
{
    roster classRoster;
    
    std::string ID[5] = {"A1","A2","A3","A4","A5"};
    std::string first[5] = {"John","Suzan","Jack","Erin","Preston"};
    std::string last[5] = {"Smith","Erickson","Napoli","Black","Desbordes"};
    std::string mail[5] = {"John1989@gm ail.com","Erickson_1990@gmail.com","The_lawyer99yahoo.com","Erin.black@comcast.net","pdesbor@wgu.edu"};
    int DOB[5] = {20,19,19,22,23};
    int days[15] = {30,35,40,50,30,40,20,40,33,50,58,40,30,40,50};
    Degree major[5] = {SECURITY,NETWORKING,SOFTWARE,SECURITY,SOFTWARE};
    int j =0;
    
    std::cout << "Class: C867 - Scripting and Programming Applications\nLanguage: C++\nStudent ID: #000849543\nName: Preston Desbordes\n";
    
    for(int i=0; i < sizeof(roster::classRosterArray)/sizeof(roster::classRosterArray[i]); i++)
    {
        classRoster.add(ID[i],first[i],last[i],mail[i],DOB[i],days[j],days[j+1],days[j+2],major[i]);
        j+=3;
    }
    
    classRoster.printAll();
    classRoster.printInvalidEmail();
    
    for(int j=0; j<sizeof(roster::classRosterArray)/sizeof(roster::classRosterArray[j]); j++)
    {
        std::string idNum;
        idNum = classRoster.classRosterArray[j]->getID();
        classRoster.printDaysInCourse(idNum);
    }
    
    classRoster.printByDegreeProgram(SOFTWARE);
    
    classRoster.remove("A3");
    classRoster.remove("A3");
    
    classRoster.~roster();
    
    return 0;
}

void roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree study)
{
    int totalDays[3] = {daysInCourse1,daysInCourse2,daysInCourse3};
    for(int i = 0; i < sizeof(classRosterArray)/sizeof(classRosterArray[i]); i++)
        if(classRosterArray[i] == nullptr)
        {
            if(study == SECURITY)
            {
            classRosterArray[i] = new securityStudent(studentID,firstName,lastName,emailAddress,age,totalDays,study);
            break;
            }
            
            else if(study == NETWORKING)
            {
            classRosterArray[i] = new networkStudent(studentID,firstName,lastName,emailAddress,age,totalDays,study);
            break;
            }
            
            else if(study == SOFTWARE)
            {
            classRosterArray[i] = new softwareStudent(studentID,firstName,lastName,emailAddress,age,totalDays,study);
            break;
            }
            
        }
}

void roster::remove(std::string studentID)
{
    bool studentRemoved = false;
    
    for(int i=0; i<sizeof(classRosterArray)/sizeof(classRosterArray[i]); i++)
    {
        if(classRosterArray[i] != nullptr && classRosterArray[i]->getID() == studentID)
        {
            classRosterArray[i] = nullptr;
            studentRemoved = true;
        }
    }
    
    if(studentRemoved == false)
    {
        std::cout << "ERROR: Student was not found!\n";
    }
}

void roster::printAll()
{
    
    for(int i=0; i<sizeof(classRosterArray)/sizeof(classRosterArray[i]); i++)
    {
        if(classRosterArray[i] != nullptr)
        {
        classRosterArray[i]->print();
        }
    }
}

void roster::printDaysInCourse(std::string studentID)
{
    int total = 3;
    int sum = 0;
    for(int i=0; i<sizeof(classRosterArray)/sizeof(classRosterArray[i]); i++)
    {
        if(classRosterArray[i]->getID() == studentID)
        {
            int *daysInCourse = classRosterArray[i]->getCompletion();
            for(int j=0; j<total;j++)//sizeof(daysInCourse)/sizeof(classRosterArray[j]); j++)
            {
                sum += daysInCourse[j];
            }
            sum = sum/total;
            break;
        }
    }
    std::cout << "The average number of days in the three courses is " << sum << "\n";
}

void roster::printInvalidEmail()
{
    for (int i = 0; i < sizeof(classRosterArray)/sizeof(classRosterArray[i]); i++) {
        std::string email = classRosterArray[i]->getEAddress();
        bool correct = false;
        
        size_t found = email.find("@");
        if (found != std::string::npos) {
            found = email.find(".");
            if (found != std::string::npos) {
                found = email.find(" ");
                if (found == std::string::npos) {
                    correct = true;
                }
            }
        }
        
        if (!correct) {
            std::cout << email << " is not a valid email address \n";
        }
    }
}

void roster::printByDegreeProgram(int degreeProgram)
{
    for(int i=0;i<sizeof(classRosterArray)/sizeof(classRosterArray[i]);i++)
    {
        if(classRosterArray[i]->getDegreeProgram() == degreeProgram)
        {
            classRosterArray[i]->print();
        }
    }
}

roster::~roster()
{
    
}



