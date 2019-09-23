//
//  BlockStruct.h
//  Blocks
//
//  Created by clobotics_ccp on 2019/9/23.
//

#ifndef BlockStruct_h
#define BlockStruct_h

// Values for Block_layout->flags to describe block objects
enum {
    BLOCK_DEALLOCATING =      (0x0001),  // runtime
    BLOCK_REFCOUNT_MASK =     (0xfffe),  // runtime
    BLOCK_NEEDS_FREE =        (1 << 24), // runtime
    BLOCK_HAS_COPY_DISPOSE =  (1 << 25), // compiler
    BLOCK_HAS_CTOR =          (1 << 26), // compiler: helpers have C++ code
    BLOCK_IS_GC =             (1 << 27), // runtime
    BLOCK_IS_GLOBAL =         (1 << 28), // compiler
    BLOCK_USE_STRET =         (1 << 29), // compiler: undefined if !BLOCK_HAS_SIGNATURE
    BLOCK_HAS_SIGNATURE  =    (1 << 30), // compiler
    BLOCK_HAS_EXTENDED_LAYOUT=(1 << 31)  // compiler
};


#define BLOCK_DESCRIPTOR_1 1
struct Block_descriptor_1 {
    uintptr_t reserved;
    uintptr_t size;
};

#define BLOCK_DESCRIPTOR_2 1
struct Block_descriptor_2 {
    // requires BLOCK_HAS_COPY_DISPOSE
    BlockCopyFunction copy;
    BlockDisposeFunction dispose;
};

#define BLOCK_DESCRIPTOR_3 1
struct Block_descriptor_3 {
    // requires BLOCK_HAS_SIGNATURE
    const char *signature;
    const char *layout;     // contents depend on BLOCK_HAS_EXTENDED_LAYOUT
};


struct Block_layout {
    void *isa;
    volatile int32_t flags; // contains ref count, 决定block的description
    int32_t reserved;
    BlockInvokeFunction invoke;// block中执行代码会封装成这个函数
    struct Block_descriptor_1 *descriptor; //block的描述
    // imported variables
};

void * _NSConcreteStackBlock[32] = { 0 };//栈元类 在函数中定义时isa指针指向
void * _NSConcreteMallocBlock[32] = { 0 };//如果block在函数返回后需要继续使用，block会被copy到堆中，isa指向
void * _NSConcreteAutoBlock[32] = { 0 };
void * _NSConcreteFinalizingBlock[32] = { 0 };
void * _NSConcreteGlobalBlock[32] = { 0 };//在全局作用域中定义的block的isa指针指向
void * _NSConcreteWeakBlockVariable[32] = { 0 };
#endif /* BlockStruct_h */
