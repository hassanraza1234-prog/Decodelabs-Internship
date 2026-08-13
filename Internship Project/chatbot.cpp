#include <iostream>
#include <string>
using namespace std;

int main()
{
    string userinput;
    cout<< "========================"<<endl;
    cout<<"  welcome to AI chatbot"<<endl;
    cout<< "========================"<<endl;
    cout<< "you can chat with me."<<endl;
    cout<< "type 'bye' or 'exit' to close the chatbot."<<endl;

    while(true)
    {
        cout << "\nyou : ";
        getline(cin,userinput);

        if (userinput == "hi" || userinput == "hello"  ||  userinput == "hey")
        {
            cout << "Bot : Hello! Nice to meet you." << endl;
        }
        else if (userinput == "how are you")
        {
            cout << "Bot : I am fine. Thank you for asking."<< endl;
        }
        else if (userinput == "What is your name")
        {
            cout << "Bot : MY name is AI chatbot." << endl;
        }
        else if (userinput == "who made you")
        {
            cout << "Bot : I was created using c++ programming language." <<endl;
        }
        else if (userinput == "What can you do")
        {
            cout << "Bot : Ican answer simple questions using if-else condition." <<endl;
        }
        else if (userinput == "good morning")
        {
            cout << "Bot : good morning! Have a wonderful day." << endl;
        }
        else if (userinput == "good evening")
        {
            cout << "Bot : good evening!" << endl;
        }
        else if (userinput == "thank you" || userinput == "thanks")
        {
            cout << "Bot : yoe are welcome!" << endl;
        }
        else if (userinput == "bye" || userinput == "exit")
        {
            cout << "Bot : Goodbye! Have a nice day." << endl;
            break;
        }
        else
        {
            cout << "Bot : sorry! I don't understand yor question." << endl;
        }
    }

    return 0;
        
   


}