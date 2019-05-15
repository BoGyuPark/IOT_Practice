//#include <Windows.h>
//#include<stdio.h>
////WNDPROC OrgWndProc;
////LRESULT CALLBACK HookWndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
////	
////	char buff[32] = { 0, };
////	if (Msg == WM_CHAR) {
////		memset(buff, 0, sizeof(buff));
////		wsprintf(buff, "%c ", LOWORD(wParam));
////		SetWindowText(hWnd, buff);
////		//return 0;
////	}
////	else if (Msg == WM_MOUSEMOVE) {
////		memset(buff, 0, sizeof(buff));
////		wsprintf(buff, "(%d,%d) ",
////			LOWORD(lParam), HIWORD(lParam));
////		SetWindowText(hWnd, buff);
////		//return 0;
////	}
////	return OrgWndProc(hWnd, Msg, wParam, lParam);
////}
//
//LRESULT CALLBACK MyWndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
//
//	char buff[32] = { 0, };
//
//	if (Msg == WM_CHAR) {
//		memset(buff, 0, sizeof(buff));
//		wsprintf(buff, "%c ", LOWORD(wParam));
//		SetWindowText(hWnd, buff);
//		//return 0;
//	}
//	else if (Msg == WM_MOUSEMOVE) {
//		memset(buff, 0, sizeof(buff));
//		wsprintf(buff, "(%d,%d) ",
//			LOWORD(lParam), HIWORD(lParam));
//		SetWindowText(hWnd, buff);
//		//return 0;
//	}
//	else if (Msg == WM_DESTROY) {
//		PostQuitMessage(0);
//		return 0;
//	}
//	else if (Msg == WM_PAINT) {
//		const char * str = "Hello Windows!";
//		HDC hdc;
//		PAINTSTRUCT ps;
//		hdc = BeginPaint(hWnd, &ps);
//		TextOut(hdc, 10, 10, str, strlen(str));
//		EndPaint(hWnd, &ps);
//		return 0;
//	}
//	return DefWindowProc(hWnd, Msg, wParam, lParam);
//}
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
//					,LPSTR lpcmdLine, int nCmdShow) {
//
//	WNDCLASS wc = { 0, };
//	wc.lpszClassName = "MyWnd";
//	wc.lpfnWndProc = MyWndProc;
//	
//	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
//	wc.hCursor = LoadCursor(0, IDC_ARROW);
//	wc.hIcon = LoadIcon(0, IDI_APPLICATION);
//
//	RegisterClass(&wc);	//윈도우에게 wc를 등록 (OS에게 알림)
//
//	HWND hwnd = CreateWindow("MyWnd", "Hellow Window", 
//		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
//		100, 100, 200, 100,
//		0, 0, 0, 0);
//
//	MSG msg;
//	while (GetMessage(&msg, 0, 0, 0)) {
//		TranslateMessage(&msg);
//		DispatchMessage(&msg);
//	}
//	return msg.wParam;
//
//
//
//
//	//CreateWindow("button", "PUSH ME!", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
//	//	400, 400, 200, 200,
//	//	0, 0, 0, 0);
//
//	//MSG msg;
//
//	//while (GetMessage(&msg, 0, 0, 0)) { //메세지를 사용자로부터 입력받음 (윈도우 창에서 입력)
//	//	char buf[32] = { 0, };
//	//	if (msg.message == WM_CHAR) {
//	//		memset(buf, 0, sizeof(buf));
//	//		wsprintf(buf, "%c ", LOWORD(msg.wParam));
//	//		SetWindowText(msg.hwnd, buf);
//	//		//continue;
//	//	}
//	//	else if (msg.message == WM_MOUSEMOVE) {
//	//		memset(buf, 0, sizeof(buf));
//	//		wsprintf(buf, "(%d,%d) ", LOWORD(msg.lParam), HIWORD(msg.lParam));
//	//		SetWindowText(msg.hwnd, buf);
//	//		//continue;
//	//	}
//	//	TranslateMessage(&msg);
//	//	DispatchMessage(&msg);
//	//}
//
//	//return msg.wParam;
//
//
//	/*printf("Before MessageBox()\n");
//
//	CreateWindow("button", "PUSH ME!", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
//		100, 100, 100, 100,
//		0, 0, 0, 0);
//
//	CreateWindow("edit","EDIT ME!", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
//		100, 100, 200, 200,
//		0, 0, 0, 0);
//
//	CreateWindow("combobox", "SELECT ON ME!", WS_CHILD | WS_VISIBLE,
//		100, 100, 200, 200,
//		0, 0, 0, 0);
//
//	CreateWindow("listbox", "SELECT ON ME!", WS_CHILD | WS_VISIBLE,
//		100, 100, 200, 200,
//		0, 0, 0, 0);
//
//
//	MessageBox(0, "Hello Windows!", "", 0);
//
//	printf("After MessageBox()\n");*/
//
//	/*printf("%d\n", MessageBox(0, "Hello Windows!", "", 0));
//	MessageBox(0, "Hello Windows!", "win", 0);
//	printf("%d\n",MessageBox(0, "Hello Windows!", "win", MB_OKCANCEL));
//	printf("%d\n", MessageBox(0, "Hello Windows!", "win", MB_YESNOCANCEL));*/
//	//사용자 입력을 기다리는 함수 : 블럭킹 함수
//
//}