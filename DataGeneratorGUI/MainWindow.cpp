#pragma once
#include "../DataGenerator/generator.h"
#include "imgui/imgui.h"
#include "MainWindow.h"
#include <cstdio>
#include <cstring>
#include <imgui/imgui_internal.h>
#include <set>
#include <string>
namespace DataGeneratorGUI {
	constexpr const char* const PHONENUMINPUT = "##Number of phone numbers to generate";
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

		ImGui::End(); // End of the MainDockSpaceHost window
		ImGui::Begin("Data Generator", &open);
		PhoneNumbersUI();
		FirstNameUI();
		LastNamerUI();
		FullNameUI();
		IDNumberUI();
		FullRecordGeneratorUI();

		ImGui::End();

	}
	void PhoneNumbersUI() {
		if (ImGui::CollapsingHeader("Phone Numbers Generator")) {

			static int inputNumOfNames = 1;
			static char generatedPhoneNumber[1024] = "";
			static bool showTextBox = false;
			ImGui::InputInt(PHONENUMINPUT, &inputNumOfNames);

			ImGuiID inputId = ImGui::GetID(PHONENUMINPUT);
			ImGuiID activeId = ImGui::GetItemID();

			if (activeId == inputId && (ImGui::IsKeyPressed(ImGuiKey_Enter) || ImGui::IsKeyPressed(ImGuiKey_KeypadEnter)) || ImGui::Button("Generate")) {
				std::string result = generateRandomPhoneNumbers(inputNumOfNames);
				strncpy_s(generatedPhoneNumber, result.c_str(), sizeof(generatedPhoneNumber));
				generatedPhoneNumber[sizeof(generatedPhoneNumber) - 1] = '\0';
				showTextBox = true;
			}
			if (showTextBox) {
				ImGui::InputTextMultiline(
					"##generated_numbers",
					generatedPhoneNumber,
					IM_ARRAYSIZE(generatedPhoneNumber),
					ImVec2(0, 0),
					ImGuiInputTextFlags_ReadOnly
				);
				if (ImGui::Button("Copy##Phone Numbers")) {
					ImGui::SetClipboardText(generatedPhoneNumber);
				}
				ImGui::SameLine();
				if (ImGui::Button("Export##Phone Numbers")) {
					ImGui::SetClipboardText(generatedPhoneNumber);
					// TODO: Open file dialog, export logic, etc.
				}
			}
		}
	}
	std::string generateRandomPhoneNumbers(int Num) {
		std::string result;
		for (int i = 0; i < Num; ++i) {
			char buffer[32];
			snprintf(buffer, sizeof(buffer), generateRandomPhoneNumber().c_str());
			result += buffer;
			result += "\n";
		}
		return result;
	}
	void FirstNameUI() {
		if (ImGui::CollapsingHeader("First Name Generator")) {
			static char generatedFirstName[1024] = "";
			static bool showTextBox = false;

			if (ImGui::Button("Generate First Name")) {
				std::string result = generateRandomFirstName();
				strncpy_s(generatedFirstName, result.c_str(), sizeof(generatedFirstName));
				generatedFirstName[sizeof(generatedFirstName) - 1] = '\0';
				showTextBox = true;
			}

			if (showTextBox) {
				ImGui::InputTextMultiline(
					"##generated_first_name",
					generatedFirstName,
					IM_ARRAYSIZE(generatedFirstName),
					ImVec2(0, 0),
					ImGuiInputTextFlags_ReadOnly
				);
				if (ImGui::Button("Copy##First Name")) {
					ImGui::SetClipboardText(generatedFirstName);
				}
				ImGui::SameLine();
				if (ImGui::Button("Export##First Name")) {
					ImGui::SetClipboardText(generatedFirstName);
					// TODO: Open file dialog, export logic, etc.
				}
			}
		}
	}
	void LastNamerUI() {
		if (ImGui::CollapsingHeader("Last Name Generator")) {
			static char generatedLastName[1024] = "";
			static bool showTextBox = false;
			static std::set<std::string> usedLastNames;

			if (ImGui::Button("Generate Last Name")) {
				std::string result = generateRandomLastName(usedLastNames);
				strncpy_s(generatedLastName, result.c_str(), sizeof(generatedLastName));
				generatedLastName[sizeof(generatedLastName) - 1] = '\0';
				showTextBox = true;
			}

			if (showTextBox) {
				ImGui::InputTextMultiline(
					"##generated_last_name",
					generatedLastName,
					IM_ARRAYSIZE(generatedLastName),
					ImVec2(0, 0),
					ImGuiInputTextFlags_ReadOnly
				);
				if (ImGui::Button("Copy##Last Name")) {
					ImGui::SetClipboardText(generatedLastName);
				}
				ImGui::SameLine();
				if (ImGui::Button("Export##Last Name")) {
					ImGui::SetClipboardText(generatedLastName);
					// TODO: Open file dialog, export logic, etc.
				}
			}
		}
	}
	void FullNameUI() {
		if (ImGui::CollapsingHeader("Full Name Generator")) {
			static char generatedFullName[1024] = "";
			static bool showTextBox = false;
			static std::set<std::string> usedLastNamesForFullName;

			if (ImGui::Button("Generate Full Name")) {
				std::string result = generateRandomFullName(usedLastNamesForFullName);
				strncpy_s(generatedFullName, result.c_str(), sizeof(generatedFullName));
				generatedFullName[sizeof(generatedFullName) - 1] = '\0';
				showTextBox = true;
			}

			if (showTextBox) {
				ImGui::InputTextMultiline(
					"##generated_full_name",
					generatedFullName,
					IM_ARRAYSIZE(generatedFullName),
					ImVec2(0, 0),
					ImGuiInputTextFlags_ReadOnly
				);
				if (ImGui::Button("Copy##Full Name")) {
					ImGui::SetClipboardText(generatedFullName);
				}
				ImGui::SameLine();
				if (ImGui::Button("Export##Full Name")) {
					ImGui::SetClipboardText(generatedFullName);
					// TODO: Open file dialog, export logic, etc.
				}
			}
		}
	}
	void IDNumberUI() {
		if (ImGui::CollapsingHeader("ID Number Generator")) {
			static char generatedIDNumber[1024] = "";
			static bool showTextBox = false;

			if (ImGui::Button("Generate ID Number")) {
				std::string result = generateRandomIDNumber();
				strncpy_s(generatedIDNumber, result.c_str(), sizeof(generatedIDNumber));
				generatedIDNumber[sizeof(generatedIDNumber) - 1] = '\0';
				showTextBox = true;
			}

			if (showTextBox) {
				ImGui::InputTextMultiline(
					"##generated_id_number",
					generatedIDNumber,
					IM_ARRAYSIZE(generatedIDNumber),
					ImVec2(0, 0),
					ImGuiInputTextFlags_ReadOnly
				);
				if (ImGui::Button("Copy##ID Number")) {
					ImGui::SetClipboardText(generatedIDNumber);
				}
				ImGui::SameLine();
				if (ImGui::Button("Export##ID Number")) {
					ImGui::SetClipboardText(generatedIDNumber);
					// TODO: Open file dialog, export logic, etc.
				}
			}
		}
	}
	void FullRecordGeneratorUI() {
		if (ImGui::CollapsingHeader("Full Record Generator")) {
			static char generatedFullRecord[4096] = "";
			static bool showTextBox = false;
			static std::set<std::string> usedLastNamesForRecord;

			if (ImGui::Button("Generate Full Record")) {
				std::string result = generateFullRecord(usedLastNamesForRecord);
				strncpy_s(generatedFullRecord, result.c_str(), sizeof(generatedFullRecord));
				generatedFullRecord[sizeof(generatedFullRecord) - 1] = '\0';
				showTextBox = true;
			}

			if (showTextBox) {
				ImGui::InputTextMultiline(
					"##generated_full_record",
					generatedFullRecord,
					IM_ARRAYSIZE(generatedFullRecord),
					ImVec2(0, 0),
					ImGuiInputTextFlags_ReadOnly
				);
				if (ImGui::Button("Copy##Full Record")) {
					ImGui::SetClipboardText(generatedFullRecord);
				}
				ImGui::SameLine();
				if (ImGui::Button("Export##Full Record")) {
					ImGui::SetClipboardText(generatedFullRecord);
					// TODO: Open file dialog, export logic, etc.
				}
			}
		}
	}

}