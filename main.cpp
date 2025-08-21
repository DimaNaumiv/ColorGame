#include <windows.h>
#include "Object_Ids.h"
#include <vector>
#include <random>

HWND text = NULL;

using namespace std;

vector<HBRUSH>colorline = vector<HBRUSH>();
HBRUSH colors[4];

random_device rNum;

int colorindex = 0;

int result = 0;

int helthcount = 3;

int startNumber = 3;

int raund = 0;

int chused = NULL;

bool gameState = false;

HWND button1 = NULL;
HWND button2 = NULL;
HWND button3 = NULL;
HWND button4 = NULL;

HWND health1 = NULL;
HWND health2 = NULL;
HWND health3 = NULL;

HWND pictcher = NULL;

HBRUSH btn1Color = NULL;
HBRUSH btn2Color = NULL;
HBRUSH btn3Color = NULL;
HBRUSH btn4Color = NULL;

HBRUSH usinghlthColor = NULL;

HBRUSH hlthColor = NULL;
HBRUSH hlthDColor = NULL;

HBRUSH usingColorPich = NULL;

HBRUSH pichColor1 = NULL;
HBRUSH pichColor2 = NULL;
HBRUSH pichColor3 = NULL;
HBRUSH pichColor4 = NULL;
HBRUSH pichColor5 = NULL;


LRESULT CALLBACK WindowsProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR CmdLine, int CmdShow) {
	const wchar_t* CLASS_NAME = L"MainWindow";
	WNDCLASSW wc = {};
	wc.lpfnWndProc = WindowsProc;
	wc.lpszClassName = CLASS_NAME;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursorW(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

	if (!RegisterClassW(&wc)) {
		MessageBoxW(0, L"Fail regist window", L"Error MEssage", MB_OK);
		return 0;
	}

	HWND hwnd = CreateWindowExW(0, CLASS_NAME, L"Window", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 500, 500, NULL, NULL, hInstance, NULL);
	if (hwnd == NULL) {
		MessageBoxW(0, L"Error creating window", L"Error Message", MB_OK);
		return 0;
	}

	button1 = CreateWindowExW(0, L"Button", L"1", WS_VISIBLE | WS_CHILD | WS_TABSTOP | BS_OWNERDRAW, 100, 300, 100, 50, hwnd, (HMENU)BUTTON1_ID, hInstance, NULL);
	if (button1 == NULL) {
		MessageBoxW(0, L"Error create button 1", L"Error Message", MB_OK);
		return 0;
	}
	button2 = CreateWindowExW(0, L"Button", L"2", WS_VISIBLE | WS_CHILD | WS_TABSTOP | BS_OWNERDRAW, 240, 300, 100, 50, hwnd, (HMENU)BUTTON2_ID, hInstance, NULL);
	if (button2 == NULL) {
		MessageBoxW(0, L"Error create button 2", L"Error Message", MB_OK);
		return 0;
	}
	button3 = CreateWindowExW(0, L"Button", L"3", WS_VISIBLE | WS_CHILD | WS_TABSTOP | BS_OWNERDRAW, 100, 370, 100, 50, hwnd, (HMENU)BUTTON3_ID, hInstance, NULL);
	if (button3 == NULL) {
		MessageBoxW(0, L"Error create button 2", L"Error Message", MB_OK);
		return 0;
	}
	button4 = CreateWindowExW(0, L"Button", L"4", WS_VISIBLE | WS_CHILD | WS_TABSTOP | BS_OWNERDRAW, 240, 370, 100, 50, hwnd, (HMENU)BUTTON4_ID, hInstance, NULL);
	if (button4 == NULL) {
		MessageBoxW(0, L"Error create button 2", L"Error Message", MB_OK);
		return 0;
	}


	health1 = CreateWindowExW(0, L"Static", L"", WS_VISIBLE | WS_CHILD | SS_OWNERDRAW, 10, 230, 50, 50, hwnd, (HMENU)HEALTH1_ID, hInstance, NULL);
	if (health1 == NULL) {
		MessageBoxW(0, L"Error create health 1", L"Error Message", MB_OK);
		return 0;
	}
	health2 = CreateWindowExW(0, L"Static", L"", WS_VISIBLE | WS_CHILD | SS_OWNERDRAW, 80, 230, 50, 50, hwnd, (HMENU)HEALTH2_ID, hInstance, NULL);
	if (health2 == NULL) {
		MessageBoxW(0, L"Error create health 2", L"Error Message", MB_OK);
		return 0;
	}
	health3 = CreateWindowExW(0, L"Static", L"", WS_VISIBLE | WS_CHILD | SS_OWNERDRAW, 150, 230, 50, 50, hwnd, (HMENU)HEALTH3_ID, hInstance, NULL);
	if (health3 == NULL) {
		MessageBoxW(0, L"Error create health 3", L"Error Message", MB_OK);
		return 0;
	}

	pictcher = CreateWindowExW(0, L"Static", L"", WS_VISIBLE | WS_CHILD | SS_OWNERDRAW, 125, 15, 200, 200, hwnd, (HMENU)PICTCHER_ID, hInstance, NULL);
	if (pictcher == NULL) {
		MessageBoxW(0, L"Error creating pictcher", L"Error Messge", MB_OK);
	}

	text = CreateWindowExW(0, L"Static", L"click on button", SS_CENTER | WS_VISIBLE | WS_CHILD, 350, 70, 120, 20, hwnd, (HMENU)text_ID, hInstance, NULL);
	if (text == NULL) {
		MessageBoxW(0, L"Error creating text", L"Error Messge", MB_OK);
	}
	ShowWindow(hwnd, CmdShow);

	MSG Msg = {};
	while (GetMessage(&Msg, NULL, 0, 0)) {
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return 0;
}

LRESULT CALLBACK WindowsProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
	case WM_DESTROY:
		if (btn1Color != NULL) {
			DeleteObject(btn1Color);
			btn1Color = NULL;
		}
		if (btn2Color != NULL) {
			DeleteObject(btn2Color);
			btn2Color = NULL;
		}
		if (btn3Color != NULL) {
			DeleteObject(btn3Color);
			btn3Color = NULL;
		}
		if (btn4Color != NULL) {
			DeleteObject(btn4Color);
			btn4Color = NULL;
		}

		if (hlthColor != NULL) {
			DeleteObject(hlthColor);
			hlthColor = NULL;
		}
		if (hlthDColor != NULL) {
			DeleteObject(hlthDColor);
			hlthDColor = NULL;
		}

		if (pichColor1 != NULL) {
			DeleteObject(pichColor1);
			pichColor1 = NULL;
		}
		if (pichColor2 != NULL) {
			DeleteObject(pichColor2);
			pichColor2 = NULL;
		}
		if (pichColor3 != NULL) {
			DeleteObject(pichColor3);
			pichColor3 = NULL;
		}
		if (pichColor4 != NULL) {
			DeleteObject(pichColor4);
			pichColor4 = NULL;
		}
		if (pichColor5 != NULL) {
			DeleteObject(pichColor5);
			pichColor5 = NULL;
		}
		PostQuitMessage(0);
		return 0;
	case WM_CREATE:
		btn1Color = CreateSolidBrush(RGB(0, 255, 0));
		btn2Color = CreateSolidBrush(RGB(0, 0, 255));
		btn3Color = CreateSolidBrush(RGB(255, 0, 0));
		btn4Color = CreateSolidBrush(RGB(255, 255, 0));

		hlthColor = CreateSolidBrush(RGB(255, 0, 0));
		usinghlthColor = hlthColor;
		hlthDColor = CreateSolidBrush(RGB(255, 255, 255));

		pichColor1 = CreateSolidBrush(RGB(0, 0, 0));
		usingColorPich = pichColor1;
		pichColor2 = btn1Color;
		pichColor3 = btn2Color;
		pichColor4 = btn3Color;
		pichColor5 = btn4Color;

		colors[0] = pichColor2;
		colors[1] = pichColor3;
		colors[2] = pichColor4;
		colors[3] = pichColor5;

		return 0;
	case WM_DRAWITEM:
	{
		LPDRAWITEMSTRUCT ipdis = (LPDRAWITEMSTRUCT)lParam;
		if (ipdis->CtlID == BUTTON1_ID || ipdis->CtlID == BUTTON2_ID || ipdis->CtlID == BUTTON3_ID || ipdis->CtlID == BUTTON4_ID) {
			HBRUSH brush = NULL;
			HWND item = ipdis->hwndItem;

			if (item == button1) {
				brush = btn1Color;
			}
			else if (item == button2) {
				brush = btn2Color;
			}
			else if (item == button3) {
				brush = btn3Color;
			}
			else {
				brush = btn4Color;
			}

			FillRect(ipdis->hDC, &ipdis->rcItem, brush);

			HPEN blackPen = CreatePen(BS_SOLID, 3, RGB(0, 0, 0));
			HPEN hOldPen = (HPEN)SelectObject(ipdis->hDC, blackPen);
			HBRUSH hOldBrush = (HBRUSH)SelectObject(ipdis->hDC, GetStockObject(NULL_BRUSH));

			Rectangle(ipdis->hDC, ipdis->rcItem.left, ipdis->rcItem.top, ipdis->rcItem.right, ipdis->rcItem.bottom);

			SelectObject(ipdis->hDC, hOldPen);
			SelectObject(ipdis->hDC, hOldBrush);

			DeleteObject(blackPen);

			wchar_t buttonText[255];
			GetWindowTextW(ipdis->hwndItem, buttonText, _countof(buttonText));

			SetTextColor(ipdis->hDC, RGB(255, 255, 255));
			SetBkMode(ipdis->hDC, TRANSPARENT);

			DrawTextW(ipdis->hDC, buttonText, -1, &ipdis->rcItem, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

			if (ipdis->itemState == ODS_FOCUS) {
				DrawFocusRect(ipdis->hDC, &ipdis->rcItem);
			}

			if (ipdis->itemState == ODS_SELECTED) {
				RECT rc = ipdis->rcItem;
				InflateRect(&rc, -1, -1);
				DrawEdge(ipdis->hDC, &rc, BDR_SUNKENOUTER, BF_RECT);
			}
			return TRUE;
		}
		else if (ipdis->CtlID == HEALTH1_ID || ipdis->CtlID == HEALTH2_ID || ipdis->CtlID == HEALTH3_ID) {
			HPEN pen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));

			if (ipdis->CtlID == HEALTH1_ID) {
				if (helthcount <= 2) {
					usinghlthColor = hlthDColor;
				}
				else {
					usinghlthColor = hlthColor;
				}
			}
			else if (ipdis->CtlID == HEALTH2_ID) {
				if (helthcount <= 1) {
					usinghlthColor = hlthDColor;
				}
				else {
					usinghlthColor = hlthColor;
				}
			}
			else if (ipdis->CtlID == HEALTH3_ID) {
				if (helthcount <= 0) {
					usinghlthColor = hlthDColor;
				}
				else {
					usinghlthColor = hlthColor;
				}
			}

			HBRUSH hOldBrush = (HBRUSH)SelectObject(ipdis->hDC, usinghlthColor);
			HPEN hOldPen = (HPEN)SelectObject(ipdis->hDC, pen);

			HWND item = ipdis->hwndItem;

			POINT points[6];

			points[0].y = 15;
			points[1].y = 25;
			points[2].y = 15;
			points[3].y = 25;
			points[4].y = 45;
			points[5].y = 25;

			points[0].x = 13;
			points[1].x = 25;
			points[2].x = 38;
			points[3].x = 49;
			points[4].x = 25;
			points[5].x = 0;

			Polygon(ipdis->hDC, points, 6);

			SelectObject(ipdis->hDC, hOldBrush);
			SelectObject(ipdis->hDC, hOldPen);

			DeleteObject(pen);

			wchar_t ButtonText[255];
			GetWindowTextW(ipdis->hwndItem, ButtonText, _countof(ButtonText));

			SetTextColor(ipdis->hDC, RGB(0, 0, 0));
			SetBkMode(ipdis->hDC, TRANSPARENT);

			DrawTextW(ipdis->hDC, ButtonText, -1, &ipdis->rcItem, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
			return TRUE;
		}
		else if (ipdis->CtlID == PICTCHER_ID) {
			;
			SelectObject(ipdis->hDC, usingColorPich);
			FillRect(ipdis->hDC, &ipdis->rcItem, usingColorPich);

			HPEN pen = CreatePen(BS_SOLID, 3, RGB(0, 0, 0));
			HPEN hOldPen = (HPEN)SelectObject(ipdis->hDC, pen);

			Rectangle(ipdis->hDC, ipdis->rcItem.left, ipdis->rcItem.top, ipdis->rcItem.right, ipdis->rcItem.bottom);

			SelectObject(ipdis->hDC, hOldPen);
			DeleteObject(pen);

			return TRUE;
		}
		break;
	}
	case WM_TIMER:
		if (wParam == Timer_color_change) {
			colorindex++;
			if (colorindex < colorline.size()) {
				usingColorPich = colorline[colorindex];
				InvalidateRect(pictcher, NULL, TRUE);
			}
			else {
				KillTimer(hwnd, Timer_color_change);
				colorindex = 0;
				usingColorPich = pichColor1;
				InvalidateRect(pictcher, NULL, NULL);
				gameState = true;
			}
		}
		if (wParam == Timer_Clean) {
			usingColorPich = pichColor1;
			InvalidateRect(pictcher, NULL, TRUE);
			KillTimer(hwnd, Timer_Clean);
		}
		return 0;
	case WM_COMMAND:
		if (LOWORD(wParam) == BUTTON1_ID) {

			if (gameState == false) {
				SetWindowTextW(text, L"take in mind");
				for (int i = 0; i < startNumber; i++) {
					colorline.push_back(colors[rNum() % 4]);
				}
				colorindex = 0;

				if (colorline.size() != 0) {
					usingColorPich = colorline[colorindex];
					InvalidateRect(pictcher, NULL, NULL);
					SetTimer(hwnd, Timer_color_change, 500, NULL);
				}
			}
			else {
				chused = 0;
				if (colorline[raund] == colors[chused]) {
					SetWindowTextW(text, L"you are right");
					usingColorPich = pichColor2;
					InvalidateRect(pictcher, NULL, NULL);
					SetTimer(hwnd, Timer_Clean, 100, NULL);

					if (raund == colorline.size() - 1) {
						SetWindowTextW(text, L"click on button");
						startNumber++;
						raund = 0;
						if (helthcount < 3) {
							helthcount++;
							InvalidateRect(health1, NULL, NULL);
							InvalidateRect(health2, NULL, NULL);
							InvalidateRect(health3, NULL, NULL);
						}
						colorline.clear();
						gameState = false;
					}
					else {
						raund++;
					}
				}
				else {
					usingColorPich = pichColor4;
					InvalidateRect(pictcher, NULL, NULL);
					SetTimer(hwnd, Timer_Clean, 100, NULL);

					helthcount--;
					if (helthcount < 0) {
						MessageBoxW(0, L"You lose", L"Message", MB_OK);
						PostQuitMessage(0);
					}
					InvalidateRect(health1, NULL, NULL);
					InvalidateRect(health2, NULL, NULL);
					InvalidateRect(health3, NULL, NULL);
					if (startNumber != 1) {
						startNumber--;
					}
					colorline.clear();
					raund = 0;
					gameState = false;
					SetWindowTextW(text, L"click on button");
				}
			}
		}
		if (LOWORD(wParam) == BUTTON2_ID) {
			if (gameState == false) {
				SetWindowTextW(text, L"take in mind");
				for (int i = 0; i < startNumber; i++) {
					colorline.push_back(colors[rNum() % 4]);
				}
				colorindex = 0;

				if (colorline.size() != 0) {
					usingColorPich = colorline[colorindex];
					InvalidateRect(pictcher, NULL, NULL);
					SetTimer(hwnd, Timer_color_change, 500, NULL);
				}
			}
			else {
				chused = 1;
				if (colorline[raund] == colors[chused]) {
					SetWindowTextW(text, L"you are right");
					usingColorPich = pichColor2;
					InvalidateRect(pictcher, NULL, NULL);
					SetTimer(hwnd, Timer_Clean, 100, NULL);

					if (raund == colorline.size() - 1) {
						SetWindowTextW(text, L"click on button");
						startNumber++;
						raund = 0;
						if (helthcount < 3) {
							helthcount++;
							InvalidateRect(health1, NULL, NULL);
							InvalidateRect(health2, NULL, NULL);
							InvalidateRect(health3, NULL, NULL);
						}
						colorline.clear();
						gameState = false;
					}
					else {
						raund++;
					}
				}
				else {
					SetWindowTextW(text, L"click on button");
					usingColorPich = pichColor4;
					InvalidateRect(pictcher, NULL, NULL);
					SetTimer(hwnd, Timer_Clean, 100, NULL);

					helthcount--;
					if (helthcount < 0) {
						MessageBoxW(0, L"You lose", L"Message", MB_OK);
						PostQuitMessage(0);
					}
					InvalidateRect(health1, NULL, NULL);
					InvalidateRect(health2, NULL, NULL);
					InvalidateRect(health3, NULL, NULL);
					if (startNumber != 1) {
						startNumber--;
					}
					colorline.clear();
					raund = 0;
					gameState = false;
				}
			}
		}
		if (LOWORD(wParam) == BUTTON3_ID) {
			if (gameState == false) {
				SetWindowTextW(text, L"take in mind");
				for (int i = 0; i < startNumber; i++) {
					colorline.push_back(colors[rNum() % 4]);
				}
				colorindex = 0;

				if (colorline.size() != 0) {
					usingColorPich = colorline[colorindex];
					InvalidateRect(pictcher, NULL, NULL);
					SetTimer(hwnd, Timer_color_change, 500, NULL);
				}
			}
			else {
				chused = 2;
				if (colorline[raund] == colors[chused]) {
					SetWindowTextW(text, L"you are right");
					usingColorPich = pichColor2;
					InvalidateRect(pictcher, NULL, NULL);
					SetTimer(hwnd, Timer_Clean, 100, NULL);

					if (raund == colorline.size() - 1) {
						SetWindowTextW(text, L"click on button");
						startNumber++;
						raund = 0;
						if (helthcount < 3) {
							helthcount++;
							InvalidateRect(health1, NULL, NULL);
							InvalidateRect(health2, NULL, NULL);
							InvalidateRect(health3, NULL, NULL);
						}
						colorline.clear();
						gameState = false;
					}
					else {
						raund++;
					}
				}
				else {
					SetWindowTextW(text, L"click on button");
					usingColorPich = pichColor4;
					InvalidateRect(pictcher, NULL, NULL);
					SetTimer(hwnd, Timer_Clean, 100, NULL);

					helthcount--;
					if (helthcount < 0) {
						MessageBoxW(0, L"You lose", L"Message", MB_OK);
						PostQuitMessage(0);
					}
					InvalidateRect(health1, NULL, NULL);
					InvalidateRect(health2, NULL, NULL);
					InvalidateRect(health3, NULL, NULL);
					if (startNumber != 1) {
						startNumber--;
					}
					colorline.clear();
					raund = 0;
					gameState = false;
				}
			}
		}
		if (LOWORD(wParam) == BUTTON4_ID) {
			if (gameState == false) {
				SetWindowTextW(text, L"take in mind");
				for (int i = 0; i < startNumber; i++) {
					colorline.push_back(colors[rNum() % 4]);
				}
				colorindex = 0;

				if (colorline.size() != 0) {
					usingColorPich = colorline[colorindex];
					InvalidateRect(pictcher, NULL, NULL);
					SetTimer(hwnd, Timer_color_change, 500, NULL);
				}
			}
			else {
				chused = 3;
				if (colorline[raund] == colors[chused]) {
					SetWindowTextW(text, L"you are right");
					usingColorPich = pichColor2;
					InvalidateRect(pictcher, NULL, NULL);
					SetTimer(hwnd, Timer_Clean, 100, NULL);

					if (raund == colorline.size() - 1) {
						SetWindowTextW(text, L"click on button");
						startNumber++;
						raund = 0;
						if (helthcount < 3) {
							helthcount++;
							InvalidateRect(health1, NULL, NULL);
							InvalidateRect(health2, NULL, NULL);
							InvalidateRect(health3, NULL, NULL);
						}
						colorline.clear();
						gameState = false;
					}
					else {
						raund++;
					}
				}
				else {
					SetWindowTextW(text, L"click on button");
					usingColorPich = pichColor4;
					InvalidateRect(pictcher, NULL, NULL);
					SetTimer(hwnd, Timer_Clean, 100, NULL);

					helthcount--;
					if (helthcount < 0) {
						MessageBoxW(0, L"You lose", L"Message", MB_OK);
						PostQuitMessage(0);
					}
					InvalidateRect(health1, NULL, NULL);
					InvalidateRect(health2, NULL, NULL);
					InvalidateRect(health3, NULL, NULL);
					if (startNumber != 1) {
						startNumber--;
					}
					colorline.clear();
					raund = 0;
					gameState = false;
				}
			}
		}
		return 0;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}