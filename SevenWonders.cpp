#include <string>
#include <ctime>	// time
#include <cstdlib>	// srand and ran
#include <vector>
#include "SevenWonders.h"
#include "player.h"
#include "Deck.h"

SevenWonders::SevenWonders( int np ){

	Age = 0;
	PlayerTurn = 1;
	numPlayers = np;
	
	vector<Deck> AgeDeck;

	Deck newDeck(numPlayers);
	cout << "displaying cards" << endl;
        newDeck.displayCard();

	newDeck.shuffle();
	AgeDeck.push_back(newDeck);
	newDeck.shuffle();
	AgeDeck.push_back(newDeck);
	newDeck.shuffle();
	AgeDeck.push_back(newDeck);
	
	cout << "display specific age" << AgeDeck[0].getSize() << endl;
	AgeDeck[0].displayCard();
	cout << "dones" << endl;

	//Deck AgeDeck(7*numPlayers);
	//DeckPtr->init(Age, numPlayers);

}

void SevenWonders::newGame(){
	srand( time(0) );
	string name;
      	int w;
	Age = 0;
	PlayerTurn = 1;
	vector<int> wonders(7, 0);

// player 1
	w = rand() % 6;
	wonders[w] = 1;
	cout << "Player one please enter your name: ";
  	cin >> name;
	Player playerone( name, 1, w+1 );
        players.push_back( playerone );
// player 2
	while ( wonders[w] ) w = rand() % 6;
	cout << "Player two please enter your name: ";
	cin >> name;
	Player playertwo( name, 2, w+1 );
	players.push_back( playertwo );

// player 3
	while ( wonders[w] ) w = rand() % 6;
	cout << "Player three please enter your name: ";
	cin >> name;
	Player playerthree( name, 3, w+1 );
	players.push_back( playerthree );

// player 4
	if ( numPlayers >= 4 ) {
	  while ( wonders[w] ) w = rand() % 6;
	  cout << "Player four please enter your name: ";
	  cin >> name;
	  Player playerfour( name, 4, w+1 );
	  players.push_back( playerfour );
	}

// player 5
	if ( numPlayers >= 5 ) {
	  while ( wonders[w] ) w = rand() % 6;
	  cout << "Player five please enter your name: ";
	  cin >> name;
	  Player playerfive( name, 5, w+1 );
	  players.push_back( playerfive );
	}

// player 6
	if ( numPlayers >= 6 ) {
	  while ( wonders[w] ) w = rand() % 6;
	  cout << "Player six please enter your name: ";
	  cin >> name;
	  Player playersix( name, 6, w+1 );
	  players.push_back( playersix );
	}

// player 7
	if ( numPlayers == 7 ) {
	  while ( wonders[w] ) w = rand() % 6;
	  cout << "Player seven please enter your name: ";
	  cin >> name;
	  Player playerseven( name, 7, w+1 );
	  players.push_back( playerseven );
	}

	//delete DeckPtr;
	//DeckPtr = new Deck;

	//DeckPtr->init(Age, numPlayers);
	cout << "exit constructor" <<endl;
}

bool SevenWonders::nextPlayer(){
	PlayerTurn++;
	return (PlayerTurn>numPlayers);
}

void SevenWonders::setNumPlayers(int newNum){
	numPlayers = newNum;
}

int SevenWonders::getPlayerTurn(){
	return PlayerTurn;
}

int SevenWonders::getAge(){
	return Age;
}

//void SevenWonders::resolveTurn(){

//}

bool SevenWonders::advanceAge(){
	PlayerTurn = 1;
	Age++;
	cout << "age:" << Age << endl;
	if (Age>0 && Age<=3){
		for (int i=0; i<numPlayers; i++) {
			AgeDeck[Age-1].displayCard();
			players[i].dealtoHand(AgeDeck[Age-1].dealCard() );
		}
	}

	return (Age>3);

}


Hand SevenWonders::getPlayerHand(int i){

	//return players[i-1].getHand();

}


Hand SevenWonders::getPlayerPlayed(int i){

	//return players[i-1].getPlayed();

}


void SevenWonders::playCard(int cardNum){

	//players[PlayerTurn-1].dealPlayed(cardNum);

}
