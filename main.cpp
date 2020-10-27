// File: main.py
// Author: 张泽楠
// Copyright ©2020 张泽楠, All Rights Reserved
// SPDX-License-Identifier: Apache-2.0
// Time: 2020‎-‎10‎-‎27 ‏‎19:11

#include <iostream>
#include <Windows.h>

using namespace std;

int main(int argc, char *argv[])
{
    ATOM HotKeyId;
    HotKeyId = GlobalAddAtom("QQHasNoF2") - 0xC000;
    if (0 == RegisterHotKey(NULL, HotKeyId, 0, VK_F2)) {
        cout << "Register HotKey Failed(F2).\nError: " << GetLastError() << endl;
    }
    else{
        cout << "Register HotKey Successfully(F2).\n" << endl;
    }

    MSG msg = { 0 };

    while (GetMessage(&msg, NULL, HotKeyId, 0)){
        switch (msg.message){
            case WM_HOTKEY:{
                if (HotKeyId == msg.wParam) {
                    cout << "F2 was pressed." << endl;
                }
                break;
            }
            default:
                break;
        }

    }
    return 0;
}
