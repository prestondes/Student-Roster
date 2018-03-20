//
//  networkStudent.h
//  Class Roster
//
//  Created by Preston Desbordes on 2/24/18.
//  Copyright © 2018 Preston Desbordes. All rights reserved.
//

#include "student.h"
#ifndef networkStudent_h
#define networkStudent_h

class networkStudent : public student
{
public:
    virtual Degree getDegreeProgram();
    using student::student;

private:
    Degree myDegree = NETWORKING;
};

#endif /* networkStudent_h */
