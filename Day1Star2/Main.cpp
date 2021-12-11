#include <fstream>
#include <iostream>


int main()
{
	std::ifstream inputFile("Input.txt");
	if (inputFile.is_open())
	{
		int increased{};
		int window[3];
		int previous{};
		for (size_t i = 0; i < 3; i++)
		{
			inputFile >> window[i];
			previous += window[i];
		}
		int current{};
		while (!inputFile.eof())
		{
			for (size_t i = 0; i < 2; i++)
				window[i] = window[i + 1];
			inputFile >> window[2];
			current = window[0] + window[1] + window[2];
			if (current > previous)
			{
				increased++;
			}
			previous = current;
		}
		std::cout << increased;
		inputFile.close();
	}
}