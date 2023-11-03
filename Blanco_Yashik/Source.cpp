#include <iostream>
#include <cmath>
#include <iomanip>

double task(double* arr, int n)
{
	double s = 0;

	int max = 0, min = arr[0], maxid = 0, minid = 0;

	for (int i = 0; i < n; i++)
		if (arr[i] > max)
		{
			max = arr[i];

			maxid = i;
		}

	for (int i = 0; i < n; i++)
		if (arr[i] < min)
		{
			min = arr[i];

			minid = i;
		}

	if (maxid > minid)
	{
		for (int i = minid + 1; i < maxid; i++)
			s += arr[i];
	}
	else
	{
		for (int i = maxid + 1; i < minid; i++)
			s += arr[i];
	}

	return s;

}

double checkelem(int n)
{
	double elem;

	std::cout << "Type element: ";

	while (true)
	{
		try
		{
			if (!(std::cin >> elem))
			{
				std::cin.clear();

				while (std::cin.get() != '\n');

				throw "element is non digit!";
			}
			else
				break;
		}

		catch (const char* exception)
		{
			std::cout << exception << '\n';

			std::cout << "Type new element: ";
		}
	}
	return elem;
}


int sizechecker(int n)
{
	while (true)
	{
		try
		{
			if (!(std::cin >> n)) // проверка на букву или спец.символы
			{
				std::cin.clear();

				while (std::cin.get() != '\n');

				throw "Size is non digit!";
			}
			else
				if (n <= 0 || n > 10)
					throw "Size is out of range!";
				else
					break;

		}

		catch (const char* exception)
		{
			std::cout << exception << '\n';

			std::cout << "Type new size: ";
		}
	}
	return n;
}

int main()
{
	int n = 0;

	double t;

	std::cout << "Type size of the array: ";

	n = sizechecker(n);

	double* arr = new double[n];

	for (int i = 0; i < n; i++)
		arr[i] = checkelem(n);

	t = task(arr, n);

	std::cout << "Sum = " << t;

	delete[] arr;
	return 0;
}
