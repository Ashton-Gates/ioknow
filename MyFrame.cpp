#include <Windows.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    const char* className = "MyWindowClass";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = className;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);

    RegisterClass(&wc);

    HWND hWnd = CreateWindowEx(0, className, "WinAPI Basic Window", WS_OVERLAPPEDWINDOW,
                               CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, nullptr, nullptr, hInstance, nullptr);

    if (hWnd == nullptr) {
        return 1;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
        case WM_CREATE:
        {
            // Create header bar
            CreateWindow("STATIC", "Header Bar", WS_VISIBLE | WS_CHILD | SS_CENTER,
                         0, 0, 800, 50, hWnd, nullptr, nullptr, nullptr);

            // Create dropdown menu
            HWND hDropdown = CreateWindow("COMBOBOX", nullptr, WS_VISIBLE | WS_CHILD | CBS_DROPDOWNLIST,
                                          10, 10, 200, 200, hWnd, nullptr, nullptr, nullptr);

            // Add example items to the dropdown menu
            SendMessage(hDropdown, CB_ADDSTRING, 0, (LPARAM)"Example 1");
            SendMessage(hDropdown, CB_ADDSTRING, 0, (LPARAM)"Example 2");
            SendMessage(hDropdown, CB_ADDSTRING, 0, (LPARAM)"Example 3");
        }
            break;

        case WM_COMMAND:
        {
            // Handle dropdown menu selection
            if (HIWORD(wParam) == CBN_SELCHANGE)
            {
                // Get the selected index
                int selectedIndex = SendMessage((HWND)lParam, CB_GETCURSEL, 0, 0);

                // Get the selected example name
                char exampleName[64];
                SendMessage((HWND)lParam, CB_GETLBTEXT, selectedIndex, (LPARAM)exampleName);

                // Show a message box with the selected example name
                MessageBox(hWnd, exampleName, "Selected Example", MB_OK | MB_ICONINFORMATION);
            }
        }
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
    }

    return 0;
}