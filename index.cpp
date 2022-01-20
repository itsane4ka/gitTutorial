#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>

using namespace std;

class DotsCoordinats
{
    float x;
    float y;
    int number;
    
public:
    DotsCoordinats ()
    {
        x = 0;
        y = 0;
        number = 0;
    }
    void setDot(float x0, float y0, int num)
    {
        x = x0;
        y = y0;
        number = num;
    }
    
    void print()
    {
        cout << "Dot number " << number << " : " << x << "\t" << y << endl;
    }
    
};

void CoordintsFilling (vector<float>& vecX, vector<float>& vecY)
{
    srand(static_cast<unsigned int>(time(0)));
    
    cout << "Dots coordinats: \n" << endl;
    int fg = 0;
    for (int i = 0; i < vecX.size(); i++)
    {
        fg = rand() % 9 + 2;
        vecX.at(i) = static_cast <float> (rand() % 201 - 100) / fg;
        vecY.at(i) = static_cast <float> (rand() % 201 - 100) / fg;
        cout << vecX[i] << "\t\t" << vecY[i] << endl << endl;
    }
}

float LineLength (float x1, float x2, float y1, float y2)
{
    float length = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    return length;
}

float Logic (vector<float>& vecX, vector<float>& vecY)
{
    float a, b, c;
    float perimeter = 200;
    DotsCoordinats Dot1, Dot2, Dot3;
    for (int i = 0; i < vecX.size() - 2; i++)
    {
        for (int j  = i + 1; j < vecX.size() - 1; j++)
        {
            if (vecX[i] != vecX[j] && vecY[i] != vecY[j]) {
                for (int t  = j + 1; t < vecX.size(); t++)
                {
                    if (vecX[i] != vecX[t] && vecY[i] != vecY[t] && vecY[j] != vecX[t] && vecY[j] != vecY[t]) {
                        a = LineLength(vecX[i], vecX[j], vecY[i], vecY[j]);
                        b = LineLength(vecX[j], vecX[t], vecY[j], vecY[t]);
                        c = LineLength(vecX[i], vecX[t], vecY[i], vecY[t]);
                        
                        if (a + b + c < perimeter) {
                            perimeter = a + b + c;
                            Dot1.setDot(vecX[i], vecY[i], i);
                            Dot2.setDot(vecX[j], vecY[j], j);
                            Dot3.setDot(vecX[t], vecY[t], t);
                        }
                    }
                }
            }
        }
    }
    cout << "RESULT:  " << endl;
    Dot1.print();
    Dot2.print();
    Dot3.print();
    cout << endl;
    
    return perimeter;
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "rus");
    
    srand(static_cast<unsigned int>(time(0)));
    
    vector<float> vecX, vecY;
    long long per = 0;
    
    unsigned int DotsAmount = 0;
    while (DotsAmount < 3) {
        DotsAmount = rand()%13;
    }
    cout << "Dots amount: " << DotsAmount << endl << endl;
    vecX.resize(DotsAmount); 
    vecY.resize(DotsAmount); 
    
    CoordintsFilling (vecX, vecY);
    
    if (!vecX.empty() && !vecY.empty()) {
        float P = Logic(vecX, vecY);
        cout << "Minimal perimeter = " << P;
    }
    
    return 0;
}



