//
//  TBTests.m
//  TBTests
//
//  Created by clobotics_ccp on 2019/9/24.
//  Copyright © 2019 cool-ccp. All rights reserved.
//

#import <XCTest/XCTest.h>

@interface TestClass : NSObject

@property (nonatomic, copy) void(^ copyBlock)(void);
@property (nonatomic, strong) void(^ strongBlock)(void);
@property (nonatomic, weak) void(^ weakBlock)(void);
- (void)test;
- (void)printBlock;
@end

@implementation TestClass

- (void)test {
    __weak typeof(self)ws = self;
    self.copyBlock = ^{
        NSLog(@"%@", [ws.copyBlock class]);
    };
    self.strongBlock = ^{
        NSLog(@"%@", [ws.strongBlock class]);
    };
    self.weakBlock = ^{
        NSLog(@"%@", [ws.weakBlock class]);
    };
    self.copyBlock();
    self.strongBlock();
    self.weakBlock();
}

- (void)printBlock {
    NSLog(@"copy: %@, strong: %@", self.copyBlock, self.strongBlock);
}

@end

@interface TBTests : XCTestCase

@end

@implementation TBTests

- (void)setUp {
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
}

- (void)testExample {
    TestClass *tc = [TestClass new];
    [tc test];
    [tc printBlock];
    
    // This is an example of a functional test case.
    // Use XCTAssert and related functions to verify your tests produce the correct results.
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
