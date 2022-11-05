#include <iostream>
#include<windows.h>
using namespace std;
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
class Administration{
    protected :
    int Ad_id;
    public:
    Administration(int ADid){
        Ad_id=ADid;
    }
    void Enter_Data(){
        cout <<"entrez l'id d'administration : \n";
        cin>>Ad_id;
    }
    void Display_Data(){
        cout<<"l'id d'administration est : "<<Ad_id<<"\n";
    }
    /*cette m�thode est pour retourner l'id et le donner au parametre d'un objet cette m�thode on va l'utiliser en administration car
    on veut avoir la meme id d'administration dans les parametres d'agent*/
    int returnid(){
        return Ad_id;
    }
};
/*pour cette class personne on va h�riter 2 autres class , Client et agent ,
pour le client, il peut demander une service, rechercher d'une information et payer des facture, pour l'agent il peut just entrer ses informations et les voir(pour cette partie)*/
class Personne
{
    protected:
    int id ;
    string First_name;
    string last_name;
    string password;
    public:
    Personne(int Id,string Name,string L_name,string pass){
        id=Id;
        First_name=Name;
        last_name=L_name;
        password=pass;
    }
    void sign_up(){
        string pass;
        cout <<"entrez votre identifiant : \n";
        cin>>id;
        cout<<"entrez votre prenom : \n";
        cin>>First_name;
        cout<<"entrez votre nom: \n";
        cin>>last_name;
        cout<<"ecrivez une mot de passe : \n";
        cin>>password;
        cout<<"reecrivez votre mot de passe :\n";
        cin>>pass;
        while(pass!=password){
            SetConsoleTextAttribute(h,FOREGROUND_RED);
            cout <<"no matching reecrivez votre mot de passe : \n";
            SetConsoleTextAttribute(h,7);
            cin>>pass;
        };
    }
    void sign_in(){
        string mdp;
        int iden;
        cout<<"donner votre identifiant : ";
        cin>>iden;
        while(iden!=id){
            SetConsoleTextAttribute(h,FOREGROUND_RED);
            cout <<"identifiant incorrect, entrez votre identifiant: \n";
            SetConsoleTextAttribute(h,7);
            cin>>iden;
        };
        cout<<"donner votre mot de passe  : ";
        cin>>mdp;
        while(mdp!=password){
            SetConsoleTextAttribute(h,FOREGROUND_RED);
            cout <<"mot de passe incorrect, reecrivez votre mot de passe: \n";
            SetConsoleTextAttribute(h,7);
            cin>>mdp;
        };
    }
    void Display_Data(){
        cout<<last_name<<" "<<First_name<<", d'id: "<<id;
        /* ou on peut �crire cout <<"l'identifiant est :"<<id <<"\n";
        cout <<"le nom est: "<<last_name<<"\n";
        cout<<"le prenom est: "<<First_name <<"\n";*/
    }

};
class Client:public Personne
{
    protected:
    string C_id;
    public:
    Client(int Id,string Name,string L_name,string CID,string pass):Personne(Id,Name,L_name,pass){
        C_id=CID;
    }
    void sign_up(){
        Personne::sign_up();
        cout<<"entrez votre nom d'utilisateur : \n";
        cin>>C_id;
    }
    void sign_in(){
        string iden;
        cout<<"donner votre nom d'utilisateur : ";
        cin>>iden;
        while(iden!=C_id){
            SetConsoleTextAttribute(h,FOREGROUND_RED);
            cout <<"utilisateur incorrect, entrez votre nom d'utilisateur: \n";
            SetConsoleTextAttribute(h,7);
            cin>>iden;
        };
        Personne::sign_in();
    }

    void Display_Data(){
        Personne::Display_Data();
        cout<<", avec nom d'utilisateur "<<C_id<<"\n";
    }
    void send_feedback(){
        string feedback;
        cout<<"que pensez vous de la service ? donnez votre feed_back: \n";
        cin>>feedback;
    }
};
/*le class agent h�rite de deux classes, Personne et administration car chaque agent doit avoir l'id d'administration o� il travaille*/
class Agent:public Personne,public Administration
{
    protected:
    int A_id;
    public:
    Agent(int Id,string Name,string L_name,int Ad_id,int AID,string pass):Personne(Id,Name,L_name,pass),Administration(Ad_id){
        A_id=AID;
    }
    void sign_up(){
        Personne::sign_up();
        cout<<"entrez votre identifiant comme agent d'administration : \n";
        cin>>A_id;
    }
    void sign_in(){
        int iden;
        cout<<"donner votre identifiant comme agent: ";
        cin>>iden;
        while(iden!=A_id){
            SetConsoleTextAttribute(h,FOREGROUND_RED);
            cout <<"identifiant agent incorrect, entrez votre identifiant agent: \n";
            SetConsoleTextAttribute(h,7);
            cin>>iden;
        };
        Personne::sign_in();
    }
    void Display_Data(){
        Personne::Display_Data();
        cout<<", d'identifiant agent : "<<A_id<<" et ";
        Administration::Display_Data();
    }
};
/*on a deux types de service, Enligne comme demande de certificat de naissance et En place comme l�galistation des documents,
donc on va h�riter de cette classe(Service)*/
class Service{
    protected:
    string Service_Name;
    public:
    Service(string SName,int SID){
        Service_Name=SName;
    }
    void Enter_Service(){
        cout <<"entrez le nom de service demand� : \n";
        cin>>Service_Name;
    }
    void Display_Service(){
        cout <<"la service est :"<<Service_Name <<"\n";
    }
};
/*Chaque service enligne  ou enplace contient un autre code autre que service_id*/
class Service_ENLIGNE:public Service{
    protected:
        int S_Id;
    public:
    Service_ENLIGNE(string SName,float P,int SID):Service(SName,P){
        S_Id=SID;
    }
    void Enter_Service(){
        Service::Enter_Service();
        cout<<"entrez le code de service en ligne demand�e : \n";
        cin>>S_Id;
    }
    void Display_Service(){
        Service::Display_Service();
        cout<<"l'id de service est : "<<S_Id<<"\n";
    }
    int returnid(){
        return S_Id;
    }
};
class Service_ENPLACE:public Service{
    protected:
        int SP_id;
    public:
    Service_ENPLACE(string SName,float P,int SPID):Service(SName,P){
        SP_id=SPID;
    }
    void Enter_Service(){
        Service::Enter_Service();
        cout<<"entrez le code de service demand�e : \n";
        cin>>SP_id;
    }
    void Display_Service(){
        Service::Display_Service();
        cout<<"l'id de service est : "<<SP_id<<"\n";
    }
    /*on a besoin de cette m�thode pour retourner l'id de service au parametre de Bill, car apres chaque service il faut payer donc on a besoin d'id de service pour valider le paiment*/
    int returnid(){
        return SP_id;
    }
};
class Bill{
    protected:
        int B_id;
        float montant;
        int Id_Service;
    public:
    Bill(int BI,float M, int IS){
        B_id=BI;
        montant=M;
        Id_Service=IS;
    }
    void Enter_bill(){
        cout<<"entrez le code de facture demand�e : \n";
        cin>>B_id;
    }
    void Display_bill(){
        cout<<"l'id de facture est : "<<B_id<<" et l'id de service demand� dans cette facture est:  "<<Id_Service<<"\n";
    }
};
class Info{
    protected:
        string Inf;
    public:
        Info(string INF){
            Inf=INF;
        }
    void Enter_info(){
        cout<<"entrez le nom d'info recherch� :B3,Passeport,Extrait_de_naissance,CIN \n";
        cin>>Inf;
    }
    void Display_info(){
        cout<<"la service est : "<<Inf<<"\n";
        //l'affichage d'info se fait avec une base de donn�es donc on va �crire un code pour exipliquer le fonctionnement sans base de donn�es
        if (Inf=="B3"){
            cout<<"les pieces a fournir : \n 1-Imprim� � remplir et � signer \n 2-Pr�sentation de la Carte d'identit� nationale et d�p�t d'une copie\n 3- Extrait de naissance pour les mineurs \n 4-Attestation de r�sidence pour les �trangers r�sidents en Tunisie\n";
            cout<<"\n Re�u de paiement du droit du bulletin (3 dinars)\n";
        } else if (Inf=="Extrait_de_naissance"){
            cout<<"les conditions :\n 1-La personne concern�e doit �tre transcrite sur les registres d��tat civil tenus par le Consulat\n";
            cout<<"2-La personne n�e en Tunisie ne peut avoir un extrait de naissance tunisien que sur pr�sentation d�un Livret de Famille Tunisien (dans ce cas l�extrait de naissance ne sera pas consid�r� comme original)\n";
        } else if(Inf=="Passeport"){
            cout<<"**Etablissement pour la 1�re fois:\n";
            cout<<"*Un imprim� d'obtention d'un passeport ordinaire lisible � la machine, le remplir et mettre la signature dans la case y aff�rente.\n";
            cout<<"*Copie de la Carte d'identit� nationale avec pr�sentation de l'originale ou un extrait de naissance pour les mineurs.\n";
            cout<<"*4 photos avec les caract�ristiques suivantes : Fond blanc,Format 3.5/4.5 cm\n";
            cout<<"*Justificatif de scolarisation pour les �l�ves et les �tudiants.\n";
            cout<<"*Autorisation du tuteur pour les mineurs accompagn�e d'une copie de sa carte d'identit� nationale.\n";
            cout<<"*Quittance de paiement d�livr�e par les recettes de finances d'une valeur de certaines formules administratives:\n";
            cout<<"*De 25 dinars pour les �tudiants et �l�ves qui justifient de leur qualit� par la pr�sentation d�un certificat et aux enfants de moins de sept ans ainsi que leur prorogation\n";
            cout<<"*De 80 dinars pour les autres ainsi que leur prorogation.\n";
        }else if(Inf=="CIN"){
        cout<<"*Pieces a fournir :\n";
        cout<<"*Imprime administratif a remplir\n";
        cout<<"*Extrait de naissance etabli des registres originaux d'etat civil datant de 3 mois au plus\n";
        cout<<"*Attestation prouvant la nationalite tunisienne\n";
        cout<<"*Attestation de residence- Attestation de travail ou de presence scolaire ou universitaire\n";
        cout<<"*3 photos d'identite de l'interesse du format 3/4 cm prises en face sur support arriere d'une couleur blanche ou claire et a l'echelle 1/10 montrant les cheveux et les yeux\n";
        cout<<"*Quittance de paiement delivree par les recettes de finances d'une valeur de 3 dinars\n";
        cout<<"*Deux exemplaires de la copie de la carte de residence et de la carte consulaire pour les residents � l'etranger\n";
        cout<<"*Autorisation du tuteur legal sign�e, l�galis�e et motiv�e pour l'obtention de la carte d'identit� nationale (raison professionnelle, �ducative, sportive ou physique) et ce pour les mineurs de moins de 18 ans\n";
        cout<<"Certificat indiquant le groupe sanguin (facultatif)\n";
        }
        else{
            SetConsoleTextAttribute(h,FOREGROUND_RED);
            cout<<"non existant\n";
            SetConsoleTextAttribute(h,7);
        }
    }
};
/*on a besoin de carte pour payer les services enligne mais pour les services enplace on va payer en espece et sur palce*/
class Carte{
    protected :
        int num_carte;
    public:
    Carte(int NC){
        num_carte=NC;
    }
    void Enter_carte(){
        cout <<"entrez le numero du carte : \n";
        cin>>num_carte;
    }
    void Display_carte(){
        cout<<"le numero de carte est : "<<num_carte<<"\n";
    }
};
int main(){
    char press,q;
    bool Sucess=false;
    bool Continue=true;
    int choix;
    int choice;
    int x,c;
    float m;
    Client C1(0,"0","0","0","0");
    Service_ENPLACE SP("0",10.5,0);
    Service_ENLIGNE SE("0",10.5,0);
    Carte C(0);
    SetConsoleTextAttribute(h,13);
    cout<< "*** Bienvenue ***\n";
    SetConsoleTextAttribute(h,7);
    /*on a deux choix, l'utilisateur est un client ou agent d'administration, donc on va donner 1 pour client et 2 pour agent,
    si l'utilisateur choisir un autre chiffre, on va demander une autre fois de choisir 1 ou 2*/
    do{
        /*on donne le choix au utilisateur car le client peut demander des services, ou rechercher des infos ou bien payer des facture*/
        cout<<"etes-vous client ou agent? 1 si client 2 si agent: \n";
        cin>>choix;
    }while(choix!=1 && choix!=2);
    if (choix==1){
        C1.sign_up();
        SetConsoleTextAttribute(h,FOREGROUND_GREEN);
        cout<<"***creation du compte avec success***\n";
        SetConsoleTextAttribute(h,7);
        C1.sign_in();
        SetConsoleTextAttribute(h,FOREGROUND_GREEN);
        cout<<"vous avez connecte avec succes \n";
        SetConsoleTextAttribute(h,7);
        C1.Display_Data();
        SetConsoleTextAttribute(h,13);
        cout<<"***Bienvenue Dans la page Client!*** \n";
        SetConsoleTextAttribute(h,7);
        /* on a 3 op�rations possible, donc on donne 1 pour demander une service,2 pour chercher des infos,3 pour payer une facture
        si l'utilisateur choisit un autre chiffre on va lui donne la main une autre fois de choisir une oop�ration, jusqu'� avoir un valide choix*/
        do{
                Sucess=false;
            do{
                cout<<"Quelle operation voules-vous faire?\n 1- demander une service \n 2- chercher une information \n 3- payer une facture \n";
                cin>>choice;
            }while(choice != 1 && choice !=2 && choice!=3);
            if(choice==1)
            {
                SetConsoleTextAttribute(h,13);
                cout<<"***Demande de Service ***\n";
                SetConsoleTextAttribute(h,7);
                /*il fuat choisir 1 ou 2, sinon la demande de choisir un chiffre se repete*/
                do{
                    cout<<"1-sevice enligne \n 2- service en place \n";
                    cin>>x;
                }while(x!=1&&x!=2);
                switch (x){
                    /*dans cette cas l'utilisateur va entrer les donn�es de service, puis le donner de paiment, ensuite v�rifier si tous les infos sont correcte
                    si tout est correcte il appyue sur O ou o et un message de succes va afficher, sinon l'op�ration va se repeter */
                case 1:
                {
                    do{
                        SE.Enter_Service();
                        Bill B(0,10.5,SE.returnid());
                        B.Enter_bill();
                        SetConsoleTextAttribute(h,13);
                        /*on a plusieurs types de services comme b3,cin,passeport alors plusieurs prix ...
    donc j'ai fix� le prix de service car on ne sait pas le prix de tous les services*/
                        cout<<"**paiment** \n";
                        SetConsoleTextAttribute(h,7);
                        cout<<"Vous devez payer 10.5 !!\n";
                        C.Enter_carte();
                        cout<<"Dernier etape , validation des cordonnees pour le client!\n";
                        C1.Display_Data();
                        SE.Display_Service();
                        B.Display_bill();
                        C.Display_carte();
                        SetConsoleTextAttribute(h,13);
                        cout<<"si tous les infos sont correctes pressez O ou o : ";
                        SetConsoleTextAttribute(h,7);
                        cin>>press;
                        if (press=='O' || press=='o')
                        {
                            Sucess=true;
                            SetConsoleTextAttribute(h,FOREGROUND_GREEN);
                            cout << "validation complete! \n";
                            SetConsoleTextAttribute(h,7);
                        }
                    }while(Sucess==false);

                }
                break;

                case 2:
                {
                    do{
                    SP.Enter_Service();
                    Bill B(0,10.5,SP.returnid());
                    B.Enter_bill();
                    cout<<"Dernier etape , validation des cordonnees pour le client ";
                    C1.Display_Data();
                    SP.Display_Service();
                    B.Display_bill();
                    SetConsoleTextAttribute(h,13);
                    cout<<"si tous les infos sont correctes pressez O ou o:";
                    SetConsoleTextAttribute(h,7);
                    cin>>press;
                    if (press=='O' || press=='o')
                        {
                            Sucess=true;
                            SetConsoleTextAttribute(h,FOREGROUND_GREEN);
                            cout << "validation complete \n";
                            SetConsoleTextAttribute(h,13);
                            cout<<"**paiment** \n vous devez payer 10.5 passez au administration pour payer \n";
                            SetConsoleTextAttribute(h,7);
                        }
                    }while(Sucess==false);
                }
                break;
                }
            }
            else if(choice==2)
                {
                    SetConsoleTextAttribute(h,13);
                    cout<<"***Recherche d'information ***\n";
                    SetConsoleTextAttribute(h,7);
                    Info I("0");
                    I.Enter_info();
                    I.Display_info();
                }

            else{
                do{
                SetConsoleTextAttribute(h,13);
                cout<<"***Paiment de facture*** \n";
                SetConsoleTextAttribute(h,7);
                cout<<"donner le code de facture\n";
                cin>>c;
                cout<<"donner le montant de facture";
                cin>>m;
                Bill B(c,m,c);
                Carte C(0);
                C.Enter_carte();
                cout<<"Dernier etape , validation des cordonnees pour le client  ";
                    C1.Display_Data();
                    B.Display_bill();
                    SetConsoleTextAttribute(h,13);
                    cout<<"si tous les infos sont correctes pressez O ou o: ";
                    SetConsoleTextAttribute(h,7);
                    cin>>press;
                    if (press=='O' || press=='o')
                        {
                            Sucess=true;
                            SetConsoleTextAttribute(h,FOREGROUND_GREEN);
                            cout << "validation complete le montant � payer est : "<<m<<"\n";
                            SetConsoleTextAttribute(h,7);

                        }
                }while(Sucess==false);
            }
            cout<<"voulez vous continuer ou quitter ? si quitter appyuer sur F ou f: ";
                    cin>>q;
                    if(q=='F' || q=='f')
                        {
                            C1.send_feedback();
                            SetConsoleTextAttribute(h,3);
                            cout<<"****Merci pour votre visite, a bientot !**** ";
                            SetConsoleTextAttribute(h,7);
                            Continue=false;
                        }
        }while (Continue==true);
        /*pour que l'utilisateur ne perdre pas le temps � chaque fois pour passer une operation , on lui donne le choix de rester sur l'interface
        pour acceder au autre operation,et s'il veut quitter il appyue sur F ou f */
    }
        else {
            Administration Ad(0);
            Ad.Enter_Data();
            Agent Ag(0,"0","0",Ad.returnid(),0,"0");
            Ag.sign_up();
            SetConsoleTextAttribute(h,FOREGROUND_GREEN);
            cout<<"***creation du compte avec success***\n";
            SetConsoleTextAttribute(h,7);
            Ag.sign_in();
            SetConsoleTextAttribute(h,13);
            cout<<"***Bienvenue Dans la page administrateur!*** \n";
            SetConsoleTextAttribute(h,7);
            Ag.Display_Data();

        }
return 0;
}
