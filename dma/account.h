/*account.h*/

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "order.h"

typedef struct {
    int client_id; /* 고객 ID */
    char name [20]; /* 고객 이름 */
    long balance; /* 잔고 */
    long margin; /* 증거금 */
    long daily_limit; /* 일일 거래 한도 */
    long daily_used; /* 금일 사용한 금액 */
    int order_limit; /* 1회 주문 수량 한도 */
} Account ;

int check_balance(Account* account, Order* order);
int check_margin(Account* account, Order* order);

#endif