// Learning C++.
// Simple Calculater (+, -, /, *, ^, < (Root))
// Game Audio Programmer (Nikita Kvitka)


// TO-DO clear previous lines!!!
// Ignore 'Enter' to make input format line 2 + 2 = 4

#include <iostream>
#include <string>
#include <cstddef>
#include <chrono>
#include <thread>



void ErrorInputMsg() {
	std::cout << "Please, use only 'a <symbol> b' input format!\n";
	std::cin.clear();
	std::cin.ignore(100000, '\n');
}

//void DelayInSeconds(const int& a)
//{
//	std::this_thread::sleep_for(std::chrono::seconds{a});
//}

//void EraseLines(const int& a) {
//	if (a > 0) {
//		std::cout << "\x1b[2K";                                 // Delete current line
//		for (int i = 1; i < a; i++) {                      		// i = 1 because we included the first line
//			std::cout << "\x1b[1A" << "\x1b[2K";                // Move cursor up one and Delete the entire line
//		}
//		std::cout << "\r";                                      // Resume the cursor at beginning of line
//	}
//}

int main() {
	// const int kLinesToErase = 10;
	// const int kSecondsToWait = 1;
	
	const std::string kSymbolCollection = "+-/*^<";
	std::string symbol = "+";
	std::size_t symbol_type = 0;

	double argument_01 = 0.0;
	double argument_02 = 0.0;

	do {
		std::cout << "Type any numbers in format: a + b (or any other symbol: -, /, *, ^, < (Root: 2 < 4 = 2))\n";
		if (!(std::cin >> argument_01 >> symbol >> argument_02)) {
			ErrorInputMsg();
			// DelayInSeconds(kSecondsToWait);
			// EraseLines(kLinesToErase);
			continue;
		}
		
		symbol_type = kSymbolCollection.find(symbol);
		if (symbol_type == std::string::npos) {
			ErrorInputMsg();
			// DelayInSeconds(kSecondsToWait);
			// EraseLines(kLinesToErase);
			continue;
		}

		break;
	} while (true);
	
	
	// std::cout << "\x1b[1A";
	switch (symbol_type) {
	case 0:
		std::cout << argument_01 << " + " << argument_02 << " = " << argument_01 + argument_02 << '\n';
		break;
	case 1:
		std::cout << argument_01 << " - " << argument_02 << " = " << argument_01 - argument_02 << '\n';
		break;
	case 2:
		std::cout << argument_01 << " / " << argument_02 << " = " << argument_01 / argument_02 << '\n';
		break;
	case 3:
		std::cout << argument_01 << " * " << argument_02 << " = " << argument_01 * argument_02 << '\n';
		break;
	case 4:
		std::cout << argument_01 << " ^ " << argument_02 << " = " << pow(argument_01, argument_02) << '\n';
		break;
	case 5:
		std::cout << argument_01 << " < " << argument_02 << " = " << pow(argument_02, (1 / argument_01)) << '\n';   // pow(a, 1/b) == b root a
		break;
	default:
		std::cout << "Oops! Something went wrong, sorry!" << '\n';
	}
	
	system("pause");

	return 0;
}