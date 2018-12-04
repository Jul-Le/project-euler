#include <iostream>
#include <fstream>
#include <string>

#define	FOR_PLAYERS	for (int p = 0; p < 2; p++)
#define FOR_CARDS	for (int c = 0; c < 5; c++)

#define PL1			0
#define PL2			1

int handsTotal[10]{ 0 };

enum hand
{
	HIGH_CARD,
	PAIR,
	TWO_PAIR,
	SET,
	STRAIGHT,
	FLUSH,
	FULL_HOUSE,
	QUADS,
	STRAIGHT_FLUSH,
	ROYAL_FLUSH
};

enum rank
{
	T = 10,
	J, Q, K, A
};

enum suit
{
	C, D, S, H
};

// Cards have rank and suit
struct cards
{
	int rank;
	int suit;
};

// Players have 5 cards and hand strength
struct players
{
	cards card[5];
	int handStrength; // enum hand
};

players player[2];
std::string line[1000]; // Each line has two hands

void readFile()
{
	std::ifstream pokerFile("poker.txt");

	for (int i = 0; i < 1000; i++)
	{
		getline(pokerFile, line[i], '\n');
		// "8C TS KC 9H 4S 7D 2S 5D 3S AC"
	}

	pokerFile.close();
}

bool pair(int p) 
{
	int i[15]{ 0 };

	FOR_CARDS
	{
		switch (player[p].card[c].rank)
		{
		case 2: i[2]++; break;
		case 3: i[3]++; break;
		case 4: i[4]++; break;
		case 5: i[5]++; break;
		case 6: i[6]++; break;
		case 7: i[7]++; break;
		case 8: i[8]++; break;
		case 9: i[9]++; break;
		case T: i[T]++; break;
		case J: i[J]++; break;
		case Q: i[Q]++; break;
		case K: i[K]++; break;
		case A: i[A]++; break;
		}
	}
	for (int c = 2; c <= A; c++)
	{
		// If two cards are the same
		if (i[c] == 2)
		{
			return true;
		}
	}
	return false;
}
bool twoPair(int p)
{
	int i[15]{ 0 };

	FOR_CARDS
	{
		switch (player[p].card[c].rank)
		{
		case 2: i[2]++; break;
		case 3: i[3]++; break;
		case 4: i[4]++; break;
		case 5: i[5]++; break;
		case 6: i[6]++; break;
		case 7: i[7]++; break;
		case 8: i[8]++; break;
		case 9: i[9]++; break;
		case T: i[T]++; break;
		case J: i[J]++; break;
		case Q: i[Q]++; break;
		case K: i[K]++; break;
		case A: i[A]++; break;
		}
	}
	for (int c = 2; c <= A; c++)
	{
		// If two cards are the same
		if (i[c] == 2)
		{
			for (int d = 2; d <= A; d++)
			{
				// If remaining cards make a pair
				if (i[d] == 2 && c != d)
				{
					return true;
				}
			}
		}
	}
	return false;
}
bool set(int p)
{
	int i[15]{ 0 };

	FOR_CARDS
	{
		switch (player[p].card[c].rank)
		{
		case 2: i[2]++; break;
		case 3: i[3]++; break;
		case 4: i[4]++; break;
		case 5: i[5]++; break;
		case 6: i[6]++; break;
		case 7: i[7]++; break;
		case 8: i[8]++; break;
		case 9: i[9]++; break;
		case T: i[T]++; break;
		case J: i[J]++; break;
		case Q: i[Q]++; break;
		case K: i[K]++; break;
		case A: i[A]++; break;
		}
	}
	for (int c = 2; c <= A; c++)
	{
		// If three cards are the same
		if (i[c] == 3)
		{
			return true;
		}
	}
	return false;
}
bool straight(int p)
{
	bool b[15]{ false };

	FOR_CARDS
	{
		switch (player[p].card[c].rank)
		{
		case 2: b[2] = true; break;
		case 3: b[3] = true; break;
		case 4: b[4] = true; break;
		case 5: b[5] = true; break;
		case 6: b[6] = true; break;
		case 7: b[7] = true; break;
		case 8: b[8] = true; break;
		case 9: b[9] = true; break;
		case T: b[T] = true; break;
		case J: b[J] = true; break;
		case Q: b[Q] = true; break;
		case K: b[K] = true; break;
		case A: b[1] = true;
			    b[A] = true; break;
		}
	}
	for (int c = 1; (c + 4) <= A; c++)
	{
		// If 5 consecutive ranks
		if (b[c] && b[c + 1] && b[c + 2] && b[c + 3] && b[c + 4])
		{
			return true;
		}
	}
	return false;
}
bool flush(int p)
{
	// If all same suit
	if (player[p].card[0].suit == player[p].card[1].suit &&
        player[p].card[0].suit == player[p].card[2].suit &&
        player[p].card[0].suit == player[p].card[3].suit &&
        player[p].card[0].suit == player[p].card[4].suit)
	{
		return true;
	}
	return false;
}
bool fullHouse(int p)
{
	int i[15]{ 0 };

	FOR_CARDS
	{
		switch (player[p].card[c].rank)
		{
		case 2: i[2]++; break;
		case 3: i[3]++; break;
		case 4: i[4]++; break;
		case 5: i[5]++; break;
		case 6: i[6]++; break;
		case 7: i[7]++; break;
		case 8: i[8]++; break;
		case 9: i[9]++; break;
		case T: i[T]++; break;
		case J: i[J]++; break;
		case Q: i[Q]++; break;
		case K: i[K]++; break;
		case A: i[A]++; break;
		}
	}
	for (int c = 2; c <= A; c++)
	{
		// If three cards are the same
		if (i[c] == 3)
		{
			for (int d = 2; d <= A; d++)
			{
				// If remaining cards make a pair
				if (i[d] == 2)
				{
					return true;
				}
			}
		}
	}
	return false;
}
bool quads(int p)
{
	int i[15]{ 0 };

	FOR_CARDS
	{
		switch (player[p].card[c].rank)
		{
		case 2: i[2]++; break;
		case 3: i[3]++; break;
		case 4: i[4]++; break;
		case 5: i[5]++; break;
		case 6: i[6]++; break;
		case 7: i[7]++; break;
		case 8: i[8]++; break;
		case 9: i[9]++; break;
		case T: i[T]++; break;
		case J: i[J]++; break;
		case Q: i[Q]++; break;
		case K: i[K]++; break;
		case A: i[A]++; break;
		}
	}
	for (int c = 2; c <= A; c++)
	{
		// If four cards are the same
		if (i[c] == 4)
		{
			return true;
		}
	}
	return false;
}
bool straightFlush(int p)
{
	bool b[15]{ false };

	FOR_CARDS
	{
		switch (player[p].card[c].rank)
		{
		case A: b[1] = true; break; // Impossible to have Royal Flush, so ace = 1
		case 2: b[2] = true; break;
		case 3: b[3] = true; break;
		case 4: b[4] = true; break;
		case 5: b[5] = true; break;
		case 6: b[6] = true; break;
		case 7: b[7] = true; break;
		case 8: b[8] = true; break;
		case 9: b[9] = true; break;
		case T: b[T] = true; break;
		case J: b[J] = true; break;
		case Q: b[Q] = true; break;
		case K: b[K] = true; break;
		}
	}
	for(int c = 1; (c + 4) <= K; c++)
	{
		// If 5 consecutive ranks
		if (b[c] && b[c + 1] && b[c + 2] && b[c + 3] && b[c + 4])
		{
			// If all same suit
			if (player[p].card[0].suit == player[p].card[1].suit && player[p].card[0].suit == player[p].card[2].suit && player[p].card[0].suit == player[p].card[3].suit && player[p].card[0].suit == player[p].card[4].suit)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	return false;
}
bool royalFlush(int p)
{
	bool t = false;
	bool j = false;
	bool q = false;
	bool k = false;
	bool a = false;

	FOR_CARDS
	{
		switch (player[p].card[c].rank)
		{
		case T: t = true; break;
		case J: j = true; break;
		case Q: q = true; break;
		case K: k = true; break;
		case A: a = true; break;
		default: return false;
		}
	}
	// If TJQKA
	if (t && j && q && k && a)
	{
		// If all same suit
		if (player[p].card[0].suit == player[p].card[1].suit &&
            player[p].card[0].suit == player[p].card[2].suit &&
            player[p].card[0].suit == player[p].card[3].suit &&
            player[p].card[0].suit == player[p].card[4].suit)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

bool pl1HasBetterPair(int* highestRank, int* secondRank, int* thirdRank, int* fourthRank, int* lowestRank)
{
	int i[2][15]{ 0 };

	FOR_PLAYERS
	{
		FOR_CARDS
		{
			switch (player[p].card[c].rank)
			{
			case 2: i[p][2]++; break;
			case 3: i[p][3]++; break;
			case 4: i[p][4]++; break;
			case 5: i[p][5]++; break;
			case 6: i[p][6]++; break;
			case 7: i[p][7]++; break;
			case 8: i[p][8]++; break;
			case 9: i[p][9]++; break;
			case T: i[p][T]++; break;
			case J: i[p][J]++; break;
			case Q: i[p][Q]++; break;
			case K: i[p][K]++; break;
			case A: i[p][A]++; break;
			}
		}
	}
	int pairRank[2]{ 0 };

	FOR_PLAYERS
	{
		for (int c = 2; c <= A; c++)
		{
			// If two cards are the same
			if (i[p][c] == 2)
			{
				pairRank[p] = c;
				break;
			}
		}
	}
	if (pairRank[PL1] > pairRank[PL2])
	{
		return true;
	}
	else if (pairRank[PL1] < pairRank[PL2])
	{
		return false;
	}
	// Same pair, compare all cards
	if (highestRank[PL1] > highestRank[PL2])
	{
		return true;
	}
	else if (highestRank[PL1] < highestRank[PL2])
	{
		return false;
	}
	else if (secondRank[PL1] > secondRank[PL2])
	{
		return true;
	}
	else if (secondRank[PL1] < secondRank[PL2])
	{
		return false;
	}
	else if (thirdRank[PL1] > thirdRank[PL2])
	{
		return true;
	}
	else if (thirdRank[PL1] < thirdRank[PL2])
	{
		return false;
	}
	else if (fourthRank[PL1] > fourthRank[PL2])
	{
		return true;
	}
	else if (fourthRank[PL1] < fourthRank[PL2])
	{
		return false;
	}
	else if (lowestRank[PL1] > lowestRank[PL2])
	{
		return true;
	}
	return false;

}

void getHandStrength()
{
	FOR_PLAYERS
	{
		if (royalFlush(p))
			player[p].handStrength = ROYAL_FLUSH;
		else if (straightFlush(p))
			player[p].handStrength = STRAIGHT_FLUSH;
		else if (quads(p))
			player[p].handStrength = QUADS;
		else if (fullHouse(p))
			player[p].handStrength = FULL_HOUSE;
		else if (flush(p))
			player[p].handStrength = FLUSH;
		else if (straight(p))
			player[p].handStrength = STRAIGHT;
		else if (set(p))
			player[p].handStrength = SET;
		else if (twoPair(p))
			player[p].handStrength = TWO_PAIR;
		else if (pair(p))
			player[p].handStrength = PAIR;
		else
			player[p].handStrength = HIGH_CARD;

		handsTotal[player[p].handStrength]++;
	}

}

bool win()
{
	// For both players p;
	FOR_PLAYERS
	{
		// For all five cards c;
		FOR_CARDS
		{
			switch (player[p].card[c].rank)
			{
			case '2': player[p].card[c].rank = 2; break;
			case '3': player[p].card[c].rank = 3; break;
			case '4': player[p].card[c].rank = 4; break;
			case '5': player[p].card[c].rank = 5; break;
			case '6': player[p].card[c].rank = 6; break;
			case '7': player[p].card[c].rank = 7; break;
			case '8': player[p].card[c].rank = 8; break;
			case '9': player[p].card[c].rank = 9; break;
			case 'T': player[p].card[c].rank = T; break;
			case 'J': player[p].card[c].rank = J; break;
			case 'Q': player[p].card[c].rank = Q; break;
			case 'K': player[p].card[c].rank = K; break;
			case 'A': player[p].card[c].rank = A; break;
			}
			switch (player[p].card[c].suit)
			{
			case 'C': player[p].card[c].suit = C; break;
			case 'D': player[p].card[c].suit = D; break;
			case 'S': player[p].card[c].suit = S; break;
			case 'H': player[p].card[c].suit = H; break;
			}
		}
	}

	getHandStrength();

	if (player[PL1].handStrength > player[PL2].handStrength)
	{
		return true;
	}
	else if (player[PL1].handStrength < player[PL2].handStrength)
	{
		return false;
	}
	// Get high card
	int highestRank[2]{ 0 };
	int secondRank[2]{ 0 };
	int thirdRank[2]{ 0 };
	int fourthRank[2]{ 0 };
	int lowestRank[2]{ 0 };
	FOR_PLAYERS
	{
		FOR_CARDS
		{
			if (player[p].card[c].rank > highestRank[p])
			{
				lowestRank[p] = fourthRank[p];
				fourthRank[p] = thirdRank[p];
				thirdRank[p] = secondRank[p];
				secondRank[p] = highestRank[p];
				highestRank[p] = player[p].card[c].rank;
			}
			else if (player[p].card[c].rank > secondRank[p])
			{
				lowestRank[p] = fourthRank[p];
				fourthRank[p] = thirdRank[p];
				thirdRank[p] = secondRank[p];
				secondRank[p] = player[p].card[c].rank;
			}
			else if (player[p].card[c].rank > thirdRank[p])
			{
				lowestRank[p] = fourthRank[p];
				fourthRank[p] = thirdRank[p];
				thirdRank[p] = player[p].card[c].rank;
			}
			else if (player[p].card[c].rank > fourthRank[p])
			{
				lowestRank[p] = fourthRank[p];
				fourthRank[p] = player[p].card[c].rank;
			}
			else if (player[p].card[c].rank > lowestRank[p])
			{
				lowestRank[p] = player[p].card[c].rank;
			}
		}
	}

	switch (player[PL1].handStrength)
	{
	case STRAIGHT_FLUSH:
	case STRAIGHT:
	case QUADS:
		if (secondRank[PL1] > secondRank[PL2])
		{
			return true;
		}
		return false;
	case FULL_HOUSE:
	case SET:
		if (thirdRank[PL1] > thirdRank[PL2])
		{
			return true;
		}
		return false;
	case FLUSH:
	case HIGH_CARD:
		if (highestRank[PL1] > highestRank[PL2])
			return true;
		else if (highestRank[PL1] < highestRank[PL2])
			return false;
		else if (secondRank[PL1] > secondRank[PL2])
			return true;
		else if (secondRank[PL1] < secondRank[PL2])
			return false;
		else if (thirdRank[PL1] > thirdRank[PL2])
			return true;
		else if (thirdRank[PL1] < thirdRank[PL2])
			return false;
		else if (fourthRank[PL1] > fourthRank[PL2])
			return true;
		else if (fourthRank[PL1] < fourthRank[PL2])
			return false;
		else if (lowestRank[PL1] > lowestRank[PL2])
			return true;
		return false;
	case TWO_PAIR: // 88664 88766 98866
		if (secondRank[PL1] > secondRank[PL2])
			return true;
		else if (secondRank[PL1] < secondRank[PL2])
			return false;
		else if (fourthRank[PL1] > fourthRank[PL2])
			return true;
		else if (fourthRank[PL1] < fourthRank[PL2])
			return false;
		else if (highestRank[PL1] > highestRank[PL2] || thirdRank[PL1] > thirdRank[PL2] || lowestRank[PL1] > lowestRank[PL2])
			return true;
		return false;
	case PAIR: // 55432 65543 76554 87655
		return pl1HasBetterPair(highestRank, secondRank, thirdRank, fourthRank, lowestRank);
	}
	return 0;
}

void printHands()
{
	std::cout << "Royal Flush:\t"		<< handsTotal[ROYAL_FLUSH]		<< std::endl;
	std::cout << "Straight Flush:\t"	<< handsTotal[STRAIGHT_FLUSH]	<< std::endl;
	std::cout << "Quads:\t\t"			<< handsTotal[QUADS]			<< std::endl;
	std::cout << "Full house:\t"		<< handsTotal[FULL_HOUSE]		<< std::endl;
	std::cout << "Flush:\t\t"			<< handsTotal[FLUSH]			<< std::endl;
	std::cout << "Straight\t"			<< handsTotal[STRAIGHT]			<< std::endl;
	std::cout << "Set:\t\t"				<< handsTotal[SET]				<< std::endl;
	std::cout << "Two pair:\t"			<< handsTotal[TWO_PAIR]			<< std::endl;
	std::cout << "One pair:\t"			<< handsTotal[PAIR]				<< std::endl;
	std::cout << "High card:\t"			<< handsTotal[HIGH_CARD]		<< std::endl;
}

int main()
{
	// Read "poker.txt"
	readFile();

	int handsWon = 0;

	for (int handNumber = 0; handNumber < 1000; handNumber++)
	{
		for (int i = 0; i < 10; i++)
		{
			// Get hands for players
			player[i / 5].card[i % 5].rank = line[handNumber].at(i * 3);
			player[i / 5].card[i % 5].suit = line[handNumber].at(i * 3 + 1);
		}
		if (win())
		{
			handsWon++;
		}
	}
	std::cout << handsWon << std::endl;

	// Just for fun
	printHands();

	return 0;
}
