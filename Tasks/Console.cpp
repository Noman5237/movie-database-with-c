#include <iostream>
#include <fstream>
#include <cstdio>


using namespace std;

void input();
void searchtitle();
void searchyear();
void searchleadactor();
void searchleadactress();
void searchdirector();
void searchproducer();
void quit();
void displayall();
void search();
void deleteFile();
void editFile();

int main()
{

    system ("title Movie Database Program");
    system ("cls");
    system ("color 0F");
    int choice;
    cout << "1.Input a new name" << endl;
    cout << "2.Search database for movie" << endl;
    cout << "3.Clear Log" << endl;
    cout << "4.Edit file" << endl;
    cout << "5.Exit Program" << endl;
    cin >> choice;

    switch (choice){
        case 1:
            input();
            break;
        case 2:
            search();
            break;
        case 3:
            deleteFile();
            break;
        case 4:
            editFile();
            break;
        case 5:
            quit();
            break;

            cin.get();


    }
}
void editFile()
{
    string name, input, newName,decision;
    string title, year, actor, actress, director, producer, plot;
    ifstream movie("newmovie.txt");
    if (!movie.eof()){
        movie >> title >> year >> actor >> actress >> director >> producer >> plot;
    }
    system("cls");

    cout << "Enter the name of the movie: ";
    cin >> input;

    if (input == title)
    {

        cout << title << ' '<< year << ' '  << actor << ' ' << actress << ' '<<  director << ' ';
        cout << producer << ' ' << plot << endl;
        cout << "Is this the correct movie?(y/n) : ";
        cin >> decision;
        if (decision == "y"){
            cout << "Enter the new movie : ";
            cin >> newName;
            name = newName;
        }

        movie.close();
    }

    ofstream movie2("newmovie.txt", ios::app);
    movie2 << title << ' '<< year << ' '  << actor << ' ' << actress << ' '<<  director << ' '<< producer << ' ' << plot << endl;
    movie2.close();
    system("pause");
    main();
}

void input()
{
    string name, input, newName,decision;
    string title, year, actor, actress, director, producer, plot;

    int age;
    long int salary;
    ofstream newmovie("newmovie.txt", ios::app);
    ofstream movieSearch ("movieSearch.txt", ios::app);
    system("cls");
    cout << "Enter the new movie's title" << endl;
    getchar();
    getline(cin,title);
    system("cls");
    cout << "Enter the movie's release year." << endl;
    getline(cin, year);
    system("cls");
    cout << "Enter the movie's lead actor" << endl;
    cin >> actor;
    system("cls");
    cout << "Enter the movie's lead actress." << endl;
    cin >> actress;
    system("cls");
    cout << "Enter the movie's director." << endl;
    cin >> director;
    system("cls");
    cout << "Enter the movie's producer." << endl;
    cin >> producer;
    system("cls");
    cout << "Enter the movie's plot." << endl;
    cin >> plot;

    movieSearch << title << " "<< year << " "<< actor << " "<< actress << " " <<
                director << " "<< producer << " " << plot << "\n";

    newmovie << "Title : " <<  title << "\n" <<
             "Year of release : " << year << "\n" <<
             "Lead Actor : "  << actor << "\n" <<
             "Lead Actress : " << actress << "\n" <<
             "Director : "<<  director << "\n" <<
             "Producer : " << producer << "\n" <<
             "Brief Synopsis : " << plot << endl;

    newmovie.close();
    movieSearch.close();
    main();
}
void searchtitle()
{
    ifstream movie("newmovie.txt");
    string title, year, actor, actress, director, producer, plot;
    string str, line;
    system("CLS");
    cout << "Enter the movie's name: ";
    cin >> str;

    while (movie >> title >> year >> actor >> actress >> director >> producer >> plot){
        if (str == title){
            system ("CLS");
            cout << "Movie found" << endl;
            cout << "Movie Title" << ' ' << title << endl;
            cout << "Year" << ' ' << year << endl;
            cout << "Lead Actor" << ' ' << actor << endl;
            cout << "Lead Actress" << ' ' << actress << endl;
            cout << "Director" << ' ' << director << endl;
            cout << "Producer" << ' ' << producer << endl;
            cout << "Brief Synopsis" << ' '<< plot <<  endl;
            cout << "\n ";
        }
    }


    while (movie >> title ){
        if (str != title){
            system ("CLS") ;
            cout << "No movie under that name exists" << endl;

        }
    }
    system ("pause");
    main();


}
void searchyear()
{
    ifstream movie("newmovie.txt");
    string title, year, actor, actress, director, producer, plot;

    string fyear;

    system ("CLS");
    cout << "Enter the year of release of the movie:";
    cin >> fyear;
    while (movie >> title >> year >> actor >> actress >> director >> producer >> plot){
        if (fyear == year){
            system ("CLS");
            cout << "Movie found" << endl;
            cout << "Movie Title" << ' ' << title << endl;
            cout << "Year" << ' ' << year << endl;
            cout << "Lead Actor" << ' ' << actor << endl;
            cout << "Lead Actress" << ' ' << actress << endl;
            cout << "Director" << ' ' << director << endl;
            cout << "Producer" << ' ' << producer << endl;
            cout << "Brief Synopsis" << ' '<< plot <<  endl;
            cout << "\n ";

        }
    }
    while (movie >> year){
        if (fyear != year){
            system ("CLS");
            cout << "No movie found"<< endl;


        }
    }
    system ("pause");
    cin.get();
    main();
}


void searchleadactor()
{
    ifstream movie ("newmovie.txt");
    string title, year, actor, actress, director, producer, plot;

    string f_actor;


    system ("CLS");
    cout << "Enter a lead actor:";
    cin >> f_actor;
    while (movie >> title >> year >> actor >> actress >> director >> producer >> plot){
        if (f_actor == actor){
            system ("CLS");
            cout << "Movie found" << endl;
            cout << "Movie Title" << ' ' << title << endl;
            cout << "Year" << ' ' << year << endl;
            cout << "Lead Actor" << ' ' << actor << endl;
            cout << "Lead Actress" << ' ' << actress << endl;
            cout << "Director" << ' ' << director << endl;
            cout << "Producer" << ' ' << producer << endl;
            cout << "Brief Synopsis" << ' '<< plot <<  endl;
            cout << "\n ";
        }
    }
    while (movie >> actor){
        if (f_actor != actor){
            system ("CLS");
            cout << "No movie found" << endl;
        }
    }
    system("pause");
    cin.get();
    main();
}


void searchleadactress()
{
    ifstream movie ("newmovie.txt");
    string title, year, actor, actress, director, producer, plot;

    string f_actress;


    system ("CLS");
    cout << "Enter a lead actress:";
    cin >> f_actress;
    while (movie >> title >> year >> actor >> actress >> director >> producer >> plot){
        if (f_actress == actress){
            system ("CLS");
            cout << "Movie found" << endl;
            cout << "Movie Title" << ' ' << title << endl;
            cout << "Year" << ' ' << year << endl;
            cout << "Lead Actor" << ' ' << actor << endl;
            cout << "Lead Actress" << ' ' << actress << endl;
            cout << "Director" << ' ' << director << endl;
            cout << "Producer" << ' ' << producer << endl;
            cout << "Brief Synopsis" << ' '<< plot <<  endl;
            cout << "\n ";
        }
    }
    while (movie >> actress){
        if (f_actress != actress){
            system ("CLS");
            cout << "No movie found" << endl;
        }
    }
    system("pause");
    cin.get();
    main();
}

void searchdirector()
{
    ifstream movie ("newmovie.txt");
    string title, year, actor, actress, director, producer, plot;

    string f_director;


    system ("CLS");
    cout << "Enter a director : ";
    cin >> f_director;
    while (movie >> title >> year >> actor >> actress >> director >> producer >> plot){
        if (f_director == director){
            system ("CLS");
            cout << "Movie found" << endl;
            cout << "Movie Title" << ' ' << title << endl;
            cout << "Year" << ' ' << year << endl;
            cout << "Lead Actor" << ' ' << actor << endl;
            cout << "Lead Actress" << ' ' << actress << endl;
            cout << "Director" << ' ' << director << endl;
            cout << "Producer" << ' ' << producer << endl;
            cout << "Brief Synopsis" << ' '<< plot <<  endl;
            cout << "\n ";
        }
    }
    while (movie >> director){
        if (f_director != director){
            system ("CLS");
            cout << "No movie found" << endl;
        }
    }
    system("pause");
    cin.get();
    main();
}


void searchproducer()
{
    ifstream movie ("newmovie.txt");
    string title, year, actor, actress, director, producer, plot;

    string f_producer;


    system ("CLS");
    cout << "Enter a producer : ";
    cin >> f_producer;
    while (movie >> title >> year >> actor >> actress >> director >> producer >> plot){
        if (f_producer == producer){
            system ("CLS");
            cout << "Movie found" << endl;
            cout << "Movie Title" << ' ' << title << endl;
            cout << "Year" << ' ' << year << endl;
            cout << "Lead Actor" << ' ' << actor << endl;
            cout << "Lead Actress" << ' ' << actress << endl;
            cout << "Director" << ' ' << director << endl;
            cout << "Producer" << ' ' << producer << endl;
            cout << "Brief Synopsis" << ' '<< plot <<  endl;
            cout << "\n ";
        }
    }
    while (movie >> producer){
        if (f_producer != producer){
            system ("CLS");
            cout << "No movie found" << endl;
        }
    }
    system("pause");
    cin.get();
    main();
}


void quit()
{
    system ("CLS");
    cout << "Thank you for using the database program" << endl;
    system ("pause");
    cin.get();
}
void displayall()
{
    ifstream movie("newmovie.txt");
    ifstream movieSearch("movieSearch.txt");
    string title, year, actor, actress, director, producer, plot;
    int age;
    long int salary;
    string name;

    while (movieSearch >> title >> year >> actor >> actress >> director >> producer >> plot){
        cout << "Movie Title" << ' ' << title << endl;
        cout << "Year" << ' ' << year << endl;
        cout << "Lead Actor" << ' ' << actor << endl;
        cout << "Lead Actress" << ' ' << actress << endl;
        cout << "Director" << ' ' << director << endl;
        cout << "Producer" << ' ' << producer << endl;
        cout << "Brief Synopsis" << ' '<< plot <<  endl;
        cout << "\n ";
    }
    system ("CLS");
    ofstream movieout("movieSearch.txt");
    while (movieout << title << year << actor << actress << director << producer << plot){
        cout << "Entire movie database"<< endl;
        cout << "Movie Title" << ' ' << title << endl;
        cout << "Year" << ' ' << year << endl;
        cout << "Lead Actor" << ' ' << actor << endl;
        cout << "Lead Actress" << ' ' << actress << endl;
        cout << "Director" << ' ' << director << endl;
        cout << "Producer" << ' ' << producer << endl;
        cout << "Brief Synopsis" << ' '<< plot <<  endl;
        cout << "\n ";
        system ("pause");
    }

    cin.get();
    main();

}
void search()
{
    int age;
    string name;
    long double salary;
    int choice2;
    system ("CLS");

    cout << "1.Search by title" << endl;
    cout << "2.Search by year" << endl;
    cout << "3.Search by lead actor" << endl;
    cout << "4.Search by lead actress" << endl;
    cout << "5.Search by director" << endl;
    cout << "6.Search by producer" << endl;
    cout << "7.Display all movies" << endl;
    cout << "8.Back" << endl;
    cout << "9.Exit program" << endl;
    cin >> choice2;

    switch (choice2){
        case 1:
            searchtitle();
            break;
        case 2:
            searchyear();
            break;
        case 3:
            searchleadactor();
            break;
        case 4:
            searchleadactress();
            break;
        case 5:
            searchdirector();
            break;
        case 6:
            searchproducer();
            break;
        case 7:
            displayall();
            break;
        case 8:
            main();
            break;
        case 9:
            quit();
            break;
    }




}
void deleteFile()
{

    string decision;
    cout << "Are you sure?[Y]es[N]o" << endl;
    cin >> decision;
    if (decision == "y"){
        ofstream movie("newmovie.txt");
        system("cls");
        cout << "Successfully Completed!" << endl;
        system("pause");
        movie.close();
        main();
    }
    else{
        main();
    }
}

