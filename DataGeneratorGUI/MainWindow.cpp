#pragma once
#include "MainWindow.h"
#include "../DataGenerator/generator.h"
constexpr const char *const PHONEGENERATOR = "Number of phone numbers to generate";
namespace DataGeneratorGUI {

    // Function that returns a random phone numbers
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
	void MainWindow(bool open) {
        static int inputNumOfNames = 1;
        static char generatedPhoneNumber[1024] = "";
        static bool showTextBox = false;
        ImGui::Begin("Main Window", &open);

        ImGui::InputInt(PHONEGENERATOR, &inputNumOfNames);

        // Get the widget ID of the InputInt (you can use the label)
        ImGuiID inputId = ImGui::GetID(PHONEGENERATOR);
        ImGuiID activeId = ImGui::GetItemID();

        if (activeId == inputId && (ImGui::IsKeyPressed(ImGuiKey_Enter) || ImGui::IsKeyPressed(ImGuiKey_KeypadEnter)) || ImGui::Button("Generate")) {
            std::string result = generateRandomPhoneNumbers(inputNumOfNames);
            strncpy_s(generatedPhoneNumber, result.c_str(), sizeof(generatedPhoneNumber));
            generatedPhoneNumber[sizeof(generatedPhoneNumber) - 1] = '\0';
            showTextBox = true;
        }
        if(showTextBox) {
            ImGui::InputTextMultiline(
                "##generated_numbers",
                generatedPhoneNumber,
                IM_ARRAYSIZE(generatedPhoneNumber),
                ImVec2(0, 150),                        
                ImGuiInputTextFlags_ReadOnly 
            );
            ImGui::SameLine();
            if (ImGui::Button("Copy")) {
                ImGui::SetClipboardText(generatedPhoneNumber);
            }
        }
        if (ImGui::Button("Close Me"))
            open = false;

        ImGui::End();

    }

}