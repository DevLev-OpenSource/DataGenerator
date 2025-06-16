#pragma once
#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_win32.h>
#include <imgui/backends/imgui_impl_dx11.h>
#include <d3d11.h>
#include <tchar.h>
#include <string>
#include "MainWindow.h"
namespace DataGeneratorGUI {

    // Function that returns a random phone number string
    std::string generateRandomPhoneNumbers(int Num) {
        std::string result;
        for (int i = 0; i < Num; ++i) {
            char buffer[32];
            snprintf(buffer, sizeof(buffer), "+1-%03d-%03d-%04d\n", rand() % 1000, rand() % 1000, rand() % 10000);
            result += buffer;
        }
        return result;
    }
	void MainWindow(bool open) {
        static int inputNumOfNames = 1;
        static char generatedPhoneNumber[1024] = "";
        static bool showTextBox = false;
        ImGui::Begin("Another Window", &open);

        ImGui::InputInt("Enter number of phones here", &inputNumOfNames);

        // Get the widget ID of the InputInt (you can use the label)
        ImGuiID inputId = ImGui::GetID("Enter number of phones here");
        ImGuiID activeId = ImGui::GetItemID();

        if (activeId == inputId && (ImGui::IsKeyPressed(ImGuiKey_Enter) || ImGui::IsKeyPressed(ImGuiKey_KeypadEnter))) {
            std::string result = generateRandomPhoneNumbers(inputNumOfNames);
            strncpy_s(generatedPhoneNumber, result.c_str(), sizeof(generatedPhoneNumber));
            generatedPhoneNumber[sizeof(generatedPhoneNumber) - 1] = '\0';
            showTextBox = true;
        }

        if (ImGui::Button("Generate")) {
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