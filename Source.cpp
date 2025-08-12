#include <iostream>
#include <vector>

int main()
{
	std::vector<int> arr;
	int tmp;
	while (std::cin >> tmp)
	{
		arr.push_back(tmp);
	}

	std::vector <int> evens;
	for (int x : arr)
	{
		if (x % 2 == 0)
		{
			evens.push_back(x);
		}
	}

	for (size_t i = 1; i < evens.size(); ++i)
	{
		int key = evens[i];
		int j = i - 1;
		while (j >= 0 && evens[j] > key)
		{
			evens[j + 1] = evens[j];
			--j;
		}

		evens[j + 1] = key;
	}

	size_t evenindex = 0;
	for (int& x : arr)
	{
		if (x % 2 == 0)
		{
			x = evens[evenindex++];
		}
	}

	for (int x : arr)
	{
		std::cout << x << " ";
	}

	return 0;
}