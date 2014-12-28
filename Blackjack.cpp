#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Card Class Declaration

class Card
{
	public:
		int value;
		char suit;
};


int main() 
{
	
	cout<<"Hello. Would you like to play a game of Blackjack? (Y/N): ";
	char ans, play_again, dealer_choice;
	cin>>ans;
	
// First we are going to set up the deck in an array
	
	do {
	Card deck[13][4];
	for (int x=0;x<=12;x++)
	{
		for (int y=0;y<=3;y++)
		{
			deck[x][y].value=x;
			if (y==0)
			{
				deck[x][y].suit='C';
			}
			if (y==1)
			{
				deck[x][y].suit='D';
			}
			if (y==2)
			{
				deck[x][y].suit='H';
			}
			if (y==3)
			{
				deck[x][y].suit='S';
			}
			
		}
	}
	
	// Variable Declaration
	int player_hand_sum=0; // This is the players hand value
	int random_value;
	int random_suit;
	Card drawn_card;
	
	int dealer_hand_sum=0; // This is the players hand value
	int dealer_random_value;
	int dealer_random_suit;
	Card dealer_drawn_card;
	
	if (ans=='N')
	{
		cout<<"Okay. Goodbye";
		return 0;
	}
	
	else
	{
		srand(time(NULL));
		for (int repeat=1;repeat<=2;repeat++)
		{
		
		// If random_value is 100 after the first loop, that means the card has been chosen already.
		do
		{
			random_value=rand()%13;
			random_suit=rand()%4;
			drawn_card.value=deck[random_value][random_suit].value;
			drawn_card.suit=deck[random_value][random_suit].suit;
		} while (drawn_card.value==100);
		
		cout<<"You have drawn a ";
		if (drawn_card.value==0)
		{
			cout<<"Ace of ";
		}
		else if (drawn_card.value==10)
		{
			cout<<"Jack of ";
		}
		else if (drawn_card.value==11)
		{
			cout<<"Queen of ";
		}
		else if (drawn_card.value==12)
		{
			cout<<"King of ";
		}
		else
		{
			cout<<drawn_card.value+1<<" of ";
		}
		
		if (drawn_card.suit=='C')
		{
			cout<<"Clubs."<<endl;
			
		}
		else if (drawn_card.suit=='D')
		{
			cout<<"Diamonds."<<endl;
		}
		else if (drawn_card.suit=='H')
		{
			cout<<"Hearts."<<endl;
		}
		else if (drawn_card.suit=='S')
		{
			cout<<"Spades."<<endl;
		}
		
		player_hand_sum=player_hand_sum+drawn_card.value+1;
		deck[random_value][random_suit].value=100;
		deck[random_value][random_suit].suit='X';
		}
		cout<<"Your hand is worth "<<player_hand_sum<<" points. "<<endl;
		char user_decision;
		
		// Now we must deal two cards to the dealer but the player cannot know what the 2 cards are.
		// These two cards must be eliminated from the deck once drawn. 
	
		for (int dealer_repeat=1;dealer_repeat<=2;dealer_repeat++)
			{
				
			// If random_value is 100 after the first loop, that means the card has been chosen already.
			do
			{
				dealer_random_value=rand()%13;
				dealer_random_suit=rand()%4;
				dealer_drawn_card.value=deck[dealer_random_value][dealer_random_suit].value;
				dealer_drawn_card.suit=deck[dealer_random_value][dealer_random_suit].suit;
			} while (dealer_drawn_card.value==100);
				
				dealer_hand_sum=dealer_hand_sum+dealer_drawn_card.value+1;
				deck[dealer_random_value][dealer_random_suit].value=100;
				deck[dealer_random_value][dealer_random_suit].suit='X';
				}
				
				cout<<"The dealer's hand after drawing two cards is worth "<<dealer_hand_sum<<"."<<endl;

	}
	
	/* Now we must have conditions to see if the game goes on. If the game ends after the inital cards are dealt, then a blackjack occurs*/
	
	if (player_hand_sum==21 && dealer_hand_sum<21)
	{
		cout<<"Congratulations you have a blackjack. You win!. Would you like to play again?";
		cin>>play_again;
	}
	
	if (player_hand_sum<21 && dealer_hand_sum==21)
	{
		cout<<"The dealer has a blackjack. You lose! Would you like to play again?";
		cin>>play_again;
	}
	
	if (player_hand_sum==21 && dealer_hand_sum==21)
	{
		cout<<"There is a Draw! Would you like to play again?";
		cin>>play_again;
	}
	
	
	char stand_or_hit;
	if (player_hand_sum<21 && dealer_hand_sum<21)
	{
		
		while (player_hand_sum<21 && dealer_hand_sum<21)
		{
			
			cout<<"Would you like to stand or hit? (S/H): ";
			cin>>stand_or_hit;
			if (stand_or_hit=='H')
			{
				do
					{
						random_value=rand()%13;
						random_suit=rand()%4;
						drawn_card.value=deck[random_value][random_suit].value;
						drawn_card.suit=deck[random_value][random_suit].suit;
					} while (drawn_card.value==100);
						
						
						cout<<"You have drawn a ";
						if (drawn_card.value==0)
						{
							cout<<"Ace of ";
						}
						else if (drawn_card.value==10)
						{
							cout<<"Jack of ";
						}
						else if (drawn_card.value==11)
						{
							cout<<"Queen of ";
						}
						else if (drawn_card.value==12)
						{
							cout<<"King of ";
						}
						else
						{
							cout<<drawn_card.value+1<<" of ";
						}
						
						if (drawn_card.suit=='C')
						{
							cout<<"Clubs."<<endl;
							
						}
						else if (drawn_card.suit=='D')
						{
							cout<<"Diamonds."<<endl;
						}
						else if (drawn_card.suit=='H')
						{
							cout<<"Hearts."<<endl;
						}
						else if (drawn_card.suit=='S')
						{
							cout<<"Spades."<<endl;
						}
						
						player_hand_sum=player_hand_sum+drawn_card.value+1;
						deck[random_value][random_suit].value=100;
						deck[random_value][random_suit].suit='X';
						
						cout<<"Your hand is worth "<<player_hand_sum<<" points. "<<endl;
						
						
				if (player_hand_sum>21) 
				{
					cout<<"You went over the 21 point limit. You lose!"<<endl<<"Would you like to play again? (Y/N): ";
					cin>>play_again;
				}

				
			}
			
			else if (stand_or_hit=='S')
			{
			}
			
			else 
			{
				cout<<"This is not a valid character. Enter S to stand or H to hit."<<endl;
			}
			
			int save_dealer_hand_sum=dealer_hand_sum;
			
			if (player_hand_sum<21)
			{if (dealer_hand_sum<=17)
					{
						dealer_choice='H';
						cout<<"The dealer hits. "<<endl;
							do
					{
										dealer_random_value=rand()%13;
										dealer_random_suit=rand()%4;
					dealer_drawn_card.value=deck[dealer_random_value][dealer_random_suit].value;
					dealer_drawn_card.suit=deck[dealer_random_value][dealer_random_suit].suit;
									} while (dealer_drawn_card.value==100);
										
										dealer_hand_sum=dealer_hand_sum+dealer_drawn_card.value+1;
										deck[dealer_random_value][dealer_random_suit].value=100;
										deck[dealer_random_value][dealer_random_suit].suit='X';
										
				cout<<"The dealer's hand after drawing is worth "<<dealer_hand_sum<<" points."<<endl;
										}
					
					
					if (save_dealer_hand_sum>17 && save_dealer_hand_sum<20)
					{
						int random_number=rand()%10;
						if (random_number<7)
						{
							dealer_choice='S';
							
	cout<<"The dealer stays. "<<"The dealer's hand is now worth "<<save_dealer_hand_sum<<" points."<<endl;
							
						}
						
						if (random_number>=7)
						{
							dealer_choice='H';
							cout<<"The dealer hits. "<<endl;
						do{
																	dealer_random_value=rand()%13;
					dealer_random_suit=rand()%4;
					dealer_drawn_card.value=deck[dealer_random_value][dealer_random_suit].value;
					dealer_drawn_card.suit=deck[dealer_random_value][dealer_random_suit].suit;
																} while (dealer_drawn_card.value==100);
																	dealer_hand_sum=dealer_hand_sum+dealer_drawn_card.value+1;
					deck[dealer_random_value][dealer_random_suit].value=100;
					deck[dealer_random_value][dealer_random_suit].suit='X';
																	
					cout<<"The dealer's hand after drawing is worth "<<dealer_hand_sum<<" points."<<endl;
																	
						}
					}
					
					if (save_dealer_hand_sum==20)
					{
						dealer_choice='S';
						cout<<"The dealer stays. "<<"The dealer's hand is now worth "<<save_dealer_hand_sum<<" points."<<endl;
					}}
					
					if (dealer_hand_sum>21)
					{
						cout<<"The dealer went over the 21 point limit. You win!"<<endl<<"Would you like to play again? (Y/N): ";
						cin>>play_again;
					}
				
					if (player_hand_sum==21 && dealer_hand_sum<21)
					{
						cout<<"You win! Would you like to play again? (Y/N): ";
						cin>>play_again;
					}
					
					if (player_hand_sum<21 && dealer_hand_sum==21)
					{
						cout<<"You lose! Would you like to play again? (Y/N): ";
						cin>>play_again;
					}
				
					if (player_hand_sum==21 && dealer_hand_sum==21)
					{
						cout<<"Push! There is a draw. Would you like to play again? (Y/N): "<<endl;
						cin>>play_again;
					}
					
					if (dealer_choice=='S' && stand_or_hit=='S' && player_hand_sum<21 && dealer_hand_sum<21)
					{
						if (player_hand_sum>dealer_hand_sum)
						{
							cout<<"Your hand is better. You win! Would you like to play again? (Y/N): "<<endl;
							cin>>play_again;
						}
						
						if (player_hand_sum==dealer_hand_sum)
						{
							cout<<"Push! There is a draw;. Would you like to play again? (Y/N): "<<endl;
							cin>>play_again;
						}
						
						else
						{
							cout<<"The dealer's hand is better. You lose! Would you like to play again? (Y/N): "<<endl;
							cin>>play_again;	
						}
					}

			}
			
					
		}
	
	
	} while (play_again=='Y');
	
	
}


