#include <iostream>

#include "ñ-formating.h"

int main(int argc, char* argv[])
{
	const std::string format = "The integer value: %d, the string value: %s";
	const std::string string = "Pushed string";

	/* static format example */
	const std::string static_message = StringFormatStatic<128>(format, 10, "Static example");

	std::cout << static_message << std::endl;

	/* dynamic format example */
	const std::string dynamic_message = StringFormatDynamic(format, 15, string);

	std::cout << dynamic_message << std::endl;

	return 0;
}