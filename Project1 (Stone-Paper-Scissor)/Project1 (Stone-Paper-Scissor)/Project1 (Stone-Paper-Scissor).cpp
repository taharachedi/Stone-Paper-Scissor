#include <iostream>
#include <cstdlib>

using namespace std;


enum enGameChoice{Stone = 1, Paper = 2, Scissor = 3}; 
enum enWinner{Player = 1, Computer = 2,Draw = 3}; 


struct stRound_Info {
	short Round_Number = 0;
	enGameChoice Player_Choice;
	enGameChoice Computer_Choice;
	enWinner Round_Winner;
	string Round_Winner_Name = "";
};


struct stGame_Result {
	short Game_Rounds = 0;
	short Player_WinTimes = 0;
	short Computer_WinTimes = 0;
	short DrawTimes = 0;
	enWinner Game_Winner;
	string Game_Winner_Name = "";
};



short HowManyRounds() {

	short Rounds = 1;

	do
	{
		cout << "How Many Rounds ? (1 => 100) \n";
		cin >> Rounds; 

	} while (Rounds < 1 || Rounds > 100); 

	return Rounds; 
} 



short Random_Number(short From, short To) {
	return rand() % (To - From + 1) + From;
}


enGameChoice Get_ComputerChoice() {
	return (enGameChoice)Random_Number(1, 3);
}


enGameChoice Read_PlayerChoice() {

	short Choice = 1;

	do
	{
		cout << "\nUr Choice : [1]:Stone , [2]:Paper , [3]:Scissor  ? \n";
		cin >> Choice;

	} while (Choice < 1 || Choice > 3);

	return (enGameChoice)Choice;
}



string Choice_Name(enGameChoice Choice) {
	string arr_Choice_Name[3] = { "Stone","Paper","Scissor" };

	return arr_Choice_Name[Choice - 1];
}


string Winner_Name(enWinner Winner) {
	string arr_WinnerName[3] = { "Player","Computer","No Winner" };

	return arr_WinnerName[Winner - 1];
} 



enWinner Get_RoundWinner(stRound_Info Round) {

	if (Round.Player_Choice == Round.Computer_Choice)    
		return enWinner::Draw;

	switch (Round.Player_Choice) 
	{  
	case enGameChoice::Stone:
		if (Round.Computer_Choice == enGameChoice::Paper) 
		{
			return enWinner::Computer;
		}
		break;

	case enGameChoice::Paper:
		if (Round.Computer_Choice == enGameChoice::Scissor) 
		{
			return enWinner::Computer;
		}
		break;

	case enGameChoice::Scissor: 
		if (Round.Computer_Choice == enGameChoice::Stone)  
		{
			return enWinner::Computer;
		}
		break;
	}

	return enWinner::Player;
}





enWinner Get_GameWinner(short PlayerWinTimes, short ComputerWinTimes) {

	if (PlayerWinTimes > ComputerWinTimes)
		return enWinner::Player;
	else if (ComputerWinTimes > PlayerWinTimes)
		return enWinner::Computer;
	else
		return enWinner::Draw;
}


 
stGame_Result Fill_GameResult(short Game_Rounds, short Player_WinTimes, short Computer_WinTimes, short DrawTimes) {  

	stGame_Result Game;

	Game.Game_Rounds = Game_Rounds;
	Game.Player_WinTimes = Player_WinTimes;
	Game.Computer_WinTimes = Computer_WinTimes;
	Game.DrawTimes = DrawTimes;

	Game.Game_Winner = Get_GameWinner(Player_WinTimes, Computer_WinTimes);
	Game.Game_Winner_Name = Winner_Name(Game.Game_Winner);

	return Game;
}



void set_Winner_ScreenColor(enWinner Winner) {

	switch (Winner)
	{
	case enWinner::Player:
		system("color 2F");
		break;

	case enWinner::Computer:
		system("color 4F");
		cout << "\a";
		break;

	default:
		system("color 6F");
		break;
	}
}




string Tabs(short NumberOfTabs) {

	string t = "";

	for (int i = 1; i < NumberOfTabs; i++)
	{
		t += "\t";
	}
	return t;
}



void Show_GameOverScreen() {

	cout << Tabs(2) << "___________________________________________________________\n\n";
	cout << Tabs(2) << "                     ++ Game Over ++                       \n\n";
	cout << Tabs(2) << "___________________________________________________________\n\n";
}



void Show_FinalGameResult(stGame_Result Game_Result) {

	cout << Tabs(2) << "_______________________[Game Result]_______________________\n\n";
	cout << Tabs(2) << "Game Rounds        : " << Game_Result.Game_Rounds << endl;
	cout << Tabs(2) << "Player Won Times   : " << Game_Result.Player_WinTimes << endl;
	cout << Tabs(2) << "Computer Won Times : " << Game_Result.Computer_WinTimes << endl;
	cout << Tabs(2) << "Draw Times         : " << Game_Result.DrawTimes << endl;
	cout << Tabs(2) << "Final Winner       : " << Game_Result.Game_Winner_Name << endl;

	cout << Tabs(2) << "___________________________________________________________\n\n";

	set_Winner_ScreenColor(Game_Result.Game_Winner);
}




void Show_RoundsResult(stRound_Info Round) {

	cout << "__________________ Round [" << Round.Round_Number << "] __________________\n\n";
	cout << "Player Choice    : " << Choice_Name(Round.Player_Choice) << endl;
	cout << "Computer Choice  : " << Choice_Name(Round.Computer_Choice) << endl;
	cout << "Round Winner     : [ " << Round.Round_Winner_Name << " ]" << endl; 
	cout << "_______________________________________________________________________________\n\n";

	set_Winner_ScreenColor(Round.Round_Winner);
}




stGame_Result Play_Game(short HowManyRounds) { 

	stRound_Info Round;

	short PlayerWinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

	for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++)
	{
		cout << "\nRound [" << GameRound << "] begins : \n";

		Round.Round_Number = GameRound;
		Round.Player_Choice = Read_PlayerChoice();  
		Round.Computer_Choice = Get_ComputerChoice();
		Round.Round_Winner = Get_RoundWinner(Round);
		Round.Round_Winner_Name = Winner_Name(Round.Round_Winner);


		Show_RoundsResult(Round);



		if (Round.Round_Winner == enWinner::Player)
			PlayerWinTimes++;
		else if (Round.Round_Winner == enWinner::Computer)
			ComputerWinTimes++;
		else
			DrawTimes++;
	}

	return Fill_GameResult(HowManyRounds, PlayerWinTimes, ComputerWinTimes, DrawTimes);
}




void Reset_Screen() {
	system("cls");
	system("color f3");
}



void StartGame() {

	char Pass = 'Y';

	do
	{
		Reset_Screen();

		stGame_Result Game = Play_Game(HowManyRounds());

		Show_GameOverScreen();
		Show_FinalGameResult(Game);    

		cout << endl << Tabs(3) << "Do U Want To Play Again ? (Y/N)";
		cin >> Pass;


	} while (Pass == 'Y' || Pass == 'y');
}



int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	system("pause>0");
    return 0;
}