# 简单说说Block

## 底层
* 在oc中，实际上就是一个对象
* 在c中，block是一个结构体
```
struct Block_layout {
    void *isa;
    volatile int32_t flags; // contains ref count
    int32_t reserved;
    BlockInvokeFunction invoke;
    struct Block_descriptor_1 *descriptor;
    // imported variables
};
```
