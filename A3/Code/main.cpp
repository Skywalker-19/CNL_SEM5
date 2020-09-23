#include <iostream>
using namespace std;

class CRC{
    int message[20], key[20], temp[20];
    int msgSize, keySize;

    public:

    void getData(){
        cout<<"\nEnter the number of message bits: "<<endl;
        cin>> msgSize;
        cout<<"\nEnter the bits: "<<endl;
        for (int i=0; i<msgSize; i++){
            cin>>message[i];
        }

        cout<<"\nEnter the number of key/generator bits: "<<endl;
        cin>>keySize;
        cout<<"\nEnter the bits: "<<endl;
        for (int i=0; i<keySize; i++){
            cin>>key[i];
        }

        appendZero();
        division(temp, key, msgSize, keySize-1);

    }

    void appendZero(){
        for (int i=0; i< keySize-1 ; i++){
            message[msgSize+i]=0;
        }

        for (int i=0; i< (msgSize + keySize -1); i++){
            temp[i]=message[i];
        }
    }

    void division(int temp[], int key[], int msgSize, int keySize){
        for(int i=0; i<msgSize; i++){
            if(key[0] == temp[i]){
                for (int j=0, k=i; j< (keySize+1); j++, k++){
                    if (!(temp[k]^key[j]))
                        temp[k]=0;
                    else
                        temp[k]=1;
                }
            }
        }

        cout<< "\nCRC: ";
        for (int i=0; i<keySize; i++){
            cout<<temp[msgSize +i];
            message[msgSize+i] = temp[msgSize+i];
        }
    }

    void check(){
        int flag=0;
        cout<<"\nSender-\nTransmitted message: ";
        for (int i=0; i<(msgSize + keySize-1); i++){
            cout<<message[i];
        }
        
	
        cout<<"\nReceiver-\n Enter the Received message: ";
        for (int i=0; i<(msgSize + keySize-1); i++){
            cin>>message[i];
        }

        for (int i=0; i<(msgSize+keySize-1); i++){
            temp[i]=message[i];
        }

        division(temp, key, msgSize, keySize-1);

        for (int i=0; i< keySize-1; i++){
            if (temp [msgSize+i]){
                flag=1;
                cout<<"\nError detected! Retransmit the data!";
                break ;
            }
        }

        if (flag==0){
            cout<<"\nNo error in received message.\nReceived message: ";
            for (int i=0; i<msgSize; i++){
                cout<<message[i];
            }
        }
    }

};

int main(){

    CRC c;
    char ch='y';
    cout<<"\n -- CRC CHECKER AND GENERATOR --"<<endl;
   do{
        c.getData();
        c.check();
        cout<<"\nContinue? ";
        cin>>ch;
    } while(ch == 'Y' || ch =='y');

    return 0;
}














