/*market.c*/

#include "../include/market.h"
#include <stdio.h>
#include "../include/order.h"
#include "../include/account.h"

int get_tick_size(int price) {
    if (price < 2000)         return 1;    /* 2,000원 미만이면 1원 단위 */
    else if (price < 5000)    return 5;    /* 5,000원 미만이면 5원 단위 */
    else if (price < 20000)   return 10;   /* 20,000원 미만이면 10원 단위 */
    else if (price < 50000)   return 50;   /* 50,000원 미만이면 50원 단위 */
    else if (price < 200000)  return 100;  /* 200,000원 미만이면 100원 단위 */
    else if (price < 500000)  return 500;  /* 500,000원 미만이면 500원 단위 */
    else                      return 1000; /* 500,000원 이상이면 1,000원 단위 */
}

int check_tick(MarketData* market, struct Order* order) {  // Order* → struct Order*
    int tick_size = get_tick_size(order->price);
    if (order->price % tick_size == 0) {
        return 1;
    } else {
        return 0;
    }
}


