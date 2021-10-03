#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    int B[3][4] = 
    {
        {1, 1, 0, 0},
        {0,-1, 1, 0},
        {0, 0,-1,-1}
    };

    int Zb[4][4] =
    {
        {2, 0, 0, 0},
        {0, 5, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0,10}
    };

    int vs[4][1] =
    {
        {10},
        {12},
        {0},
        {20}
    };

    int Bt[4][3] = 
    {
        {1, 0, 0},
        {1,-1, 0},
        {0, 1,-1},
        {0, 0,-1}
    };

    double a[4][3];
    for (int i = 0; i < 4; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            a[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                a[i][j] += Zb[i][k] * Bt[k][j];
            }
        }
    }

    double b[3][3];
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            b[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                b[i][j] += B[i][k] * a[k][j];
            }
        }
    }

    // printf("%lf",b[0][0]);
    // printf("%s"," " );
    // printf("%lf",b[0][1]);
    // printf("%s"," " );
    // printf("%lf",b[0][2]);
    // printf("%s","\n");
    // printf("%lf",b[1][0]);
    // printf("%s"," " );
    // printf("%lf",b[1][1]);
    // printf("%s"," " );
    // printf("%lf",b[1][2]);
    // printf("%s","\n");
    // printf("%lf",b[2][0]);
    // printf("%s"," " );
    // printf("%lf",b[2][1]);
    // printf("%s"," " );
    // printf("%lf",b[2][2]);
    // printf("%s","\n");

    double c[3][1];
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 1; j++) 
        {
            c[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                c[i][j] += -1*B[i][k] * vs[k][j];
            }
        }
    }



    double inverseB[3][3];
    double determinantB=0;

    for(int i = 0; i < 3; i++)
        determinantB = determinantB + (b[0][i]*(b[1][(i+1)%3]*b[2][(i+2)%3] - b[1][(i+2)%3]*b[2][(i+1)%3]));

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            inverseB[i][j]=((b[(i+1)%3][(j+1)%3] * b[(i+2)%3][(j+2)%3]) - (b[(i+1)%3][(j+2)%3]*b[(i+2)%3][(j+1)%3]))/ determinantB;
    }

    
    double result[3][1];
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 1; j++) 
        {
            result[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                result[i][j] += inverseB[i][k] * c[k][j];
            }
        }
    }
    printf("%s","Current in loop 1 " );
    printf("%lf", result[0][0] );
    printf("%s","\n" ); 
    printf("%s","Current in loop 2 " );
    printf("%lf", result[1][0] );
    printf("%s","\n" );
    printf("%s","Current in loop 3 " );
    printf("%lf", result[2][0] );
    printf("%s","\n" );
    return 0;
}