#include<iostream>
#include<stdlib.h>
#include<ctime>
#include <windows.h>

using namespace std;

WORD GetConsoleTextAttribute (HANDLE hCon)
{
  CONSOLE_SCREEN_BUFFER_INFO con_info;
  GetConsoleScreenBufferInfo(hCon, &con_info);
  return con_info.wAttributes;
}

void printline()
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    const int saved_colors = GetConsoleTextAttribute(hConsole);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout<<"\t\t\t\t";
    cout<<" ----------------------------------"<<endl;
    SetConsoleTextAttribute(hConsole, saved_colors);
}

class Clock
{
protected:
    int H;
    int M;
    int S;
public:

    virtual void set(short)=0;

    void display()
    {
    cout<<"\t\t\t\t";
    cout<<" || ";

    if(H<10)
    cout<<"0";

    cout<<H<<" : ";

    if(M<10)
    cout<<"0";

    cout<<M<<" : ";

    if(S<10)
    cout<<"0";

    cout<<S;
    cout<<" || ";
    }
};

class stopwatch:public Clock
{
public:
    void set(short total)
    {
    H=total/3600;
    total%=3600;
    M=total/60;
    total%=60;
    S=total;
    }
};

class Ctime:public Clock
{
public:
    void set(short total)
    {
    time_t t = time(NULL);
	tm *timePtr = localtime(&t);

    H=(timePtr->tm_hour);

    if(H>12)
        H=H-12;
    M=(timePtr->tm_min);
    S=(timePtr->tm_sec);
    }
    void correction()
    {
        time_t t = time(NULL);
        tm *timePtr = localtime(&t);

        int a=(timePtr->tm_hour);

    if(a>12){
        cout<<"P.M.";
    }
    else{
        cout<<"A.M";
    }

    }
};
class Alarm
{
public:
    void display(int total)
{
    int H,M,S;

    H=total/3600;
    total%=3600;
    M=total/60;
    total%=60;
    S=total;

    cout<<"\t\t\t\t";
    cout<<" || ";

    if(M<10)
    cout<<"0";

    cout<<H<<" : ";

    if(M<10)
    cout<<"0";

    cout<<M<<" : ";

    if(S<10)
    cout<<"0";

    cout<<S;
    cout<<" || ";
}
};

int main()
{
    short op;
    string y;
    bool a=0;
    do
{
    cout<<"\nCLOCK:";
    cout<<"\n\t1.Stop Watch\n";
    cout<<"\n\t2.Current Time\n";
    cout<<"\n\t3.Alarm\n";
    cout<<"\n\t4.Exit\n";
    cout<<endl;
X:
    cout<<"\Choose :";
    cin>>op;

    switch(op)
    {

    case 1:
    {
        int h,m,s;
        string lable;
        cout<<"Enter Hour-Minutes-Second with Space separated : ";
        cin>>h>>m>>s;
        cout<<"Label :";
        cin>>lable;
        system("CLS");
        int total=(s)+(m*60)+(h*3600);
        stopwatch C1;

        while(total!=0)
        {
            system("CLS");
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
            printline();

            C1.set(total);

            cout<<"\t";
            C1.display();
            total--;
            cout<<endl;
            printline();

            for(int i=0;i<559500000;i++)
            ;
        }

        system("CLS");
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
        printline();
        C1.set(total);
        cout<<"\t";
        C1.display();
        cout<<endl;
        printline();

        for(int i=0;i<10;i++)
        {

            system("CLS");
            cout<<" !! "<<lable<<" !!";

            for(int j=0;j<100;j++)
            ;
            Beep(500,1000);
            for(int j=0;j<100;j++)
            ;

            system("CLS");
        }
        break;
        }

    case 2:
        {
            printline();
            Ctime C2;
            C2.set(1);
            cout<<"\t";
            C2.display();
            C2.correction();
            cout<<endl;
            printline();
    break;
        }
    case 3:
        {
            int h,m;
            Alarm A;

            string a;
            string lable;
            time_t t = time(NULL);
            tm *timePtr = localtime(&t);
            int remain;
            int t1=(timePtr->tm_hour)*(3600)+(timePtr->tm_min)*(60);
            M:
            cout<<"\nEnter Hour-Minutes with Space separated : ";
            cin>>h>>m;

            if(h>12)
            {
                cout<<"\n!!You have to choose in Between A.M. or P.M.";
                goto M;
            }
            L:
            cout<<"\NEnter A.M. or P.M. :";
            cin>>a;
            cout<<"Label :";
            cin>>lable;
            if(a=="P.M." || a=="A.M.")
            {
            if(a=="P.M.")
            {
                if(h==12 && m==0)
                {
                    h+=0;
                }
                else
                {
                    h+=12;
                }
            }
            else
            {
                if(h==12)
                h+=12;
            }
            int t2=(h)*(3600)+(m)*(60);
            if(t1>t2)
            {
                remain=86400-t1+t2;
            }
            else if(t2>t1)
            {
                remain=t2-t1;
            }
            else
            {
                cout<<"\nNot Possible\n";
            }
            while(remain!=0)
            {
                system("CLS");
                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
                printline();
                cout<<"\t";
                A.display(remain);
                cout<<endl;
                printline();
                remain--;
                cout<<endl;
                for(int i=0;i<559500000;i++)
                ;
            }
            system("CLS");
                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
                printline();
                cout<<"\t";
                A.display(remain);
                cout<<endl;
                printline();

                cout<<endl;
                for(int i=0;i<559500000;i++)
                ;
        for(int i=0;i<10;i++)
        {
            system("CLS");
            cout<<" !! "<<lable<<" !!";

            for(int j=0;j<100;j++)
            ;
            Beep(500,1000);
            for(int j=0;j<100;j++)
            ;
        }
        }
        else
            {
                cout<<"\n!!Enter Only in Between A.M. or P.M.";
                goto L;
            }
            break;
        }
    case 4:
        {
            exit(0);
        }
    default:
            {
                cout<<"Enter only in between 1-3 So ";
                goto X;
            }
    }
Y:


    cout<<"\nRepeat ? : YES or NO : ";
    cin>>y;

    if(y=="YES" || y=="yes" || y=="Yes")
        {a=0;
        system("CLS");
        }
    else if(y=="NO" || y=="No" || y=="no")
       {
           a=1;
       }
       else
       {
           system("CLS");
             cout<<"Enter only Yes or No ";

                goto Y;
       }

}while(a==0);

    return 0;
}
