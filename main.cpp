#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;

int main()
{
    filesystem::create_directories("saves");
    bool estAdmin = false;
    bool vrai = false;
    int connex = 0;
    string pseudo;
    string mdp;
    string bmdp;
    string nbchoix;
    int level = 0;
    int monde = 1;
    int choix = 0; 
    int xp = 0;
    int money = 0;

    cout << "Bonjour et bienvenue dans le jeu THE WORLD 1.0" << endl << endl;
    cout << "Pour commencer veuillez :" << endl;
    while (true)
    {
        cout << "1 : NOUVELLE PARTIE" << endl << "2 : CHARGER UNE PARTIE" << endl;
        cout << "choix : ";
        cin >> choix;
        if (choix == 2)
        {
            cout << "Nous allons continuer vers le chargement de partie..." << endl;
            break;
        }
        else if (choix == 1)
        {
            cout << "Nous allons continuer vers l'enregistrement de partie..." << endl;
            break;
        }
        else if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Mauvaise valeur donnée." << endl;
            continue;
        }
        else
        {
            cout << "Mauvais chiffre donné !" << endl;
        }
    }
    if (choix == 1)
    {
        cout << "Nous allons vous enregistrer." << endl;
        while (true)
        {
            while (true)
            {
                cout << "Tout d'abord nous allons commencer par choisir votre pseudo." << endl;
                cout << "pseudo : ";
                cin >> pseudo;
                string chemin = "saves/" + pseudo + ".txt";
                ifstream save(chemin);
                if (save.is_open())
                {
                    cout << "Ce pseudo existe deja." << endl;
                }
                else
                {
                    break;
                }
            }
            cout << "Tres bien maintenant le mot de passe : " << endl;
            cout << "mot de passe : ";
            cin >> mdp;
            cout << endl << "Parfait, pseudo : " << pseudo << ", mot de passe : " << mdp << "." << endl;
            cout << "Est ce que cela vous va [O/N] ?" << endl;
            cout << "choix : ";
            cin >> nbchoix;
            if (nbchoix == "O")
            {
                bmdp = mdp;
                string chemin = "saves/" + pseudo + ".txt";
                ofstream save(chemin);
                if (save.is_open())
                {
                    cout << "Parfait, sauvegarde cree." << endl;
                    save << connex << endl;
                    save << bmdp << endl;
                    save << xp << endl;
                    save << level << endl;
                    save << monde << endl;
                    save << money << endl;
                }
                save.close();
                break;
            }
            else if (nbchoix == "N")
            {
                cout << "Recommencons." << endl;
            }
            else if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Mauvaise valeur donnée.";
                continue;
            }
            else
            {
                cout << "Mauvaise lettre donnée !" << endl;
            }
        }
    }
    else if (choix == 2)
    {
        cout << "Nous allons charger votre partie" << endl;
        while (true)
        {
            string banni1temp;
            string banni2temp;
            int connextemp;
            string mdptemp;
            int xptemp;
            int leveltemp;
            int mondetemp;
            int moneytemp;
            cout << "Veuillez entrer votre pseudo." << endl;
            cout << "pseudo : ";
            cin >> pseudo;
            string chemin = "saves/" + pseudo + ".txt";
            if (ifstream banni("banni.txt"); banni.is_open())
            {
                banni >> banni1temp;
                banni >> banni2temp;
                if (pseudo == banni1temp || pseudo == banni2temp)
                {
                    cout << "Votre compte a ete banni par un admin." << endl;
                    cout << "Veuillez en recreer un." << endl;
                    cout << "(Apuyez sur entree pour continuer)";
                    cin.ignore();
                    cin.get();
                    return 1;
                }
            }
            if (ifstream save(chemin); save.is_open())
            {
                cout << "Un fichier de sauvegarde avec ce pseudo a bien ete retrouve !" << endl;
                if (!(save >> connextemp >> mdptemp >> xptemp >> leveltemp >> mondetemp >> moneytemp))
                {
                    cout << "FICHIER CORROMU" << endl << "Veuillez le supprimer avec la commande rm saves/" << pseudo << ".txt" << endl;
                    return 1;
                }
                connex = connextemp;
                bmdp = mdptemp;
                xp = xptemp;
                level = leveltemp;
                monde = mondetemp;
                money = moneytemp;
                save.close();
                break;
            }
            else
            {
                cout << "Fichier introuvable, veuillez redonner votre pseudo." << endl;
            }
        }
        cout << "Maintenant veuillez entrer votre mot de passe." << endl;
        while (true)
        {
            cout << "Mot de passe : ";
            cin >> mdp;
        if (bmdp == mdp)
            {
                cout << "Vous avez bien ete log in avec : " << pseudo << endl;
                break;
            }
            else
            {
                cout << "Veuillez recommencer." << endl;
            }
        }
    }
    if (pseudo == "admin")
    {
        ifstream fichierAdmin("admin.txt");
        string mdpAdmin;
        if (fichierAdmin >> mdpAdmin)
        {
            estAdmin = (mdp == mdpAdmin);
        }   
    }
    cout << "Bien le bonjour, " << pseudo << endl;
    int o;
    while (true)
    {
        cout << "Veuillez choisir entre ces choix ici présents : " << endl;
        cout << "1 : CONSULTER SON XP" << endl << "2 : CONSULTER SON LEVEL" << endl;
        cout << "3 : CONSULTER SON MONDE" << endl << "4 : CONSULTER SON ARGENT" << endl;
        cout << "5 : PARTIR A L'AVENTURE" << endl << "6 : VOIR SON NOMBRE DE CONNEXION" << endl;
        cout << "7 : QUITTER" << endl;
        if (pseudo == "admin" && mdp == "NathanAdmin67")
        {
            cout << "67 : VOIR LA DATA D'UN JOUEUR" << endl;
            cout << "69 : BANNIR UN JOUEUR" << endl;
        }
        cout << "choix : ";
        cin >> o;
        if (o == 1)
        {
            cout << "Votre XP est de : " << xp << endl;
        }
        else if (o == 2)
        {
            cout << "Votre level est de : " << level << endl;
        }
        else if (o == 3)
        {
            cout << "Votre monde est le : monde " << monde << endl;
        }
        else if (o == 4)
        {
            cout << "Votre argent est de : " << money << endl;
        }
        else if (o == 5)
        {
            cout << "Vous decidez de partir a l'aventure ?" << endl;
            cout << "C'est parti !" << endl;
            cout << "Vous vous balladez..." << endl << "Et soudain ?!" << endl;
            cout << "(Appuyez sur entree pour continuer)" << endl;
            cin.ignore();
            cin.get();
            cout << "Un boss de niveau " << level + 1 << " apparait !" << endl;
            cout << "Que decidez vous de faire ?" << endl;
            cout << "1 : ATTAQUER" << endl << "2 : FUIR" << endl;
            int k;
            cout << "choix : ";
            cin >> k;
            if (k == 1)
            {
                cout << "Vous gagnez !" << endl;
                cout << "+25 xp !" << endl << "+25 argent ! " << endl;
                xp += 25;
                money +=25;
                if (xp >= 25 && level == 0)
                {
                    cout << "Vous augmentez de niveau !" << endl;
                    level += 1;
                }
                else if (xp >= 100 && level == 1)
                {
                    cout << "Vous augmentez de niveau ! " << endl;
                    level += 1;
                }
                else if (xp >= 500 && level == 2)
                {
                    cout << "Vous augmentez de niveau !" << endl;
                    level += 1;
                    cout << "Niveau maximum atteint." << endl;
                }
            }
            else if (k == 2)
            {
                cout << "Vous fuyez !" << endl;
                cout << "Le boss vous rattrape !" << endl;
                cout << "-10 argent !" << endl;
                money -= 10;
            }
        }
        else if (o == 7)
        {
            cout << "Au revoir !" << endl;
            break;
        }
        else if (o == 6)
        {
            cout << "Votre nombre de connexions est de : " << connex << " connexions." << endl;
        }
        else if (estAdmin && o == 69)
        {
            string banni1;
            string banni2;
            string bannitext = "banni.txt";
            ifstream banni("banni.txt");
            if (banni.is_open())
            {
                cout << "Le fichier a bien ete trouve." << endl;
            }
            banni >> banni1;
            banni >> banni2;
            banni.close();
            while (true)
            {
                int l;
                string pseudoban;
                string chemin = "saves/" + pseudoban + ".txt";
                cout << "Qu'est ce que vous voulez faire ?" << endl;
                cout << "1 : VOIR BANNI 1" << endl << "2 : VOIR BANNI 2" << endl;
                cout << "3 : MODIFIER BANNI 1" << endl << "4 : MODIFIER BANNI 2 " << endl;
                cout << "5 : QUITTER" << endl << "6 : SAUVEGARDER LA DATA" << endl;
                cout << "choix : ";
                cin >> l;
                if (l == 1)
                {
                    cout << "Banni 1 est : " << banni1 << endl;
                }
                else if (l == 2)
                {
                    cout << "Banni 2 est : " << banni2 << endl;
                }
                else if (l == 3)
                {
                    while (true)
                    {
                        cout << "Banni 1 : ";
                        cin >> pseudoban;
                        string chemin = "saves/" + pseudoban + ".txt";
                        if (ifstream save(chemin); save.is_open())
                        {
                            cout << "Ce pseudo existe bien ! " << endl;
                            break;
                        }
                        else
                        {
                            cout << "Ce pseudo est incorrect." << endl;
                        }
                    }
                    while (true)
                    {
                        string banchoix;
                        cout << "Etes vous sur de bannir " << pseudoban << " ?" << endl;
                        cout << "[O/N]" << endl;
                        cout << "choix : ";
                        cin >> banchoix;
                        if (banchoix == "O")
                        {
                            banni1 = pseudoban;
                            vrai = false;
                            cout << "Veuillez comfirmer le ban en appuyant sur 'Sauvegarder la data'." << endl;
                            break;
                        }
                        else if (banchoix == "N")
                        {
                            cout << "Recommencons." << endl;
                        }
                        else
                        {
                            cout << "Mauvaise valeur entree." << endl;
                        }
                    }
                }
                else if (l == 4)
                {
                    while (true)
                    {
                        cout << "Banni 2 : ";
                        cin >> pseudoban;
                        string chemin = "saves/" + pseudoban + ".txt";
                        if (ifstream save(chemin); save.is_open())
                        {
                            cout << "Ce pseudo existe bien ! " << endl;
                            break;
                        }
                        else
                        {
                            cout << "Ce pseudo est incorrect." << endl;
                        }
                    }
                    while (true)
                    {
                        string banchoix;
                        cout << "Etes vous sur de bannir " << pseudoban << " ?" << endl;
                        cout << "[O/N]" << endl;
                        cout << "choix : ";
                        cin >> banchoix;
                        if (banchoix == "O")
                        {
                            banni2 = pseudoban;
                            vrai = false;
                            cout << "Veuillez comfirmer le ban en appuyant sur 'Sauvegarder la data'." << endl;
                            break;
                        }
                        else if (banchoix == "N")
                        {
                            cout << "Recommencons." << endl;
                        }
                        else
                        {
                            cout << "Mauvaise valeur entree." << endl;
                        }
                    }
                }
                else if (l == 5)
                {
                    if (vrai == true)
                    {
                        cout << "Au revoir !" << endl;
                        break;
                    }
                    else if (vrai == false)
                    {
                        cout << "Veuillez sauvegarder la data avant de quitter !" << endl;
                    }
                }
                else if (l == 6)
                {
                    vrai = true;
                    cout << "Sauvegarde de la data..." << endl;
                    ofstream banni("banni.txt");
                    banni << banni1 << endl;
                    banni << banni2;
                    cout << "Data sauvegardee." << endl;
                }
            }
        }
        else if (estAdmin && o == 67)
        {
            int adminconnex;
            string adminmdp;
            int adminxp;
            int adminlevel;
            int adminmonde;
            int adminmoney;
            string adminpseudo;
            while (true)
            {
                while (true)
                {
                    cout << "Quel est le pseudo du joueur que vous voulez consulter ?" << endl;
                    cout << "pseudo : ";
                    cin >> adminpseudo;
                    string chemin = "saves/" + adminpseudo + ".txt";
                    if (adminpseudo == "admin")
                    {
                        cout << "Ce pseudo est le votre !" << endl;
                    }
                    else
                    {
                        break;
                    }
                }
                string chemin = "saves/" + adminpseudo + ".txt";
                if (ifstream save(chemin); save.is_open())
                {
                    cout << "Ce pseudo existe bien" << endl;
                    save >> adminconnex;
                    save >> adminmdp;
                    save >> adminxp;
                    save >> adminlevel;
                    save >> adminmonde;
                    save >> adminmoney;
                    break;
                }
                else if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Mauvaise valeur donnée";
                    continue;
                }
                else
                {
                    cout << "Ce pseudo n'existe pas, veuillez en mettre un autre" << endl;
                }
            }
            while (true)
            {
                cout << "Maintenant qu'est ce que vous voulez faire ?" << endl;
                cout << "1 : CONSULTER SON NOMBRE DE CONNEXIONS" << endl;
                cout << "2 : CONSULTER SON MOT DE PASSE" << endl << "3 : CONSULTER SON XP" << endl;
                cout << "4 : CONSULTER SON LEVEL" << endl << "5 : CONSULTER SON MONDE" << endl;
                cout << "6 : CONSULTER SON ARGENT" << endl << "7 : QUITTER" << endl;
                int adminchoix;
                cout << "choix : ";
                cin >> adminchoix;
                if (adminchoix == 1)
                {
                    cout << "Son nombre de connexions est de : " << adminconnex << " connexions." << endl;
                }
                else if (adminchoix == 2)
                {
                    cout << "Son mot de passe est " << adminmdp << endl;
                }
                else if (adminchoix == 3)
                {
                    cout << "Son xp est de " << adminxp << endl;
                }
                else if (adminchoix == 4)
                {
                    cout << "Son level est de " << adminlevel << endl;
                }
                else if(adminchoix == 5)
                {
                    cout << "Son monde est le monde " << adminmonde << endl;
                }
                else if (adminchoix == 6)
                {
                    cout << "Son argent est de : " << adminmoney << endl;
                }
                else if (adminchoix == 7)
                {
                    cout << "Au revoir ! " << endl;
                    break;
                }
                else if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Mauvaise valeur donnée." << endl;
                    continue;
                }
                else
                {
                    cout << "Mauvais chiffre donné !" << endl;
                }
            }
        }
        else if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Mauvaise valeur donnée.";
            continue;
        }
        else
        {
            cout << "Mauvais chiffre donné !" << endl;
        }
    }
    connex += 1;
    string chemin = "saves/" + pseudo + ".txt";
    ofstream save(chemin);
    cout << "Sauvegarde de la data..." << endl;
    save << connex << endl;
    save << bmdp << endl;
    save << xp << endl;
    save << level << endl;
    save << monde << endl;
    save << money << endl;
    save.close();
    cout << "(Appuyez sur entree pour continuer...)" << endl;
    cin.ignore();
    cin.get();
    return 0;
}