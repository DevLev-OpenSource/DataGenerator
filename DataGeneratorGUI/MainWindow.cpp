#pragma once
#include "../DataGenerator/generator.h"
#include "GenerativeTextData.h"
#include "MainWindow.h"
#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>
#include <imgui/imgui_stdlib.h>
#include <string>
namespace DataGeneratorGUI {
	constexpr const int MAXDISPLAYLINES = 10;
	// Flags for the host window, which is the main docking window
	ImGuiWindowFlags host_window_flags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove
		| ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoBringToFrontOnFocus
		| ImGuiWindowFlags_NoNavFocus | ImGuiWindowFlags_NoDocking;
	// Basic flags for the main window
	ImGuiWindowFlags flags =
		ImGuiWindowFlags_NoMove;
	// Global flag to indicate if the docking layout needs to be set up
	bool g_firstFrame = true;
	void SetupDockingLayout() {
		// Get the ID of the main dockspace
		ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");

		// Clear any previous layout from this dockspace ID
		ImGui::DockBuilderRemoveNode(dockspace_id);
		// Create a new empty dock node
		ImGui::DockBuilderAddNode(dockspace_id, ImGuiDockNodeFlags_DockSpace);
		// Make the dockspace fill the current window (or viewport)
		ImGui::DockBuilderSetNodeSize(dockspace_id, ImGui::GetMainViewport()->Size);

		// Split the dockspace into two: left and right, 50 50 split
		ImGuiID dock_left_id = ImGui::DockBuilderSplitNode(dockspace_id, ImGuiDir_Left, 0.5, nullptr, &dockspace_id);

		// Docks the "Data Generator" into the left 
		ImGui::DockBuilderDockWindow("Data Generator", dock_left_id);

		// Finalize the docking layout.
		ImGui::DockBuilderFinish(dockspace_id);
	}

	void MainWindow(bool open) {
		// 1. Create a full-screen DockSpace
		ImGuiViewport* viewport = ImGui::GetMainViewport();
		ImGui::SetNextWindowPos(viewport->WorkPos);
		ImGui::SetNextWindowSize(viewport->WorkSize);
		ImGui::SetNextWindowViewport(viewport->ID);

		// Set the style for the host window to have no rounding, border, or padding
		ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));

		// Begin the host window with the specified flags
		ImGui::Begin("MainDockSpaceHost", nullptr, host_window_flags);
		ImGui::PopStyleVar(3); // Pop rounding, border, padding

		ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
		ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), ImGuiDockNodeFlags_PassthruCentralNode);

		if (g_firstFrame) {
			g_firstFrame = false;
			SetupDockingLayout();
		}
		// End of the MainDockSpaceHost window
		ImGui::End();
		// Start of the Data Generator window
		ImGui::Begin("Data Generator", &open);

		// Create a static instance of GenerativeTextData for each generator type
		static GenerativeTextData phoneDataModel("Phone Numbers Generator", generateRandomPhoneNumbers);
		DrawTextGeneratorUI(phoneDataModel);

		static GenerativeTextData firstNameDataModel("First Name Generator", generateRandomFirstNames);
		DrawTextGeneratorUI(firstNameDataModel);


		static GenerativeTextData lastNameDataModel("Last Name Generator", generateRandomLastNames);
		DrawTextGeneratorUI(lastNameDataModel);


		static GenerativeTextData fullNameDataModel("Full Name Generator", generateRandomFullNames);
		DrawTextGeneratorUI(fullNameDataModel);


		static GenerativeTextData IDdataModel("ID Number Generator", generateRandomIDNumbers);
		DrawTextGeneratorUI(IDdataModel);


		static GenerativeTextData fullRecorddataModel("Full Record Generator", generateFullRecords);
		DrawTextGeneratorUI(fullRecorddataModel);

		// End of the Data Generator window
		ImGui::End();

	}
	void DrawTextGeneratorUI(GenerativeTextData& dataModel)
	{
		// Using the dataModel's title for the CollapsingHeader + ID.
		if (ImGui::CollapsingHeader(dataModel.GetTitle().c_str())) {

			// Push a unique ID for this widget instance to ensure no ID conflicts.
			// "##" is to the title to make it an invisible ID otherwise it will show right next to the widget.
			std::string widgetId = "##" + dataModel.GetTitle();
			ImGui::PushID(widgetId.c_str());

			// Input field for the number of items to generate
			ImGui::InputInt("##Input", &dataModel.inputCount);

			// Get the widget ID of the InputInt for Enter key detection
			ImGuiID inputId = ImGui::GetID("##Input");
			ImGuiID activeId = ImGui::GetItemID(); // GetID of the last active item

			// Check for "Generate" button click OR Enter key press while InputInt is active
			if ((activeId == inputId && (ImGui::IsKeyPressed(ImGuiKey_Enter) || ImGui::IsKeyPressed(ImGuiKey_KeypadEnter))) || ImGui::Button("Generate")) {
				// Call the data model's Generate function to update its internal strings
				dataModel.Generate(MAXDISPLAYLINES);
				dataModel.showTextBox = true; // Show the text box after generation
			}

			if (dataModel.showTextBox) {

				ImGui::InputTextMultiline(
					"##generatedData",
					&dataModel.GetData(), // Pass a pointer to the std::string
					ImVec2(0, 0),
					ImGuiInputTextFlags_ReadOnly // Make it read-only
				);

				// --- Action Buttons ---
				// Push another ID for the buttons to prevent conflicts if multiple button sets are on screen
				ImGui::PushID("##ActionButtons"); // Add ## for invisible ID
				if (ImGui::Button("Copy")) {
					ImGui::SetClipboardText(dataModel.GetData().c_str()); // Copy all the data to clipboard
				}
				ImGui::SameLine();
				if (ImGui::Button("Export")) {
					// TODO: Implement actual file dialog and export logic here,
					ImGui::SetClipboardText(dataModel.GetData().c_str()); // Placeholder: still copies
				}
				ImGui::PopID(); // Pop "ActionButtons" ID
			}
			ImGui::PopID(); // Pop the unique ID for this widget instance
		}
	}

}