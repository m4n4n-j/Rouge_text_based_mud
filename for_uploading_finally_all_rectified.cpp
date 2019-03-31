#include<simplecpp>
#include<iostream>
using namespace std;
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//*MINOR CHANGES HERE*//
int enter_church=0;
int enter_military=0;
int enter_people=0;
struct You{
   int Health;
   int Armour;
   int Damage;
   int BlockRestore;
   You()
   {
        Health=100;
        Armour=40;
        Damage=40;
        BlockRestore=10;

   }
};
struct Enemy{
   int Health;
   int Armour;
   int Damage;
   int BlockRestore;
   Enemy()
   {
        Health=100;
        Armour=60;
        Damage=50;
        BlockRestore=10;
   }
};
void final();
void enemymove(You *Me,Enemy *Villain);
struct question
{
    string ques1,ques2;
    char correctoptionques1;
    char correctoptionques2;
};

struct mapunit
{
    string Name;
    int point;
    question quest;
    bool puzzle1,puzzle2;
    struct mapunit *north;
    struct mapunit *south;
    struct mapunit *west;
    struct mapunit *east;
    mapunit()
    {
        Name='\0';
        point=50;
        puzzle1=0;
        puzzle2=0;
        north=south=west=east=NULL;
    }
};

class start
{
    public:
    void playinside();
    void mapp();
    void credits();
    int puzzle();
};

void start::credits()
{
    cout<<"ROGUE"<<endl;
    cout<<endl;
    cout<<"Written by"<<endl;
    cout<<"Manan Jain"<<endl;
    cout<<"Shivam Jaiswal"<<endl;
    cout<<"Omkar Mohije"<<endl;
    cout<<"Yashi Agarwal"<<endl;
    cout<<endl;
    cout<<"Programming language used:"<<endl;
    cout<<"Simple Code Blocks"<<endl;
    cout<<endl;
};
int start::puzzle()
{
    struct mapunit *military,*treasure,*people,*church,*rogue1,*rogue2;
    struct mapunit *centre,*mypointer;
    military=new mapunit();
    treasure=new mapunit();
    people=new mapunit();
    church=new mapunit();
    rogue1=new mapunit();
    rogue2=new mapunit();
    centre=new mapunit();

    centre->east=rogue2;
    centre->west=people;
    centre->south=church;
    centre->north=rogue1;
    centre->Name="centre arena";

    rogue1->north=treasure;
    rogue1->south=centre;
    rogue1->Name="rogue1 building ";

    treasure->south=rogue1;
    treasure->Name="treasure building";

    rogue2->west=centre;
    rogue2->south=military;
    rogue2->Name="rogue2 building";

    military->north=rogue2;
    military->Name="military building";

    people->east=centre;
    people->Name="public building";

    church->north=centre;
    church->Name="church building";

    unsigned int case_=0;
    case_=rand()%2;
    if(case_)
    {
         military->quest.ques1="what is as light as feather, but even the world's stongest man couldn't hold it for more than a minute?\n a) shadow  b) breath  c) soul  d)none of the above";cout<<endl;
         military->quest.ques2="who makes it,has no need of it.\n who buys it,has no use for it.\n Who uses it can neither see nor fill it.\n what is it? a)sugar b)coffee c) coffin d)nature\n";;cout<<endl;
         military->quest.correctoptionques1='b';
         military->quest.correctoptionques2='c';
    }
    else if(!case_)
    {
         military->quest.ques2="what is as light as feather, but even the world's stongest man couldn't hold it for more than a minute?\n a) shadow  b) breath  c) soul  d)none of the above";cout<<endl;
        military->quest.ques1="who makes it,has no need of it.\n who buys it,has no use for it.\n Who uses it can neither see nor fill it.\n what is it? a)sugar b)coffee c) coffin d)nature\n";;cout<<endl;
         military->quest.correctoptionques1='c';
        military->quest.correctoptionques2='b';
    }

    case_=rand()%2;
    if(case_)
    {
         church->quest.ques1="I am tall ,when i am young \nand i am short, when i am old. What am i? \n a) stick  b) spirit  c) flame  d) candle.";cout<<endl;
        church->quest.ques2="He has married many women, but has never been married. Who is he? a) Krishna  b) husband  c) You don't know  d) priest";cout<<endl;
    }
    else if(!case_)
    {
         church->quest.ques2="I am tall ,when i am young \nand i am short, when i am old. What am i? \n a) stick  b) spirit  c) flame  d) candle.";cout<<endl;
        church->quest.ques1="He has married many women, but has never been married. Who is he? a) Krishna  b) husband  c) You don't know  d) priest";cout<<endl;
    }
    church->quest.correctoptionques2=church->quest.correctoptionques1='d';

    case_=rand()%2;
    if(case_)
    {
        treasure->quest.ques2="What starts with t filled with t and ends with the tea? \n a)teapot b)treat c)talent d)threat";cout<<endl;
        treasure->quest.ques1="What can travel around the world while staying in a corner? \n a) light  b) air  c) voice  d) stamp";cout<<endl;
        treasure->quest.correctoptionques1='d';
        treasure->quest.correctoptionques2='a';
    }
    else if(!case_)
    {
        treasure->quest.ques1="What starts with t filled with t and ends with the tea? \n a)teapot b)treat c)talent d)threat";cout<<endl;
        treasure->quest.ques2="What can travel around the world while staying in a corner? \n a) light  b) air  c) voice  d) stamp";cout<<endl;
        treasure->quest.correctoptionques2='d';
        treasure->quest.correctoptionques1='a';
    }

    case_=rand()%2;
    if(case_)
    {
        people->quest.ques1="What gets wetter and wetter the more it dries? \n a) well  b) jelly  c) towel  d) soil.";cout<<endl;
        people->quest.ques2="What has hands but can not clap? \n a) scarecrow  b) clock  c) death  d) law.";cout<<endl;
    }
    else if(!case_)
    {
        people->quest.ques1="What gets wetter and wetter the more it dries? \n a) well  b) jelly  c) towel  d) soil.";cout<<endl;
         people->quest.ques2="What has hands but can not clap? \n a) scarecrow  b) clock  c) death  d) law.";cout<<endl;
    }
    people->quest.correctoptionques1=people->quest.correctoptionques2='c';

    rogue1->quest.ques1="Open at night, \nA show is played \n ,that might delight, \nbut be careful, it can turn to a fright \n but its always over by daylight? \na)ghost  b) disaster  c) dream  d) moon.";cout<<endl;
    rogue1->quest.correctoptionques1='c';

    rogue2->quest.ques1="I am a type of building but I am not a shed \nI have many rooms but I am not a house \nI have several departments but I am not a grocery store \nI have many beds but I am not a hotel \nI am where you might go when you are feeling sick but I am not a drugstore? \na) graveyard  b) hospital  c) liquor shop  d) tent";cout<<endl;
    rogue2->quest.correctoptionques1=' b';

    char c,x;
    cout<<"You are in the centre and game begins here"<<endl;
    cout<<"If want to play the game enter y else q to quit"<<endl;
    cin>>c;
    system("CLS");
    mypointer=centre;
    if(c=='y')
    {
        cout<<"You are in the centre.Enter the direction you want to go"<<endl;
        cout<<"Key in n for north, s for south, e for east, w for west, q for quit"<<endl;
        cout<<endl;
        int pointsum=military->point+people->point+treasure->point+church->point;

            while(pointsum!=300)
            {
                char here=0;
                while(pointsum!=300){
                cout<<"if you want to move in another building, Enter 1 or for remaining to stay enter zero"<<endl;
                cin>>here;
                if(here<=122&&here>=97)
                {
                        cout<<"you have entered wrong keyword please enter right enter 0 or 1"<<endl;
                        cin>>here;

                }
                if(here=='1'){out:
                    int found=0;
                    do
                    {
                        cin.ignore();
                        cout<<"Enter the direction"<<endl;
                        cin>>x;
                        found=0;
                        switch(x)
                        {
                            case 'n' : if(mypointer->north!=NULL)
                                       {mypointer=mypointer->north;}
                                        else
                                        {
                                            cout<<"you have entered wrong direction try again"<<endl;
                                            found=1;
                                        }
                                        break;
                            case 'e' :  if(mypointer->east!=NULL)
                                        mypointer=mypointer->east;
                                        else
                                        {
                                            cout<<"you have entered wrong direction"<<endl;
                                            found=1;
                                        }
                                        break;
                            case 's':   if(mypointer->south!=NULL)
                                        mypointer=mypointer->south;
                                        else
                                        {
                                            cout<<"you have entered wrong direction"<<endl;
                                            found=1;
                                        }
                                        break;
                            case 'w':   if(mypointer->west!=NULL)
                                        mypointer=mypointer->west;
                                        else
                                        {
                                            cout<<"you have entered wrong direction"<<endl;
                                            found=1;
                                        }
                                        break;
                            case 'q': goto exit;
                        }
                    }while(found==1);
                }
                cin.ignore();
                cout<<"you are in the "<<mypointer->Name<<endl;
                if(mypointer==centre)
                {
                    cout<<"press enter to continue"<<endl;
                    goto out;
                }

                if(((mypointer!=rogue1)&&(mypointer!=rogue2))&&(mypointer!=centre))
                {
                    char d;
                    cout<<"if you want to attempt puzzle here key in y,e for exit and n move"<<endl;
                    cin>>d;
                    if(d=='y')
                    {
                        if(mypointer->puzzle1==0)
                        {
                            char option;
                            cout<<"here"<<endl;
                            cout<<mypointer->quest.ques1;
                            cin>>option;
                            if(option!=mypointer->quest.correctoptionques1)
                                {
                                cout<<"you lost better luck next time"<<endl;return 1;
                                }
                            if(option==mypointer->quest.correctoptionques1)
                            {
                                cout<<"congratulation you got right answer"<<endl<<endl;
                                mypointer->point=mypointer->point+25;
                                mypointer->puzzle1=1;
                            }
                        }
                        else if((mypointer->puzzle2==0 )&& (mypointer->puzzle1==1 &&mypointer!=centre))
                        {
                            cout<<"you have solved every puzzle here go in another room"<<endl;
                        }
                    }
                    else
                    if(d=='e')
                    {
                        goto exit;
                    }
                }
                else if((mypointer==rogue1||mypointer==rogue2)&&(mypointer!=centre))
                {
                    if(mypointer->puzzle1==1)
                    {
                        cout<<"you have solved every puzzle here go in another room"<<endl;
                    }
                    else if(mypointer->puzzle1==0)
                    {   char option;
                        cout<<mypointer->quest.ques1;
                        cin>>option;
                        cin.ignore();
                        mypointer->puzzle1=1;
                        if(option!=mypointer->quest.correctoptionques1)
                            {goto exit;}
                        else if(option==mypointer->quest.correctoptionques1)
                        {
                            cout<<"oops this puzzle has no point "<<endl;
                            cout<<"you have wasted sometime here \n but only one question is there in this building "<<endl;
                        }
                    }
                }
                pointsum=military->point+people->point+treasure->point+church->point;
                if(pointsum==300) return 0;
            }

    }
    }
    else if(c=='q')
    {
        goto exit;
    }
    exit:return 1;
    return 0;
}

void start::playinside()
{
    cin.ignore();
    char name[50],a;
    string m;
    cout<<"Please enter your name"<<endl;
    cin.getline(name,50);
    cout<<endl;
    cout<<"Wake up "<<name<<" !,wake up fast, the king demands you!!"<<endl;
    cout<<"Waking up dizzily you find yourself in an unknown room."<<endl;
    cout<<"you ask the man demanding you.Who are you, how do you know my name? , why does the king want me?"<<endl;
    cout<<"The man explains You sire, are the Hand Of The King , and he urgently calls for your supplication!"<<endl;


        cout<<"absolutely rattled you inquire , What ?!? me the hand? I don't remember any such thing.!!"<<endl;

        cout<<"Oh my God , you forgot everything again!! I told you not to drink so much.. said the man."<<endl;
        cout<<endl;
        cout<<endl;
    cout<<"-----------------------------------------------------------------------------------------------"<<endl;
    cout<<"Press y to continue or n to quit"<<endl;
    cin>>a;
    system("CLS");
    if(a=='y')
    {


        cout<<"'WHIP!', you find yourself hallucinating again , and this time you felt the pain of someone hitting"<<endl;
        cout<<"you on your back with a whip."<<endl;

        cout<<"consoling yourself, you hastily reach the courthouse and king expresses ,OH! "<<name<<" where were you,There have been so many problems in the kingdom today go and fix them!!"<<endl;
        cout<<"Seeing your puzzled face, the man who called you starts explaining your job "<<endl;
        cout<<"*RULES*"<<endl;
        cout<<"There are four main buildings in the kingdom ; Treasury , Town hall , Military HQ , Church"<<endl;
        cout<<"Each of these are the main causes of trouble to the empire."<<endl;
        cout<<"All of them can cause the dethronement of the king and your job is to avoid that scenario at any cost."<<endl;
        cout<<"Each of these Buildings have the base INFLUENCE. There is one puzzle in each of these buildings. "<<endl;
        cout<<"Each puzzle is to be solved to advance further in the game. Wrong answer to any puzzle will lead to decrease in"<<endl;
        cout<<"influence of that building which will lead to termination of the reign of the king and hence your game will end."<<endl;
        cout<<"You reach the centre of the kingdom."<<endl;
        cout<<endl;
        cout<<"------------------------------------------------------------------------"<<endl;
        cout<<"Enter y to continue and see the map and n to exit"<<endl;
        cin>>a;
        if(a=='n')
        {   goto l;}
        mapp();
    }
    l:;
}
void start::mapp()
{
    turtleSim();
    {
        repeat(4)
        {
            forward(20);
            right(90);
        }
        right(90);
        forward(20);
        left(90);
        forward(10);
        right(90);
        forward(20);
        right(90);
        penUp();
        forward(10);
        right(180);
        penDown();
        repeat(4)
        {
            forward(20);
            right(90);
        }
        penUp();
        forward(10);
        right(90);
        forward(20);
        penDown();
        forward(40);
        right(90);
        forward(10);
        left(90);
        left(90);
        repeat(4)
        {
            forward(20);
            right(90);
        }
        forward(10);
        left(90);
        forward(20);
        right(90);
        forward(20);
        left(90);
        forward(10);
        right(90);
        repeat(4)
        {
            forward(20);
            right(90);
        }
        forward(10);
        penUp();
        right(90);
        forward(20);
        penDown();
        forward(20);
       right(90);
       forward(10);
       right(180);
       repeat(4)
        {
            forward(20);
            right(90);
        }
        forward(10);
        left(90);
        penUp();
        forward(30);
        left(90);
        forward(30);
        penDown();
        forward(20);
        right(90);
        forward(10);
        left(90);
        forward(20);
        right(180);
         repeat(4)
        {
            forward(20);
            right(90);
        }
        penUp();
        forward(1000);

        wait(3);
    }
}
main_program
{
    start s;
    cout<<"Welcome to ROGUE"<<endl;
    int ch,m;
    char c;
    cout<<"Enter the following to"<<endl;
    cout<<"1 to play"<<endl;
    cout<<"2 for credits"<<endl;
    cout<<"3 to exit"<<endl;
    cin>>ch;
    switch(ch)
    {
        case 1: s.playinside();
                m=s.puzzle();

                if(m==0)
                {

        cout<<"Congratulations, Although you have cleared all the eight puzzles...you still haven't won the game."<<endl;

        cout<<"The unused puzzles were not useless afterall." <<endl;

        cout<<"The Magnitude of hallucinations increase to such an extent you can feel the sky speaking to you.!!"<<endl;
        cout<<"Be conscious always it says!"<<endl;

        cout<<"You get a clue regarding your condition."<<endl;

        cout<<"You start to understand why you see these hallucinations, why you are feeling"<<endl;
        cout<<"so dizzy and moreover the clue from rogue building helps you realize that it has all been a dream."<<endl;

        cout<<"Now you wake up yet again, see a blurry image of an old man trying to wake you up."<<endl;
        cout<<"You start noticing the murky cellar, blood dripping down the floor, through your whole body."<<endl;
        cout<<"The old man desperately trying to get you back to consciousness in what seemed forever."<<endl;
        cout<<"His eyes lightened up seeing you wake up."<<endl;
        cout<<"He convulsively started speaking,Wake up son! our village was ransacked by the Demon."<<endl;
        cout<<"He killed your parents, looted the our houses & devoured everything in his sight."<<endl;
        cout<<"But your fight damaged your enemy enough to stop him although you fell unconscious, he too had to retreat."<<endl;
        cout<<"Although emotionally shaken , you get yourselves together and start putting the puzzle pieces together. "<<endl;
        cout<<"Hastily you remember about the second puzzle piece. You remember the clue about the hospital"<<endl;
        cout<<"Figuring out your archenemy's destination you rush there to face him , to defeat him!"<<endl;

                 }
                 else
                 if(m==1)
                 goto label;
                 goto kuy;
                break;
        case 2: s.credits();
                cout<<"Enter y to play the game and n to quit"<<endl;
                cin>>c;
                system("CLS");
                if(c=='y')
                {
                    s.playinside();
                    m=s.puzzle();
                     if(m==1) goto label;
                     else if(m==0)
                {

        cout<<"Congratulations, Although you have cleared all the six puzzles...you still haven't won the game."<<endl;

        cout<<"But the puzzles were not useless afterall." <<endl;

        cout<<"The Magnitude of hallucinations increase to such an extent you can feel the sky speaking to you.!!"<<endl;
        cout<<"Be conscious always it says!"<<endl;

        cout<<"You get a clue regarding your condition."<<endl<<endl;

        cout<<"You start to understand why you see these hallucinations, why you are feeling"<<endl;
        cout<<"so dizzy and moreover the clue from rogue building helps you realize that it has all been a dream."<<endl;

        cout<<"Now you wake up yet again, see a blurry image of an old man trying to wake you up."<<endl;
        cout<<"You start noticing the murky cellar, blood dripping down the floor, through your whole body."<<endl;
        cout<<"The old man desperately trying to get you back to consciousness in what seemed forever."<<endl;
        cout<<"His eyes lightened up seeing you wake up."<<endl;
        cout<<"He convulsively started speaking,Wake up son! our village was ransacked by the Demon."<<endl;
        cout<<"He killed your parents, looted the our houses & devoured everything in his sight."<<endl<<endl;
        cout<<"But your fight damaged your enemy enough to stop him although you fell unconscious, he too had to retreat."<<endl;
        cout<<"Although emotionally shaken , you get yourselves together and start putting the puzzle pieces together. "<<endl;
        cout<<"Hastily you remember about the second puzzle piece. You remember the clue about the hospital"<<endl;
        cout<<"Figuring out your archenemy's destination you rush there to face him , to defeat him!"<<endl;

                 }
                 goto kuy;
        }
        else
                {   cout<<"Bye meet you soon"<<endl;
                    goto label;}

                    break;

        case 3: cout<<"Bye"<<endl;
                goto label;
        default: cout<<"wrong input"<<endl;
    }

    kuy:;
    Enemy *Villain;
    Villain = new Enemy();
    You *Me;
    Me= new You();
    cout<<"Fight Starts Now!!"<<endl;
    cout<<"You have an advantage of having a better weapon than your enemy"<<endl;
    while(Villain->Health>=0 && Me->Health>=0){
    cout<<endl;
    char m;
    cout << "Attack(a) or block(b)?" << endl;
    cin>>m;
    if(m=='a'){
       if(Villain->Armour>0)
       {
       if((Villain->Armour-Me->Damage/2)>=0)
            {

                   Villain->Armour=(Villain->Armour)-(Me->Damage)/2;
                   Villain->Health=(Villain->Health)-(Me->Damage)/2;
            }
        else {
                Villain->Health=Villain->Health+Villain->Armour;
               Villain->Armour=0;
            }
         }
       else{
            Villain->Health=Villain->Health-Me->Damage;
        }
      }
      else if(m=='b')
      {
        if(Me->Health<100)
            Me->Health+=10;
        if(Me->Health>100)
            Me->Health=100;
      }

      else cout<<"Invalid input.";
        enemymove(Me,Villain);
        cout<<"Villain(Health)= "<<Villain->Health<<"   ";
        cout<<"Me(Health)= "<<Me->Health<<"   ";
        cout<<endl;
        cout<<"Villain(Armour)= "<<Villain->Armour<<"   ";
        cout<<"Me(Armour)= "<<Me->Armour<<"   ";
            cout<<endl;

        if(Villain->Health<=0) cout<<"****YOU WON****";
        else if(Me->Health<=0)  cout<<"You Lost :(";
}

cout<<endl<<endl;

final();
label:"Sorry , you lost , better luck next time.!";
}


void enemymove(You *Me,Enemy *Villain)
{

    int case_=0;
    long int *a=NULL;
    case_=rand()%2;
    case_=rand()%2;
    switch(case_)
    {
        case 0 : //attack
                    cout<<"enemy attacked"<<endl;
                    if(Me->Armour>0)
                    {
                        if((Me->Armour-(Villain->Damage/2)>=0))
                         {

                            Me->Armour=(Me->Armour)-(Villain->Damage)/2;
                            Me->Health=(Me->Health)-(Villain->Damage)/2;
                        }

                    else
                        {
                            Me->Armour=0;
                        }
                    }

                        break;
        case 1: //defense.
                    cout<<"enemy defensed"<<endl;
                    if(Villain->Health<100)
                    Villain->Health+=10;
                    if(Villain->Health>100)
                    Villain->Health=100;
    }



}
void final()
{
cout<<"You gave him the final blow!! The final attack hit him so hard that he lost consciousness and fell forward , face down."<<endl;
cout<<"just when you were about to rejoice for your victory you notice something strange on his back."<<endl;
cout<<"His torn clothes revealed the same whip marks you have been seeing in your Hallucinations."<<endl;
cout<<"And then you realize that you just killed the Hero and The real Demon is YOU."<<endl;
}
