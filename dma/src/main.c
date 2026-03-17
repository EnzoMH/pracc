/*main.c*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/order.h"
#include "../include/account.h"
#include "../include/market.h"
#include <time.h>

int main() {
    Order order;
    order.order_id = 1 ;
    order.client_id = 1001 ;
    order.order_type = ORDER_BUY;
    order.price  = 75000 ;
    order.quantity = 10 ;

    /* malloc, Dynamic Allocation을 위한 학습 ; 2026-03-11 */
    /* int n = 3 ; /* 일단 고객은 3으로 제한 id와 잔고를 2차원 배열로 지정 */
    /* Account clients[3]; Before*/

    /* Before Dynamic Allocation, Before 20260316 */
    /* Account account;
    account.client_id = 1001;
    account.balance = 10000000;
    account.margin = 3000000; */

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    Account* account = create_account(1001, "신명호", 10000000, 3000000);

    MarketData market;
    strcpy(market.stock_code, "005930");
    market.current_price = 75000;
    market.upper_limit = 76000;
    market.lower_limit = 74000;

    destroy_account(account); 
    clock_gettime(CLOCK_MONOTONIC, &end); 

    long elapsed_ns = (end.tv_sec - start.tv_sec) * 1000000000L + (end.tv_nsec - start.tv_nsec);
    
    for (int i = 0; i < 3; i++) {
    /* printf("client_id: %d, balance: %ld\n", account.client_id, account.balance);*/
    printf("client_id: %d, balance: %ld\n", account->client_id, account->balance);
}

    printf("order_id     : %d\n", order.order_id);
    printf("price        : %d\n", order.price);
    printf("quantity     : %d\n", order.quantity);
    printf("balance      : %ld\n", account->balance);
    printf("margin       : %ld\n", account->margin);
    printf("stock_code   : %s\n", market.stock_code);
    printf("current_price: %d\n", market.current_price);
    printf("upper_limit  : %d\n", market.upper_limit);
    printf("lower_limit  : %d\n", market.lower_limit);
    
    /*printf("margin_check: %d\n", check_balance(&account, &order));*/
    /*printf("balance_check: %d\n", check_margin(&account, &order));*/
    
    printf("margin_check: %d\n", check_balance(account, &order));
    printf("balance_check: %d\n", check_margin(account, &order));
    printf("valid_order  : %d\n", valid_order(&market, &order));
    printf("check_tick   : %d\n", check_tick(&market, &order));
    printf("elapsed : %ld ns\n", elapsed_ns);
}