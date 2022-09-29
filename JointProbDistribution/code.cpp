#include <bits/stdc++.h>
#define PI 3.1415926535
#define ll long long
using namespace std;

int main()
{
    int a, b, i = 0, j = 0;
    float sum = 0;

    cout << "\n******** JOINT PROBABILITY DISTRIBUTION **********\n\n";

    cout << "Enter the order of J matrix : \n";
    cin >> a >> b;
    float x[b], y[a], expx, expy, expxy, cov, corel;
    float varx, vary;
    float k[a][b];

    cout << endl;

    cout << "Enter the values of J matrix:\n";

    for(int i = 0; i < a; i++) // scan 2D array
    {
        int val = 1;

        if(i != 0)
          val = 0;

        for(int j = val; j < b; j++)
            cin >> k[i][j];
    }

    cout << endl;

    cout << "\n \n X/Y\t";     // print 2D array
    for(int i = 0; i < a; i++)
    {
        int val = 1;

        if(i != 0)
          val = 0;

        for(int j = val; j < b; j++)
        {
            cout << k[i][j] << "\t";

            if(j == b-1)
              cout << endl;
        }
    }
    cout << endl << endl;
    cout << "\n*** Marginal Distribution of X ***";

    cout << "\nX\t";                  // marginal dist of X
    for(int i = 1; i < a; i++)
    {
        if(i == a-1)
        {
            cout << k[i][0] << "\t";
            cout << "\nP(x)\t";

            for(i = 1; i < a; i++)
            {
                sum = 0;
                for(int j = 1; j < b; j++)
                {
                    sum += k[i][j];
                }
                x[i-1] = sum;
                cout << x[i-1] << "\t";
            }
        }
        else
        {
          cout << k[i][0] << "\t";
        }
    }

    cout << endl << endl;
    cout << " *****  Marginal Distribution Of Y ******\n";
    cout << "Y\t";          // marginal dist of Y

    for(int j = 1; j < b; j++)
    {
        if(j == b-1)
        {
            cout << k[0][j] << "\t";
            cout << "\nP(y)\t";
            for(j = 1; j < b; j++)
            {
                sum = 0;
                for(int i=1; i<a; i++)
                {
                    sum += k[i][j];
                }
                y[j-1] = sum;
                cout << y[j-1] << "\t";
            }
        }
        else
        {
          cout << k[0][j] << "\t";
        }
    }
    cout << endl << endl;

    cout << "***** Expectation Of X *****";

    while(i < a)                 // expectation of X
    {
        sum = 0;
        cout << "\nE(x): ";

        for(i = 1; i < a; i++)
        {
            sum += (k[i][0] * x[i-1]);
        }
        expx = sum;
        cout << expx;
        i = a + 1;
    }
    cout << endl << endl;

    cout << "***** Expectation Of Y ******";

    while(j < b)                 // expectation of Y
    {
        sum = 0;
        cout << "\nE(y): ";
        for(j = 1; j < b; j++)
        {
            sum += (k[0][j] * y[j-1]);
        }
        expy = sum;
        cout << expy;
        j = b + 1;
    }

    cout << endl << endl;

    cout << "***** Variance Of X *****";
    i = 0;
    while(i < a)                     // variance of X
    {
        sum = 0;
        cout << "\nVar(x): ";
        for(i=1; i<a; i++)
        {
            sum += ((k[i][0] * k[i][0]) * x[i-1]);
        }
        varx = sum - (expx * expx);
        cout << varx;
        i = a + 1;
    }
    cout << endl << endl;

    cout << "***** Variance Of Y *****";
    j = 0;
    while(j < b)                         // variance of Y
    {
        sum = 0;
        cout << "\nVar(y): ";

        for(j = 1; j < b; j++)
        {
            sum += ((k[0][j] * k[0][j]) * y[j-1]);
        }
        vary = sum - (expy * expy);
        cout << vary;
        j = b + 1;
    }

    cout << endl << endl;

    cout << "***** Covariance Of X and Y *****";

    i = 0;
    while(i < a)                // covariance of X,Y
    {
        sum = 0;
        for(i = 1; i < a; i++)
            for(j = 1; j < b; j++)
            {
                sum += (k[0][j] * k[i][0] * k[i][j]);
            }
        expxy = sum;
        cout << "\nE(x,y): ";
        cout << expxy;

        cout << "\nCov(x,y): ";
        cov = expxy - (expx * expy);
        cout << cov;
        i = a + 1;
    }

    cout << endl << endl;

    cout << "***** Co-relation Of X and Y *****";
    i = 0;
    while(i < a)                       // corelation of X,Y
    {
        sum = 0;
        corel = cov/(sqrt(varx) * sqrt(vary));
        cout << "\nCorelation(x,y): " << corel;
        i = a + 1;
    }

    cout << endl << endl << "            *** THANK YOU MADAM ***          " << endl << endl;
    return 0;
}
