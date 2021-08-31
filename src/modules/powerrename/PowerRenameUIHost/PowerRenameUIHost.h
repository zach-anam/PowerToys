#pragma once

#include "resource.h"
#include "XamlBridge.h"
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.system.h>
#include <winrt/windows.ui.xaml.hosting.h>
#include <windows.ui.xaml.hosting.desktopwindowxamlsource.h>
#include <winrt/windows.ui.xaml.controls.h>
#include <winrt/Windows.ui.xaml.media.h>
#include <winrt/Windows.UI.Core.h>
#include <winrt/PowerRenameUI_new.h>

using namespace winrt;
using namespace Windows::UI;
using namespace Windows::UI::Composition;
using namespace Windows::UI::Xaml::Hosting;
using namespace Windows::Foundation::Numerics;
using namespace Windows::UI::Xaml::Controls;


class AppWindow : public DesktopWindowT<AppWindow>
{
public:
    __declspec(dllexport) static int Show(HINSTANCE hInstance, int nCmdShow);

    LRESULT MessageHandler(UINT message, WPARAM wParam, LPARAM lParam) noexcept;

private:
    AppWindow(HINSTANCE hInstance) noexcept :
        m_instance(hInstance)
    {
    }

    void CreateAndShowWindow(int nCmdShow);
    bool OnCreate(HWND, LPCREATESTRUCT) noexcept;
    void OnCommand(HWND, int id, HWND hwndCtl, UINT codeNotify) noexcept;
    void OnDestroy(HWND hwnd) noexcept;
    void OnResize(HWND, UINT state, int cx, int cy) noexcept;

    wil::unique_haccel m_accelerators;
    const HINSTANCE m_instance;
    HWND m_xamlIsland{};
    winrt::PowerRenameUI_new::MainWindow m_mainUserControl{ nullptr };
};
