#include <fstream>
#include <iostream>
#include <string>


int main()
{
	std::ifstream inputFile("Input.txt");
	if (inputFile.is_open())
	{
		int depth{};
		int horizontal{};
		while (!inputFile.eof())
		{
			std::string direction{};
			int amount{};
			inputFile >> direction >> amount;
			if (direction == "forward")
				horizontal += amount;
			if (direction == "down")
				depth += amount;
			if (direction == "up")
				depth -= amount;
		}
		std::cout << depth * horizontal;
		inputFile.close();
	}
}