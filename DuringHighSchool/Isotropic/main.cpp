#include <windows.h>
#include <math.h>

LRESULT CALLBACK WndProc ( HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam );

int WINAPI WinMain ( HINSTANCE hInstance, HINSTANCE hPrevInstance,
										 LPSTR lpszCmdLine, int nCmdShow ) {
	static char * lpszAppName = "Isotropic";
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
	
	hwnd = CreateWindow ( lpszAppName, "Isotropic",
												WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
												CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL );
	if ( !hwnd ) return FALSE;
	ShowWindow ( hwnd, nCmdShow );
	UpdateWindow ( hwnd );
	
	while ( GetMessage ( &msg, NULL, 0, 0 ) ) {
		TranslateMessage ( &msg );
		DispatchMessage ( &msg );
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc ( HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam ) {
	static POINT p;
	double fx, dx=0.0628;
	static HPEN hDotPen, h2Pen;
	HDC hdc;
	PAINTSTRUCT ps;
	
	switch ( message ) {
		case WM_CREATE :
			hDotPen = CreatePen ( PS_DOT, 1, RGB ( 0, 0, 0 ) );
			h2Pen   = CreatePen ( PS_SOLID, 2, RGB ( 0, 0, 0 ) );
			return 0;
		case WM_SIZE :
			p.x = LOWORD ( lParam );
			p.y = HIWORD ( lParam );
			return 0;
		case WM_PAINT :
			hdc=BeginPaint ( hwnd, &ps );
			SetMapMode ( hdc, MM_ISOTROPIC );
			SetWindowExtEx ( hdc, 62800, 20000, NULL );
			SetViewportOrgEx ( hdc, p.x/20, p.y/2, NULL );
			SetViewportExtEx ( hdc, p.x-p.x/10, -p.y, NULL );
			SelectObject ( hdc, GetStockObject ( NULL_BRUSH ) );
			SelectObject ( hdc, hDotPen );
			//Se traseaza axele
			MoveToEx ( hdc, 0, 0, NULL );
			LineTo ( hdc, 62800, 0 );
			MoveToEx ( hdc, 0, -10000, NULL );
			LineTo ( hdc, 0, 10000 );
			//Se traseaza dreptunghiul care incadreaza fereastra
			Rectangle ( hdc, 0, 10000, 62800, -10000 );
			//Se traseaza graficul
			SelectObject ( hdc, h2Pen );
			MoveToEx ( hdc, 0, 0, NULL );
			for ( fx=dx; fx<=6.29; fx+=dx )
				LineTo ( hdc, (int)(fx*10000), (int)(sin ( fx )*10000) );
      EndPaint ( hwnd, &ps );
			return 0;
		case WM_DESTROY :
			PostQuitMessage ( 0 );
			return 0;
  	default :
			return DefWindowProc ( hwnd, message, wParam, lParam );
	}
}
