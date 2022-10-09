#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

using namespace std;

void gotoxy(int column, int line);
void enteredLine(int, char*);

int main()
{
    // Output message
    cout<<"Pleas Enter the Length of the Line: ";

    // getting size of the line
    int lsize;
    cin>>lsize;

    // allocating an array as dynamic array of characters
    char* first_line= new char[lsize];
    enteredLine(lsize, first_line);

    //
    system("CLS");
    cout<<first_line;

    return 0;
}

void enteredLine(int lsize, char* stptr)
{
    // flag and input character
    int flag=1;
    char c;

    // my controlling pointers
    char* crptr;
    char* enptr;

    // checking that the array allocated
    if (stptr!=NULL)
    {
        // initializing my pointers
        crptr=stptr;
        enptr=stptr;

        // the main program goes here
        while (flag)
        {
          c=getch();

          // extended key
          if (c==-32)
          {
              c=getch();
              switch (c)
              {
                // home
                case 71:
                    crptr=stptr;
                    break;

                // left
                case 75:
                    crptr--;
                    if (crptr<stptr)
                        crptr=stptr;
                    break;

                // right
                case 77:
                    crptr++;
                    if (crptr>enptr)
                        crptr=enptr;
                    break;

                // end
                case 79:
                    crptr=enptr;
                    break;
              }

              // putting the cursor on the right position
              gotoxy((crptr-stptr), 1);
          }

          // normal key
          else
          {
              // printable characters
              if(c>32 && c<128)
              {
                  cout<<c;
                  *(stptr+(crptr-stptr))=c;
                  crptr++;
                  if (crptr>enptr)
                    enptr++;
              }

              // if the user entered enter
              else if (c==13)
              {
                  stptr[enptr-stptr]='\0';
                  flag=0;
              }

              // if the user entered escape
              else if (c==27)
              {
                  stptr[stptr-stptr]='\0';
                  flag=0;
              }
          }
        }
    }
}

void gotoxy(int column, int line)
{
  COORD coord;

  coord.X = column;
  coord.Y = line;

  SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ), coord);
}
