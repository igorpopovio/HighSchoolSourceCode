//Name: Mini-editor grafic
//Author: Popov Igor

#include <windows.h>
#include <math.h>
#include <string.h>
#include "edit.h"
#include "func.h"

LRESULT CALLBACK WndProc ( HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam );

HANDLE hInst;
HWND hMwnd;
int xClient, yClient;
POINT pos, vpos;
POINT punct[40];
int np=0;
int modx, mody;
bool tdesen=FALSE, mdesen=FALSE, tasta;
int tip_fig=IDM_POLIL;


int WINAPI WinMain ( HINSTANCE hInstance, HINSTANCE hPrevInstance,
										 LPSTR lpszCmdLine, int nCmdShow ) {
	static char * lpszAppName = "Mini-editor grafic";
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
	
	hwnd = CreateWindow ( lpszAppName, "Mini-editor grafic",
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
	char text[] = "Acest program afiseaza deocamdata un text centrat in fereastra!";
	
	switch ( message ) {
		case WM_SETFOCUS :
      ShowCursor ( TRUE );
      return 0;
    case WM_SIZE :
      xClient = LOWORD ( lParam );
      yClient = HIWORD ( lParam );
      tasta   = FALSE;
      return 0;
    case WM_KEYDOWN :
      if ( wParam == 'L' || wParam == 'C' || wParam == 'D' || wParam == 'G' ) {
        if ( mdesen || tdesen ) return 0;
      }
      else {
        switch ( wParam ) {
          case 'L' : tip_fig = IDM_POLIL; return 0;
          case 'C' : tip_fig = IDM_CERC;  return 0;
          case 'D' : tip_fig = IDM_DREPT; return 0;
          case 'G' : tip_fig = IDM_POLIG; return 0;
        }
        if ( cursor_pos ( wParam, lParam ) ) return 0;
        if ( wParam == VK_INSERT ) {
          insert1 ( );
          return 0;
        }
        if ( wParam != VK_END ) return 0;
        mdesen = TRUE;
      }
    case WM_RBUTTONDOWN :
      if ( mdesen ) {
        buton_dr ( message, lParam );
        Figura ( );
        ReleaseCapture ( );
        ClipCursor ( NULL );
        tdesen = FALSE;
        mdesen = FALSE;
        np     = 0;
        tasta  = FALSE;
      }
      return 0;
    case WM_LBUTTONDOWN :
      buton_st1 ( lParam );
      return 0;
		case WM_MOUSEMOVE :
			mouse_move ( lParam );
			return 0;
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
