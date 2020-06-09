///* Solution Includes */
//#include "Expression.h"
//#include "Exception.h"
//
///* ************************************************ */
///* ************** Already Implemented ************* */
//
//Expression::Expression(double arg_1, double arg_2, char expressionSign)
//    : m_Argument_1(arg_1), m_Argument_2(arg_2), m_ExpressionSign(expressionSign) { }
//
//
///* ************************************************ */
///* ******************** Stage_1 ******************* */
//
//Addition::Addition(double arg1, double arg2) : Expression(arg1, arg2, '+')
//{    
//}
//
//double Addition::Result() const
//{
//    return m_Argument_1 + m_Argument_2;
//}
//
///* ************************************************ */
///* ******************** Stage_1 ******************* */
//
//Subtraction::Subtraction(double arg1, double arg2) : Expression(arg1, arg2, '-')
//{
//}
//
//double Subtraction::Result() const
//{
//    return m_Argument_1 - m_Argument_2;
//}
//
///* ************************************************ */
///* ******************** Stage_1 ******************* */
//
//Multiplication::Multiplication(double arg1, double arg2) : Expression(arg1, arg2, '*')
//{
//}
//
//double Multiplication::Result() const
//{
//    return m_Argument_1 * m_Argument_2;
//}
//
//
///* ************************************************ */
///* ******************** Stage_1 ******************* */
//
//Division::Division(double arg1, double arg2) : Expression(arg1, arg2, '/')
//{
//}
//
//double Division::Result() const
//{
//    if (m_Argument_2 == 0) throw DivisonByZero();
//    return m_Argument_1 / m_Argument_2;
//}
//
//
///* ************************************************ */
//
//void Expression::Print(std::ostream& out) const
//{
//    out << m_Argument_1 << " " << m_ExpressionSign << " " << m_Argument_2 << " = ";
//}
//
//std::ostream& operator << (std::ostream& out, const Expression& expression)
//{
//    expression.Print(out);
//    return out;
//}