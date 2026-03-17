/*order.c*/

#include <stdio.h>
#include "../include/order.h"
#include "../include/market.h"

int valid_order(MarketData* marketdata, Order* order){
    long order_price = order-> price;

    if (marketdata->lower_limit < order_price && order_price < marketdata->upper_limit) {
        return 1 ;
    } else {
        return 0;
    }
}

/*
#include "account.h"
#include "order.h"

int check_balance(Account* account, Order* order) {
    long order_amount = order->price * order->quantity;


    if (account->balance > order_amount) {

        return 1;

    } else {
        return 0;

    }
}

int check_margin(Account* account, Order* order) {
    long order_amount = order->price * order->quantity;

    if (account->margin < order_amount) {
        return 0;
    } else {
        return 1;
    }

}
*/