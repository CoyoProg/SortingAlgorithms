#include "SortAlgorithm.h"
#include <iostream>

void SortAlgorithm::BubbleSort(std::vector<int>& listToSortP)
{
	std::cout << "~~~~~ Sorting ~~~~~~" << std::endl;

	bool swapped;
	int vectorSize = listToSortP.size();

	for (int i = 0; i < vectorSize - 1; i++)
	{
		swapped = false;

		/** We Loop check if the value of listToSortP[j] is higher than listToSortP[j + 1] */
		for (int j = 0; j < vectorSize - i - 1; j++)
		{
			if (listToSortP[j] > listToSortP[j + 1])
			{
				/** And Swap them if its true */
				std::swap(listToSortP[j], listToSortP[j + 1]);

				for (int num : listToSortP)
				{
					std::cout << num << " ";
				}

				std::cout << std::endl;

				swapped = true;
			}
		}

		/** If swapped is still false, then the list is already sorted */
		if (!swapped)
		{
			ShowResult(listToSortP);
			break;
		}
	}
}

void SortAlgorithm::SelectionSort(std::vector<int>& listToSortP)
{
	std::cout << "~~~~~ Sorting ~~~~~~" << std::endl;

	int vectorSize = listToSortP.size();

	/** We Loop check if any value is lower than the value of listToSortP[i] */
	for (int i = 0; i < vectorSize - 1; i++)
	{
		int minIndex = i;

		for (int j = i + 1; j < vectorSize; j++)
		{
			if (listToSortP[j] < listToSortP[minIndex])
			{
				minIndex = j;
			}
		}

		if (minIndex != i)
		{
			/** And Swap the new lowest value with listToSortP[i] */
			std::swap(listToSortP[i], listToSortP[minIndex]);

			for (int num : listToSortP)
			{
				std::cout << num << " ";
			}

			std::cout << "\033[33m";
			std::cout << "\t swapped " << listToSortP[i] << " and " << listToSortP[minIndex];
			std::cout << "\033[37m";
			std::cout << std::endl;
		}
	}

	ShowResult(listToSortP);
}

void SortAlgorithm::QuickSort(std::vector<int>& listToSortP)
{
}


void SortAlgorithm::ShowResult(std::vector<int>& listToSortP)
{
	std::cout << "~~~~~ Sorting ~~~~~~" << std::endl;

	std::cout << "\033[33m";
	std::cout << "Sorted vector: ";
	for (int num : listToSortP)
	{
		std::cout << num << " ";
	}
	std::cout << "\033[37m";
	std::cout << std::endl;
}
