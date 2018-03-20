//
//  student.h
//  Class Roster
//
//  Created by Preston Desbordes on 2/24/18.
//  Copyright © 2018 Preston Desbordes. All rights reserved.
//

#include "degree.h"
#include <string>
#ifndef student_h
#define student_h

class student
{
public:
    student(std::string ID, std::string first, std::string last, std::string email, int howOld, int days[3], Degree study);
    virtual void print();
    std::string getID();
    void setID(std::string identification);
    std::string getFName();
    void setFName(std::string yourFirst);
    std::string getLName();
    void setLName(std::string yourLast);
    std::string getEAddress();
    void setEAddress(std::string email);
    int getAge();
    void setAge(int howOld);
    int* getCompletion();
    void setCompletion(int progress[3]);
    virtual Degree getDegreeProgram();
    void setDegreeProgram(Degree in);
    ~student();

private:
    std::string student_ID;
    std::string first_Name;
    std::string last_Name;
    std::string email_Address;
    int age;
    int completion[3];
    Degree programOfStudy;
};

#endif /* student_h */
