#include <windows.h>
#include <stdio.h>

LRESULT CALLBACK MyWndProc(HWND,
	UINT,
	WPARAM,
	LPARAM);

int main()
{
	WNDCLASS wc = { 0, };
	wc.lpszClassName = "MyWnd";
	wc.lpfnWndProc = MyWndProc;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadCursor(0, IDC_ARROW);
	wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	RegisterClass(&wc);

	HWND hwnd = CreateWindow("MyWnd", "Hellow Window",
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		100, 100, 200, 100, 0, 0, 0, 0);

	MSG msg;
	while (GetMessage(&msg, 0, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK MyWndProc(HWND hWnd,
	UINT msg,
	WPARAM wParam,
	LPARAM lParam)
{
	if (msg == WM_DESTROY) {
		PostQuitMessage(0);
		return 0;
	}
	else if (msg == WM_PAINT) {

		//하드웨어적으로 WM_PAINT 발생
		PAINTSTRUCT ps;
		HDC hdc;
		hdc = BeginPaint(hWnd, &ps);
		printf("(%d,%d) - (%d,%d)\n",
			ps.rcPaint.left,
			ps.rcPaint.top,
			ps.rcPaint.right,
			ps.rcPaint.bottom);
		EndPaint(hWnd, &ps);
		return 0;

		//PAINTSTRUCT ps;
		//HDC hdc;
		//hdc = BeginPaint(hWnd, &ps);

		//printf(".");
		//// GDI 함수를 이용하여 그림 또는 글씨를 그린다.
		//Rectangle(hdc, 20, 20, 40, 40);
		//Rectangle(hdc, 120, 20, 140, 40);

		//EndPaint(hWnd, &ps);
		//return 0;

		//RECT rc;
		//GetUpdateRect(hWnd, &rc, TRUE);
		//ValidateRect(hWnd, &rc);
		//printf(".");
		//HDC hdc = GetDC(hWnd);
		//// GDI 함수를 이용하여 그림 또는 글씨를 그린다.
		//Rectangle(hdc, 20, 20, 40, 40);
		//Rectangle(hdc, 120, 20, 140, 40);
		//ReleaseDC(hWnd, hdc);
		//return 0;
	}
	else if (msg == WM_CHAR) {
		RECT rc1 = { 10,10,20,20 };
		RECT rc2 = { 30,30,40,40 };
		InvalidateRect(hWnd, &rc1, TRUE);
		InvalidateRect(hWnd, &rc2, TRUE);
		return 0;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}