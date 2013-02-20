#include <windows.h>
#include "segment.h"
#include "cerc.h"
#include "element.h"
#include <list>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cmath>

#define IDM_EXIT 0
#define IDM_EXERCITIU_1 1
#define IDM_EXERCITIU_2 2
#define IDM_EXERCITIU_3 3
#define IDM_CLEAR 6
#define IDM_EOL 7

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/* Build menu */
void addMenu(HWND hWnd);

/* Exercitiile */
void ex1(HWND);
void ex2(HWND);
void ex3(HWND);


/*  Make the class name into a global variable  */
char szClassName[ ] = "MyWindow";
std::list<punct*> L;
unsigned int current = 0;
unsigned int clicks = 0;
long color = RGB(0,0,0);

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW; ;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           "Laborator Nr.3",       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           500,                 /* The programs width */
           500,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

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


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
    POINT coord;
    static segment *s;
    static cerc *c;

    switch (message)                  /* handle the messages */
    {

        case WM_CREATE:
            addMenu(hWnd);
            // Generez doua puncte, un segment si un cerc
        break;
        case WM_COMMAND:
            wmId    = LOWORD(wParam);
            wmEvent = HIWORD(wParam);
            // Parse the menu selections:
            switch (wmId) {
                case IDM_EXERCITIU_1:
                    current = 1;
                    ex1(hWnd);
                    break;
                case IDM_EXERCITIU_2:
                    current = 2;
                    ex2(hWnd);
                    break;
                case IDM_EXERCITIU_3:
                    current = 3;
                    clicks = 0;
                    L.clear();
                    InvalidateRect (hWnd, NULL, TRUE);
                    UpdateWindow (hWnd);
                    break;
                case IDM_EOL:
                    clicks = 0;
                    break;
                case IDM_CLEAR:
                    current = 0;
                    L.clear();
                    InvalidateRect (hWnd, NULL, TRUE);
                    UpdateWindow (hWnd);
                    break;
                case IDM_EXIT:
                    DestroyWindow(hWnd);
                    break;
                default:
                    current = 0;
                    return DefWindowProc(hWnd, message, wParam, lParam);
            }
		break;
        case WM_LBUTTONDOWN:

            if(current == 3)    {

                GetCursorPos(&coord);
                // Preiau coord. cursorului f. de coltul zonei client
                ScreenToClient(hWnd, (LPPOINT) &coord);


                if( clicks == 0 )   {

                    s = new segment();

                    s->setX(coord.x);
                    s->setY(coord.y);

                }   else {

                    s->setDx(coord.x - s->getX());
                    s->setDy(coord.y - s->getY());
                    s->setColor(color);
                    L.push_back(s);
                    InvalidateRect (hWnd, NULL, TRUE);
                    UpdateWindow (hWnd);
                    s = new segment();
                    s->setX(coord.x);
                    s->setY(coord.y);
                }
                clicks++;

            } else if(current == 4) {

                GetCursorPos(&coord);
                // Preiau coord. cursorului f. de coltul zonei client
                ScreenToClient(hWnd, (LPPOINT) &coord);


                if( clicks == 0 )   {

                    c = new cerc();

                    c->setX(coord.x);
                    c->setY(coord.y);

                    clicks++;

                }   else {


                    int dx = (coord.x - c->getX());
                    int dy = (coord.y - c->getY());
                    c->setR(sqrt(dx*dx + dy*dy));
                    c->setColor(color);
                    L.push_back(c);
                    InvalidateRect (hWnd, NULL, TRUE);
                    UpdateWindow (hWnd);
                    clicks = 0;
                }

            }

            break;
        case WM_KEYDOWN:
            switch (wParam) {

                case VK_END:
                    clicks = 0;
                break;

                case 'r': case 'R':
                    color = RGB(255, 0, 0); // Desenez cu rosu
                break;

                case 'g': case 'G':
                    color = RGB(0, 255, 0); // Desenez cu verde
                break;

                case 'b': case 'B':
                    color = RGB(0, 0, 255); // Desenez cu albastru
                break;

                case 's': case 'S':
                    current = 3;
                    clicks = 0;
                break;

                case 'c': case 'C':
                    current = 4;
                    clicks = 0;
                break;

            }
        break;
        case WM_PAINT:  {
            hdc = BeginPaint(hWnd, &ps);
            std::list<punct*>::iterator it;
                for (it=L.begin(); it!=L.end(); ++it){
                    (*it)->draw(hdc);
                }
            EndPaint(hWnd, &ps);
            UpdateWindow(hWnd);
        }
		break;
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hWnd, message, wParam, lParam);
    }

    return 0;
}

void addMenu(HWND hwnd)
{
  HMENU hMenubar;
  HMENU hFileMenu;

  hMenubar = CreateMenu();
  hFileMenu = CreateMenu();

  AppendMenuW(hFileMenu, MF_STRING, IDM_EXERCITIU_1, L"&Exercitiul&1");
  AppendMenuW(hFileMenu, MF_STRING, IDM_EXERCITIU_2, L"&Exercitiul&2");
  AppendMenuW(hFileMenu, MF_STRING, IDM_EXERCITIU_3, L"&Exercitiul&3");
  AppendMenuW(hFileMenu, MF_SEPARATOR, 0, NULL);
  AppendMenuW(hFileMenu, MF_STRING, IDM_EXIT, L"&Quit");

  AppendMenuW(hMenubar, MF_POPUP, (UINT_PTR)hFileMenu, L"&File");
  AppendMenuW(hMenubar, MF_STRING, IDM_CLEAR, L"&Clear");

  SetMenu(hwnd, hMenubar);
}

void ex1(HWND hwnd){

    punct *a = new punct(10,10, RGB(255, 0, 0));
    punct *b = new punct(100,100, RGB(255, 0, 0));
    segment *s = new segment(10, 10, RGB(0, 255, 0), 90, 90);
    cerc *c = new cerc(55, 55, RGB(0, 0, 255), 15);

    L.clear();

    L.push_back(a);
    L.push_back(b);
    L.push_back(s);
    L.push_back(c);
    InvalidateRect (hwnd, NULL, TRUE);
    UpdateWindow (hwnd);

    return;
}

void ex2(HWND hwnd){

    L.clear();

    srand((unsigned)time(NULL));

    for(int i = 0; i < 5000; i++)    {

        int x,y,dx,dy;
        long color;


        x = rand()*300/RAND_MAX;
        y = rand()*300/RAND_MAX;
        dx = rand()*200/RAND_MAX;
        dy = rand()*200/RAND_MAX;
        color = RGB(rand()*255/RAND_MAX,rand()*255/RAND_MAX,rand()*255/RAND_MAX);


        L.push_back(new segment(x,y,color,dx,dy));

    }


    InvalidateRect (hwnd, NULL, TRUE);
    UpdateWindow (hwnd);

    return;
}


