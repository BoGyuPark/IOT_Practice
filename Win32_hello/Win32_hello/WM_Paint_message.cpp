#include <windows.h>
#include <stdio.h>
#include<time.h>
#include "resource.h"
#include "bird.h"

//typedef struct {
//	int xPos, yPos, width, height;
//}Rect, *pRect;

LRESULT CALLBACK MyWndProc(HWND, UINT, WPARAM, LPARAM);

int main()
{
	WNDCLASS wc = { 0, };
	wc.lpszClassName = "MyWnd";
	wc.lpfnWndProc = MyWndProc;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadCursor(0, IDC_ARROW);
	wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	RegisterClass(&wc);

	/*HWND hwnd = CreateWindow("MyWnd", "Hellow Window",
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		100, 100, 200, 100, 0, 0, 0, 0);*/

	/*CreateWindow("MyWnd", "Hellow Window",
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, 0, 0);*/
	
	//저절로 움직이는 애니메이션
	//호출시 최대 크기버튼, 최소 크기버튼 없앰
	CreateWindow("MyWnd", "Hellow Window",
		WS_OVERLAPPEDWINDOW& ~WS_MAXIMIZEBOX& ~WS_MINIMIZEBOX | WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, 0, 0);


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
	/*
	//폰트 설정
	//common dialog box structure
	static CHOOSEFONT cf;
	//logical font structure
	static LOGFONT lf;
	//current text color
	static DWORD rgbCurrent;
	HFONT hfont, hfontPrev;
	DWORD rgbPrev;


	//펜 설정
	//common dialog box structure
	static CHOOSECOLOR cc;
	//arry of custom colors
	static COLORREF acrCustClr[16];
	//pen handle
	HPEN hPen, hPenPrev;
	//initial color selection
	static DWORD rgbCurrentPen;


	//붓 설정
	HBRUSH hBrush, hBrushPrev;
	static DWORD rgbCurrentBrush;
	*/


	//비트맵
	static HBITMAP hBitmap;
	static BITMAP bm;
	static int bmpWidth, bmpHeight;
	HDC memDC;

	//여러가지 이미지
	static Bird birds[] = {
		 {red_bird,sizeof(red_bird) / sizeof(Rect),0,},
		 {green_bird,sizeof(green_bird) / sizeof(Rect),0,},
		 {bomb_bird,sizeof(bomb_bird) / sizeof(Rect),0,},
		 {yellow_bird,sizeof(yellow_bird) / sizeof(Rect),0,},
		 {red_mini_bird,sizeof(red_mini_bird) / sizeof(Rect),0,},
		 {bluesky_bird,sizeof(bluesky_bird) / sizeof(Rect),0,},
	};
	int i;
	int cur_img;

	
	//그림 움직이기
	static int dx = 0, dy = 0;
	//	int i, j;
	//const Rect red_bird = { 10,14,102,97 };	//실제로는 직접 좌표 찾아야함
	const Rect red_bird[] = {
		{ 10,14,102,97 },
		{ 116,14,100,97 },
		{ 10,118,102,97 },
		{ 116,118,100,97 },
		{ 10,226,102,93 },
	};
	static int cur_red_bird = 0;

	static int xOrg, yOrg, widthClient, heightClient, xDir, yDir;
	int xBirdRight, xBirdLeft, yBirdBottom, yBirdTop;
	

	//char str[] = "Hello World!";

	if (msg == WM_CREATE) {
		/*
		////폰트 설정
		//ZeroMemory(&cf, sizeof(cf));
		//cf.lStructSize = sizeof(cf);
		//cf.hwndOwner = hWnd;
		//cf.lpLogFont = &lf;
		//cf.rgbColors = rgbCurrent;
		//cf.Flags = CF_SCREENFONTS | CF_EFFECTS;
		//ChooseFont(&cf);

		////펜 설정
		//ZeroMemory(&cc, sizeof(cc));
		//cc.lStructSize = sizeof(cc);
		//cc.hwndOwner = hWnd;
		//cc.lpCustColors = (LPDWORD)acrCustClr;
		//cc.rgbResult = rgbCurrentPen;
		//cc.Flags = CC_FULLOPEN | CC_RGBINIT;
		//ChooseColor(&cc);
		*/

		//비트맵 로드
		//리소스로 가져오기
		hBitmap = LoadBitmap(GetModuleHandle(0), MAKEINTRESOURCE(IDB_BITMAP1));

		////파일 직접 가져오기
		//hBitmap = (HBITMAP)LoadImage(0, "angry_birds.bmp", 
		//	IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		GetObject(hBitmap, sizeof(bm), &bm);
		bmpWidth = bm.bmWidth;
		bmpHeight = bm.bmHeight;


		//타이머 설정
		SetTimer(hWnd, 1010, 200, NULL);	//초당 약 33번 WM_TIMER 메세지 발생
		SetTimer(hWnd, 1011, 30, NULL);
		srand(time(0));

		return 0;
	}
	else if (msg == WM_SIZE) {

		//사용자 영역의 가로, 세로 크기
		widthClient = LOWORD(lParam);
		heightClient = HIWORD(lParam);

		for (i = 0; i < sizeof(birds) / sizeof(Bird); i++) {
			//새의 첫 위치를 저장
			birds[i].org.xOrg = rand() % widthClient;
			birds[i].org.yOrg = rand() % heightClient;

			// 0 or 1 값 저장
			birds[i].dir.xDir = rand() % 2;
			birds[i].dir.yDir = rand() % 2;
		}
		

		/*xOrg = rand() % widthClient;
		yOrg = rand() % heightClient;

		xDir = rand() % 2;
		yDir = rand() % 2;*/

		return 0;
	}
	else if (msg == WM_DESTROY) {
		//타이머 종료
		KillTimer(hWnd, 1010); KillTimer(hWnd, 1011);

		DeleteObject(hBitmap);
		PostQuitMessage(0);
		return 0;
	}
	else if (msg == WM_PAINT) {
		PAINTSTRUCT ps;
		HDC hdc;

		//char str[] = "Hello World!";
		hdc = BeginPaint(hWnd, &ps);

		/*
		//1. 텍스트 그리기

		hfont = CreateFontIndirect(cf.lpLogFont);	//폰트를 생성하는 함수
		
		//새로운 폰트를 선택할 때 이전에 사용하던 폰트의 핸들을 리턴해줌
		hfontPrev = (HFONT)SelectObject(hdc, hfont);	// 새로운 폰트, 붓, 펜 등을 선택하는 함수
		rgbCurrent = cf.rgbColors;
		rgbPrev = SetTextColor(hdc, rgbCurrent);

		TextOut(hdc, 100 + dx, 100 + dy, str, strlen(str));

		SelectObject(hdc, hfontPrev);
		SetTextColor(hdc, rgbPrev);

		//2. 점찍기
		for (int i = 0; i < 30; i++) {
			for (int j = 0; j < 30; j++) {
				SetPixel(hdc, 100 + i + dx, 150 + j + dy, RGB(255, 0, 0));
			}
		}

		//3. 선 그리기
		hPen = CreatePen(PS_SOLID, 3, cc.rgbResult);
		rgbCurrentPen = cc.rgbResult;
		hPenPrev = (HPEN)SelectObject(hdc, hPen);

		MoveToEx(hdc, 100+dx, 200+dy, NULL);
		LineTo(hdc, 150+dx, 250+dy);

		//4. 도형 그리기

		hBrush = CreateSolidBrush(cc.rgbResult);
		rgbCurrentBrush = cc.rgbResult;
		hBrushPrev = (HBRUSH)SelectObject(hdc, hBrush);

		Rectangle(hdc, 100+dx, 300+dy, 150+dx, 350+dy);
		Ellipse(hdc, 200+dx, 300+dy, 250+dx, 350+dy);

		SelectObject(hdc, hBrushPrev);
		DeleteObject(hBrush);

		SelectObject(hdc, hPenPrev);
		DeleteObject(hPen);*/

		//5. 비트맵 그리기
		memDC = CreateCompatibleDC(hdc);
		SelectObject(memDC, hBitmap);

		for (i = 0; i < sizeof(birds) / sizeof(Bird); i++) {
			cur_img = birds[i].cur_img;

			//2번째, 3번째 인자 : DC그림이 그려질 (x,y)좌표
			BitBlt(
				hdc,
				birds[i].org.xOrg + birds[i].ds.dx,
				birds[i].org.yOrg + birds[i].ds.dy,
				birds[i].images[cur_img].width,
				birds[i].images[cur_img].height,
				memDC,
				birds[i].images[cur_img].xPos,
				birds[i].images[cur_img].yPos,
				SRCCOPY);
		}
		
		//BitBlt(hdc, 300+dx, 100+dy, bmpWidth, bmpHeight, memDC, 0, 0, SRCCOPY);
		DeleteDC(memDC);

		EndPaint(hWnd, &ps);
		return 0;
		/*
		////하드웨어적으로 WM_PAINT 발생
		//PAINTSTRUCT ps;
		//HDC hdc;
		//hdc = BeginPaint(hWnd, &ps);
		//printf("(%d,%d) - (%d,%d)\n",
		//	ps.rcPaint.left,
		//	ps.rcPaint.top,
		//	ps.rcPaint.right,
		//	ps.rcPaint.bottom);
		//EndPaint(hWnd, &ps);
		//return 0;

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
		*/
	}
	else if (msg == WM_CHAR) {
		RECT rc1 = { 10,10,20,20 };
		RECT rc2 = { 30,30,40,40 };
		InvalidateRect(hWnd, &rc1, TRUE);
		InvalidateRect(hWnd, &rc2, TRUE);
		return 0;
	}
	else if (msg == WM_KEYDOWN) {
		switch (LOWORD(wParam))
		{
		case VK_LEFT:
			dx -= 5;	InvalidateRect(hWnd, NULL, TRUE);
			break;
		case VK_RIGHT:
			dx += 5;	InvalidateRect(hWnd, NULL, TRUE);
			break;
		case VK_UP:
			dy -= 5;	InvalidateRect(hWnd, NULL, TRUE);
			break;
		case VK_DOWN:
			dy += 5;	InvalidateRect(hWnd, NULL, TRUE);
			break;
		}
		//소프트웨어적으로 페인트메세지를 다시 보내어 다시 그리게 됨.
		//창을 최소화안해도 다시그려짐
		//InvalidateRect(hWnd, NULL, TRUE);
	}
	else if (msg == WM_TIMER) {
		switch (wParam) {
			//캐릭터가 움직이는 효과
			case 1010:
				for (i = 0; i < sizeof(birds) / sizeof(Bird); i++) {
					birds[i].cur_img++;
					if (birds[i].cur_img > birds[i].num_img - 1)
						birds[i].cur_img = 0;
				}
				
				/*cur_red_bird++;
				if (cur_red_bird > 4) cur_red_bird = 0;*/
				break;
			
			//캐릭터 자체가 움직이는 효과 (이동)
			case 1011:
				for (i = 0; i < sizeof(birds) / sizeof(Bird); i++) {
					//방향이 1이면 오른쪽으로 +5, 아니면 -5
					birds[i].ds.dx =
						birds[i].dir.xDir == 1 ?
						birds[i].ds.dx + 5 :
						birds[i].ds.dx - 5;

					//방향이 1이면 아래쪽으로 +5, 아니면 -5
					birds[i].ds.dy =
						birds[i].dir.yDir == 1 ?
						birds[i].ds.dy + 5 :
						birds[i].ds.dy - 5;

					cur_img = birds[i].cur_img;

					//새 그림의 오른쪽 경계
					xBirdRight =
						birds[i].org.xOrg +
						birds[i].ds.dx +
						birds[i].images[cur_img].width;

					//새 그림의 왼쪽 경계
					xBirdLeft =
						birds[i].org.xOrg +
						birds[i].ds.dx;

					//새 그림의 아래쪽 경계
					yBirdBottom =
						birds[i].org.yOrg +
						birds[i].ds.dy +
						birds[i].images[cur_img].height;

					//새 그림의 위쪽 경계
					yBirdTop =
						birds[i].org.yOrg +
						birds[i].ds.dy;

					//캐릭터가 창의 오른쪽을 넘어서면
					if (xBirdRight > widthClient)	birds[i].dir.xDir = 0;
					//캐릭터가 창의 왼쪽을 넘어서면
					else if (xBirdLeft < 0)	birds[i].dir.xDir = 1;

					//캐릭터가 창의 아래를 넘어서면
					if (yBirdBottom > heightClient)	birds[i].dir.yDir = 0;
					//캐릭터가 창의 위를 넘어서면
					else if (yBirdTop < 0)	birds[i].dir.yDir = 1;
				}
				
				/*dx = (xDir == 1) ? dx + 5 : dx - 5;
				dy = (yDir == 1) ? dy + 5 : dy - 5;
				
				xBirdRight = xOrg + dx + red_bird[cur_red_bird].width;
				xBirdLeft = xOrg + dx;
				yBirdBottom = yOrg + dy + red_bird[cur_red_bird].height;
				yBirdTop = yOrg + dy;

				if (xBirdRight > widthClient) xDir = 0;
				else if (xBirdLeft < 0) xDir = 1;

				if (yBirdBottom > heightClient) yDir = 0;
				else if (yBirdTop < 0) yDir = 1;*/
		
				break;
		}
		InvalidateRect(hWnd, NULL, TRUE);
		/*cur_red_bird++;
		if (cur_red_bird > 4) cur_red_bird = 0;
		InvalidateRect(hWnd, NULL, TRUE);*/
		return 0;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}