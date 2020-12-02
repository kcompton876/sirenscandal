#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
using namespace std;

// variable definitions:
string  name,
		seat,
		boyChoice1,
		boyChoice2,
		boyChoice3;
	char major,
		motorcycles,
		plansDean,
		studyDate,
		PLchoice,
		chadRedo,
		stewartLecture,
		lunchChoice;
	int mailChoice,
		scottChoice,
		sum = 0,
		mathProblem,
		doCounter = 0,
		points = 0,
		addToScores;
	// for math class questions do-while loop:

// outputs file with a short recap of user's gameplay
// ((**comes from partyORlibrary() and leads to end of program**))
void gamerecap(char major, string seat, string boyChoice1,char PLchoice, string boyChoice2, string boyChoice3);


void displayHighScore()
{
	int highScore;
	string name;
	ifstream inFile;
	inFile.open("highscore.txt");
	
	if(!inFile)	
	{
        cout<<"File not found!\n";
        exit(EXIT_FAILURE);
	}
    inFile >> name;
    inFile >> highScore;
    cout << "highscorer: " << name << endl;
    cout << "highscore: " << highScore << endl;
   }


void highscore(string newName, int newScore)
{
    int highScore;
    ifstream inFile;
	inFile.open("highscore.txt");
	
	if(!inFile)	
	{
        cout<<"File not found!\n";
        exit(EXIT_FAILURE);
	}
    inFile >> name;
    inFile >> highScore;
    
    if (highScore < newScore)
    {
        name = newName;
        highScore = newScore;
        inFile.close();
        ofstream outFile;
	    outFile.open("highscore.txt");
	    outFile << name << endl;
	    outFile << highScore;
	    outFile.close();
    }
    else 
    {
        inFile.close();
    }
}


// yes OR no question validation loop:
char whilefunc (char functionChoice)
{
	while (functionChoice != 'y' && functionChoice != 'Y' && functionChoice != 'n' && functionChoice != 'N')
	{
		cout << "-- you have to enter y or n--" << endl;
		cin >> functionChoice;
	}
	return functionChoice;
}


void partyORlibrary()
// party / library scene (boyChoice2): 
// ((**comes from lunchfunc() and leads to gamerecap()**))
{
	string boyChoice2; 
	char PLchoice, chadRedo, stewartLecture;

	cout << "do you want to go to a party or the library? (p/l): \n";
	cin >> PLchoice;
	while (PLchoice != 'p' && PLchoice != 'P' && PLchoice != 'l' && PLchoice != 'L')
	{
		cout << "invalid input! you must enter one of the given letter choices \n";
		cout << "do you want to go to a party or the library? (p/l): \n";
		cin >> PLchoice;
	}
	if (PLchoice == 'p' || PLchoice == 'P') // user chooses party: potential to meet chad unlocked
	{
		cout << "--you get ready for the party with your friends and head over-- \n";
		cout << "--after saying hi to a few people you recognize, you turn around and someone runs into you, almost knocking you over-- \n";
		cout << "--you look at him and take in his khaki shorts and arrogant face-- \n";
		cout << "KHAKI SHORTS BOY: hey watch where you`re going! \n";
		cout << "AMBER: ugh don`t worry about him. his name`s Chad and he`s just your typical frat boy. you`re better off avoiding him. \n";
		cout << "--you attempt to enjoy the rest of your time at the party after this maddening incident-- \n";
		cout << "--as you`re leaving, you run into Chad again and your efforts to avoid him fail-- \n";
		cout << "CHAD: hey, sorry for bumping into you earlier. can we start over? (y/n) \n";
		cin >> chadRedo;
		whilefunc(chadRedo); // yes or no validation function
		chadRedo = whilefunc(chadRedo);
		if (chadRedo == 'y' || chadRedo == 'Y') // if user gives chad another chance
		{
			cout << "CHAD: cool! what`s your name?\n";
			cout << "ME: " << name << endl;
			cout << "CHAD: it`s nice to meet you, " << name << endl;
			cout << "--you and Chad talk for a bit and he actually seems nice, although something about him still seems untrustworthy--\n";
			cout << "--you leave the party feeling better about giving someone another chance--\n";
			boyChoice2 = "Chad"; // connection made with chad
			points += 2; // +2 points for connecting with chad
			gamerecap(major, seat, boyChoice1, PLchoice, boyChoice2, boyChoice3);
		}
		else // chadRedo == 'n' || chadRedo == 'N' // if user doesn't give chad another chance
		{
			cout << "CHAD: geez i said i was sorry. the boys were right, being nice never works. see ya never loser.\n";
			cout << "--you feel bad about saying no for a split second, then realize you`re probably better off not associating with a frat boy like Chad--\n";
			boyChoice2 = "none"; // no connection made with chad
			// no points added
			gamerecap(major, seat, boyChoice1, PLchoice, boyChoice2, boyChoice3);
		}
	}
	else // PLchoice == l || PLchoice == L // user chooses library: potential to meet stewart unlocked
	{
		// bookfinder for-loop:
      cout<<"         ________________________     \n";
      cout<<"        /                     ///_    \n";
      cout<<"       /  T H E              /////_   \n";
      cout<<"      /      L I B R A R Y  ///////   \n";
      cout<<"     /_____________________///////    \n";
      cout<<"    (______________________)/////     \n";
      cout<<"    /______________________/////      \n";
      cout<<"    (______________________)///       \n";
      cout<<"    /______________________///        \n";
      cout<<"    (______________________)/         \n";
		cout << "--you pack up your study materials and head toward the library-- \n";
		cout << "--you stop by starbucks on the way for a snack-- \n";
		cout << "LIBRARIAN: What book are you looking for honey?"  << endl;
		cout << "ME: Oh, im looking for to kill a moking bird." <<endl;
		cout << "LIBRARIAN: That will be on isle 2, row 3, book 11." << endl;
		cout << "ME: Okay thankyou! \n **isle 2, row 3, book 11.isle 2, row 3, book 11.** \n";
		for (int i=0; i<=2; i++)
		{
		    cout << "isle " << i << endl;
		}
		for (int i=0; i<=3; i++)
		{
		    cout << "row " << i << endl;
		}
		cout << "...and book\n";
		for (int i = 0; i <= 11; i++)
		{
		    cout << i << endl;
		}
		
		cout << "ME: Ah, here it is!!";
		
		// stewart encounter:
		cout << "--you settle into an individual study area to prepare for your next exam-- \n";
		cout << "--you hear someone behind you-- \n";
		cout << "MEAN NERD: hmm that`s quite a suboptimal study technique. uh hi, i`m Stewart and i think you need my help. \n";
		cout << "-- CHOOSE: get lost dude i`m busy (n) OR okay i guess learning some study tips wouldn`t hurt (y)--\n";
		cin >> stewartLecture;
		whilefunc(stewartLecture);
		stewartLecture = whilefunc(stewartLecture);
		if (stewartLecture == 'y' || stewartLecture == 'Y') // if user wants study tips
		{
			
			cout << "--Stewart lectures you on study techniques while also damaging your self-esteem for about 45 minutes-- \n";
			cout << "STEWART: hey, what was your name by the way?\n";
			cout << "ME: i`m " << name << "." << endl;
			cout << "STEWART: hey " << name << " you should help me grade papers. i'm a TA. \n";
			cout << "ME: uh okay i guess so\n";
			cout << "STEWART: okay the scores are 50, 55, 60, 65, and 70\n";
			const int NUM_SCORES = 5;
			int grade[NUM_SCORES];
			for (int i = 0; i < NUM_SCORES; i++)
			{
				grade[i] = (50 + (5 * i));
			}
			cout << "STEWART: how many points should i add to all the scores to make them have an average of 70?\n";
			cin >> addToScores;
			while(addToScores != 10)
			{
				cout << "STEWART: i don't think that's right..try something else?: \n";
				cin >> addToScores;
			}
			if(addToScores == 10)
			{
				points += 50; // + 50 points for eventually doing math right!
				cout << "STEWART: yea that's right! thanks for your help!\n"; 
				for (int i = 0; i < NUM_SCORES; i++)
				{
					grade[i] += 10;
				}
				cout << "STEWART: now the scores are ";
				for (int i = 0; i < NUM_SCORES; i++)
				{
					cout << grade[i] << " ";
				}
				cout << endl;
			}
			cout << "-- you're now tired after all that work so you go back to your dorm --\n";
			boyChoice2 = "Stewart"; // made connection with stewart
			points += 50; // + 50 points for connecting with stewart
			gamerecap(major, seat, boyChoice1, PLchoice, boyChoice2, boyChoice3);
		}
		else // stewartLecture == 'n' || stewartLecture == 'N' // if user doesnt want any tips
		{
			cout << "STEWART: okay, rude i was just trying to help. enjoy failing.\n";
			cout << "--you peacefully continue studying with your sUbOpTimAl tEchNiQue for a couple hours then head back to your dorm for some rest--\n";
			boyChoice2 = "none"; // no connection made with stewart
			// no points added
			gamerecap(major, seat, boyChoice1, PLchoice, boyChoice2, boyChoice3);
		}	
	}
}



void lunchfunc()
// ((**comes from foodchoicefunc() and leads to partyORlibrary()**))
{
	cout << "--you walk up to the register to pay for your food--\n";
	cout << "CASHIER: that'll be $9.57\n";
	cout << "** oo this dude's pretty **\n";
	cout << "** should i talk to him? y/n **\n";
	cin >> lunchChoice;
	whilefunc(lunchChoice);
	if (lunchChoice == 'y' || lunchChoice == 'Y')
	{
		cout << "ME: *checks his nametag* hheyy, when do you go on break, zayn?\n";
		cout << "ZAYN: uhh, i get off at 2\n";
		cout << "ME: see you then cutie *wink*\n";
		cout << "ZAYN: uhhh okay...\n";
		cout << "-- you eat your lunch and come back to see zayn at 2 --\n";
		cout << "ZAYN: what did you wanna talk about?\n";
		cout << "ME: oh i don't know i thought you were cute.. wanna hang out tonight?\n";
		cout << "ZAYN: uhhhh.. sure let's meet at harry's place. you know where it is?\n";
		cout << "ME: oh yea i know where it is! cool i'll see you!\n";
		boyChoice3 = "zayn";
		points += 150; // + 150 points for connecting with zayn
	}
	else // if lunchchoice == n or N
	{
		cout << "ME: okay thanks.. enjoy the rest of your day!\n";
		cout << "ZAYN: uhh, thanks you too\n";
		boyChoice3 = "none";
		// no points added
	}

    // lunch scene
    partyORlibrary();
}


void foodchoicefunc()
// ((**comes from mathclass() and leads to lunchfunc()**))
{
    int chickfila;
  cout<<"               | |                 \n";
  cout<<"               | |                 \n";
  cout<<"               | |                 \n";
  cout<<"               | |                 \n";
  cout<<"               | |                 \n";
  cout<<"               | |                 \n";
  cout<<"   ---------------------------     \n";
  cout<<"   |_________________________|     \n";
  cout<<"    |                       |      \n";
  cout<<"    |                       |      \n";
  cout<<"    |   L U N C H  T I M E  |      \n";
  cout<<"    |                       |      \n";
  cout<<"    |                       |      \n";
  cout<<"    |                       |      \n";
  cout<<"    |`~`~`~`~`~`~`~`~`~`~`~`|      \n";
  cout<<"    |~,~,~,~,~,~,~,~,~,~,~,~|      \n";
  cout<<"    |,~,~,~,~,~,~,~,~,~,~,~,|      \n";
  cout<<"    |`~`~`~`~`~`~`~`~`~`~`~`|      \n";
  cout<<"    |~,~,~,~,~,~,~,~,~,~,~,~|      \n";
  cout<<"    |`~`~`~`~`~`~`~`~`~`~`~`|      \n";
  cout<<"    |                       |      \n";
  cout<<"     \\______________________/     \n";
	cout << "--The class ends and you are hungy for Chick-Fil-A --" << endl;
	cout << "** Where is Chick-Fil-A (1. University Center 2. Library 3. Dining Hall)**" << endl;
	cin >> chickfila;
	while (chickfila != 1 && chickfila != 2 && chickfila != 3)
	{
		cout << "Invalid choice. Choose : 1. University Center 2. Library 3. Dining Hall" << endl;
		cin >> chickfila;
	}
	if (chickfila == 1)
	{
		cout << "Awesome! Im gonna get some nuggets!" << endl;
		points += 10;
		lunchfunc();
	}
	else if (chickfila == 2 || chickfila == 3)
	{
		cout << "-- you show up and you cant find Chick-Fil-A--" << endl;
		cout << "** i guess i`ll eat something at the dining hall **"<< endl;
		// no points added
		lunchfunc();
	}
}



// math class scene (boyChoice1):
void mathClass()
{
    int max = 500;
    srand(time(0));
    int x = rand()%max;
    int y = rand()%max;
	cout << "**My Math class is about to start!**" << endl << endl << endl;
	cout << "--Where will you sit? (Front or Back)--"<<endl;
	cin >> seat;
	while (seat != "front" && seat != "Front" && seat != "Back" && seat != "back")
	{
		cout << "AMBER: Oops! Thats not a seat, silly. Would you like to sit in front or in back? ";
		cin >> seat;
	}
	if (seat == "front" || seat == "Front")
	{
		cout << "**Ooo he looks smart! Maybe he can help me get through this class?**" << endl;
		cout << "AMBER: Oh, good luck up front! Only the REALLY smart people sit there." << endl;
		cout << "--You walk up to the front and sit next to the smart kid. Class begins and the professor starts asking questions-- "<< endl;
	
		do 
		{
			cout << "PROFFESOR E:" << name << " what is " << x << " + " << y <<"?" << endl;
			cin >> mathProblem;
			sum = x + y;
			doCounter++;
		}
		while (mathProblem != sum);
		if (doCounter < 3)
		{
			points += 100; // +100 points for knowing math
			cout << "SMART GUY: Wow! You're really smart. My name is Scott, I could learn a lot from you!" << endl;
			cout << "ME: **giggles**"<< endl;
			cout <<"SCOTT: Wanna have a study date (y/n)? " << endl;
			cin >> studyDate;
			whilefunc(studyDate);
			studyDate = whilefunc(studyDate);
			if (studyDate == 'y' || studyDate == 'Y')
			{
				cout << "SCOTT: Awesome possum! Can't Wait to see you later alligator! "<< endl;
				cout << "ME: *confused* ...okay see you later!" << endl;
				boyChoice1 = "Scott"; // connection made with scott
				points += 50; // + 5 points for connecting with scott
			}
			else if (studyDate == 'n' || studyDate == 'N')
			{
				cout << "ME: No im okay. Maybe another time." <<endl;
				cout << "SCOTT: Okay, good luck this semester." <<endl;
				boyChoice1 = "none"; // no connection made with scott
				// no points added
			}
			foodchoicefunc();
			//cuts to next function (lunch function needed)
		}
		else
		{
			cout << "SMART GUY: **rudly laughs**";
			cout << "PROFESSOR E: Scott, what is 857 multiplied by 476?" << endl;
			cout << "SCOTT (smart guy): 407,932 sir. *looks over at you and smirks* \nSCOTT: You might need a tutor."<< endl;
			cout << "--1. Insult Him 2. Ask him to be your tutor--"<< endl;
			cin >> scottChoice;
			while (scottChoice != 1 && scottChoice != 2)
			{
				cout << "-- choose: 1. Insult Him  OR 2. Ask him to be your tutor--" << endl;
				cin >> scottChoice;
			}
			if (scottChoice == 1)
			{
				cout << "ME: At least i have a life outside of school." << endl;
				cout << "-- you get up and leave class to go to the dining hall--"<< endl;
				boyChoice1 = "none"; // no connection made with scott
				// no points added
			}
			else if (scottChoice == 2)
			{
				cout << "ME: Well you seem pretty smart, would you be my tutor?" << endl;
				cout << "SCOTT: What a turn of events, I suppose I could help you."<< endl;
				boyChoice1 = "Scott"; // connection made with scott
				points += 50; // + 50 points for connecting with scott
			}
			foodchoicefunc();
			//cuts to next function (lunch function needed)
		}
	}
	else if (seat == "back" || seat == "Back")
	{
		cout << "**Oo a hot boy in a leather jacket is sitting in the back**"<<endl;
		cout << "AMBER: Oh, thats my seat, " << name << endl;
		cout << "HOT BOY IN LEATHER JACKET: Hey do either of you know where I can pick up my mail (1. University Center 2. Cat Alley 3. The Post Office)?" << endl;
		cin >> mailChoice;
		while (mailChoice != 1 && mailChoice != 2 && mailChoice != 3)
		{
			cout << "AMBER: Sweetie, thats not a choice. Do you know where it is (1. University Center 2. Cat Alley 3. The Post Office)? " <<endl;
			cin >> mailChoice;
		}
		if (mailChoice == 1)
		{
			points += 100; // + 100 points for knowing where to get mail
			cout << "HOT BOY IN LEATHER JACKET: Awesome thank you. Come sit next to me!";
			cout << "AMBER: *grunts* I was going to sit there!" << endl;
			cout << "HOT BOY IN LEATHER JACKET: Well i just asked her to sit here. Theres a seat up front! Have a good day, Amber! \n Sorry about her, shes very expressive. What is your name?" << endl;
			cout << "ME: My name is " << name << ". Whats your name?" << endl;
			cout << "DEAN: Its Dean, do you like motorcycles (OMG yes = y | Ew No = n)? "<< endl;
			cin >> motorcycles;
			whilefunc(motorcycles);
			motorcycles = whilefunc(motorcycles);
			if (motorcycles == 'y' || motorcycles == 'Y')
			{
				cout << "DEAN: Right on. Wanna hang out this weekend (y/n)?";
				cin >> plansDean;
				whilefunc(plansDean);
				plansDean = whilefunc(plansDean);
				if (plansDean == 'y' || plansDean == 'Y')
				{
					cout << "DEAN: Great! Maybe i can take you on a ride?";
					cout << "ME: Saturday?";
					cout << "DEAN: I'll see you at 8."<< endl;
					boyChoice1 = "Dean"; // connection made with dean
					points += 200; // + 200 points for connecting with dean
					foodchoicefunc();
					//cuts to next function (lunch function needed)
				}
				else if(plansDean == 'n' || plansDean =='N')
				{
					cout << "DEAN: Thats a shame. I guess ill see you around sometime." << endl;
					boyChoice1 = "none"; // no connection made with dean
					// no points added
					foodchoicefunc();
					//cuts to next function (lunch function needed)
				}
			}
			else // motorcycles == 'n' || motorcycles == 'N'
			{
				cout << "DEAN: Thats a shame. I guess ill see you around sometime." << endl;
				cout << "** did i say something wrong? **" << endl;
				boyChoice1 = "none"; // no connection made with dean
				// no points added
				foodchoicefunc();
				//cuts to next function (lunch function needed)
			}
		}
		else if (mailChoice == 2 || mailChoice == 3)
		{
			// no points added bc you dont know where mail is
			cout << "AMBER: Oh honey, thats not right. *looks over at the hot guy in the leather jacket* Its in the University Center over by the bookstore. I'll walk you there after class!"<< endl;
			cout << "ME: Great, looks like im stuck sitting up front. I hope the professor doesnt ask me any questions." << endl;
			cout << "--You get through class without the professor asking you hard questions--"<< endl;
			seat = "front";
			boyChoice1 = "none"; // no connection made with dean
			foodchoicefunc();
			//cuts to next function (lunch function needed)
		}
	}
}



//Case 1
void howToPlay()
{
	char menu;
	do
	{
	cout << "This game is based around a female freshman college student. You will have to use your memory,"
	<< " and knowledge of the TAMUCC campus to gain gems and build relationships.\nAfter each choice you make, you have to push enter to confirm your choice.\n Make sure you press the correct keys." << endl;
	cout << "Inner monologue will be enclosed in ** while the game prompts will be enclosed in --." << endl;
	cout << "in order to play the game, make sure you download highscore.txt." << endl;
	cout << "Would you like to return to menu (y/n)? "<< endl;
	cin >> menu;
	whilefunc(menu);
	}
	while (menu == 'n' || menu =='N');
}


// Case 2
void storyStarter()
{
	cout << "AMBER: Welcome to TAMUCC, home of the islanders. What is your name?\n";
	cout << "please enter a 3-letter nickname: ";
	cin >> name;
	cout << "AMBER: Hi " << name << " , its nice to meet you! What will your major be? \n -Computer Science(c)\n -Nursing(n) \n -Business(b)\n -Psychology(p) \n";
	cin >> major;
	while (major != 'c' && major != 'C' && major != 'n' && major != 'N' && major != 'b' && major != 'B' && major != 'P' && major != 'p')
	{
		cout << "AMBER: Oops! We dont have that major here. Please choose one of the four majors:  \n -Computer Science(c)\n -Nursing(n) \n -Business(b)\n -Psychology(p) \n";
		cin >> major;
	}
	
	cout << "AMBER: What a fun major to have!!" << endl;
	mathClass();
}


void gamerecap(char major, string seat, string boyChoice1,char PLchoice, string boyChoice2, string boyChoice3)
// game recap (writes to output file):
// ** comes from partyORlibrary() // leads to end of program **
{
	ofstream outFile;		//define output file stream object
	outFile.open("gamerecap.txt");	//create file gamerecap.txt
	
	outFile << "your siren scandal game recap:\n";

	// major recap (storyStarter)
	if (major == 'c' || major == 'C')
	{
		outFile << "you were a computer science major! \n";
	}
	else if (major == 'n' || major == 'N')
	{
		outFile << "you were a nursing major! \n";
	}
	else if (major == 'b' || major == 'B')
	{
		outFile << "you were a business major! \n";
	}
	else if (major == 'p' || major == 'P')
	{
		outFile << "you were a psychology major! \n";
	}

	// math class recap (boyChoice1)
	if (seat == "front" || seat == "Front")
	{
		if (boyChoice1 == "Scott")
		{
			outFile << "you sat in the front in math class and met Scott!\n";
		}
		else // boyChoice1 == "none"
		{
			outFile << "you sat in the front in math class but did not make a connection with Scott :(\n";
		}
	}
	else // seat == "back" || seat == "Back"
		if (boyChoice1 == "Dean")
		{
			outFile << "you sat in the back in math class and met Dean!\n";
		}
		else
		{
			outFile << "you sat in the back in math class but did not make a connection with Dean :(\n";
		}

	// ***LUNCH FUNCTION RECAP*** //
	if (boyChoice3 == "zayn")
		{
			outFile << " you made a connection with zayn while buying lunch!\n";
		}
		else 
		{
			outFile << " you did not make a connection with zayn :(\n";
		}


	// party or library recap (boyChoice2)
	if (PLchoice == 'p' || PLchoice == 'P')
	{
		if (boyChoice2 == "Chad")
		{
			outFile << " you went to the party and made a connection with Chad!\n";
		}
		else 
		{
			outFile << " you went to the party but did not make a connection with Chad :)\n";
		}
	}
	else // PLchoice == 'l' || PLchoice == 'L'
	{
		if (boyChoice2 == "Stewart")
		{
			outFile << " you went to the library and made a connection with Stewart!\n";
		}
		else 
		{
			outFile << " you went to the library but did not make a connection with Stewart :(\n";
		}	
	}

	cout << "--you can find a recap of your gameplay in gamerecap.txt!--"<<endl;
	outFile.close();		//close the file
	highscore(name, points);
}



void menufunc()
{
	int choice;
	cout << " Welcome to Siren Scandal! \n _1_ How to Play \n _2_ Start Game \n _3_ View Highscore \n _4_ Exit \n";
	cout << "Enter 1, 2, or 3! \n";
	cin >> choice;
	switch (choice)
	{
		case 1:
			howToPlay();
			menufunc();
			break;
		case 2: 
			storyStarter();
			cout << "thanks for playing siren scandal!\n";
			break;
		case 3:
			displayHighScore();
			menufunc();
			break;
		case 4:
			cout << "thanks for playing siren scandal!\n";
			break;
		default:
			cout << "That is not a choice! Please enter 1, 2, or 3:";
	}
}


int main ()
// splash screen and menu
{
	int choice;
    cout<<"       ------      ------      \n";
    cout<<"      //      \\   //      \\     \n";
    cout<<"     //        \\//         \\     \n";
    cout<<"    //         \\/           \\     \n"; 
    cout<<"    \\                      //     \n";
    cout<<"     \\      S I R E N     //       \n";
    cout<<"      \\   S C A N D A L  //         \n";
    cout<<"       \\                //          \n";
    cout<<"        \\              //           \n";
    cout<<"         \\            //             \n";
    cout<<"          \\          //              \n";
    cout<<"           \\        //               \n";
    cout<<"            \\      //                \n";
    cout<<"             \\    //                 \n";
    cout<<"               \\//                   \n";
    
	cout << " Welcome to Siren Scandal! \n _1_ How to Play \n _2_ Start Game \n _3_ View Highscore \n _4_ Exit \n";
	cout << "Enter 1, 2, or 3! \n";
	cin >> choice;
	switch (choice)
	{
		case 1:
			howToPlay();
			menufunc();
			break;
		case 2: 
			storyStarter();
			cout << "thanks for playing siren scandal!\n";
			break;
		case 3:
			displayHighScore();
			menufunc();
			break;
		case 4:
			cout << "thanks for playing siren scandal!\n";
			break;
		default:
			cout << "That is not a choice! Please enter 1, 2, or 3:";
	}
	return 0;
}

