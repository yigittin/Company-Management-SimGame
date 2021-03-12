#include <iostream>
#include <Windows.h>
#include <ctime>
using namespace std;

//CONSULTANT EMPLOYEE INHERITANCE AYARLA

class Company
{

};

class Employee
{
protected:
    string isim;
    int yas = 20;
    int tecrube = 2;
    int maas = 5500;
    int maasAlt = 0;
    int birikim = 0;
    int emeklilikYas;
    int gider = 4000;
public:


    virtual int yaslanma()
    {
        return 0;
    }

    virtual int altLimitBelirle() { return maasAlt = 3000; }





};

class Engineer :public Employee
{
private:
    int katki = 0;
    int problem = 0;
    int potansiyel = 0;
public:
    int yaslanma(int x)
    {
        yas = yas + x;
        maas = maas + (x * 200);
        tecrube = tecrube + x;
        potansiyelBelirle();
        return maas, yas;
    }
    void setIsim(string isim)
    {
        this->isim = isim;
    }
    string getIsim()
    {
        return isim;
    }

    void setYas(int yas)
    {
        this->yas = yas;
        if (yas < 18)
        {
            cout << "Yaþ 18 den kucuk olamaz" << endl;
            cout << "18 olarak ayarlandi " << endl;
            this->yas = 18;
        }
    }
    int getYas()
    {
        return yas;
    }

    void setProblem(int problem)
    {
        this->problem = problem;
        if (problem > 3)
        {
            katki = problem * 670;
        }
    }
    int getProblem()
    {
        return problem;
    }
    void bastir()
    {
        cout << isim << " KATKI :" << katki << " PROBLEM :" << problem << " MAAS :" << maas << " YAS :" << yas << " " << "maas alt : " << maasAlt << " " << "Potansiyel  : " << potansiyel << " Birikim : " << birikim << endl;
    }

    int katkiPayi()
    {
        maas += (katki / 50);
        return maas;
    }

    int hataPayi()
    {
        maas -= (katki / 50);
        return maas;
    }

    int problemCoz(int y) {

        if (y <= potansiyel)
        {
            problem = problem + y;
            katki = problem * 300;
            katkiPayi();
        }
        else
        {
            problemHata((y - potansiyel));
            problemCoz(potansiyel);
            hataPayi();
        }

        return problem;
    }

    int problemHata(int y)
    {
        problem = problem - y;
        if (y > 10)
        {

            katki = katki - (y * 1000);
            hataPayi();
        }
        return problem;
    }

    int altLimitBelirle()
    {
        int x = 2000;
        if (tecrube == 0) {}
        else
            x = x + (tecrube * 400);

        x = x + ((yas - 18) * 140);

        maasAlt = x;
        return maasAlt;
    }

    int potansiyelBelirle()
    {
        if (yas < 26) {
            int x = 0;
            x = x + ((yas - 18) * 2);
            if (tecrube > 0)
                x = x + (tecrube + 2);
            else
                x = x + 4;

            potansiyel = x;
        }
        else
        {
            int x = 0;
            x = x + ((yas - 18) * 2);
            if (tecrube == 0)
            {
                x - 10;
            }
            else
                x = x + tecrube;

            potansiyel = x;
        }

        return potansiyel;
    }
    int birikimYap()
    {
        birikim += (maas - gider);
        return birikim;
    }

};

class Manager :public Employee
{

};

class Consultant :public Employee
{
private:
    int satisMiktari = 0;
    float prim = 0;
    int musteriSayi = 0;
public:
    void setIsim(string isim)
    {
        this->isim = isim;
    }
    string getIsim()
    {
        return isim;
    }
    int getMusteri()
    {
        return musteriSayi;
    }
    void setPrim(float y)
    {
        if (y > 15)
        {
            cout << "Prim cok yuksek tekrar ayarlaniyor" << endl;
            this->prim = 15;
        }
        else
            this->prim = y;
    }
    float getPrim()
    {
        return prim;
    }
    float getSatis()
    {
        return satisMiktari;
    }
    int satisYapma(int y)
    {

        satisMiktari += y;
        primPayi(y);
        return satisMiktari;

    }
    float primPayi(float y)
    {
        y = y * (prim / 100);
        maas += y;
        return maas;
    }
    int altLimitBelirle()
    {
        return 0;
    }
    float networkPayi()
    {
        prim += musteriSayi / 1000;
        return prim;
    }
    int musteriBulma(int y)
    {
        musteriSayi += y;
        satisYapma((1400 * y));
        networkPayi();
        return musteriSayi;
    }



    void bastir()
    {
        cout << isim << " Satis : " << satisMiktari << " Prim :" << prim << " musteri : " << musteriSayi << " Maas :" << maas << endl;
    }

};

//Yigit KATKI :47570 PROBLEM :71 MAAS :20703 YAS :24 maas alt : 9000 Potansiyel  : 22
//Yigit KATKI :42210 PROBLEM :63 MAAS :19765 YAS :34 maas alt : 11000 Potansiyel  : 34
//Yigit KATKI : 69680 PROBLEM : 104 MAAS : 33835 YAS : 34 maas alt : 11000 Potansiyel : 34
int main()
{
    Engineer yigit;
    Consultant* ptrCons;
    int classModder = 0;
    yigit.setYas(20);
    yigit.setIsim("Yigit");
    yigit.potansiyelBelirle();
    Consultant dilek;
    dilek.setIsim("dilek");
    dilek.setPrim(7);
    dilek.musteriBulma(10);
    ptrCons = &dilek;
    classModder += ptrCons->getMusteri();
    yigit.problemCoz(classModder);
    yigit.bastir();
    yigit.yaslanma(5);
    dilek.bastir();
    dilek.musteriBulma(16);
    classModder += ptrCons->getMusteri();
    yigit.potansiyelBelirle();
    yigit.problemCoz(classModder);
    yigit.altLimitBelirle();
    dilek.bastir();
    yigit.bastir();




    int stop = 10;


    int enFazla = 30, enAz = 10;

    srand(time(0));


    /* do
     {
         srand(time(0));
         int x = rand() % (enFazla - enAz + 1) + enAz;
         yigit.yaslanma(1);
         yigit.altLimitBelirle();
         yigit.problemCoz(x);
         yigit.birikimYap();
         yigit.bastir();
         stop--;
         Sleep(400);
     } while (stop);
     */

}



