#include"BankingSystem.h"

bool BankingSystem::createAccount(int timestamp, std::string id){
    if(this->accounts.count(id) != 0){
        return false;
    }

    this->accounts[id] = new Account(id);
    return true;
}

std::optional<int> BankingSystem:: deposit(int timestamp, std::string account_id, int amount){
    if(this->accounts.count(account_id) == 0){
        return std::nullopt;
    }

    Account * account = this->accounts[account_id];
    std::optional<int> balance = account->deposit(timestamp, amount);

    return balance;
}

std::optional<int> BankingSystem:: withdraw(int timestamp, std::string account_id, int amount){
    if(this->accounts.count(account_id) == 0){
        return std::nullopt;
    }

    Account * account = this->accounts[account_id];
    std::optional<int> balance = account->withdraw(timestamp, amount);

    return balance;
}

std::vector<std::string> BankingSystem::getTopKWithdrawers(int n){

    class Cmp{
    public:
        bool operator()(const Account * a, const Account * b) const{
            if (a->getTotalWithdraw() == b->getTotalWithdraw()){
                return a->id < b->id;
            }
            return a->getTotalWithdraw() > b->getTotalWithdraw();
        }
    };

    std::vector<std::string> topWithdrawers;
    std::priority_queue<Account *, std::vector<Account*>, Cmp> pq;
    for(auto account:this->accounts){
        pq.push(account.second);
        if(pq.size() > n){
            pq.pop();
        }
    }

    while(!pq.empty()){
        Account * account = pq.top();
        pq.pop();
        topWithdrawers.push_back(account->id + "(" + std::to_string(account->getTotalWithdraw()) + ")");
    }

    std::reverse(topWithdrawers.begin(), topWithdrawers.end());

    return topWithdrawers;
}





BankingSystem::Account::Account(std::string id){
    this->id = id;
    this->balance = 0;
    this->totalWithdraw = 0;
}

std::optional<int> BankingSystem::Account::deposit(int timestamp, int amount){
    this->balance += amount;

    return this->balance;
}

std::optional<int> BankingSystem::Account::withdraw(int timestamp, int amount){
    if(amount > this->balance){
        return std::nullopt;
    }

    this->balance -= amount;
    this->totalWithdraw += amount;

    return this->balance;
}

int BankingSystem::Account::getBalance() const{
    return this->balance;
}

int BankingSystem::Account::getTotalWithdraw() const{
    return this->totalWithdraw;
}
