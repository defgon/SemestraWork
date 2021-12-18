#pragma once
// ====================================================================================================
// Includes
// ====================================================================================================

// Uncomment the next line if Microsoft Visual Studio 2017 is used. Must be before the other includes.
// #include "pch.h" 
#include <iostream>
#include <string>

// ====================================================================================================
// Print functions
// ====================================================================================================

/// Prints an empty line.
void skipLine() {
	std::cout << std::endl;
}

/// Prints a full-line separator consisting of the given char.
void printSeparator(char symbol = '=') {
	const int LINE_LENGTH = 80; // (char count)
	for (int i = 0; i < LINE_LENGTH; i++) {
		std::cout << symbol;
	}
	std::cout << std::endl;
}

/// Prints a warning containing the given message.
void printWarning(std::string message) {
	printSeparator('!');
	std::cout << "WARNING: " << message << std::endl;
	printSeparator('!');
}

/// Prints a single bullet point.
void printBulletPoint(std::string name, int value) {
	const std::string BULLET = "-->";
	std::cout << BULLET << " " << name << " " << value << std::endl;
}