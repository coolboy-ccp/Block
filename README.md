# 简单说说Block

## block结构

```
struct Block_layout {
    void *isa;
    volatile int32_t flags; // contains ref count
    int32_t reserved;
    BlockInvokeFunction invoke;
    struct Block_descriptor_1 *descriptor;
    // imported variables
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
```
* isa, 表示结构体指向的元类
* flags, block定义时系统生成的
* reserved, 没用到
* invoke, block内部执行的代码保留在这个invoke中
* descriptor, block的描述
* variables, 如果block引用了外部变量，则会添加这个外部变量为其成员变量
* Block_descriptor_1 存储block信息
* Block_descriptor_2 BLOCK_HAS_COPY_DISPOSE
* Block_descriptor_3 BLOCK_HAS_SIGNATURE

### 元类
_NSConcreteStackBlock 

_NSConcreteMallocBlock

_NSConcreteGlobalBlock

### 关于block_copy
