#include <iostream>
using namespace std;
class Personne
{
private:
    const int ncin;
    string nom;
    int age;
public:
    Personne(string n, int c, int a);
    void incrementerAge();
    void setAge(int);
    int getAge() const;
    void setnom(string);
    string getnom() const;
    void afficher() const;

};
Personne::Personne(string n,int c,int a=-1):nom(n),ncin(c),age(a){}

int Personne::getAge() const
{
    return this->age;
}
void Personne::incrementerAge()
{
    age++;
}
void Personne::setAge(int x)
{
    if(x>age)
    {
        age=x;
    }
}
void Personne::setnom(string ch)
{
    nom=ch;
}
string Personne::getnom()const
{
    return nom;
}
void Personne::afficher() const
 {
 	cout<<"le numero cin :" << ncin<< endl;
 	cout<<"son nom est :" << nom << endl;
 	cout<<"son age est :" << age << endl;
 }
class Compte
{
    const int numCompte;
    Personne proprietaire;
    double solde;
    public:
        Compte(int n,Personne p,double s);
        double getSolde()const;
        int getnumCompte()const;
        //void setProprietaire(Personne);
        //Personne getProprietaire();
        void retirerArgent(double montant);
        void deposerArgent(double montant);
        void afficherCompte();

};
Compte::Compte(int n,Personne p,double s=0):numCompte(n),proprietaire(p)
{
    if(s>=0)
    {
        solde=s;
    }
    else
    {
        solde=0;
    }
}
double Compte::getSolde()const
{
    return solde;
}
int Compte::getnumCompte()const
{
    return numCompte;
}
/*
void Compte::setProprietaire(Personne p)
{
    proprietaire=p;
}
Personne Compte::getProprietaire()
{
    return proprietaire;
}
*/
void Compte::retirerArgent(double montant)
{
    if(solde>montant)
    {
        solde-=montant;
    }
    //return solde;
}
void Compte::deposerArgent(double montant)
{
    solde+=montant;
    //return solde;
}
void Compte::afficherCompte()
{
    //cin >> numCompte;
    //cin >> proprietaire;
    //cin >> solde;
  //  cout << numCompte << endl;
//    cout << proprietaire.getnom << endl;
    cout << solde << endl;
}
class Banque
{
    string nom;
    //Personne proprietaire;
    int nombreComptes;
    Compte *tab[100];
    public:
        Banque(string nom);
        void ouvrirCompte(Compte* c);
        /*void transfertArgent(Compte,Compte,double montant);
        void store(int nombreComptes);*/
        void fermerCompte(int numCompte);
        void retirer(int numCompte, double montant);
        void deposer(int numCompte, double montant);
        Compte* rechercher(int numCompte)const;
};
Banque::Banque(string n):nom(n),nombreComptes(0)
{
    for(int i=0;i<100;i++)
    {
        tab[i]=NULL;
    }
}
Compte*Banque::rechercher(int numCompte) const
{
    for(int i=0;i<nombreComptes;i++)
    {
        if(tab[i]->getnumCompte()==numCompte)
            return tab[i];
    }
    return NULL;
}
/*
void Banque::transfertArgent(Compte compte1,Compte compte2,double montant)
{
    double d1,d2;
    d1=Compte::retirerArgent(compte1,montant);
    d2=Compte::deposerArgent(compte2,montant);
}*/
void Banque::ouvrirCompte(Compte* c)
{
    tab[nombreComptes++]=c;
}
/*void store(int nombreComptes)
{
    if account=ouvrirCompte(int num_compte,Personne)
    {
        nombreComptes+=1;
    }
    for(int i=0; i<nombreComptes; i++)
    {
        accounts[i]=account;
    }
}
*/
void Banque::fermerCompte(int numCompte)
{
    Compte* compteAFermer=rechercher(numCompte);
    if(compteAFermer!=NULL)
    {
        delete(compteAFermer);
        //tab[nombreCompte-1] decalage a faire
        //tab[compteAFermer-tab];
    }
}
