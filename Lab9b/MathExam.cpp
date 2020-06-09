///* Solution Includes */
//#include "MathExam.h"
//#include "Exception.h"
//
///* System Includes */
//#include <iomanip>
//#include <fstream>
//
///* ************************************************ */
///* ************** Already Implemented ************* */
//
//MathExam::MathExam(std::string filename)
//{
//    std::ifstream expressionFile(filename, std::ios::in);
//	
//    int arg_1; int arg_2; char sign;
//	
//    while (expressionFile.eof() == false)
//    {
//        expressionFile >> arg_1 >> sign >> arg_2;
//	
//        switch (sign)
//        {
//            case '+':
//            {
//                this->m_Expressions.push_back(new Addition(arg_1, arg_2)); break;
//            }
//            case '-':
//            {
//                this->m_Expressions.push_back(new Subtraction(arg_1, arg_2)); break;
//            }
//            case '*':
//            {
//                this->m_Expressions.push_back(new Multiplication(arg_1, arg_2)); break;
//            }
//            case '/':
//            {
//                this->m_Expressions.push_back(new Division(arg_1, arg_2)); break;
//            }
//        }
//    }
//}
//
///* ************************************************ */
///* ******************** Stage_2 ******************* */
//
//MathExam::~MathExam()
//{
//    for (auto it = m_Expressions.begin(); it != m_Expressions.end(); it++)
//        delete *it;
//}
//
///* ************************************************ */
///* ******************** Stage_2 ******************* */
//
//std::vector<double> MathExam::Answers()
//{
//    std::vector<double> results;
//    for (auto i : m_Expressions)
//        results.push_back(i->Result());
//    return results;
//}
//
///* ************************************************ */
///* ******************** Stage_3 ******************* */
//
//MathExam::MathExam(std::vector<char> signs, std::vector<double> values)
//{
//    for (int i = 0; i < signs.size(); i++)
//    {
//        char sign = signs[i];
//        double arg_1 = values[2*i];
//        double arg_2 = values[2*i+1];
//
//        switch (sign)
//        {
//        case '+':
//        {
//            this->m_Expressions.push_back(new Addition(arg_1, arg_2)); break;
//        }
//        case '-':
//        {
//            this->m_Expressions.push_back(new Subtraction(arg_1, arg_2)); break;
//        }
//        case '*':
//        {
//            this->m_Expressions.push_back(new Multiplication(arg_1, arg_2)); break;
//        }
//        case '/':
//        {
//            this->m_Expressions.push_back(new Division(arg_1, arg_2)); break;
//        }
//        }
//    }
//}
//
//
///* ************************************************ */
///* ******************** Stage_3 ******************* */
//
//void MathExam::Solve()
//{
//    int correct = 0;
//    for (int i = 0; i < m_Expressions.size(); i++)
//    {
//        double input;
//        std::cout << *(m_Expressions[i]);
//        std::cin >> input;
//        if (input == m_Expressions[i]->Result()) correct++;
//        std::cout << std::endl;
//    }
//    std::cout << std::endl;
//    std::cout << "You Got " << correct << " Out Of 4 Right Answers" << std::endl;
//}
//
///* ************************************************ */
