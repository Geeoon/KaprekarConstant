#include <iostream>
#include <algorithm>
#include <vector>

int iteration(int num, int numDigits, int i) {
	std::vector<int> digitList;
	for (int i = numDigits; i > 0; i--) {  // stores it in order.
		digitList.push_back((num / static_cast<int>(pow(10, i - 1))) % 10);
	}
	
	std::sort(digitList.begin(), digitList.end());

	int descending{ 0 };
	for (int i = 0; i < numDigits; i++) {
		descending += digitList[i] * static_cast<int>(pow(10, i));
	}

	int ascending{ 0 };
	for (int i = 0; i < numDigits; i++) {
		ascending += digitList[i] * static_cast<int>(pow(10, numDigits - i - 1));
	}

	int out{ descending - ascending };
	if (out == 6174) {
		return i + 1;
	} else {
		return iteration(out, 4, i + 1);
	}
}

int main() {
	// user input
	int number{ 0 };
	std::cout << "Enter a 4 digit number: ";
	std::cin >> number;
	while (number < 1 || number > 9999) {
		std::cout << "Invalid input.  Enter a 4 digit number: ";
		std::cin >> number;
	}

	// run the recursive function.
	std::cout << "It took " << iteration(number, 4, 0) << " iterations.";
	std::cin >> number;

	return 0;
}
