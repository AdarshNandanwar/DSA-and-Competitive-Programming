#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string getWord(ll n);

int main(){
    ll h, m;
    cin>>h>>m;
    string hour = getWord(h), minute = getWord(m);
    
    if(m == 0){
        cout<<getWord(h)<<" o' clock"<<endl;
    } else if(m == 15){
        cout<<"quarter past "<<getWord(h)<<endl;
    } else if(m == 30){
        cout<<"half past "<<getWord(h)<<endl;
    } else if(m == 45){
        cout<<"quarter to "<<getWord((h+1)==13?1:(h+1))<<endl;
    }else if(m == 1){
        cout<<getWord(m)<<" minute past "<<getWord(h)<<endl;
    } else if(m == 59){
        cout<<getWord(m)<<" minute to "<<getWord((h+1)==13?1:(h+1))<<endl;
    } else if(m < 30){
        cout<<getWord(m)<<" minutes past "<<getWord(h)<<endl;
    } else{
        cout<<getWord(m)<<" minutes to "<<getWord((h+1)==13?1:(h+1))<<endl;
    }
    return 0;
}

string getWord(ll n){
    string word;
    switch (n){
        case 1:{
            word = "one";
            break;
        }
        case 2:{
            word = "two";
            break;
        }
        case 3:{
            word = "three";
            break;
        }
        case 4:{
            word = "four";
            break;
        }
        case 5:{
            word = "five";
            break;
        }
        case 6:{
            word = "six";
            break;
        }
        case 7:{
            word = "seven";
            break;
        }
        case 8:{
            word = "eight";
            break;
        }
        case 9:{
            word = "nine";
            break;
        }
        case 10:{
            word = "ten";
            break;
        }
        case 11:{
            word = "eleven";
            break;
        }
        case 12:{
            word = "twelve";
            break;
        }
        case 13:{
            word = "thirteen";
            break;
        }
        case 14:{
            word = "fourteen";
            break;
        }
        case 15:{
            word = "fifteen";
            break;
        }
        case 16:{
            word = "sixteen";
            break;
        }
        case 17:{
            word = "seventeen";
            break;
        }
        case 18:{
            word = "eighteen";
            break;
        }
        case 19:{
            word = "nineteen";
            break;
        }
        case 20:{
            word = "twenty";
            break;
        }
        case 21:{
            word = "twenty one";
            break;
        }
        case 22:{
            word = "twenty two";
            break;
        }
        case 23:{
            word = "twenty three";
            break;
        }
        case 24:{
            word = "twenty four";
            break;
        }
        case 25:{
            word = "twenty five";
            break;
        }
        case 26:{
            word = "twenty six";
            break;
        }
        case 27:{
            word = "twenty seven";
            break;
        }
        case 28:{
            word = "twenty eight";
            break;
        }
        case 29:{
            word = "twenty nine";
            break;
        }
        case 30:{
            word = "thirty";
            break;
        }
        case 31:{
            word = "twenty nine";
            break;
        }
        case 32:{
            word = "twenty eight";
            break;
        }
        case 33:{
            word = "twenty seven";
            break;
        }
        case 34:{
            word = "twenty six";
            break;
        }
        case 35:{
            word = "twenty five";
            break;
        }
        case 36:{
            word = "twenty four";
            break;
        }
        case 37:{
            word = "twenty three";
            break;
        }
        case 38:{
            word = "twenty two";
            break;
        }
        case 39:{
            word = "twenty one";
            break;
        }
        case 40:{
            word = "twenty";
            break;
        }
        case 41:{
            word = "nineteen";
            break;
        }
        case 42:{
            word = "eighteen";
            break;
        }
        case 43:{
            word = "seventeen";
            break;
        }
        case 44:{
            word = "sixteen";
            break;
        }
        case 45:{
            word = "fifteen";
            break;
        }
        case 46:{
            word = "fourteen";
            break;
        }
        case 47:{
            word = "thirteen";
            break;
        }
        case 48:{
            word = "twelve";
            break;
        }
        case 49:{
            word = "eleven";
            break;
        }

        case 50:{
            word = "ten";
            break;
        }
        case 51:{
            word = "nine";
            break;
        }
        case 52:{
            word = "eight";
            break;
        }
        case 53:{
            word = "seven";
            break;
        }
        case 54:{
            word = "six";
            break;
        }
        case 55:{
            word = "five";
            break;
        }
        case 56:{
            word = "four";
            break;
        }
        case 57:{
            word = "three";
            break;
        }
        case 58:{
            word = "two";
            break;
        }
        case 59:{
            word = "one";
            break;
        }
        default:
            break;
    }
    return word;
}