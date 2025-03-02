#ifndef BANKINGSYSTEM_H
#define BANKINGSYSTEM_H

#include<queue>
#include<string>
#include<unordered_map>
#include<vector>

class BankingSystem{
private:

    class Account{
    private:

        int balance;
        int totalWithdraw;

    public:

        std::string id;

        Account(std::string id);

        std::optional<int> deposit(int timestamp, int amount);

        std::optional<int> withdraw(int timestamp, int amount);

        int getBalance() const;

        int getTotalWithdraw() const;
    };
    
    std::unordered_map<std::string, Account *> accounts;

public:

    bool createAccount(int timestamp, std::string);

    std::optional<int> deposit(int timestamp, std::string account_id, int amount);

    std::optional<int> withdraw(int timestamp, std::string account_id, int amount);

    std::vector<std::string> getTopKWithdrawers(int n);
};

#endif // BANKINGSYSTEM_H class