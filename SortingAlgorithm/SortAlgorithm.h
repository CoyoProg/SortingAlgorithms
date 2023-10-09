#pragma once
#include <vector>

class SortAlgorithm
{
public:
	static void BubbleSort(std::vector<int>& listToSortP);
	static void SelectionSort(std::vector<int>& listToSortP);
	static void QuickSort(std::vector<int>& listToSortP);

private:
	static void ShowResult(std::vector<int>& listToSortP);
	static void QuickSort(std::vector<int>& listToSortP, int firstIndexP, int lastIndexP);
	static int QuickSortPartition(std::vector<int>& listToSortP, int firstIndexP, int lastIndexP);
};

