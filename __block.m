//
//  TestBlock.m
//  a
//
//  Created by clobotics_ccp on 2019/9/23.
//  Copyright © 2019 cool-ccp. All rights reserved.
//

#import <Foundation/Foundation.h>

void func_2() {
    __block int a = 1;
    void(^block_2)(void) = ^{
        a = 2;
        
    };
    block_2();
}




