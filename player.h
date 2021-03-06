/* Max Walsh, 7 Wonders
 * This is the interface file for the Player class. This instantiates for each
 * player in the 7 Wonders card game.
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Hand.h"
#include "wonder.h"

using namespace std;

class Player {

	public:
		Player( int = 1, int = 1 );
		int getScore();

		//Coin Stuff
		int getCoins();
		void addCoins( int );
		void removeCoins( int );

		//Cards in hand stuff
		void dealtoHand(int);
		Hand getHand();
		int getHandSize();
		int clearHand();
		void takeHand(Player &nextPlayer);

		//Cards in play Stuff
		void dealPlayed(int cardNum);
		Hand getPlayed();
		void clearPlayed();

		void checkCard(int);
		void addResource(string, int);

		void showWonder();
		void showResources();

	private:
		string name;
		int score;
		int victory;
		int military;
		int coins;
		vector<int> resources;
		int calcScore();
		Wonder wond;
		int playPlayerCard( int ); // moves playerHand card to inPlay

		Hand inPlay;
		Hand playerHand;

};
#endif
