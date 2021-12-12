#include <fstream>
#include <iostream>
#include <string>
#include <vector>


uint64_t CO2Rating(std::vector<std::string> input)
{
	int bitIndex{};
	while (input.size() > 1)
	{
		int one{};
		int zero{};

		for (auto& s : input)
		{
			if (s[bitIndex] == '1')
				one++;
			else
				zero++;
		}

		int leastCommon = one < zero;

		for (auto it = input.begin(); it != input.end(); )
		{
			if (input.size() == 1)
				break;
			int bitToCompare = (*it)[bitIndex] - '0';
			if (bitToCompare != leastCommon)
				it = input.erase(it);
			else
				it++;
		}

		bitIndex++;
		if (bitIndex >= 12)
			bitIndex = 0;
	}
	return std::stoi(input[0], 0, 2);
}

uint64_t OxygenRating(std::vector<std::string> input)
{
	int bitIndex{};
	while (input.size() > 1)
	{
		int one{};
		int zero{};

		for (auto& s : input)
		{
			if (s[bitIndex] == '1')
				one++;
			else if (s[bitIndex] == '0')
				zero++;
		}

		int mostCommon = one >= zero;

		for (auto it = input.begin(); it != input.end(); )
		{
			if (input.size() == 1)
				break;
			int bitToCompare = (*it)[bitIndex] - '0';
			if (bitToCompare != mostCommon)
				it = input.erase(it);
			else
				it++;
		}

		bitIndex++;
		if (bitIndex >= 12)
			bitIndex = 0;
	}

	return std::stoi(input[0], 0, 2);
}

int main()
{
	std::ifstream inputFile("Input.txt");
	std::vector<std::string> input;
	if (inputFile.is_open())
	{
		while (!inputFile.eof())
		{
			std::string s;
			inputFile >> s;
			input.push_back(s);
		}
		inputFile.close();
	}

	std::cout << OxygenRating(input) * CO2Rating(input);
}