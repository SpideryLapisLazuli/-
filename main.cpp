#include<iostream>
class linse
{
    bool zeroBlock()
    {
        return one == nullptr;
    }
    class block
    {
    public:
        char sym;
        int Pnum;
        int *Fnum;
        block *blockNull;
        block(int Pnum,char sym)//можно переменную также как и ту что в классе назвать смысл не поменяется this рулит
        {
        this->sym=sym;
        this->Pnum=Pnum;
        blockNull=0;
        //this->Fnum=&this->Pnum;//&this->Pnum;
        }

    };
public:
    block *one;
    block *zero;
    linse()
    {
        one=0;
        zero=0;
    }
    void Newblock(int Pnum,char sym)
    {
        block* b = new block(Pnum,sym);
        if(zeroBlock())
        {
            one=b;
            zero=b;
            return;
        }
        zero->blockNull=b;
        zero->Fnum=&b->Pnum;
        //zero->Fnum=Fnum;
        //std::cout<<*zero->Fnum;
        zero=b;

    }
    int show()
    {
        if(zeroBlock()) return 0;
        block *b=one;
        while(b)
        {
            std::cout<<b->Pnum<<b->sym;
            if (b->blockNull!=0) std::cout<<*b->Fnum;
            else return 0;
            b=b->blockNull;
        }
        return 0;
    }
};
int main()
{
    linse L;
    int Pnum=0;
    char sym='+';
    for(int i=0;std::cin.get()!='\n';i++)
    {
        std::cin>>Pnum>>sym;
        L.Newblock(Pnum,sym);
        //L.Newblock(b,a);

    }/////////
    L.show();
    return 0;
}
