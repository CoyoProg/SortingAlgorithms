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

/** Warper Function for Quick Sort */
void SortAlgorithm::QuickSort(std::vector<int>& listToSortP)
{
	std::cout << "~~~~~ Sorting ~~~~~~" << std::endl;

	int pivot = listToSortP.size() - 1;
	int firstIndex = 0;

	QuickSort(listToSortP, firstIndex, pivot);

	ShowResult(listToSortP);
}

/** Divide the list in two list */
void SortAlgorithm::QuickSort(std::vector<int>& listToSortP, int firstIndexP, int lastIndexP)
{
	if (firstIndexP < lastIndexP)
	{
		// Partition the array into two sub-arrays
		int divideIndex = QuickSortPartition(listToSortP, firstIndexP, lastIndexP);

		// Recursively sort into 2 sub-arrays
		QuickSort(listToSortP, firstIndexP, divideIndex - 1);
		QuickSort(listToSortP, divideIndex, lastIndexP);
	}
}

int SortAlgorithm::QuickSortPartition(std::vector<int>& listToSortP, int firstIndexP, int lastIndexP)
{
	int pivot = lastIndexP;				// Pivot is the value of the last element
	int lastIndex = lastIndexP;
	bool nothingHappened = true;

	for (int i = 0; i < pivot;)
	{
		// If the current element is bigger than the pivot
		if (listToSortP[i] > listToSortP[pivot])
		{
			/** We save the value before moving the values */
			int temporary = listToSortP[i];

			/** Then we assign the current element to the value before the pivot */
			listToSortP[i] = listToSortP[pivot - 1];

			/** And assign the element before the pivot to the value of the pivot */
			listToSortP[pivot - 1] = listToSortP[pivot];

			/** And finaly assign the value of the pivot to the temporary value, 
				We moved the current value to the right of the pivot,
				Moved the value before the pivot where was the current value,
				And move the pivot one time to the left */ 

			listToSortP[pivot] = temporary;
			pivot -= 1;

			nothingHappened = false;



			// WE COULD JUST USE ROTATE BUT I CANT FIGURE OUT HOW TO MAKE IT WORK WHEN PIVOT > i ;
			/** We move the lower value after the pivot */
			//std::rotate(listToSortP.begin() + i, listToSortP.begin() + i + 1, listToSortP.begin() + pivot + 1);

			//pivot--;

			/** And we move the value before the pivot where the lower value was */
			//std::rotate(listToSortP.begin() + i, listToSortP.begin() + pivot, listToSortP.begin() + pivot + 1);
		}
		else
			i++;
	}

	if (!nothingHappened)
	{
		for (int num : listToSortP)
		{
			std::cout << num << " ";
		}

		std::cout << std::endl;
	}

	return (pivot);
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
