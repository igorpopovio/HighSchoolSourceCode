/*
  Name: Ceas Digital - Digital Clock
  Copyright: Freeware
  Author: Popov Igor
  Date: 13/07/07 20:28
  Description: This program shows the current date and time
*/



#include <windows.h>
#include <time.h>
#include <string.h>

#define ID_TIMER 1
#define YEAR ( datetime->tm_year % 100 )
#define MONTH ( datetime->tm_mon + 1 )
#define MDAY ( datetime->tm_mday )
#define WDAY ( datetime->tm_wday )
#define HOUR ( datetime->tm_hour )
#define MIN ( datetime->tm_min )
#define SEC ( datetime->tm_sec )

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
void SizeTheWindow ( short *, short *, short *, short * );
char sDate[2], sTime[2], sAMPM[2][5];
int iDate, iTime;

/*  Make the class name into a global variable  */
char szClassName[ ] = "Ceas";

int WINAPI WinMain (HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nFunsterStil)

{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    short xStart, yStart, xClient, yClient;
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_HREDRAW | CS_VREDRAW;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default color as the background of the window */
    wincl.hbrBackground = (HBRUSH) CreateSolidBrush ( RGB ( 255, 255, 0 ) );

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

		SizeTheWindow ( &xStart, &yStart, &xClient, &yClient );
    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           "Ceas Digital",       /* Title Text */
           WS_POPUP | WS_CAPTION | WS_SYSMENU, /* default window */
           xStart,       /* Windows decides the position */
           yStart,       /* where the window ends up on the screen */
           xClient,                 /* The programs width */
           yClient,                 /* and height in pixels */
           NULL,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );


		if ( !SetTimer ( hwnd, ID_TIMER, 1000, NULL ) ) {
			MessageBox ( hwnd, "Too many clocks or timers!",
									 szClassName, MB_ICONEXCLAMATION | MB_OK );
			return FALSE;
		}
		
    /* Make the window visible on the screen */
    ShowWindow ( hwnd, SW_SHOWNOACTIVATE );
    UpdateWindow ( hwnd );

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}

void SizeTheWindow ( short *pxStart, short *pyStart, short *pxClient, short *pyClient ) {
	HDC hdc;
	TEXTMETRIC tm;
	hdc=CreateIC ( "DISPLAY", NULL, NULL, NULL );
	GetTextMetrics ( hdc, &tm );
	DeleteDC ( hdc );
	
	*pxClient=2 * GetSystemMetrics ( SM_CXDLGFRAME ) + 16 * tm.tmAveCharWidth;
	*pxStart=GetSystemMetrics ( SM_CXSCREEN ) - *pxClient;
	*pyClient=2 * GetSystemMetrics ( SM_CYDLGFRAME ) + 4 * tm.tmHeight;
	*pyStart=0;		//GetSystemMetrics ( SM_CYSCREEN ) - *pyClient
}

void SetInternational ( void ) {
	static char cName[]="intl";
	iDate=GetProfileInt ( cName, "iDate", 0 );
	iTime=GetProfileInt ( cName, "iTime", 0 );
	GetProfileString ( cName, "sDate", "/", sDate, 2 );
	GetProfileString ( cName, "sTime", "/", sTime, 2 );
	GetProfileString ( cName, "s1159", "AM", sAMPM[0], 5 );
	GetProfileString ( cName, "s2359", "PM", sAMPM[1], 5 );
}

void WndPaint ( HWND hwnd, HDC hdc ) {
	static char szWday[]="Sun\0Mon\0Tue\0Wed\0Thu\0Fri\0Sat";
	char cBuffer[40];
	long lTime;
	RECT rect;
	short nLength;
	struct tm *datetime;
	time ( &lTime );
	datetime=localtime ( &lTime );
	nLength=wsprintf ( cBuffer, " %s %d%s%02d%s%02d \r\n",
										 ( LPSTR ) szWday + 4 * WDAY,
										 iDate==1?MDAY:iDate==2?YEAR:MONTH, ( LPSTR ) sDate,
										 iDate==1?MONTH:iDate==2?MONTH:MDAY, ( LPSTR ) sDate,
										 iDate==1?YEAR:iDate==2?MDAY:YEAR );
	if (iTime==1 )
	  nLength+=wsprintf ( cBuffer + nLength, " %02d%s%02%s%02d ",
	                      HOUR, ( LPSTR ) sTime, MIN, ( LPSTR ) sTime, SEC );
	else
		nLength+=wsprintf ( cBuffer + nLength, " %d%s%02d%s%02d%s ",
		                    ( HOUR %12 ) ? ( HOUR %12 ) : 12,
		                    ( LPSTR ) sTime, MIN, ( LPSTR ) sTime, SEC,
		                    (LPSTR ) sAMPM[HOUR/12] );
	
	GetClientRect ( hwnd, &rect );
	SetBkColor ( hdc, RGB ( 255, 255, 0 ) );
	//SetBkMode ( hdc, TRANSPARENT ); 
	//SetTextAlign ( hdc, TA_CENTER );
	//TextOut ( hdc, rect.left, rect.top, cBuffer, strlen ( cBuffer ) );
	DrawText ( hdc, cBuffer, -1, &rect, DT_CENTER | DT_NOCLIP );
	//SetBkMode ( hdc, OPAQUE );
}

/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    HDC hdc;
    PAINTSTRUCT ps;
    		
		switch (message)                  /* handle the messages */
    {
        case WM_CREATE:
					SetInternational ( );
					InvalidateRect ( hwnd, NULL, TRUE );
					return 0;
				
				case WM_TIMER:
					InvalidateRect ( hwnd, NULL, FALSE );
					return 0;
					
				case WM_PAINT:
					hdc=BeginPaint ( hwnd, &ps );
					WndPaint ( hwnd, hdc );
					EndPaint ( hwnd, &ps );
					return 0;
					
				case WM_WININICHANGE:
					SetInternational ( );
					InvalidateRect ( hwnd, NULL, FALSE );
					return 0;
								
				case WM_DESTROY:
          KillTimer ( hwnd, ID_TIMER );
					PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
          break;
        default:                      /* for messages that we don't deal with */
          return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
