#ifndef OPERATION_HEADER
#define OPERATION_HEADER

/* System Includes */
#include <string>
#include <iostream>

#include "Exception.h"

/* NO 'USING NAMESPACE STD' USAGE */

/* ************************************************ */
/* ************** Already Implemented ************* */

template <typename T>
class Expression
{
protected: 
    
    char m_ExpressionSign; /* Represents Expression's Sign ('+','-','*','/') */

    T m_Argument_1; /* Represents L Argument */
	T m_Argument_2; /* Represents R Argument */

public: Expression(T arg_1, T arg_2, char expressionSign);

    virtual T Result() const = 0;

    virtual void Print(std::ostream& out) const;

    friend std::ostream& operator << (std::ostream& out, const Expression<T>& expression);
};

template <typename T>
Expression<T>::Expression(T arg_1, T arg_2, char expressionSign)
    : m_Argument_1(arg_1), m_Argument_2(arg_2), m_ExpressionSign(expressionSign) { }

template <typename T>
class Addition : public Expression<T>
{
public:
    Addition(T arg1, T arg2);
    T Result() const;
};

template <typename T>
class Subtraction : public Expression<T>
{
public:
    Subtraction(T arg1, T arg2);
    T Result() const;
};

template <typename T>
class Multiplication : public Expression<T>
{
public:
    Multiplication(T arg1, T arg2);
    T Result() const;
};

template <typename T>
class Division : public Expression<T>
{
public:
    Division(T arg1, T arg2);
    T Result() const;
};

template <typename T>
Addition<T>::Addition(T arg1, T arg2) : Expression<T>(arg1, arg2, '+')
{
}

template <typename T>
T Addition<T>::Result() const
{
    return m_Argument_1 + m_Argument_2;
}

template <typename T>
Subtraction<T>::Subtraction(T arg1, T arg2) : Expression<T>(arg1, arg2, '-')
{
}

template <typename T>
T Subtraction<T>::Result() const
{
    return m_Argument_1 - m_Argument_2;
}

template <typename T>
Multiplication<T>::Multiplication(T arg1, T arg2) : Expression<T>(arg1, arg2, '*')
{
}

template <typename T>
T Multiplication<T>::Result() const
{
    return m_Argument_1 * m_Argument_2;
}

template <typename T>
Division<T>::Division(T arg1, T arg2) : Expression<T>(arg1, arg2, '/')
{
}

template <typename T>
T Division<T>::Result() const
{
    if (m_Argument_2 == 0) throw DivisonByZero();
    return m_Argument_1 / m_Argument_2;
}

template <typename T>
void Expression<T>::Print(std::ostream& out) const
{
    out << m_Argument_1 << " " << m_ExpressionSign << " " << m_Argument_2 << " = ";
}

template <typename T>
std::ostream& operator << (std::ostream& out, const Expression<T>& expression)
{
    expression.Print(out);
    return out;
}

#endif /* OPERATION_HEADER */
