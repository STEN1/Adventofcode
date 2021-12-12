#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::ifstream inputFile("Input.txt");
	if (inputFile.is_open())
	{
		int one[12] = {};
		int zero[12] = {};
		while (!inputFile.eof())
		{
			std::string bits;
			inputFile >> bits;
			for (size_t i = 0; i < bits.size(); i++)
			{
				if (bits[i] == '1')
					one[i]++;
				if (bits[i] == '0')
					zero[i]++;
			}
		}

		std::string gamma = "000000000000";
		std::string epsilon = "000000000000";

		for (size_t i = 0; i < 12; i++)
		{
			if (one[i] > zero[i])
			{
				gamma[i] = '1';
			}
			else
			{
				epsilon[i] = '1';
			}
		}

		std::cout << std::stoi(gamma, 0, 2) * std::stoi(epsilon, 0, 2);

		inputFile.close();
	}
}