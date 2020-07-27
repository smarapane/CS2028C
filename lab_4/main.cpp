
#include "Show.h"
#include "TV.h"
#include "Movie.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void dispShowInfo(Show showChoice) {
	showChoice.Details();
	showChoice.Play();
}

int main() {
  
	string showName, showDescrip, showCredits, temp;
	int episodes, seasons;
	char choice;
  static vector< vector< string > > seasonEpisode;	//Choose which and what you want to input of the four catagories
    do {
    	cout << "Type 1 for instance of Show, 2 for Movie, 3 for TV Show, 4 for Movie declared as a Show, 5 for TV Show declared as a Show." << endl;
	    cin >> choice;
      getline(cin, temp);
    	switch (choice) {
    	case '1':
		{
			cout << "Enter name: ";
			getline(cin, showName);
			cout << "Enter description: " ;
			getline(cin, showDescrip);
			Show instance(showName, showDescrip);
			dispShowInfo(instance);
			break;
		}
	    case '2':
		{
			cout << "Enter name: ";
			getline(cin, showName);
      cout << "Enter description: ";
			getline(cin, showDescrip);
      cout << "Enter credits: ";
      getline(cin, showCredits);
            
			Movie instance = Movie(showName, showDescrip, showCredits);
			dispShowInfo(instance);
			break;
		}
	    case '3':
		{
			cout << "Enter name: ";
      getline(cin, showName);
			cout << "Enter description: ";
			getline(cin, showDescrip);
			cout << "Enter episodes: ";
			cin >> episodes;
			cout << "Enter seasons: ";
			cin >> seasons;
      getline(cin, temp);
      for (int i = 0; i < seasons; i++) {
        vector< string > tempVec;
        seasonEpisode.push_back(tempVec);
        for (int j = 0; j < episodes; j++) {
          cout << "Enter name of season " << i + 1 << " episode " << j + 1 << ": ";
          getline(cin, temp);
          seasonEpisode[i].push_back(temp);
        }
      }

		  TV instance = TV(episodes, seasons, seasonEpisode, showName, showDescrip);
      instance.Play();
      dispShowInfo(instance);
			break;
		}
	    case '4':
		{
			cout << "Enter name: ";
			getline(cin, showName);
			cout << "Enter description: ";
			getline(cin, showDescrip);
			cout << "Enter credits: ";
      getline(cin, showCredits);

		  Show instance = Movie(showName, showDescrip, showCredits);
			dispShowInfo(instance);
			break;
		}
	    case '5':
		{
		  cout << "Enter name: ";
			getline(cin, showName);
			cout << "Enter description: ";
      getline(cin,showDescrip);
			cout << "Enter episodes: ";
			cin >> episodes;
			cout << "Enter seasons: ";
			cin >> seasons;
      getline(cin, temp);
      for (int i = 0; i < seasons; i++) {
        vector< string > tempVec;
        seasonEpisode.push_back(tempVec);
        for (int j = 0; j < episodes; j++) {
          cout << "Enter name of season " << i + 1 << " episode " << j + 1 << ": ";
          getline(cin, temp);
          seasonEpisode[i].push_back(temp);
        }
      }
			Show *instance = new TV(episodes, seasons, seasonEpisode, showName, showDescrip);
		  dispShowInfo(*instance);
      instance->Play();
			break;
    }
		default:
    {
			cout<<"Invalid input" << endl;
			break;
		}
  }
    cout << "Do you want to try again? (y/n)" << endl;
    cin >>  choice;
	} while (choice == 'y');
	return 0;
}
