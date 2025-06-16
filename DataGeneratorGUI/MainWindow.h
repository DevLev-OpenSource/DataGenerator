#pragma once
#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_win32.h>
#include <imgui/backends/imgui_impl_dx11.h>
#include <d3d11.h>
#include <tchar.h>
#include <string>
namespace DataGeneratorGUI {
    std::string generateRandomPhoneNumbers(int Num);
    void MainWindow(bool open);
}