//
//  student.cpp
//  Class Roster
//
//  Created by Preston Desbordes on 2/24/18.
//  Copyright © 2018 Preston Desbordes. All rights reserved.
//

#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"

student::student(std::string ID, std::string first, std::string last, std::string email, int howOld, int days[3], Degree study)
    {
        
        setID(ID);
        setFName(first);
        setLName(last);
        setEAddress(email);
        setAge(howOld);
        setCompletion(days);
        setDegreeProgram(study);
    }
    
    void student::print()
    {
        int *timeSpent = getCompletion();
        std::cout << "ID: " << getID() << "\t" << "First Name: " << getFName() << "\t" << "Last Name: " << getLName() << "\t" << "Age: " << getAge() << "\t" << "daysInCourse: {" << timeSpent[0] << "," << timeSpent[1] << "," << timeSpent[2] << "}";
        
        std:: cout << "\t" << "Degree Program: ";
        switch(getDegreeProgram())
        {
            case 0:
                std::cout << "SECURITY";
                break;
            case 1:
                std::cout << "NETWORK";
                break;
            case 2:
                std::cout << "SOFTWARE";
                break;
        }
        
        std::cout << "\n";
        
        
    }
    
    std::string student::getID()
    {
        return student_ID;
    }
    
    void student::setID(std::string identification)
    {
        student_ID = identification;
    }
    
    std::string student::getFName()
    {
        return first_Name;
    }
    
    void student::setFName(std::string yourFirst)
    {
        first_Name = yourFirst;
    }
    
    std::string student::getLName()
    {
        return last_Name;
    }
    
    void student::setLName(std::string yourLast)
    {
        last_Name = yourLast;
    }
    
    
    std::string student::getEAddress()
    {
        return email_Address;
    }
    
    void student::setEAddress(std::string email)
    {
        email_Address = email;
    }
    
int student::getAge()
    {
        return age;
    }
    
void student::setAge(int howOld)
    {
        age = howOld;
    }
    
    int* student::getCompletion()
    {
        return completion;
    }
    
    void student::setCompletion(int* progress)
    {
        for(int i = 0;i<3;i++)
        {
            completion[i] = progress[i];
        }
    }
    
    Degree student::getDegreeProgram()
    {
        return Degree();
    }
    
    void student::setDegreeProgram(Degree plan)
    {
        programOfStudy = plan;
    }

    student::~student()
    {
    
    }
