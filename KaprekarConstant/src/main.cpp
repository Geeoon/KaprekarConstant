#include <iostream>
#include <algorithm>
#include <vector>

int iteration(int num, int numDigits, int i) {
	std::vector<int>* digitList;
	digitList = new std::vector<int>;
	for (int i = numDigits; i > 0; i--) {  // stores it in order.
		digitList->push_back((num / static_cast<int>(pow(10, i - 1))) % 10);
	}
	
	std::sort(digitList->begin(), digitList->end());

	int descending{ 0 };
	for (int i = 0; i < numDigits; i++) {
		descending += (*digitList)[i] * static_cast<int>(pow(10, i));
	}

	int ascending{ 0 };
	for (int i = 0; i < numDigits; i++) {
		ascending += (*digitList)[i] * static_cast<int>(pow(10, numDigits - i - 1));
	}

	digitList->clear();
	delete digitList;

	int out{ descending - ascending };
	std::cout << "Iteration " << i << ": " << out << std::endl;
	if (out == num) {
		return i;
	} else {
		return iteration(out, 4, i + 1);
	}
}

int main() {
	constexpr int digits{ 8 };
	while (true) {
		// user input
		int number{ 0 };
		std::cout << "Enter a " << digits << " digit number: ";
		std::cin >> number;
		while (number < 1 || number > static_cast<int>(pow(10, digits) - 1)) {
			std::cout << "Invalid input.  Enter a 4 digit number: ";
			std::cin >> number;
		}

		// run the recursive function.
		std::cout << "It took " << iteration(number, digits, 1) << " iterations." << std::endl;
	}
	return 0;
}
