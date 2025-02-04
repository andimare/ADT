#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

class cardDeck {
	private:
		// a Deck of cards is implemented as an array of integers from 0 to 51
		int cards[51];
		int currentCard;
	public:
		//constructor
		cardDeck();
		//shuffle the deck
		void shuffle();
		//return the next card in the deck. HINT:you must establish a current location in the deck
		int getCard(int) const;
		
		/*clubs 0-12 , diamonds 13-25, hearts 26-38 , spades 39-51.In each range , the first card is the ace and the last three cards are jack, queen, king.
		//Write card c as suit, card value */
		void  printCard(int c);
};	

cardDeck :: cardDeck(){
	int i = 0;
	do{
		this->cards[i] = i;
		++i;
	}while(i < 52);
}

void cardDeck :: shuffle(){
	int holder;
	
	for(int i = 0; i < 52; ++i) {
		
		holder = this->cards[0];
		
		srand(time(0));
		int n = rand();
		
		this->cards[0] = this->cards[(n * 100 / (i + 1)) % 52];
		this->cards[(n * 100 / (i + 1)) % 52] = holder;
	}
}

int cardDeck::getCard(int i) const{
	return this->cards[i];
}

void cardDeck::printCard(int c){
	for(int i = 0; i < 52; ++i) {
		cout<<"cards["<<i<<"] : "<<this->cards[i]<<endl;
	}
}

bool checkExistance(int arr[], int val){
	bool exist = false;
	int len = sizeof(arr) / sizeof(arr[0]);
	
	for(int i = 0; i < len; ++i){
		if(arr[i] == val){
			exist = true;
			break;
		}
	}
	
	return exist;
}

void rangedCard(int card, string str){
	int rem = card % 13;
	
	if(rem > 9 || rem == 0){
		if(rem == 0) cout<<card<<" ACE "<<str<<endl;
		else if(rem == 10) cout<<card<<" JACK"<<str<<endl;
		else if(rem == 11) cout<<card<<" Queen"<<str<<endl;
		else if(rem == 12) cout<<card<<" KING"<<str<<endl;
	}
	else 	cout<<card<<" "<<rem<<str<<endl;
}

void dealHd(cardDeck &d, int x) {
	int dealt[x] = {0, 0, 0, 0, 0};
	int dummy;
	int i = 0;
	
	do{
		
		srand(time(0));
		int n = rand();
		
		dummy =  d.getCard((n * 100 / (i + 1)) % 52);
		
		if( !checkExistance(dealt, dummy) ){
			dealt[i] = dummy;
		}else{
			--i;
		}

		++i;
	}while(i < x);
	
	
	cout<<endl<<endl;
	
	// Sorting the dealt card 
	for(int j = 0; j < x; ++j){
		for(int k = j + 1; k < x; k++){
			if(dealt[k] < dealt[j]) {
				int rep = dealt[j];
				dealt[j] = dealt[k];
				dealt[k] = rep;
			}
		}
	}
	
	for(int j = 0; j < x; ++j){
		
		int pos = dealt[j]/13;
		
		if(pos < 2){
			if(pos == 0) rangedCard(dealt[j], " Clubs");
			else rangedCard(dealt[j], " Diamonds");
		}else{
			if(pos == 2) rangedCard(dealt[j], " Hearts");
			else rangedCard(dealt[j], " Spades");
		}
	}
	
}

int main() {
	cardDeck cdr;
	
	cdr.shuffle();
	
	cout<<endl<<endl;
	
	cdr.printCard(4);
	
	dealHd(cdr,5);
	
	return 0;
}
