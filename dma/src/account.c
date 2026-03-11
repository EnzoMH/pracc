/*account.c*/

#include "../include/account.h"
#include "../include/order.h"

int check_balance(Account* account, Order* order) {
    long order_amount = order->price * order->quantity;
    /* 주문 총금액 = 주문 가격 × 주문 수량 */

    if (account->balance > order_amount) {
        /* 잔고가 주문 총금액보다 크면 */
        return 1;
        /* 잔고 충분 → 주문 가능 */
    } else {
        return 0;
        /* 잔고 부족 → 주문 불가 */
    }
}

int check_margin(Account* account, Order* order) {
    long order_amount = order->price * order->quantity;
    /* 증거금이 주문 총금액보다 충분한가? */
    if (account->margin < order_amount) {
        return 0;
    } else {
        return 1;
    }

}