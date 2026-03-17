/*order.h*/

#ifndef ORDER_H
#define ORDER_H

#include "market.h"

#define ORDER_BUY 1
#define ORDER_SELL 2

typedef struct Order {
    int order_id;       /* 주문번호 */
    char stock_id[7];   /* 종목코드 */
    int order_type;     /* 주문종류 */
    int price;          /* 주문가격 */
    int quantity;       /* 수량 */
    int client_id;      /* 고객아이디 */
} Order;

int valid_order(MarketData* marketdata, Order* order);

#endif