//
//  TestBlock.m
//  a
//
//  Created by clobotics_ccp on 2019/9/23.
//  Copyright © 2019 cool-ccp. All rights reserved.
//

#import <Foundation/Foundation.h>

//_NSConcreteGlobalBlock
void(^block_1)(void) = ^{};

//_NSConcreteStackBlock
void func_2() {
    void(^block_2)(void) = ^{};
    block_2();
}

//_NSConcreteStackBlock -> _NSConcreteMallocBlock
void func_3() {
    void(^block_3)(void) = ^{};
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.3 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        block_3();
    });
}



