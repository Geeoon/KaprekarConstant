#include <iostream>
#include <algorithm>
#include <vector>

int iteration(int num, int numDigits, int i) {
	std::vector<int>* digitList;  // creating as a pointer to delete later
	digitList = new std::vector<int>;
	for (int i = numDigits; i > 0; i--) {  // stores it into the vector
		digitList->push_back((num / static_cast<int>(pow(10, i - 1))) % 10);
	}
	
	std::sort(digitList->begin(), digitList->end());  // sort in ascending order

	int descending{ 0 };
	for (int i = 0; i < numDigits; i++) {
		descending += (*digitList)[i] * static_cast<int>(pow(10, i));
	}

	int ascending{ 0 };
	for (int i = 0; i < numDigits; i++) {
		ascending += (*digitList)[i] * static_cast<int>(pow(10, numDigits - i - 1));
	}

	digitList->clear();
	delete digitList;  // clear memory to conserve resources

	int out{ descending - ascending };
	//std::cout << "Iteration " << i << ": " << out << std::endl;
	if (out == num) {  // base case.  This is almost the same as out == 6174; however, this method prevents infinite loops with 0
		return i;  // return the number of iterations
	} else {
		return iteration(out, 4, i + 1);  // call itself with new value and i + 1
	}
}

int main() {
	constexpr int digits{ 6 };
	int number{ 0 };
	/*
	int max{ 0 };
	int maxI{ 0 };
	for (int i = 1; i < pow(10, digits); i++) {
		int iterations{ iteration(i, digits, 1) };
		if (iterations > max) {
			maxI = iterations;
			max = i;
		}
	}
	std::cout << "The " << digits << " digit number that took the most iterations is " << max << " with " << maxI << " iterations.";
	*/
	while (true) {
		// user input
		std::cout << "Enter a " << digits << " digit number: ";
		std::cin >> number;
		while (number < 1 || number > static_cast<int>(pow(10, digits) - 1)) {
			std::cout << "Invalid input.  Enter a " << digits << " digit number: ";
			std::cin >> number;
		}

		// run the recursive function.
		std::cout << "It took " << iteration(number, digits, 1) << " iterations." << std::endl;
	}
	int test{ 0 };
	std::cin >> test;
	return 0;
}