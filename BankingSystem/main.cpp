#include<iostream>
#include "BankingSystem.h"


int main(){
    BankingSystem bs;

    bs.createAccount(1, "account1");
    bs.createAccount(2, "account2");
    bs.createAccount(3, "account3");
    bs.createAccount(4, "account4");
    std::cout<<bs.deposit(101, "account1", 1000).value()<<std::endl;
    std::cout<<bs.withdraw(102, "account1", 100).value()<<std::endl;
    std::cout<<bs.deposit(103, "account2", 2000).value()<<std::endl;
    std::cout<<bs.withdraw(104, "account2", 200).value()<<std::endl;
    std::cout<<bs.deposit(103, "account3", 200).value()<<std::endl;
    std::cout<<bs.withdraw(102, "account3", 200).value()<<std::endl;

    for(std::string s:bs.getTopKWithdrawers(3)){
        std::cout<<s<<" ";
    }
    std::cout<<std::endl;

    return 0;
}