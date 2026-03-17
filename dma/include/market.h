/*market.h*/

#ifndef MARKET_H
#define MARKET_H

typedef struct{
    char stock_code[7];     /* 종목코드 */
    int current_price;      /* 현재가 */
    int upper_limit;        /* 상한가 */
    int lower_limit;        /* 하한가 */
    int base_price;         /* 기준가(전일종가) */

} MarketData;

struct Order;

int get_tick_size(int price);
int check_tick(MarketData* market, struct Order* order);

#endif