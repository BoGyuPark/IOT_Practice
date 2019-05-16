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
	
	//������ �����̴� �ִϸ��̼�
	//ȣ��� �ִ� ũ���ư, �ּ� ũ���ư ����
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
	//��Ʈ ����
	//common dialog box structure
	static CHOOSEFONT cf;
	//logical font structure
	static LOGFONT lf;
	//current text color
	static DWORD rgbCurrent;
	HFONT hfont, hfontPrev;
	DWORD rgbPrev;


	//�� ����
	//common dialog box structure
	static CHOOSECOLOR cc;
	//arry of custom colors
	static COLORREF acrCustClr[16];
	//pen handle
	HPEN hPen, hPenPrev;
	//initial color selection
	static DWORD rgbCurrentPen;


	//�� ����
	HBRUSH hBrush, hBrushPrev;
	static DWORD rgbCurrentBrush;
	*/


	//��Ʈ��
	static HBITMAP hBitmap;
	static BITMAP bm;
	static int bmpWidth, bmpHeight;
	HDC memDC;

	//�������� �̹���
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

	
	//�׸� �����̱�
	static int dx = 0, dy = 0;
	//	int i, j;
	//const Rect red_bird = { 10,14,102,97 };	//�����δ� ���� ��ǥ ã�ƾ���
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
		////��Ʈ ����
		//ZeroMemory(&cf, sizeof(cf));
		//cf.lStructSize = sizeof(cf);
		//cf.hwndOwner = hWnd;
		//cf.lpLogFont = &lf;
		//cf.rgbColors = rgbCurrent;
		//cf.Flags = CF_SCREENFONTS | CF_EFFECTS;
		//ChooseFont(&cf);

		////�� ����
		//ZeroMemory(&cc, sizeof(cc));
		//cc.lStructSize = sizeof(cc);
		//cc.hwndOwner = hWnd;
		//cc.lpCustColors = (LPDWORD)acrCustClr;
		//cc.rgbResult = rgbCurrentPen;
		//cc.Flags = CC_FULLOPEN | CC_RGBINIT;
		//ChooseColor(&cc);
		*/

		//��Ʈ�� �ε�
		//���ҽ��� ��������
		hBitmap = LoadBitmap(GetModuleHandle(0), MAKEINTRESOURCE(IDB_BITMAP1));

		////���� ���� ��������
		//hBitmap = (HBITMAP)LoadImage(0, "angry_birds.bmp", 
		//	IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		GetObject(hBitmap, sizeof(bm), &bm);
		bmpWidth = bm.bmWidth;
		bmpHeight = bm.bmHeight;


		//Ÿ�̸� ����
		SetTimer(hWnd, 1010, 200, NULL);	//�ʴ� �� 33�� WM_TIMER �޼��� �߻�
		SetTimer(hWnd, 1011, 30, NULL);
		srand(time(0));

		return 0;
	}
	else if (msg == WM_SIZE) {

		//����� ������ ����, ���� ũ��
		widthClient = LOWORD(lParam);
		heightClient = HIWORD(lParam);

		for (i = 0; i < sizeof(birds) / sizeof(Bird); i++) {
			//���� ù ��ġ�� ����
			birds[i].org.xOrg = rand() % widthClient;
			birds[i].org.yOrg = rand() % heightClient;

			// 0 or 1 �� ����
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
		//Ÿ�̸� ����
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
		//1. �ؽ�Ʈ �׸���

		hfont = CreateFontIndirect(cf.lpLogFont);	//��Ʈ�� �����ϴ� �Լ�
		
		//���ο� ��Ʈ�� ������ �� ������ ����ϴ� ��Ʈ�� �ڵ��� ��������
		hfontPrev = (HFONT)SelectObject(hdc, hfont);	// ���ο� ��Ʈ, ��, �� ���� �����ϴ� �Լ�
		rgbCurrent = cf.rgbColors;
		rgbPrev = SetTextColor(hdc, rgbCurrent);

		TextOut(hdc, 100 + dx, 100 + dy, str, strlen(str));

		SelectObject(hdc, hfontPrev);
		SetTextColor(hdc, rgbPrev);

		//2. �����
		for (int i = 0; i < 30; i++) {
			for (int j = 0; j < 30; j++) {
				SetPixel(hdc, 100 + i + dx, 150 + j + dy, RGB(255, 0, 0));
			}
		}

		//3. �� �׸���
		hPen = CreatePen(PS_SOLID, 3, cc.rgbResult);
		rgbCurrentPen = cc.rgbResult;
		hPenPrev = (HPEN)SelectObject(hdc, hPen);

		MoveToEx(hdc, 100+dx, 200+dy, NULL);
		LineTo(hdc, 150+dx, 250+dy);

		//4. ���� �׸���

		hBrush = CreateSolidBrush(cc.rgbResult);
		rgbCurrentBrush = cc.rgbResult;
		hBrushPrev = (HBRUSH)SelectObject(hdc, hBrush);

		Rectangle(hdc, 100+dx, 300+dy, 150+dx, 350+dy);
		Ellipse(hdc, 200+dx, 300+dy, 250+dx, 350+dy);

		SelectObject(hdc, hBrushPrev);
		DeleteObject(hBrush);

		SelectObject(hdc, hPenPrev);
		DeleteObject(hPen);*/

		//5. ��Ʈ�� �׸���
		memDC = CreateCompatibleDC(hdc);
		SelectObject(memDC, hBitmap);

		for (i = 0; i < sizeof(birds) / sizeof(Bird); i++) {
			cur_img = birds[i].cur_img;

			//2��°, 3��° ���� : DC�׸��� �׷��� (x,y)��ǥ
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
		////�ϵ���������� WM_PAINT �߻�
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
		//// GDI �Լ��� �̿��Ͽ� �׸� �Ǵ� �۾��� �׸���.
		//Rectangle(hdc, 20, 20, 40, 40);
		//Rectangle(hdc, 120, 20, 140, 40);

		//EndPaint(hWnd, &ps);
		//return 0;

		//RECT rc;
		//GetUpdateRect(hWnd, &rc, TRUE);
		//ValidateRect(hWnd, &rc);
		//printf(".");
		//HDC hdc = GetDC(hWnd);
		//// GDI �Լ��� �̿��Ͽ� �׸� �Ǵ� �۾��� �׸���.
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
		//����Ʈ���������� ����Ʈ�޼����� �ٽ� ������ �ٽ� �׸��� ��.
		//â�� �ּ�ȭ���ص� �ٽñ׷���
		//InvalidateRect(hWnd, NULL, TRUE);
	}
	else if (msg == WM_TIMER) {
		switch (wParam) {
			//ĳ���Ͱ� �����̴� ȿ��
			case 1010:
				for (i = 0; i < sizeof(birds) / sizeof(Bird); i++) {
					birds[i].cur_img++;
					if (birds[i].cur_img > birds[i].num_img - 1)
						birds[i].cur_img = 0;
				}
				
				/*cur_red_bird++;
				if (cur_red_bird > 4) cur_red_bird = 0;*/
				break;
			
			//ĳ���� ��ü�� �����̴� ȿ�� (�̵�)
			case 1011:
				for (i = 0; i < sizeof(birds) / sizeof(Bird); i++) {
					//������ 1�̸� ���������� +5, �ƴϸ� -5
					birds[i].ds.dx =
						birds[i].dir.xDir == 1 ?
						birds[i].ds.dx + 5 :
						birds[i].ds.dx - 5;

					//������ 1�̸� �Ʒ������� +5, �ƴϸ� -5
					birds[i].ds.dy =
						birds[i].dir.yDir == 1 ?
						birds[i].ds.dy + 5 :
						birds[i].ds.dy - 5;

					cur_img = birds[i].cur_img;

					//�� �׸��� ������ ���
					xBirdRight =
						birds[i].org.xOrg +
						birds[i].ds.dx +
						birds[i].images[cur_img].width;

					//�� �׸��� ���� ���
					xBirdLeft =
						birds[i].org.xOrg +
						birds[i].ds.dx;

					//�� �׸��� �Ʒ��� ���
					yBirdBottom =
						birds[i].org.yOrg +
						birds[i].ds.dy +
						birds[i].images[cur_img].height;

					//�� �׸��� ���� ���
					yBirdTop =
						birds[i].org.yOrg +
						birds[i].ds.dy;

					//ĳ���Ͱ� â�� �������� �Ѿ��
					if (xBirdRight > widthClient)	birds[i].dir.xDir = 0;
					//ĳ���Ͱ� â�� ������ �Ѿ��
					else if (xBirdLeft < 0)	birds[i].dir.xDir = 1;

					//ĳ���Ͱ� â�� �Ʒ��� �Ѿ��
					if (yBirdBottom > heightClient)	birds[i].dir.yDir = 0;
					//ĳ���Ͱ� â�� ���� �Ѿ��
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