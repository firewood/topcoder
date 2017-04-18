// Google Code Jam 2017 Qualification Round
// Problem B. Tidy Numbers

#import <Foundation/Foundation.h>
#import <stdio.h>

@interface Solver : NSObject {

}
+ (NSInteger) solve:(NSInteger)n;
@end

@implementation Solver
+ (NSInteger) solve:(NSInteger)n {
    for (NSInteger d = 1; d <= n; d *= 10) {
        NSInteger a = (n / d) % 10, b = (n / d / 10) % 10;
        if (a < b) {
            NSInteger c = n - (n % (d * 10));
            n = c - 1;
        }
    }
    return n;
}
@end

int main(void) {
    @autoreleasepool {
        char buffer[1024];
        fgets(buffer, 1024, stdin);
        NSInteger T = atoll(buffer);
        for (NSInteger t = 1; t <= T; ++t) {
            fgets(buffer, 1024, stdin);
            NSInteger n = atoll(buffer);
            NSInteger ans = [Solver solve:n];
            printf("Case #%ld: %ld\n", (long)t, (long)ans);
        }
    }
    return 0;
}
