/* System Includes */
#include <iostream>
#include <iomanip>
#include <complex>

/* Solution Includes */
#include "MathExam.h"
#include "Exception.h"


/* NO 'USING NAMESPACE STD' USAGE */

int main(int argc, char** argv)
{
	/*std::cout << "--------------------- Stage_1 (2.0 Pts) ---------------------" << std::endl;

	{
		Addition A2(1, 1), A3(4, 7);
		Subtraction S2(5, 1), S3(2, 7);
		Multiplication M2(1, 5), M4(3, 9);
		Division D2(4, 2), D4(9, 2);

		std::cout << "A2: " << A2 << " = " << std::setw(2) << A2.Result() << std::endl;
		std::cout << "A3: " << A3 << " = " << std::setw(2) << A3.Result() << std::endl;
		std::cout << "S2: " << S2 << " = " << std::setw(2) << S2.Result() << std::endl;
		std::cout << "S3: " << S3 << " = " << std::setw(2) << S3.Result() << std::endl;
		std::cout << "M2: " << M2 << " = " << std::setw(2) << M2.Result() << std::endl;
		std::cout << "M4: " << M4 << " = " << std::setw(2) << M4.Result() << std::endl;
		std::cout << "D2: " << D2 << " = " << std::setw(2) << D2.Result() << std::endl;
		std::cout << "D4: " << D4 << " = " << std::setw(2) << D4.Result() << std::endl;
	}

	std::cout << "--------------------- Stage_2 (1.0 Pts) ---------------------" << std::endl;

	{
		MathExam mathExam("Expressions.txt"); auto result = mathExam.Answers();
	
		for (int i = 0; i < result.size(); i++)
			std::cout << "Expression # " << i << " Value: " << result[i] << std::endl;
	}

	std::cout << "--------------------- Stage_3 (2.0 Pts) ---------------------" << std::endl;

	{
		MathExam mathExam({ '+','*','-','/' }, { 1,2,2,3,4,1,6,2 });
	
		mathExam.Solve(); std::cout << std::endl;
	}*/

	std::cout << "--------------------- Stage_4 (2.0 Pts) ---------------------" << std::endl;

	{
		Addition<int> A2(1, 1), A3(4, 7);
		Multiplication<int> M2(1, 5), M4(3, 9);
		Addition<float> A4(2.4f, 1.4f), A5(1.0f, 2.0f);
		Division<float> D2(4.0f, 2.0f), D4(9.0f, 2.0f);
		Addition<std::complex<double>> A6({ 2.9,1.3 }, { 7.4,9.0 });
		Subtraction<std::complex<double>> S2({ 5.4,2.0 }, { 1.1,4.0 });
	
		std::cout << "A2: " << A2 << " = " << std::setw(2) << A2.Result() << std::endl;
		std::cout << "A3: " << A3 << " = " << std::setw(2) << A3.Result() << std::endl;
		std::cout << "M2: " << M2 << " = " << std::setw(2) << M2.Result() << std::endl;
		std::cout << "M4: " << M4 << " = " << std::setw(2) << M4.Result() << std::endl;
		std::cout << "A5: " << A5 << " = " << std::setw(2) << A5.Result() << std::endl;
		std::cout << "D2: " << D2 << " = " << std::setw(2) << D2.Result() << std::endl;
		std::cout << "D4: " << D4 << " = " << std::setw(2) << D4.Result() << std::endl;
		std::cout << "A4: " << A4 << " = " << std::setw(2) << A4.Result() << std::endl;
		std::cout << "S3: " << A6 << " = " << std::setw(2) << A6.Result() << std::endl;
		std::cout << "S2: " << S2 << " = " << std::setw(2) << S2.Result() << std::endl;
	
		std::cout << std::endl;
	
		MathExam<int> mathExam_1("Expressions.txt"); auto result = mathExam_1.Answers();
	
		for (int i = 0; i < result.size(); i++)
			std::cout << "Expression # " << i << " Value: " << result[i] << std::endl;
	
		std::cout << std::endl;
	
		MathExam<float> mathExam_2({ '+','*','-','/' }, { 1.4f,2.1f,2.9f,3.0f,4.4f,1.3f,6.7f,2.7f });
	
		mathExam_2.Solve(); std::cout << std::endl;
	}

	std::cout << "--------------------- Stage_5 (1.0 Pts) ---------------------" << std::endl;

	{
		Division<int> D3(4, 0), D5(9, 2);
	
		try
		{
			std::cout << "D5: " << D5 << " = " << std::setw(2) << D5.Result() << std::endl;
			std::cout << "D3: " << D3 << " = " << std::setw(2) << D3.Result() << std::endl;
		}
		catch (UnknownExpression &exceotion)
		{
			std::cout << exceotion.what() << std::endl;
		}
	}

	return 0;
}
