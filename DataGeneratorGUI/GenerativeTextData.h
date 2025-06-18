#pragma once

#include <functional> 
#include <string>

class GenerativeTextData {
public:
	int inputCount; // Default count for generation
	bool showTextBox; // Flag to control visibility of the text box

public:
	GenerativeTextData(
		const std::string& title,                           // Title for the collapsing header
		std::function<std::string(int)> generationFunction // The function that generates the data
	);
	// Trigger generation and prepare display string
	void Generate(int maxDisplayLines);

	const std::string& GetTitle() const { return m_title; }
	std::string& GetData() { return m_GeneratedData; }

private:
	std::string m_title; // Title for the collapsing header
	std::function<std::string(int)> m_generationFunction; // Function to generate the text based on input count
	std::string m_GeneratedData; // The generated data string

};