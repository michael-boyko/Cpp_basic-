#include "walletManager.h"

Wallet *createWallet(int amount) {
    Wallet *wallet = new (std::nothrow) Wallet[1];

    if (wallet == nullptr) {
        std::cout << "Error: memory could not be allocated" << std::endl;
    }
    wallet->septims = amount;
    return wallet;
}

void destroyWallet(Wallet *wallet) {
    delete (wallet);
}

Wallet *createWallets(int amount) {
    Wallet *wallets = new (std::nothrow) Wallet[amount];

    if (wallets == nullptr) {
        std::cout << "Error: memory could not be allocated" << std::endl;
    }
    return wallets;
}

void destroyWallets(Wallet *wallet) {
    delete[] (wallet);
}
