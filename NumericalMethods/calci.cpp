#include<iostream>
#include<cmath>
#include <bits/stdc++.h>
#define f(x,y) (y*y-x*x)/(y*y+x*x)
using namespace std;

class regula_falsi
{
    private:
    float a,b;
    public :
    float compute_function(float);
    regula_falsi();
};

float regula_falsi :: compute_function(float x)
{
    float res = cos(x)-(3*x)+1;
    return res;
}

regula_falsi::regula_falsi()
{
    float x,res,fa,fb,fx;
    int i,n;
    cout << "Enter values of a and b : " << endl;
    cin >> a >> b;
    cout << "Enter number of approximations : " << endl;
    cin >> n;
    cout << "\t a\t\t b\t\t fa\t\t fb\t\t x\t\t fx" << endl;
    for(i=0;i<n;i++)
    {
        cout << "\t" << a << "\t" << b << "\t";
        fa = compute_function(a);
        cout << fa << "\t";
        fb = compute_function(b);
        cout << fb << "\t\t";
        x = ((a*fb)-(b*fa))/(fb-fa);
        cout << x << "\t";
        fx = compute_function(x);
        cout << fx << endl;
        res = (fx*fb);
        if(res < 0)
            a = x;
        else
            b = x;
    }
}

class modified_eulers_method
{
    private:
        float x0,y0,mods,h;
        int n;
    public:
        float compute_function(float,float);
        float y_value(float,float);
        modified_eulers_method();
};

float modified_eulers_method :: compute_function(float x,float y)
{
    float res = sin(x) + cos(y);
    return res;
}

float modified_eulers_method :: y_value(float x,float y)
{
    float res = y0 + ((h/2)*((compute_function(x0,y0)) + compute_function(x,y)));
    return res;
}

modified_eulers_method :: modified_eulers_method()
{
    float y1E , y_change , x ,y;
    cout<<"Enter the initial values of x and y : "<<endl;
    cin>>x0>>y0;
    cout<<"Enter the step size and number of steps : "<<endl;
    cin>>h>>n;
    cout<<"\n\n";
    cout<<"x \t\t y(E) \t\t y(1) \t\t y(2) \t\t y(3)\n"<<endl;
    for(int i = 0; i<n; i++ )
    {
        x = x0 + h;
        cout<<x<<" \t\t ";
        y1E = y0+(h*compute_function(x0,y0));
        y_change = y1E;
        cout<<y1E<<" \t ";
        for(int j = 0;j<3;j++)
        {
            y = y_value(x,y_change);
            cout<<y<<" \t ";
            y_change = y;
        }
        cout<<endl;
        x0 = x0 + h;
        y0 = y;
    }
}

class calculator
{
    public : void taylorSINEseries();
             void rangeKUTTAtwo();
             void rangeKUTTAfour();
             void taylorCOSINEseries();
};

//Range Kutta Second Order
void calculator :: rangeKUTTAtwo()
{
  float x0, xn, h, y, k1, k2;
  int i, n;
  cout << "***RANGE KUTTA SECOND ORDER***\n";

  cout<<"Enter Initial Condition"<< endl;
  cout<<"x0 = ";
  cin>> x0;

  cout<<"y = ";
  cin >> y;

  cout<<"Enter calculation point xn: ";
  cout << "xn = ";
  cin>>xn;

  cout <<"Enter step size: ";
  cout << "h = ";
  cin >> h;

  //count the number of iterations using step size h
  n = int((xn-x0)/h);

  //iterate for number of iterations

  cout<< "\nx0\ty0\tyn\n";
  cout<< "-------------------\n";
  for(i=0; i<n; i++)
  {
      k1 = h * f(x0,y);
      k2 = h * f((x0 + 0.5*h), (y+ 0.5*k1));

      //update next value of y
      y = y + (1.0/6.0) * (k1+2*k2);

      //update next value of x
      x0 = x0+h;
  }
  cout << "y(x) = " << "y(" << xn << ")" << " = " << y << endl << endl;
  return;
}

//Range Kutta Fourth Order
void calculator :: rangeKUTTAfour()
{
  float x0, y0, xn, h, yn, k1, k2, k3, k4, k;
  int i, n;

  cout << endl;
  cout << "***RANGE KUTTA FOURTH ORDER***\n";
  cout<<"Enter Initial Condition"<< endl;
  cout<<"x0 = ";
  cin>> x0;

  cout<<"y0 = ";
  cin >> y0;

  cout<<"Enter calculation point xn = ";
  cin>>xn;

  cout<<"Enter number of steps: ";
  cin>> n;

 /* Calculating step size (h) */
  h = (xn-x0)/n;

 /* Runge Kutta Method 4th order*/
 cout<<"\nx0\ty0\tyn\n";
 cout<<"-----------------------\n";
 for(i=0; i < n; i++)
 {
  k1 = h * (f(x0, y0));
  k2 = h * (f((x0+h/2), (y0+k1/2)));
  k3 = h * (f((x0+h/2), (y0+k2/2)));
  k4 = h * (f((x0+h), (y0+k3)));

  k = (k1+2*k2+2*k3+k4)/6;
  yn = y0 + k;

  cout<< x0<<"\t"<< y0<<"\t"<< yn<< endl;
  x0 = x0+h;
  y0 = yn;
 }

 /* Displaying result */
  cout<<"\nValue of y at x = "<< xn<< " is " << yn;
  cout << endl << endl;
  return;
}

void calculator :: taylorSINEseries()
{
    cout << endl;
    cout << "***TAYLOR SERIES FOR SINE EXPANSION***\n\n";
    cout << "sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ......\n\n";

    float accuracy = 0.0001, denominator, sinx, sinval;

    float n;
    cout << "Enter an angle to calculate sine value: ";
    cin >> n;

    float angle = n;

    // Converting degrees to radian
    n = n * (3.142 / 180.0);

    float x1 = n;

    // maps the sum along the series
    sinx = n;

    // holds the actual value of sin(n)
    sinval = sin(n);
    int i = 1;
    do
    {
        denominator = 2 * i * (2 * i + 1);
        x1 = -x1 * n * n / denominator;
        sinx = sinx + x1;
        i = i + 1;
    } while (accuracy <= fabs(sinval - sinx));
    cout << "sin(" << angle << ") = " << sinx << endl << endl;

    return;
}

void calculator :: taylorCOSINEseries()
{

    cout << "***TAYLOR SERIES FOR COSINE EXPANSION***\n\n";
    float accuracy = 0.0001, x1, denominator, cosx, cosval;
    cout << "cos(x) = 1 - x^2/2! + x^4/4! - x^6/6! + .....\n\n";

    float n;
    cout << "Enter an angle to calculate cosine value: ";
    cin >> n;

    float angle = n;

    // Converting degrees to radian
    n = n * (3.142 / 180.0);

    x1 = 1;

    // maps the sum along the series
    cosx = x1;

    // holds the actual value of cos(n)
    cosval = cos(n);
    int i = 1;
    do
    {
        denominator = 2 * i * (2 * i - 1);
        x1 = -x1 * n * n / denominator;
        cosx = cosx + x1;
        i = i + 1;
    } while (accuracy <= fabs(cosval - cosx));
    cout << "cosine(" << angle << ") = " << cosx << endl << endl;

    return;
}

class calculatoraho
{
    public : void simpson18();
             void simpson38();
             void weddle();
             double f2(double x);

};
double calculatoraho :: f2(double x){

    double a=1/(1+x*x);    //write the function whose definite integral is to be calcuated here
    return a;
}


void calculatoraho :: simpson18()
{
     cout.precision(4);        //set the precision
    cout.setf(ios::fixed);
    int n,i;            //n is for subintervals and i is for loop
    double a,b,c,h,sum=0,integral;
    cout<<"\nEnter the limits of integration,\n\nInitial limit,a= ";
    cin>>a;
    cout<<"\nFinal limit, b=";                //get the limits of integration
    cin>>b;
    cout<<"\nEnter the no. of subintervals(IT SHOULD BE EVEN), \nn=";        //get the no. of subintervals
    cin>>n;
    double x[n+1],y[n+1];
    h=(b-a)/n;                        //get the width of the subintervals
    for (i=0;i<n+1;i++)
    {                        //loop to evaluate x0,...xn and y0,...yn
        x[i]=a+i*h;                //and store them in arrays
        y[i]=f2(x[i]);
    }
    for (i=1;i<n;i+=2)
    {
        sum=sum+4.0*y[i];                //loop to evaluate 4*(y1+y3+y5+...+yn-1)
    }
    for (i=2;i<n-1;i+=2)
    {
        sum=sum+2.0*y[i];                //loop to evaluate 4(y1+y3+y5+...+yn-1)+
                                       // 2*(y2+y4+y6+...+yn-2)*/
    }
    integral=h/3.0*(y[0]+y[n]+sum);    //h/3*[y0+yn+4*(y1+y3+y5+...+yn-1)+2*(y2+y4+y6+...+yn-2)]
    cout<<"\nThe definite integral  is "<<integral<<"\n"<<endl;
    return ;
}

void calculatoraho :: simpson38()
{
    cout.precision(4);        //set the precision
    cout.setf(ios::fixed);
    int n,i;            //n is for subintervals and i is for loop
    double a,b,c,h,sum=0,integral;
    cout<<"\nEnter the limits of integration,\n\nInitial limit,a= ";
    cin>>a;
    cout<<"\nFinal limit, b=";  //get the limits of integration
    cin>>b;
    cout<<"\nEnter the no. of subintervals(IT SHOULD BE A MULTIPLE OF 3), \nn=";
    //get the no. of subintervals
    cin>>n;
    double x[n+1],y[n+1];
    h=(b-a)/n;     //get the width of the subintervals
    for (i=0;i<n+1;i++){                        //loop to evaluate x0,...xn and y0,...yn
        x[i]=a+i*h;                //and store them in arrays
        y[i]=f2(x[i]);
    }
    for (i=1;i<n;i++)     {
        if (i%3==0)
            sum=sum+2*y[i];
        else
            sum=sum+3*y[i];
    }
    integral=3*h/8*(y[0]+y[n]+sum);  //3h/8*[y0+yn+3*(y1+y2+y4+...)+2*(y3+y6+y9+...+)]
    cout<<"\nThe definite integral  is "<<integral<<"\n"<<endl;
    return ;
}

void calculatoraho :: weddle()
{
    cout.precision(4);        //set the precision
    cout.setf(ios::fixed);
    int n,i;
    float s=0.0,a,b,h;
    cout<<"\nEnter the limits of integration,\n\nInitial limit,a= ";
    cin>>a;
    cout<<"\nFinal limit, b=";  //get the limits of integration
    cin>>b;
    cout<<"\nEnter the no. of subintervals(IT SHOULD BE A MULTIPLE OF 6), \nn=";
    //get the no. of subintervals
    cin>>n;
    h=(b-a)/n;
    if(n%6==0)
		{for(i=0;i<n;i=i+6)
		s=s+f2((i)*h)+5*f2((i+1)*h)+f2((i+2)*h)+6*f2((i+3)*h)+f2((i+4)*h)+5*f2((i+5)*h)+f2((i+6)*h);}
	s=0.3*h*s;
	cout<<"\nThe definite integral  is "<<s<<"\n"<<endl;
    return ;
}

class maths
{
    public :
    void adambash()
    {
        float y3,yd0,yd1,yd2,yd3,yp,yf,yc,h,x;
        int i,n;
        cout<<"Enter the value of y3 = \n ";
        cin>>y3;
        cout<<"Enter the value of yd0 = \n ";
        cin>>yd0;
        cout<<"Enter the value of yd1 = \n ";
        cin>>yd1;
        cout<<"Enter the value of yd2 = \n ";
        cin>>yd2;
        cout<<"Enter the value of yd3 = \n ";
        cin>>yd3;
        cout<<"Enter the value of h = \n ";
        cin>>h;
        cout<<"Enter the value of x = \n ";
        cin>>x;
        cout<<"Enter the no.of corrections= ";
        cin>>n;
        cout<<"Predictor value is \n";
        yp=y3+(h/24)*(55*yd3-59*yd2+37*yd1-9*yd0);
        cout<<"\n"<<yp<<endl;
        for(i=0;i<n;i++)
        {
            cout<<"Functional value is \n";
            yf=(1/(x*x))-(yp/x);
            cout<<"\n"<<yf<<endl;
            cout<<"The corrector value is \n";
            yc=y3+(h/24)*(yd1-5*yd2+19*yd3+9*yf);
            cout<<"\n"<<yc<<endl;
            yp=yc;
        }
    }

    void milne()
    {
        float y0,y2,yd0,yd1,yd2,yd3,yp,yf,yc,h,x;
        int i,n;
        cout<<"Enter the value of y0 = \n ";
        cin>>y0;
        cout<<"Enter the value of y2 = \n ";
        cin>>y2;
        cout<<"Enter the value of yd0 = \n ";
        cin>>yd0;
        cout<<"Enter the value of yd1 = \n ";
        cin>>yd1;
        cout<<"Enter the value of yd2 = \n ";
        cin>>yd2;
        cout<<"Enter the value of yd3 = \n ";
        cin>>yd3;
        cout<<"Enter the value of h = \n ";
        cin>>h;
        cout<<"Enter the value of x = \n ";
        cin>>x;
        cout<<"Enter the no.of corrections= ";
        cin>>n;
        cout<<"Predictor value is \n";
        yp=y0+(4*h/3)*(2*yd1-yd2+2*yd3);
        cout<<"\n"<<yp<<endl;
        for(i=0;i<n;i++)
        {
            cout<<"Functional value is \n";
            yf=(1/(x*x))-(yp/x);
            cout<<"\n"<<yf<<endl;
            cout<<"The corrector value is \n";
            yc=y2+(h/3)*(yd2+4*yd3+yf);
            cout<<"\n"<<yc<<endl;
            yp=yc;
        }
    }
    void milne2nd()
    {
        float y0,y2,yd0,yd1,yd2,yd3,yp,yf,yc,h,x,z0,z2,zp,zc,zd0,zd1,zd2,zd3,zf;
        int i,n;
        cout<<"Enter the value of y0 = \n ";
        cin>>y0;
        cout<<"Enter the value of y2 = \n ";
        cin>>y2;
        cout<<"Enter the value of z0 = \n ";
        cin>>z0;
        cout<<"Enter the value of z2 = \n ";
        cin>>z2;
        cout<<"Enter the value of yd0 = \n ";
        cin>>yd0;
        cout<<"Enter the value of yd1 = \n ";
        cin>>yd1;
        cout<<"Enter the value of yd2 = \n ";
        cin>>yd2;
        cout<<"Enter the value of yd3 = \n ";
        cin>>yd3;
        cout<<"Enter the value of zd0 = \n ";
        cin>>zd0;
        cout<<"Enter the value of zd1 = \n ";
        cin>>zd1;
        cout<<"Enter the value of zd2 = \n ";
        cin>>zd2;
        cout<<"Enter the value of zd3 = \n ";
        cin>>zd3;
        cout<<"Enter the value of h = \n ";
        cin>>h;
        cout<<"Enter the value of x = \n ";
        cin>>x;
        cout<<"Enter the no.of corrections= ";
        cin>>n;
        cout<<"Predictor value is \n";
        yp=y0+(4*h/3)*(2*yd1-yd2+2*yd3);
        zp=z0+(4*h/3)*(2*zd1-zd2+2*zd3);
        cout<<"\n"<<yp<<endl<<zp;
        for(i=0;i<n;i++)
        {
            cout<<"Functional value is \n";
            zf=1-2*yp*zp;
            cout<<"\n"<<zf<<endl;
            cout<<"The corrector value is \n";
            yc=y2+(h/3)*(yd2+4*yd3+zp);
            zc=z2+(h/3)*(zd2+4*zd3+zf);
            cout<<"\n"<<yc<<endl<<zc<<endl;
            yp=yc;
            zp=zc;
        }
    }
};

//Final Main Function
int main()
{
    int choice;
    for(;;)
    {
        cout<<"\n\n\n\t\t\t\tNumerical Methods Calculator"<<endl;
        cout<<"\t\tMenu : "<<endl;
        cout<<"\t\t1.Simpson's 1/3 Rule"<<endl;
        cout<<"\t\t2.Simpson's 3/8 Rule"<<endl;
        cout<<"\t\t3.Weddle's Rule"<<endl;
        cout<<"\t\t4.Runge Kutta 2nd order"<<endl;
        cout<<"\t\t5.Runge Kutta 4th Order"<<endl;
        cout<<"\t\t6.Taylor Sine Series Method"<<endl;
        cout<<"\t\t7.Taylor Cosine Series Method"<<endl;
        cout<<"\t\t8.Modified Euler's Method"<<endl;
        cout<<"\t\t9.Regula-Falsi Method"<<endl;
        cout<<"\t\t10.Adam-Bashforth Method"<<endl;
        cout<<"\t\t11.Milne's Predictor-Corrector Method"<<endl;
        cout<<"\t\t12.Milne's Predictor-Corrector Method to solve 2nd Order ODE"<<endl;
        cout<<"\t\t13.Exit"<<endl;
        cout<<"\t\tEnter your choice : ";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
            case 1 :
                calculatoraho c1;
                c1.simpson18();
                break;
            case 2 :
                calculatoraho c2;
                c2.simpson38();
                break;
            case 3 :
                calculatoraho c3;
                c3.weddle();
                break;
            case 4 :
                calculator c4;
                c4.rangeKUTTAtwo();
                break;
            case 5 :
                calculator c5;
                c5.rangeKUTTAfour();
                break;
            case 6 :
                calculator c6;
                c6.taylorSINEseries();
                break;
            case 7 :
                calculator c7;
                c7.taylorCOSINEseries();
                break;
            case 8 :
              {
                  modified_eulers_method obmem1;
                break;
              }
            case 9 :
                {
                regula_falsi obrf1;
                break;
                }
            case 10 :
                maths oba1;
                oba1.adambash();
                break;
            case 11 :
                maths oba2;
                oba2.milne();
                break;
            case 12 :
                maths oba3;
                oba3.milne2nd();
                break;
            case 13 : cout << "Thank You :-)";
                exit(0);
            default :
                cout<<"Invalid Choice"<<endl;
        }
    }
}
