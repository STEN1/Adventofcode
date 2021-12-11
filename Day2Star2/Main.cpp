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
		int aim{};
		while (!inputFile.eof())
		{
			std::string direction{};
			int amount{};
			inputFile >> direction >> amount;
			if (direction == "forward")
			{
				horizontal += amount;
				depth += aim * amount;
			}
			if (direction == "down")
				aim += amount;
			if (direction == "up")
				aim -= amount;
		}
		std::cout << depth * horizontal;
		inputFile.close();
	}
}