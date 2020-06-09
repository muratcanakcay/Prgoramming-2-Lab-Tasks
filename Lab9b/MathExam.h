#ifndef MATH_EXAM_HEADER
#define MATH_EXAM_HEADER

/* System Includes */
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>

/* Solution Includes */
#include "Expression.h"

/* NO 'USING NAMESPACE STD' USAGE */

/* ************************************************ */

template <typename T>
class MathExam
{
    std::vector<Expression<T>*> m_Expressions;

public:

    MathExam(std::string filename);
	
	MathExam(std::vector<char> signs, std::vector<T> values);

    ~MathExam();
	
	std::vector<T> Answers(); void Solve();
};

/* ************************************************ */
template <typename T>
MathExam<T>::MathExam(std::string filename)
{
    std::ifstream expressionFile(filename, std::ios::in);

    T arg_1; T arg_2; char sign;

    while (expressionFile.eof() == false)
    {
        expressionFile >> arg_1 >> sign >> arg_2;

        switch (sign)
        {
        case '+':
        {
            this->m_Expressions.push_back(new Addition<T>(arg_1, arg_2)); break;
        }
        case '-':
        {
            this->m_Expressions.push_back(new Subtraction<T>(arg_1, arg_2)); break;
        }
        case '*':
        {
            this->m_Expressions.push_back(new Multiplication<T>(arg_1, arg_2)); break;
        }
        case '/':
        {
            this->m_Expressions.push_back(new Division<T>(arg_1, arg_2)); break;
        }
        }
    }
}

/* ************************************************ */
/* ******************** Stage_2 ******************* */

template <typename T>
MathExam<T>::~MathExam()
{
    for (auto it = m_Expressions.begin(); it != m_Expressions.end(); it++)
        delete* it;
}

/* ************************************************ */
/* ******************** Stage_2 ******************* */
template <typename T>
std::vector<T> MathExam<T>::Answers()
{
    std::vector<T> results;
    for (auto i : m_Expressions)
        results.push_back(i->Result());
    return results;
}

/* ************************************************ */
/* ******************** Stage_3 ******************* */
template <typename T>
MathExam<T>::MathExam(std::vector<char> signs, std::vector<T> values)
{
    for (int i = 0; i < signs.size(); i++)
    {
        char sign = signs[i];
        T arg_1 = values[2 * i];
        T arg_2 = values[2 * i + 1];

        switch (sign)
        {
        case '+':
        {
            this->m_Expressions.push_back(new Addition<T>(arg_1, arg_2)); break;
        }
        case '-':
        {
            this->m_Expressions.push_back(new Subtraction<T>(arg_1, arg_2)); break;
        }
        case '*':
        {
            this->m_Expressions.push_back(new Multiplication<T>(arg_1, arg_2)); break;
        }
        case '/':
        {
            this->m_Expressions.push_back(new Division<T>(arg_1, arg_2)); break;
        }
        }
    }
}


/* ************************************************ */
/* ******************** Stage_3 ******************* */
template <typename T>
void MathExam<T>::Solve()
{
    int correct = 0;
    for (int i = 0; i < m_Expressions.size(); i++)
    {
        T input;
        std::cout << *(m_Expressions[i]);
        std::cin >> input;
        if (input == m_Expressions[i]->Result()) correct++;
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "You Got " << correct << " Out Of 4 Right Answers" << std::endl;
}






#endif /* MATH_EXAM_HEADER */
