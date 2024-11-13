#include <cstdio>
#include <iostream>
double m, h;
int main()
{
    scanf("%lf%lf", &m, &h);
    double bmi = m / (h * h);
    if (bmi < 18.5)
    {
        printf("Underweight\n");
    }
    else if (bmi < 24)
    {
        printf("Normal\n");
    }
    else
    {
        std::cout << bmi << std::endl;
        printf("Overweight\n");
    }
    return 0;
}