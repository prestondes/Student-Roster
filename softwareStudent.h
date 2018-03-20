//
//  softwareStudent.h
//  Class Roster
//
//  Created by Preston Desbordes on 2/24/18.
//  Copyright © 2018 Preston Desbordes. All rights reserved.
//

#include "student.h"
#ifndef softwareStudent_h
#define softwareStudent_h

class softwareStudent : public student
{
public:
    virtual Degree getDegreeProgram();
    using student::student;

private:
    Degree myDegree = SOFTWARE;
};

#endif /* softwareStudent_h */
