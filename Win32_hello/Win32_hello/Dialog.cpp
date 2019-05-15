#include<Windows.h>
#include "resource.h"
#include<stdio.h>
#include<math.h>

BOOL CALLBACK DlgProc(HWND hDlg, UINT Msg, WPARAM wParam, LPARAM lParam);

int main() {
	/*DialogBox(0, MAKEINTRESOURCE(IDD_DIALOG1), 0, DlgProc);
	return 0;*/
	HWND hDlg = CreateDialog(0, MAKEINTRESOURCE(IDD_DIALOG1), 0, DlgProc);
	ShowWindow(hDlg, SW_SHOW);
	MSG msg;
	while (GetMessage(&msg, 0, 0, 0)) {
		IsDialogMessage(hDlg, &msg);
	}
	return msg.wParam;
}

BOOL CALLBACK DlgProc(HWND hDlg, UINT Msg, WPARAM wParam, LPARAM lParam) {

	LPTSTR strPrincipal = new char[20],
		strInterest = new char[20], strPeriods = new char[20],
		strInterestEarned = new char[20], strAmountEarned = new char[20];

	HWND hWndPrincipal, hWndInterest, hWndPeriods, hWndCompound,
		hWndInterestEarned, hWndAmountEarned, hWndCalculate;

	double Principal, AnnualRate, InterestEarned;
	double FutureValue, RatePerPeriod, i;
	int NumberOfPeriods, CompoundType, n;

	hWndPrincipal = GetDlgItem(hDlg, IDC_PRINCIPAL);
	hWndInterest = GetDlgItem(hDlg, IDC_ANNUAL_RATE);
	hWndPeriods = GetDlgItem(hDlg, IDC_NBR_OF_PERIODS);
	hWndCompound = GetDlgItem(hDlg, IDC_COMPOUND);
	hWndInterestEarned = GetDlgItem(hDlg, IDC_INTEREST_EARNED);
	hWndAmountEarned = GetDlgItem(hDlg, IDC_AMOUNT_EARNED);
	hWndCalculate = GetDlgItem(hDlg, IDC_CALC);

	switch (Msg)
	{
	case WM_INITDIALOG:
		SetWindowText(hWndPrincipal, "0.00");
		SetWindowText(hWndInterest, "7.55");
		SetWindowText(hWndPeriods, "0");
		SetWindowText(hWndInterestEarned, "0.00");
		SetWindowText(hWndAmountEarned, "0.00");

		CheckRadioButton(hDlg, IDC_COMPOUND,
			IDC_ANNUALLY, IDC_COMPOUND);
		return TRUE;

	case WM_COMMAND:
		switch (wParam)
		{
		case IDC_CALC:
			GetWindowText(hWndPrincipal, strPrincipal, 20);
			GetWindowText(hWndInterest, strInterest, 10);
			GetWindowText(hWndPeriods, strPeriods, 8);

			Principal = atof(strPrincipal);
			AnnualRate = atof(strInterest) / 100;

			if (IsDlgButtonChecked(hDlg, IDC_COMPOUND) ==
				BST_CHECKED)
				CompoundType = 12;
			else if (IsDlgButtonChecked(hDlg, IDC_QUATERLY) ==
				BST_CHECKED)
				CompoundType = 4;
			else if (IsDlgButtonChecked(hDlg, IDC_SEMIANNUALLY) ==
				BST_CHECKED)
				CompoundType = 2;
			else // if( IsDlgButtonChecked(hWndDlg, IDC_ANNUALLY) == 
				 // BST_CHECKED )
				CompoundType = 1;

			NumberOfPeriods = atoi(strPeriods);
			i = AnnualRate / CompoundType;
			n = CompoundType * NumberOfPeriods;

			RatePerPeriod = AnnualRate / NumberOfPeriods;
			FutureValue = Principal * pow(1 + i, n);
			InterestEarned = FutureValue - Principal;

			sprintf(strInterestEarned, "$%.2f", InterestEarned);
			sprintf(strAmountEarned, "$%.2f", FutureValue);

			SetWindowText(hWndInterestEarned, strInterestEarned);
			SetWindowText(hWndAmountEarned, strAmountEarned);
			return TRUE;

		/*case IDCANCEL:
			EndDialog(hDlg, 0);
			return TRUE;*/
		case IDCANCEL:
			DestroyWindow(hDlg);
			PostQuitMessage(0);
			return TRUE;
		}
		break;
	}

	return FALSE;
}
