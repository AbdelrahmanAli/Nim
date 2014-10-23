#include <iostream>
#include <windows.h>
using namespace std;


    void printer(int stones){
        for(int i = 0 ; i < stones+3 ; i++)
        {
            if(i!=stones-1){cout << "--";}
            else{cout << "---";}
        }

        cout <<endl<<" Stones : "<<stones<<endl;

        for(int i = 0 ; i < stones ; i++)
        {    if(i==0) cout << "  0";
            else cout << " 0";          }

        cout<<endl;

        for(int i = 0 ; i < stones ; i++)
        {   if(i==0)
            {   cout << " U";
                if(stones==1)
                {  cout << " C"; }
            }
            else if(i!=stones-1)
            { cout << "  "; }
            else
            { cout << "   C"; }
        }

        cout<<endl;

        for(int i = 0 ; i < stones+3 ; i++)
        {
            if(i!=stones-1){cout << "--";}
            else{cout << "---";}
        }

        cout<<endl;
}

	bool checkValidation(int input , int max,int stones){
		if(input > max || input < 1||input>stones){
			return true;
		}
		return false;
	}

	int firstBlock(int stones ,int max){
		int reqStones = (stones-1)%(max+1);
		if(reqStones==0)return max+1;
		else return reqStones;
		return 0;
	}

	void gameTurn(int max , int stones , int specialPositions[], int tracker,bool prime){
		printer(stones);

		bool dump = true;

		while (stones>0)
    {   bool loser = false;
		bool winner = true;
		bool checker = true;
		int user=stones+1;
		int input;
		int computer;

		while(checker)
		{
			cout <<"User Take : ";
			cin >> input;
			cout << endl;
			checker = checkValidation(input,max,stones);
			if(checker)
            {cout << "The Taken Stones Should Be <= max And >= 1 , Please Try Again !\n";}
			else{
				user-=input;
				stones-=input;
                printer(stones);
                cout<< endl;

				bool takeCare = false;
				for(int i = 0 ; i < tracker &&(user >= specialPositions[i]); i++){
					if(user == specialPositions[i])
					{   takeCare=true;
						break;
					}
				}

				if(stones==0)
				{
					loser=true;
					cout<<"      --------------\n";
					cout<<"      | You Lose ! |\n";
					cout<<"      --------------\n\n\n";
					return ;
				}
				else if(takeCare){
					winner = false;
				}
			}
		}
		if(!loser)
		{   if(winner)
            {   int maxPlusOne = max+1;
                if(dump)
                {
                        if(prime)
                        {
                            int firstBlockStones = firstBlock(stones+input , max);

                            if(input<=firstBlockStones)
                            {
                            computer=firstBlockStones-input;
                            if(computer<=0) { computer=1;}
                            }
                            else
                            { computer = (firstBlockStones + maxPlusOne)-input;}

                            cout << "Computer Take : "<<computer<<endl;
                            stones-=computer;
                            printer(stones);
                            cout<< endl;
                            prime = false;
                        }
                        else
                        {
                            computer=maxPlusOne-input;
                            cout << "Computer Take : "<<computer<<endl;
                            stones-=computer;
                            printer(stones);
                            cout<< endl;
                        }
                }
                else
                {   computer = maxPlusOne - input - 1 ;
                    stones-=computer;
                    dump = true;
                    cout << "Computer Take : "<<computer<<endl;
                    printer(stones);
                    cout<< endl;
                }

            }
            else
            {   dump = false;
                computer=1;
                cout << "Computer Take : "<<computer<<endl;
                stones-=computer;
                printer(stones);
                cout<< endl;
            }

            if(stones==0)
            {   cout<<"      -------------\n";
                cout<<"      | You Win ! |\n";
                cout<<"      -------------\n\n\n";
                return ;
            }


		}

    }

    }


int main()
{
        cout <<endl;
        cout<<" --------------------------------------\n";
        cout<<" | |           Welcome              | |\n";
        cout<<" --------------------------------------\n\n";
    while(true)
    {   cout <<" Choose One Option :\n";
        cout <<" -------------------\n";
        cout << " 1- Computer Choose Maximum Remove Value And User Choose Number Of Stones."<<endl;
        cout << " 2- Computer Choose Number Of Stones And User Choose Maximum Remove Value."<<endl;
        cout << " 3- User Choose Both Number Of Stones And Maximum Remove Value."<<endl;
        cout <<" 4- View Instructions."<<endl;
        cout << " #- Exit.\n\n";
        cout << "   I Choose : ";
        int choice;
        cin >> choice;
        if(choice==1)
        {   int stones;
            while(true)
            {   cout <<"Enter Number Of Stones (Must Be Greater Than 6): ";
                cin >> stones;
                if(stones<=6) {cout<<"Number Of Stones Must Be Greater Than 6 , Try Again !\n";}
                else {break;}
            }

            int max;
            bool prime = false;
            int modTaken;
            if((stones-1)%2==0)
            {
                max = ((stones-1)/2)-1;
                modTaken=2;
            }
            else if((stones-1)%3==0)
            {
                max = ((stones-1)/3)-1;
                modTaken=3;

            }
            else if((stones-1)%5==0)
            {
                max = ((stones-1)/5)-1;
                modTaken=5;
            }
            else if((stones-1)%7==0 && (stones-1)!=7){

                max = ((stones-1)/7)-1;
                modTaken=7;

            }
            else {
                max = (stones-1) / 2 ;
                modTaken=2;
                prime = true;
            }
                cout << "The Maximum Is : " << max<<endl<<endl;

                int tracker = 1;
                int specialPositions [100] ;
                specialPositions[0]=2;
                for(int i = 1 ; i < modTaken; i++){
                    specialPositions[i]=specialPositions[i-1]+max+1;
                    tracker++;
                }
                  gameTurn( max , stones ,specialPositions,tracker,prime);
        }
        else if(choice==2)
        {
            int max;
            while(true){
            cout <<"Enter Maximum Remove Value (Must Be Greater Than 1): ";
            cin >> max;
            if(max<=1) {cout<<"Maximum Remove Value Must Be Greater Than 1 , Try Again !\n";}
            else{break;}
            }

            int stones =1+((max+1)*3);
            cout << "The Number Of Stones Is : " << stones<<endl<<endl;

            int specialPositions [3];
            specialPositions[0]= 2;
            for(int i = 1 ; i < 3; i++){
                    specialPositions[i]=specialPositions[i-1]+max+1;
            }
            gameTurn(max , stones ,specialPositions,3,false );
        }
        else if(choice == 3)
        {
            int stones;
            while(true){
            cout <<"Enter Number Of Stones (Must Be Greater Than 6): ";
            cin >> stones;
            if(stones<=6){cout<<"Number Of Stones Must Be Greater Than 6 , Try Again !\n";}
            else{break;}
            }

            int max;
            while(true){
            cout <<"Enter Maximum Remove Value (Must Be Greater Than 1): ";
            cin >> max;
            if(max<=1||max>=(stones-1)){cout<<"Maximum Remove Value Must Be Greater Than 1 \nAnd Also Less Than Number Of Stones-1, Try Again !\n";}
            else{break;}
            }
                int tracker = 1;
                int specialPositions [100] ;
                specialPositions[0]=2;
                for(int i = 1 ; i < (int)(stones/2); i++){
                    specialPositions[i]=specialPositions[i-1]+max+1;
                    tracker++;
                }

                if((stones-1)%(max+1)==0){
                    gameTurn( max , stones ,specialPositions,(int)(stones/2),false);
                }
                else{
                    gameTurn( max , stones ,specialPositions,(int)(stones/2),true);
                }


        }
        else if(choice == 4){
                cout<<endl;
                cout<<"It's Simple , We Have Group Of Stones Which We Will Take\n";
                cout<<"Number From Them Sequentially , This Number Is Greater Than\n";
                cout<<"Or Equal To One And Less Than or Equal to a Special Max. Value\n";
                cout<<"The Last One Who Pick Stones Is The Loser.\n";
        }
        else{
            cout<<endl<<endl;
            cout<<" Bye...Bye...\n\n I Hope You Enjoyed The Game !"<<endl<<endl<<endl;
            cout<<"                             Author: MaTrix (Abdelrahman Ali)"<<endl;
            cout<<endl<<endl;
            break;
        }
        cout <<endl;
        cout<<"--------------------------------------\n";
        cout<<"              Try Again\n";
        cout<<"--------------------------------------\n";



    }
    Sleep(2*1000);
	return 0;
}
