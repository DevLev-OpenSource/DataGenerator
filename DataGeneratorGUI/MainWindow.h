#pragma once
#include "GenerativeTextData.h"
#include "imgui/imgui.h"

namespace DataGeneratorGUI {

	void SetupDockingLayout();
	void MainWindow(bool open);
	void DrawTextGeneratorUI(
		GenerativeTextData& dataModel // The data model instance for this specific generator
	);
}