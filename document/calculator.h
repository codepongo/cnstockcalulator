#import <Foundation/Foundation.h>
#pragma mark -
#pragma mark Rate
@interface Rate:NSObject {
@property (nonatomic, assign)CGFloat commission;
@property (nonatomic, assign) CGFloat stamp;
@property (nonatomic, assign) CGFloat transfer;
}
@end
@implementation Rate
@synthesize commission, stamp, transfer;
@end

#pragma mark -
#pragma mark Trade
@interface Trade:NSObject
@property (nonatomic, assign) CGFloat price;
@property (nonatomic, assign) CGInterger quantity;
@property (nonatomic, readonly, assign) CGFloat amount;
@end
@implementation Trade
@synthesize price, quantity, amount;
@end

#pragma mark -
#pragma mark CalculateBrain
@interface CalculateBrain:NSObject
@property (nonatomic, copy) NSString* code; 
@property (nonatomic, assign) BOOL inSZ;
@property (nonatomic, copy) CGFloat rate;
@property (nonatomic, copy) Trade buy;
@property (nonatomic, copy) Trade sell;
@property (nonatomic, assign)CGFloat commission;
@property (nonatomic, assign) CGFloat stamp;
@property (nonatomic, assign) CGFloat transfer;
- (CGFloat)commission:(CGFloat)amount;
- (CGFloat)stamp:(CGFloat)amount;
- (CGFloat)transfer:(CGFloat)amount;
@end

@implementation CalculateBrain
@synthesize code, inSZ, rate, buy, sell, commission, stamp, transfer
@end
/*

def commission(total):
    total = int(total)
    if total == 0:
        return 0
    commission = 5
    if total > 10000:
        commission = total * rate.commission
    return money_round(commission, 2)

def stamp(total):
    stamp = 1
    if total * 0.001 > stamp:
        stamp = total * 0.001
    return money_round(stamp, 2)

def transfer(code, total):
    transfer = 0
    if code[:2].lower() == 'SH'.lower() or code[0] == '6':
        transfer = total * 0.02 / 1000
    else:
        transfer = total * 0.02 / 1000
    return money_round(transfer, 2)

def sell_(code, price, count):
    price = float(price)
    count = int(count)
    total = price * count
    _commission = commission(total)
    _stamp = stamp(total)
    _transfer = transfer(code, total)
    real = total - _commission - _transfer - _stamp
    if count == 0:
        real_price = 0
    else:
        real_price = money_round(real/count, 3)
    #print '[S]%.3f %.3f %.2f %.2f %.2f' % (real, real_price, _commission, _transfer, _stamp)
    return real, real_price, _commission, _transfer, _stamp

def buy_(code, price, count):
    price = float(price)
    count = int(count)
    total = price * count
    _commission = commission(total)
    _transfer = transfer(code, total)
    real = total + _commission + _transfer
    if count == 0:
        real_price = 0
    else:
        real_price = money_round(real/count, 3)
    #print '[B]%.3f %.3f %.2f %.2f' % (real, real_price, _commission, _transfer)
    return real, real_price, _commission, _transfer

def cost_(code, price, count):
    price = float(price)
    count = int(count)
    total = price * count
    b = buy_(code, price, count)
    s = sell_(code, price, count)
    _commission = b[2] + s[2]
    _transfer = b[3] + s[3]
    stamp = s[4]

    real = total + _commission + _transfer + stamp
    if count == 0:
        real_price = 0
    else:
        real_price = real /count
    #print '*',  real, real_price, _commission, _transfer, stamp
    return real, real_price, _commission, _transfer, stamp

def cost(code, price, count):
    r = cost_(code, price, count)
    return -r[0], r[1], count

    
def buy(code, price, count):
    r =buy_(code, price, count)
    return -r[0], r[1], count
def sell(code, price, count):
    r =sell_(code, price, count)
    return r[0], r[1], -count
*/ 
