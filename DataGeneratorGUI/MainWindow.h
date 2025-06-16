#pragma once
#include "imgui/imgui.h"
#include <string>
namespace DataGeneratorGUI {


	std::string generateRandomPhoneNumbers(int Num);
	void SetupDockingLayout();
	void MainWindow(bool open);
	void PhoneNumbersUI();
	void FirstNameUI();
	void LastNamerUI();
	void FullNameUI();
	void IDNumberUI();
	void FullRecordGeneratorUI();
}