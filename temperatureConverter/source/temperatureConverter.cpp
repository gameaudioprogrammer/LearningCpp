// Learning C++
// Temperature Converter (between Fahrenheit, Celcius and Kelvin)
// Game Audio Programmer (Nikita Kvitka)

#include <iostream>
#include <iomanip>


static double TwoDecimalRounding(double a)
{
	return round(a * 100) / 100;  // Round 0.23451 to 0.23
}


static void Convertor(double a, char b)
{
	const double kFahrenCoeff = 32.0;
	const double kFactor = 1.8000;
	const double kKelvinCoeff = 273.15;
	const int kWidth = 10;

	double f = 0.0;
	double c = 0.0;
	double k = 0.0;

	switch (b)
	{
	case 'F':   // Fahrenheit to Celcius and Kelvin
		f = a;
		c = (f - kFahrenCoeff) / kFactor;
		k = c + kKelvinCoeff;

		std::cout << TwoDecimalRounding(f) << "F" << std::setw(kWidth)
			<< TwoDecimalRounding(c) << "C" << std::setw(kWidth)
			<< TwoDecimalRounding(k) << "K" << std::endl;
		break;

	case 'C':   // Celcius to Fahrenheit and Kelvin
		c = a;
		f = (c * kFactor) + kFahrenCoeff;
		k = c + kKelvinCoeff;

		std::cout << TwoDecimalRounding(c) << "C" << std::setw(kWidth)
			<< TwoDecimalRounding(f) << "F" << std::setw(kWidth)
			<< TwoDecimalRounding(k) << "K" << std::endl;
		break;

	case 'K':   // Kelvin to Celcius and Fahrenheit
		k = a;
		c = k - kKelvinCoeff;
		f = (c * kFactor) + kFahrenCoeff;

		std::cout << TwoDecimalRounding(k) << "K" << std::setw(kWidth)
			<< TwoDecimalRounding(c) << "C" << std::setw(kWidth)
			<< TwoDecimalRounding(f) << "F" << std::endl;
		break;

	default:
		std::cout << "Something went wrong, check implementation" << std::endl;
	}
}



int main()
{
	double temperature = 0;
	char scale;

	// Input Validation
	do
	{
		std::cout << "Type only numbers and scale (F, C or K), i.e. 32F or 54C or 534K\n";

		if (!(std::cin >> temperature >> scale))
		{
			std::cin.clear();
			std::cin.ignore(1000000, '\n');
			continue;
		}
		temperature = TwoDecimalRounding(temperature);
		scale = static_cast<char>(toupper(scale));

		if (scale != 'F' && scale != 'C' && scale != 'K')
		{
			std::cin.clear();
			std::cin.ignore(1000000, '\n');
			continue;
		}

		break;

	} while (true);


	Convertor(temperature, scale);
	
	
	system("pause");
	return 0;
}
