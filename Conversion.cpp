#include <iostream>
using namespace std;

const int MAX = 100;

class Conversion
{
private:
    int value,radix;
    int count,data[MAX];
public:
    Conversion(int x,int n) : value(x),radix(n),count(0) {}
    void Compute();
    void Print() const;
};

void Conversion :: Compute()
{
    int temp1;
    int temp2 = value;
    for(int i = 0 ; temp2 > 0 ; i ++)
    {
        temp1 = temp2 % radix;
        temp2 = temp2 / radix;
        data[i] = temp1;
        count ++;
    }
}

void Conversion :: Print() const
{
    for(int i = count-1 ; i >= 0 ; i --)
    {
        cout << data[i];
    }
    cout << endl;
}

int main()
{
    int x;
    cout << "请输入需要转换的十进制的正整数:";
    cin  >> x;

    int radix;
    cout << "请输入需要转换的进制:";
    cin >> radix;

    Conversion obj(x,radix);
    obj.Compute();
    cout << "转换后的" << radix << "进制数是:";
    obj.Print();
    return 0;
}