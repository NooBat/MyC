//Giải phương trình bậc 1, 2, trùng phương
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

//Tìm số nghiệm và giải phương trình bậc 1
int Equaldeg1(double a, double b, double x)
{
    //Số nghiệm của phương trình
    int nSolution1;

    if (a != 0)
    {
        x = -b / a;
        return 1; 
    }
    //a == 0
    else
    {   
        x = 0;
        if (b == 0)
        {
            //Phương trình vô định
            return -1;
        }
        else
        {
            //Phương trình vô nghiệm
            return 0;
        }
    }
}
//Tìm số nghiệm và giải phương trình bậc 2
int Equaldeg2(double a, double b, double c, double x1, double x2)
{
    //Số nghiệm phương trình bậc 2
    x1 = x2 = 0;
    
    double delta = b * b - 4 * a * c;
    if (delta < 0)
    {
        return 0;
    }
    else if (delta == 0)
    {
        x1 = x2 = -b / (2 * a);
        return 1;
    }
    else
    {
        x1 = (-b - sqrt(delta)) / (2 * a);
        x2 = (-b + sqrt(delta)) / (2 * a);
        return 2;   
    }
}

int main()
{
    int Bac, numSol;
    double a, b, c, x, x1, x2, y1, y2, delta;
    cout << "Chon loai phuong trinh: \n";
    cout << "Phuong trinh bac 1, nhan so 1.\n";
    cout << "Phuong trinh bac 2, nhan phim 2.\n";
    cout << "Phuong trinh trung phuong, nhan phim 4.\n";
    cin >> Bac;

    switch (Bac)
    {
        case 1:
            cout << "Nhap a: ";
            cin >> a;
            
            cout << "Nhap b: ";
            cin >> b;

            numSol = Equaldeg1(a, b, x);
            if (numSol == 0)
            {
                cout << "Phuong trinh vo nghiem.\n";
            }

            if (numSol == 1)
            {
                cout << "Phuong trinh " << a << "x + " << b << " = 0 co 1 nghiem x = " << x << ".\n"; 
            }

            if (numSol == -1)
            {
                cout << "Phuong trinh co vo so nghiem.\n";
            }

            break;
        case 2:
            cout << "Nhap a: ";
            cin >> a;

            cout << "Nhap b: ";
            cin >> b;

            cout << "Nhap c: ";
            cin >> c;

            while (a == 0)
            {
                cout << "Nhap lai a: ";
                cin >> a;
            }
            
            x1 = x2 = 0;
    
            delta = b * b - 4 * a * c;

            if (delta == 0)
            {
                x1 = x2 = -b / (2 * a);
            }
            if (delta > 0)
            {
                x1 = (-b - sqrt(delta)) / (2 * a);
                x2 = (-b + sqrt(delta)) / (2 * a);   
            }
            numSol = Equaldeg2(a, b, c, x1 ,x2);

            if (numSol == 0)
            {
                cout << "Phuong trinh vo nghiem.\n";
            }

            if (numSol == 1)
            {
                cout << "Phuong trinh " << a << "(x^2) + " << b << "x + " << c << " = 0 co nghiem kep x = " << x1 << ".\n";  
            }

            if (numSol == 2)
            {
                 cout << "Phuong trinh " << a << "(x^2) + " << b << "x + " << c << " = 0 co 2 nghiem phan biet la: \n";
                 cout << "x1 = " << x1 << endl;
                 cout << "x2 = " << x2 << endl;
            }
            break;
        case 4:
            cout << "Nhap a: ";
            cin >> a;

            cout << "Nhap b: ";
            cin >> b;

            cout << "Nhap c: ";
            cin >> c;

            while (a == 0)
            {
                cout << "Nhap lai a: ";
                cin >> a;
            }
            
            int t1, t2;
            y1 = y2 = 0;
    
            delta = b * b - 4 * a * c;
            if (delta == 0)
            {
                y1 = y2 = -b / (2 * a);
            }
            if (delta > 0)
            {
                y1 = (-b - sqrt(delta)) / (2 * a);
                y2 = (-b + sqrt(delta)) / (2 * a); 
            }

            numSol = Equaldeg2(a, b, c, t1, t2); 
            if (numSol == 0)
            {
                cout << "Phuong trinh vo nghiem.\n";
            }
            else if (numSol == 1)
            {
                if (y1 < 0)
                {
                    cout << "Phuong trinh vo nghiem.\n";
                }
                else if (y1 == 0)
                {
                    cout << "Phuong trinh " << a << "(x^4) + " << b << "(x^2) + " << c << " = 0 co 1 nghiem x = " << 0 << ".\n";
                }
                else
                {
                    cout << "Phuong trinh " << a << "(x^4) + " << b << "(x^2) + " << c << " = 0 co 2 nghiem la: \n";
                    cout << "x1 = " << -sqrt(y1) << endl;
                    cout << "x2 = " << sqrt(y1) << endl;
                }
            }
            else
            {
                if (y1 < 0)
                {
                    if (y2 < 0)
                    {
                        cout << "Phuong trinh vo nghiem.\n";
                    }
                    else if (y2 == 0)
                    {
                        cout << "Phuong trinh " << a << "(x^4) + " << b << "(x^2) + " << c << " = 0 co 1 nghiem la: " << 0 << ".\n";
                    }
                    else
                    {
                        cout << "Phuong trinh " << a << "(x^4) + " << b << "(x^2) + " << c << " = 0 co 2 nghiem la: \n";
                        cout << "x1 = " << -sqrt(y2) << endl;
                        cout << "x2 = " << sqrt(y2) << endl;                 
                    }
                }
                else if (y1 == 0)
                {
                    if (y2 < 0)
                    {
                        cout << "Phuong trinh " << a << "(x^4) + " << b << "(x^2) + " << c << " = 0 co 1 nghiem x = " << 0 << ".\n";
                    }
                    else if (x2 == 0)
                    {
                        cout << "Phuong trinh " << a << "(x^4) + " << b << "(x^2) + " << c << " = 0 co nghiem kep x = " << 0 << endl;
                    }
                    else
                    {
                        cout << "Phuong trinh " << a << "(x^4) + " << b << "(x^2) + " << c << " = 0 co 3 nghiem x la: \n";
                        cout << "x1 = " << -sqrt(y2) << endl;
                        cout << "x2 = " << 0 << endl;
                        cout << "x3 = " << sqrt(y2) << endl;
                    }
                }
                else
                {
                    if (y2 < 0)
                    {
                        cout << "Phuong trinh " << a << "(x^4) + " << b << "(x^2) + " << c << " = 0 co 2 nghiem x la: \n";
                        cout << "x1 = " << -sqrt(y1) << endl;
                        cout << "x2 = " << sqrt(y1) << endl;
                    }
                    else if (y2 == 0)
                    {
                        cout << "Phuong trinh " << a << "(x^4) + " << b << "(x^2) + " << c << " = 0 co 3 nghiem x la: \n";
                        cout << "x1 = " << -sqrt(y1) << endl;
                        cout << "x2 = " << 0 << endl;
                        cout << "x3 = " << sqrt(y1) << endl;
                    }
                    else
                    {
                        cout << "Phuong trinh " << a << "(x^4) + " << b << "(x^2) + " << c << " = 0 co 4 nghiem x la: \n";
                        cout << "x1 = " << -sqrt(y2) << endl;
                        cout << "x2 = " << -sqrt(y1) << endl;
                        cout << "x3 = " << sqrt(y1) << endl;
                        cout << "x4 = " << sqrt(y2) << endl;
                    }
                    break;
                }
            }
    }
    return 0;
}
    
