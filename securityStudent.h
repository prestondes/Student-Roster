//
//  securityStudent.h
//  Class Roster
//
//  Created by Preston Desbordes on 2/24/18.
//  Copyright © 2018 Preston Desbordes. All rights reserved.
//

#include "student.h"
#ifndef securityStudent_h
#define securityStudent_h

class securityStudent : public student
{
public:
    virtual Degree getDegreeProgram();
    using student::student;

private:
    Degree myDegree = SECURITY;
};

#endif /* securityStudent_h */
