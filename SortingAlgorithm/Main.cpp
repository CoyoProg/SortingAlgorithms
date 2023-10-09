#include <iostream>
#include "SortAlgorithm.h"

void ChooseAlgorithm();

void GenerateRandomVector(std::vector<int>& vec);

#define clearConsole std::cout << "\x1B[2J\x1B[H";

int main()
{
	srand(time(NULL));

	ChooseAlgorithm();

	return 0;
}

void ChooseAlgorithm()
{
	int choice = 0;

	std::cout << "Choose your sorting "
		<< "\033[33mAlgorithm\033[37m"
		<< ":\n"
		<< "\t *1 Bubble Sort \n"
		<< "\t *2 Selection Sort \n"
		<< "\t *3 Quick Sort \n";

	std::cout << "\033[36mYour Choice: ";

	bool isValid = false;

	while (!isValid)
	{
		if (std::cin >> choice && choice > 0 && choice < 4)
		{
			isValid = true;
		}
		else
		{
			// Input is not an integer, clear error flags and ignore invalid input
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please enter an integer between 1 and 3." << std::endl;
		}
	}

	clearConsole;

	std::cout << "\033[33m";


	/** Initialize vector to sort*/
	std::vector<int> vec;
	GenerateRandomVector(vec);

	/** Depending on choice, run the Algorithm to sort the vector */
	switch (choice)
	{
	case 1:
		SortAlgorithm::BubbleSort(vec);
		break;
	case 2:
		SortAlgorithm::SelectionSort(vec);
		break;
	case 3:
		SortAlgorithm::QuickSort(vec);
		break;
	case 4:
		break;
	}
	std::cout << std::endl;
	std::cout << "Return to menu ?... \n";
	system("pause"); // Pause the console on Windows

	clearConsole;
	ChooseAlgorithm();
}

void GenerateRandomVector(std::vector<int>& vec)
{
	int listSize = 6 + rand() % 5;
	for (int i = 0; i < listSize; i++)
	{
		vec.push_back(rand() % 100);
	}


	std::cout << "Original vector: ";
	for (int num : vec)						// Print the original vector
	{
		std::cout << num << " ";
	}
	std::cout << "\033[37m";
	std::cout << std::endl;
}
