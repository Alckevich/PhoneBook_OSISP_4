// Osisp_laba_4.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Osisp_laba_4.h"
#include <sstream>

#define MAX_LOADSTRING 100

#define IDC_FILTER_BUTTON	701			// Button identifier
#define IDC_ALL_BUTTON		702			// Button identifier
#define IDC_MAIN_EDIT		102			// Edit box identifier
#define IDC_LASTNAME_EDIT	103
#define IDC_LISTBOX			804
#define IDC_CURENTRY		805

void ApplyFilter(void);
void LoadPhoneBook(void);
void DisplayAllEntries(void);
void DisplayEntries(void);
void DisplayEntry(int index);

HWND hEdit, hText;
HWND hCurrentEntryEdit, hCurrentEntryLabel;
HWND hLastNameLabel, hLastNameEdit;
HWND hPhoneLabel, hPhoneEdit;
HWND hAddressLabel, hAddressEdit;
HWND hFindButton;
HWND hListBox;

std::vector<ENTRY> entries;

PhoneBookRepository phoneBookRepository;

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_OSISP_LABA_4, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_OSISP_LABA_4));
	
	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_OSISP_LABA_4));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_OSISP_LABA_4);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   hLastNameLabel = CreateWindowEx(NULL
	   , L"STATIC", NULL
	   , WS_CHILD | WS_VISIBLE
	   , 20, 20, 70, 23
	   , hWnd, NULL, hInstance, NULL);

   SetWindowTextW(hLastNameLabel, L"LastName:");

   hLastNameEdit = CreateWindowEx(WS_EX_CLIENTEDGE,
	   L"EDIT",
	   L"",
	   WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL,
	   100, 20, 200, 23,
	   hWnd,
	   (HMENU)IDC_LASTNAME_EDIT,
	   GetModuleHandle(NULL),
	   NULL);


   hPhoneLabel = CreateWindowEx(NULL
	   , L"STATIC", NULL
	   , WS_CHILD | WS_VISIBLE
	   , 20, 50, 70, 21
	   , hWnd, NULL, hInstance, NULL);

   SetWindowTextW(hPhoneLabel, L"Phone:");

   hPhoneEdit = CreateWindowEx(WS_EX_CLIENTEDGE,
	   L"EDIT",
	   L"",
	   WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL,
	   100, 50, 200, 23,
	   hWnd,
	   (HMENU)IDC_MAIN_EDIT,
	   GetModuleHandle(NULL),
	   NULL);


   hAddressLabel = CreateWindowEx(NULL
	   , L"STATIC", NULL
	   , WS_CHILD | WS_VISIBLE
	   , 20, 80, 70, 21
	   , hWnd, NULL, hInstance, NULL);

   SetWindowTextW(hAddressLabel, L"Address:");

   hAddressEdit = CreateWindowEx(WS_EX_CLIENTEDGE,
	   L"EDIT",
	   L"",
	   WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL,
	   100, 80, 200, 23,
	   hWnd,
	   (HMENU)IDC_MAIN_EDIT,
	   GetModuleHandle(NULL),
	   NULL);

   hFindButton = CreateWindowEx(NULL,
	   L"BUTTON",
	   L"All",
	   WS_TABSTOP | WS_VISIBLE |
	   WS_CHILD | BS_DEFPUSHBUTTON,
	   190, 105, 50, 23,
	   hWnd,
	   (HMENU)IDC_ALL_BUTTON,
	   GetModuleHandle(NULL),
	   NULL);

   hFindButton = CreateWindowEx(NULL,
	   L"BUTTON",
	   L"Find",
	   WS_TABSTOP | WS_VISIBLE |
	   WS_CHILD | BS_DEFPUSHBUTTON,
	   250, 105, 50, 23,
	   hWnd,
	   (HMENU)IDC_FILTER_BUTTON,
	   GetModuleHandle(NULL),
	   NULL);


   hCurrentEntryLabel = CreateWindowEx(NULL
	   , L"STATIC", NULL
	   , WS_CHILD | WS_VISIBLE
	   , 100, 160, 100, 21
	   , hWnd, NULL, hInstance, NULL);

   SetWindowTextW(hCurrentEntryLabel, L"Current Entry:");

   hCurrentEntryEdit = CreateWindowEx(WS_EX_CLIENTEDGE,
	   L"EDIT",
	   L"",
	   WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_AUTOVSCROLL | ES_MULTILINE,
	   100, 190, 200, 200,
	   hWnd,
	   (HMENU)IDC_CURENTRY,
	   GetModuleHandle(NULL),
	   NULL);

   // Adding a ListBox.
   hListBox = CreateWindowEx(WS_EX_CLIENTEDGE
	   , L"LISTBOX", NULL
	   , WS_CHILD | WS_VISIBLE | ES_AUTOVSCROLL | LBS_NOTIFY
	   , 400, 20, 500, 400
	   , hWnd, (HMENU)IDC_LISTBOX, hInstance, NULL);

   DisplayAllEntries();
   SetFocus(hListBox);
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		case IDC_FILTER_BUTTON:
			ApplyFilter();
			break;
		case IDC_ALL_BUTTON:
			DisplayAllEntries();
			break;
		case IDC_LISTBOX: {
			switch (wmEvent) {
				
			case LBN_SELCHANGE:
				int i = SendMessage(hListBox, LB_GETCURSEL, 0, 0);
				DisplayEntry(i);
				return TRUE;

			}
			return FALSE;
		}
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

BOOL isNullOrEmpty(char* a){
	if (a == NULL){
		return true;
	}

	if (a[0] == '\0'){
		return true;
	}

	return false;
}

void DisplayAllEntries(){
	LoadPhoneBook();
	DisplayEntries();
}

void DisplayEntry(int index){
	ENTRY entry = entries[index];
	std::ostringstream oss;
	oss << "Phone: "	 << entry.phone		<< "\r\n";
	oss << "Name: "		 << entry.name		<< "\r\n";
	oss << "Lastname: "  << entry.lastname	<< "\r\n";
	oss << "Patronym: "  << entry.patronym	<< "\r\n";
	oss << "Street: "	 << entry.street	<< "\r\n";
	oss << "House: "	 << entry.house		<< "\r\n";
	oss << "Housing: "	 << entry.housing	<< "\r\n";
	oss << "Apartment: " << entry.apartment << "\r\n";
	
	std::string temp = oss.str();
	std::wstring wstr(temp.begin(), temp.end());
	SetWindowText(hCurrentEntryEdit, wstr.c_str());
}

void ApplyFilter(){
	char buff[1024];

	GetWindowTextA(hLastNameEdit, buff, 1024);
	if (!isNullOrEmpty(buff)){
		phoneBookRepository.FindByLastName(buff, &entries);
	}
	
	DisplayEntries();
}

void LoadPhoneBook(){
	phoneBookRepository.Get(&entries);
}

void DisplayEntries(){
	SendMessage(hListBox, LB_RESETCONTENT, 0, 0);

	for (int i = 0; i < entries.size(); i++){
		std::wstring wstr(entries[i].name.begin(), entries[i].name.end());
		SendMessage(hListBox, LB_ADDSTRING, NULL, (LPARAM)wstr.c_str());
	}
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
