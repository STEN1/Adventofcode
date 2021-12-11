#include <fstream>
#include <iostream>

int main()
{
	std::ifstream inputFile("Input.txt");
	if (inputFile.is_open())
	{
		int i{};
		int previous{};
		int current{};
		inputFile >> previous;
		while (!inputFile.eof())
		{
			inputFile >> current;
			if (current > previous)
				i++;
			previous = current;
		}
		std::cout << i;
		inputFile.close();
	}
}