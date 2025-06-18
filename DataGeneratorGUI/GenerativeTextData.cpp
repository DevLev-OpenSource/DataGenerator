#include "GenerativeTextData.h"
#include "imgui/imgui.h"
#include <functional>
#include <string>

GenerativeTextData::GenerativeTextData(
	const std::string& title,
	std::function<std::string(int)> generationFunction
) :
	inputCount(1),
	showTextBox(false),
	m_title(title),
	m_generationFunction(generationFunction),
	m_GeneratedData("")
{
}


// trigger generation and prepare display string
void GenerativeTextData::Generate(int maxDisplayLines) {
	// Ensure the input number is at least 1
	if (inputCount < 1) {
		inputCount = 1;
	}
	m_GeneratedData = m_generationFunction(inputCount);
}
