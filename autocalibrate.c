#include <windows.h>
#include <string.h>

int main(void) {
    HWND hwnd = FindWindowW(NULL, L"IWBServer");
    if (!hwnd) return 1;

    const wchar_t* cmd = L"EP_START_QUICK_AUTO_CAL";

    COPYDATASTRUCT cds;
    cds.dwData = 0;
    cds.cbData = (wcslen(cmd) + 1) * sizeof(wchar_t);
    cds.lpData = (PVOID)cmd;

    LRESULT result = SendMessageW(hwnd, WM_COPYDATA, 0, (LPARAM)&cds);
    return (result != 0) ? 0 : 1;
}
