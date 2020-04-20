#include "FloatNumber.h"

#include <iostream>

int main(int argc, char** argv)
{
	std::cout << std::endl << "---------------------------   STAGE_1 (2Pts)   --------------------------" << std::endl << std::endl;

	const int floatCount = 7;

	FloatNumber floatNumbers1[] =
	{
		FloatNumber(),
		FloatNumber(2),
		FloatNumber(4,99),
		FloatNumber(13,7),
		FloatNumber(2.25f),
		FloatNumber(7.05f),
		FloatNumber(3.999f)
	};

	for (int i = 0; i < floatCount; i++)
	{
		std::cout << "Float Number: "; floatNumbers1[i].WriteToConsole();
		std::cout << std::endl;
	}

	std::cout << std::endl << "---------------------------   STAGE_2 (1Pts)   --------------------------" << std::endl << std::endl;

	FloatNumber float1;
	float1.ReadFromConsole();

	std::cout << "Your Float Number: "; float1.WriteToConsole();
	std::cout << std::endl;

	std::cout << std::endl << "---------------------------   STAGE_3 (1Pts)   --------------------------" << std::endl << std::endl;

	FloatNumber float2(14.76f); FloatNumber float3(2.18f); FloatNumber float4(14.76f);

	bool float23Equal = float2.Equals(float3);
	bool float24Equal = float2.Equals(float4);

	std::cout << "Float Number :"; float2.WriteToConsole(); std::cout << (float23Equal ? " Equals" : " Not Equals") << " To Float Number: "; float3.WriteToConsole(); std::cout << std::endl;
	std::cout << "Float Number :"; float2.WriteToConsole(); std::cout << (float24Equal ? " Equals" : " Not Equals") << " To Float Number: "; float4.WriteToConsole(); std::cout << std::endl;

	std::cout << std::endl << "---------------------------   STAGE_4 (1Pts)   --------------------------" << std::endl << std::endl;

	FloatNumber floatNumbers2[] =
	{
		FloatNumber(0,035),
		FloatNumber(7),
		FloatNumber(4,99),
		FloatNumber(13,995),
		FloatNumber(18.001f),
		FloatNumber(2.95f),
		FloatNumber(9.999f)
	};

	for (int i = 0; i < floatCount; i++)
	{
		std::cout << "Adds Float Numbers: "; floatNumbers1[i].WriteToConsole();
		std::cout << " To Float Number: "; floatNumbers2[i].WriteToConsole();
		std::cout << " With Result: "; (floatNumbers1[i] + floatNumbers2[i]).WriteToConsole();

		std::cout << std::endl;
	}

	std::cout << std::endl << "---------------------------   STAGE_5 (1Pts)   --------------------------" << std::endl << std::endl;

	FloatNumber floatString1("4.550"); FloatNumber floatString2("64.080");

	std::cout << "Float Number From String: "; floatString1.WriteToConsole(); std::cout << std::endl;
	std::cout << "Float Number From String: "; floatString2.WriteToConsole(); std::cout << std::endl;

	return 0;
}
