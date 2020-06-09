#ifndef EXCEPTION_HEADER
#define EXCEPTION_HEADER

/* System Includes */
#include <iostream>
#include <exception>

/* NO 'USING NAMESPACE STD' USAGE */

/* ************************************************ */
/* ************** Already Implemented ************* */

class UnknownExpression : public std::exception
{
public:

    virtual const char* what() const override
    {
        std::cout << "Undefined Expression Type" << std::endl; return "";
    }
};

/* ************************************************ */
/* ******************** Stage_5 ******************* */

class DivisonByZero : public UnknownExpression
{
public:

    virtual const char* what() const override
    {
        std::cout << "Division By Zero Exception" << std::endl; return "";
    }
};

/* ************************************************ */

#endif /* EXCEPTION_HEADER */
