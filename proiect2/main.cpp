#include <iostream>
#include <typeinfo>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Card{
protected:
    string nrCard;
    string NumeDetinator;
    string data_expirare;
    int CVV;
    double credit;
    static string emitent;
public:

    Card()
    {
        nrCard="necunoscut";
        NumeDetinator="necunoscut";
        data_expirare="-";
        CVV=0;
        credit=0;
    }
    Card(string nc,string Nd="necunoscut",string data="-",int cv=0, double c=0)
    {
        nrCard=nc;
        NumeDetinator=Nd;
        data_expirare=data;
        CVV=cv;
        credit=c;
    }
    Card(const Card&);
    Card& operator= (Card&);
    virtual void citire();
    virtual void retragere(double bani);
    friend ostream& operator<<(ostream&, Card&);
    friend istream& operator>>(istream&, Card&);
    static void afisare_emitent()
    {
        cout<<"emitent: "<<emitent<<endl;
    }
    void setcredit(double s)
    {
      credit = s;
    }
    double getcredit()
    {
      return credit;
    }
    string getnume()
    {
        return NumeDetinator;
    }
    virtual ~Card(){cout<<"\n~Card\n";}
};
void Card::retragere(double bani)
{
    cout<<"Se realizeaza tranzatia";
}
void Card::citire()
{
    cout<<"Numar card: ";
    cin>>nrCard;
    try{
        int i = 0;
        while (nrCard[i])
        {
            if(nrCard[i]<'0' || nrCard[i]>'9')
            {
                throw nrCard;
            }
            i++;
        }
    }
    catch(string nrcard){cout<<"Numarul cardului nu este valid, introduceti altul!";
    cin>>nrCard;}
    cout<<" Nume detinator: ";
    cin>>NumeDetinator;
    cout<<" Data expirare: ";
    cin>>data_expirare;
    try{
        int i = 0;
        while (data_expirare[i])
        {
            if(i==2 ||i==5)
            {
                if(data_expirare[i]!='/')
                {
                    throw data_expirare;
                }

            }
            else
            {
                if(data_expirare[i]<'0' || data_expirare[i]>'9')
                {
                    throw data_expirare;
                }
            }
            i++;
        }
    }
    catch(string data_expirare){cout<<"Data de expirare a cardului nu este valida, introduceti altul!";
    cin>>data_expirare;}
    cout<<" CVV: ";
    cin>>CVV;
    cout<<" credit: ";
    cin>>credit;
    try{

        if(credit<0)
        {
            throw credit;
        }
    }
    catch(double credit){cout<<"Creditul nu poate fi negativ, introduceti altul! ";
    cin>>credit;}
}
Card::Card(const Card& ob)
{
    nrCard=ob.nrCard;
    NumeDetinator=ob.NumeDetinator;
    data_expirare=ob.data_expirare;
    CVV=ob.CVV;
    credit=ob.credit;
}

Card& Card::operator= (Card& ob)
{
    if (this != &ob)
    {
        nrCard=ob.nrCard;
        NumeDetinator=ob.NumeDetinator;
        data_expirare=ob.data_expirare;
        CVV=ob.CVV;
        credit=ob.credit;
    }
    return *this;
}
istream& operator>>(istream& in, Card& c)
{
    cout<<"Numar card: ";
    in>>c.nrCard;
    try{
        int i = 0;
        while (c.nrCard[i])
        {
            if(c.nrCard[i]<'0' || c.nrCard[i]>'9')
            {
                throw c.nrCard;
            }
            i++;
        }
    }
    catch(string nrcard){cout<<"Numarul cardului nu este valid, introduceti altul!";
    in>>c.nrCard;}
    cout<<" Nume detinator: ";
    in>>c.NumeDetinator;
    cout<<" Data expirare(de forma dd/mm/yyyy): ";
    in>>c.data_expirare;
    try{
        int i = 0;
        while (c.data_expirare[i])
        {
            if(i==2 ||i==5)
            {
                if(c.data_expirare[i]!='/')
                {
                    throw c.data_expirare;
                }

            }
            else
            {
                if(c.data_expirare[i]<'0' || c.data_expirare[i]>'9')
                {
                    throw c.data_expirare;
                }
            }
            i++;
        }
    }
    catch(string data_expirare){cout<<"Data de expirare a cardului nu este valida, introduceti altul! ";
    in>>c.data_expirare;}
    cout<<" CVV: ";
    in>>c.CVV;
    cout<<" credit: ";
    in>>c.credit;
    try{

        if(c.credit<0)
        {
            throw c.credit;
        }
    }
    catch(double credit){cout<<"Creditul nu poate fi negativ, introduceti altul! ";
    in>>c.credit;}
    return in;
}
ostream& operator<<(ostream& out, Card& c)
{
    out<<"Numar card: "<<c.nrCard<<" Nume detinator: "<<c.NumeDetinator<<" Data expirare: "<<c.data_expirare<<" CVV: "<<c.CVV<<" credit: "<<c.credit<<endl;
    return out;
}
                                                ///Standard
class Card_standard: public Card
{
protected:
    int limitaExtragere;
    double comisionDepasireLimita;
public:
    Card_standard():Card()
    {
        limitaExtragere=0;
        comisionDepasireLimita=0;
    }
    Card_standard(string nc,string Nd="necunoscut",string data="-",int cv=0, double c=0,int le=0,double cd=0):Card(nc,Nd,data,cv,c)
    {
        limitaExtragere=le;
        comisionDepasireLimita=cd;
    }
    Card_standard(const Card_standard& ob):Card(ob)
    {
        limitaExtragere=ob.limitaExtragere;
        comisionDepasireLimita=ob.comisionDepasireLimita;
    }
    Card_standard& operator=(Card_standard&);
    void citire();
    void retragere(double bani);
    friend ostream& operator<<(ostream&, Card_standard&);
    friend istream& operator>>(istream&, Card_standard&);
    int getlimitaExtragere()
    {
      return limitaExtragere;
    }
    double getcomisionDepasireLimita()
    {
        return comisionDepasireLimita;
    }
    ~Card_standard(){cout<<"\n~Card_standard\n";}
};
string Card::emitent="Gheorghe Cosmina";
Card_standard& Card_standard::operator=(Card_standard& ob)
{
    if (this != &ob)
    {
        Card::operator=(ob);
        limitaExtragere=ob.limitaExtragere;
        comisionDepasireLimita=ob.comisionDepasireLimita;
    }
    return *this;
}
void Card_standard :: citire()
{
    Card::citire();
    cout<<"limita extragere";
    cin>>limitaExtragere;
    cout<<"comision depasire limita";
    cin>>comisionDepasireLimita;
}
void Card_standard ::retragere( double bani)
{
    if(bani<credit)
    {
        cout<<"ok";
        if(bani>limitaExtragere)
                        {
                            cout<<"aaaaaa";
                            credit=credit-bani - (bani*(comisionDepasireLimita/100));
                        }
                        else
                        {
                            cout<<"bbbbbb";
                            credit=credit-bani;
                        }
    }
}
istream& operator>>(istream& in, Card_standard& c)
{
    cin>>dynamic_cast<Card&>(c);
    cout<<"limita extragere";
    cin>>c.limitaExtragere;
    cout<<"comision depasire limita";
    cin>>c.comisionDepasireLimita;
}
ostream& operator<<(ostream& out, Card_standard& c)
{
    out<<dynamic_cast<Card&>(c);
    out<<"limita extragere "<<c.limitaExtragere<<"comision depasire limita "<<c.comisionDepasireLimita;
    return out;
}
                                            ///PREMIUM
class Card_premium: public Card_standard
{
    double cashback;
public:
    Card_premium():Card_standard()
    {
        cashback=0;
    }
    Card_premium(string nc,string Nd="necunoscut",string data="-",int cv=0, double c=0,int le=0,double cd=0, double cb=0):Card_standard(nc,Nd,data,cv,c)
    {
        cashback=cb;
    }
    Card_premium(const Card_premium& ob):Card_standard(ob)
    {
        cashback=ob.cashback;
    }
    Card_premium& operator=(Card_premium&);
    void citire();
    void retragere(double bani);
    friend istream& operator>>(istream&, Card_premium&);
    friend ostream& operator<<(ostream&, Card_premium&);
    double getcashback()
    {
        return cashback;
    }
    ~Card_premium(){cout<<"\n~Card_premium\n";}
};
Card_premium& Card_premium::operator=(Card_premium& ob)
{
    if (this != &ob)
    {
        Card_standard::operator=(ob);
        cashback=ob.cashback;
    }
    return *this;
}
void Card_premium ::retragere( double bani)
{
    if(bani<credit)
    {
        cout<<"ccccc";
        credit=credit-bani+ (cashback/100)*bani;
    }
}
void Card_premium :: citire()
{
    Card_standard::citire();
    cout<<"cashback";
    cin>>cashback;
}
istream& operator>>(istream& out, Card_premium& c)
{
    cin>>dynamic_cast<Card_standard&>(c);
    cout<<"cashback";
    cin>>c.cashback;
}
ostream& operator<<(ostream& out, Card_premium& c)
{
    out<<dynamic_cast<Card_standard&>(c);
    out<<"cashback "<<c.cashback;
    return out;
}
int main()
{
    int optiune;
    cout<<"CARDURI!"<<endl;
    cout<<"1.Initializare carduri."<<endl;
    cout<<"2.Afisare carduri."<<endl;
    cout<<"3.Afisare emitent"<<endl;
    cout<<"4.Extragere bani de pe card.(cu setteri si getteri)"<<endl;
    cout<<"5.Extragere bani de pe card.(prin metoda)"<<endl;
    cout<<"6.Meniu."<<endl;
    cout<<"0.Iesire din banca"<<endl;
    cout<<"Alegeti o actiune."<<endl;
    cin>>optiune;
    string l;
    vector<Card*>v;
    int n;
    double bani;
    while(optiune!=0)
    {

    if(optiune==1){
        cout<<"Nr carduri:";
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cout<<"tip card: 1-standard, 2-premium";
            int optiune;
            cin>>optiune;
            if(optiune==1)
            {
                v.push_back(new Card_standard());
            }
            else
            {
                v.push_back(new Card_premium());
            }
        }
        for(auto c=v.begin();c!=v.end();c++)
        {
            //(**c).citire();
            if(typeid(**c)==typeid(Card_standard))
            {
                ///*dynamic_cast<Card_standard*>(*c)=c1;
                cin>>*dynamic_cast<Card_standard*>(*c);
            }
            if(typeid(**c)==typeid(Card_premium))
            {
                ///*dynamic_cast<Card_premium*>(*c)=c2;
                cin>>*dynamic_cast<Card_premium*>(*c);
            }
        }
    }
    if(optiune==2)
    {
        for(auto c=v.begin();c!=v.end();c++)
    {
        ///(**c).setcredit(77);
        if(typeid(**c)==typeid(Card_standard))
        {
            ///*dynamic_cast<Card_standard*>(*c)=c1;
            cout<<*dynamic_cast<Card_standard*>(*c);
        }
        if(typeid(**c)==typeid(Card_premium))
        {
            ///*dynamic_cast<Card_premium*>(*c)=c2;
            cout<<*dynamic_cast<Card_premium*>(*c);
        }
        Card::afisare_emitent();
    }
    }
    if(optiune==3)
    {
        Card::afisare_emitent();
    }
    if(optiune==4)
    {
        cout<<"Numele detinatorului cardului de pe care extragem: ";
        cin>>l;
        cout<<"Cat extragem?";
        cin>>bani;
        for(auto c=v.begin();c!=v.end();c++)
        {
            if(l==(**c).getnume())
            {
                if(bani<=(**c).getcredit())
                {
                    if(typeid(**c)==typeid(Card_standard))
                    {
                        if(bani>(*dynamic_cast<Card_standard*>(*c)).getlimitaExtragere())
                        {
                            (**c).setcredit((**c).getcredit()-bani - (bani*((*dynamic_cast<Card_standard*>(*c)).getcomisionDepasireLimita()/100)));
                        }
                        else
                        {
                            (**c).setcredit((**c).getcredit()-bani);
                        }
                    }
                    if(typeid(**c)==typeid(Card_premium))
                    {
                        (**c).setcredit((**c).getcredit()-bani+ ((*dynamic_cast<Card_premium*>(*c)).getcashback()/100)*bani);
                    }

                }
            }
        }
    }
    if(optiune==5)
    {
        cout<<"Numele detinatorului cardului de pe care extragem: ";
        cin>>l;
        cout<<"Cat extragem?";
        cin>>bani;
        for(auto c=v.begin();c!=v.end();c++)
        {
            if(l==(**c).getnume())
            {
                (**c).retragere(bani);
            }
        }
    }
    if(optiune==6)
    {
        cout<<"CARDURI!"<<endl;
    cout<<"1.Initializare carduri."<<endl;
    cout<<"2.Afisare carduri."<<endl;
    cout<<"3.Afisare emitent"<<endl;
    cout<<"4.Extragere bani de pe card.(cu setteri si getteri)"<<endl;
    cout<<"5.Extragere bani de pe card.(prin metoda)"<<endl;
    cout<<"6.Meniu."<<endl;
    cout<<"0.Iesire din banca"<<endl;
    }
    cout<<"Alegeti o alta actiune."<<endl;
    cin>>optiune;
    }

}
