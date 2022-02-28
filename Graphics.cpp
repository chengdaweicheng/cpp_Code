#include <iostream>
#include <iomanip>
using namespace std;

class Graphics					//ͼ����
{
protected:
    int edges;
public:
    Graphics(int x):edges(x) { }
    virtual void Draw()=0;
};

class IsoscelesTriangles : public Graphics		//������������
{
public:
    IsoscelesTriangles(int x): Graphics(x) { }
    void Draw();
};

void IsoscelesTriangles::Draw()
{
    //int i,j;
    if(edges<=0)
        cout<<"errors"<<endl;
    if(edges>0)
    {
        for(int i=0;i<edges;i++)
        {
            for(int j=0;j<edges-i;j++)		//���ǰ���ո�
                cout<<setw(2)<<' ';
            for(int j=0;j<2*i+1;j++)
                cout<<setw(2)<<'*';
            cout<<endl;
        }
    }
    cout<<endl;
}

class Parallelogram : public Graphics		//ƽ���ı�����
{
public:
    Parallelogram(int x):Graphics(x) { }
    void Draw();
};

void Parallelogram :: Draw()
{
    if(edges<=0)
        cout<<"errors"<<endl;
    if(edges>0)
    {
        for(int i=0;i<edges;i++)
        {
            for(int j=0;j<edges-i;j++)
                cout<<setw(2)<<' ';
            for(int j=0;j<edges;j++)		//���ÿ�е�*��
                cout<<setw(2)<<'*';
            cout<<endl;
        }
    }
    cout<<endl;
}

int main()
{
    int e;
    cin>>e;
    Graphics *objs[2];
    objs[0]=new IsoscelesTriangles(e);
    objs[1]=new Parallelogram(e);
    for(int i=0;i<2;i++)
        objs[i]->Draw();
    delete objs[0];
    delete objs[1];
    return 0;
}