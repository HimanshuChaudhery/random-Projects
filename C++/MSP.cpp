#include<iostream> // for input and output
#include<fstream> // for file handling
#include<sstream> // for coverting any data type into string
#include<windows.h> 
using namespace std;

class Bill{
    private:
        string Item;
        int Rate, Quantity;

    public:
        Bill(): Item(""), Rate(0), Quantity(0){
    
        };

    //Setter function
    void setItem(string item){
        Item = item;
    }

    void setRate(int rate){
        Rate = rate;
    }

    void setQuant(int quant){
        Quantity = quant;
    }

    // Getter function
    string getItem(){
        return Item;
    }

    int getRate(){
        return Rate;
    }

    int getQuant(){
        return Quantity;
    }

};

// ADD ITEM
addItem(Bill b){
    bool close = false;
    while(!close){
        int choice;
        cout<<"\t1.Add."<<endl;
        cout<<"\t2.Close."<<endl;
        cout<<"\tEnter Choice"<<endl;
        cin>>choice;
        
        if(choice==1){
            system("cls");
            string item;
            int rate, quant;

            cout<<"\tEnter Item Name: ";
            cin>>item;
            b.setItem(item);

            cout<<"\tEnter Rate of Item: ";
            cin>>rate;
            b.setRate(rate);

            cout<<"\tEnter Quantity of item: ";
            cin>>quant;
            b.setQuant(quant);

            // Saving ENTERED data in txt file
            ofstream out; // app means append it use add multiple ENTERED data one after another without removing the previous data.
            out.open("D:/bill.txt", ios::app);

            // Checking if our txt file is opening or not
            if(!out){
                cout<<"\tError: File Can't Open!"<<endl;
            }
            else{
                out<<"\t"<<b.getItem()<<" : "<<b.getRate()<<" : "<<b.getQuant()<<endl<<endl;
            }
            out.close();
            cout<<"\tItem Added Successfully"<<endl;
            Sleep(3000); // we have to give value in milliseconds
        }

        else if(choice==2){
            system("cls");
            close = true;
            cout<<"\tBack To Main Menu!"<<endl;
            Sleep(3000);
        }

    }
}


int main(){
    Bill b; // Object creation

    bool exit = false;
    while(!exit){
        system("cls");
        int val;
        cout<<"\tWelcome to Super Market Billing System"<<endl;
        cout<<"\t**************************************"<<endl;
        cout<<"\t\t1.Add Item."<<endl;
        cout<<"\t\t2.Print Bill."<<endl;
        cout<<"\t\t3.Exit"<<endl;
        cout<<"\t\tEnter Choice: ";
        cin>>val;

        if (val==1){
            system("cls");
            addItem(b);
            Sleep(3000);
        }

    }
}