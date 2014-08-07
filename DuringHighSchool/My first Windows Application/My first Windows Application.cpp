//Name: My first Windows Application
//Author: Popov Igor

#include <windows.h>

LRESULT CALLBACK WndProc ( HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam );

int WINAPI WinMain ( HINSTANCE hInstance, HINSTANCE hPrevInstance,
										 LPSTR lpszCmdLine, int nCmdShow ) {
	static char * lpszAppName = "My first Windows Application";
	HWND hwnd;
	MSG msg;
	WNDCLASS wndclass;

	if ( !hPrevInstance ) {
		wndclass.lpszClassName = lpszAppName;
		wndclass.lpfnWndProc   = ( WNDPROC ) WndProc;
		wndclass.style         = CS_HREDRAW | CS_VREDRAW;
		wndclass.hInstance     = hInstance;
		wndclass.lpszMenuName  = NULL;
		wndclass.hbrBackground = ( HBRUSH ) GetStockObject ( WHITE_BRUSH );
		wndclass.hIcon         = LoadIcon ( NULL, IDI_APPLICATION );
		wndclass.hCursor       = LoadCursor ( NULL, IDC_ARROW );
		wndclass.cbClsExtra    = 0;
		wndclass.cbWndExtra    = 0;
		if ( !RegisterClass ( &wndclass ) ) return FALSE;
	}
	
	hwnd = CreateWindow ( lpszAppName, "Prima mea aplicatie Windows",
												WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
												CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL );
	if ( !hwnd ) return FALSE;
	ShowWindow ( hwnd, SW_SHOW );
	UpdateWindow ( hwnd );
	
	while ( GetMessage ( &msg, NULL, 0, 0 ) ) {
		TranslateMessage ( &msg );
		DispatchMessage ( &msg );
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc ( HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam ) {
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;
	char text[] = "Acest program afiseaza un text centrat in fereastra!";
	
	switch ( message ) {
		case WM_PAINT :
			hdc=BeginPaint ( hwnd, &ps );
			GetClientRect ( hwnd, &rect );
			DrawText ( hdc, text, strlen ( text ), &rect, DT_CENTER | DT_EXTERNALLEADING |
								 DT_NOCLIP | DT_WORDBREAK );
			EndPaint ( hwnd, &ps );
			return 0;
		case WM_DESTROY :
			PostQuitMessage ( 0 );
			return 0;
  	default :
			return DefWindowProc ( hwnd, message, wParam, lParam );
	}
}
